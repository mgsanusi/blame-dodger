/**
 * @file
 * MetIO Server
 *
 */  
  
/*
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 *
 */ 
#include "lwip/opt.h"
  
#if LWIP_TCP
#include "lwip/tcp.h"
  
#ifdef MEMLEAK_DEBUG
static const char mem_debug_file[] ICACHE_RODATA_ATTR = __FILE__;

#endif	/* 
  
/*
 * This implements a netio server.
 *  The client sends a command word (4 bytes) then a data length word (4 bytes).
 *  If the command is "receive", the server is to consume "data length" bytes into
 *   a circular buffer until the first byte is non-zero, then it is to consume
 *   another command/data pair.
 *  If the command is "send", the server is to send "data length" bytes from a circular
 *   buffer with the first byte being zero, until "some time" (6 seconds in the
 *   current netio126.zip download) has passed and then send one final buffer with
 *   the first byte being non-zero. Then it is to consume another command/data pair.
 */ 
  
/* See http://www.nwlab.net/art/netio/netio.html to get the netio tool */ 
  
/* implementation options */ 
#define NETIO_BUF_SIZE              (4 * 1024)
#define NETIO_USE_STATIC_BUF        0
  
/* NetIO server state definition */ 
#define NETIO_STATE_WAIT_FOR_CMD    0
#define NETIO_STATE_RECV_DATA       1
#define NETIO_STATE_SEND_DATA       2
#define NETIO_STATE_SEND_DATA_LAST  3
#define NETIO_STATE_DONE            4
  
{
  
  
  
  
  
  
  
  


/* NetIO command protocol definition */ 
#define NETIO_CMD_QUIT              0
#define NETIO_CMD_C2S               1
#define NETIO_CMD_S2C               2
#define NETIO_CMD_RES               3

			  err_t err);

netio_close (void *arg, struct tcp_pcb *pcb) 
{
  
  
  
  
  
  
    {
      
	/* closing failed, try again later */ 
	tcp_recv (pcb, netio_recv);
    
  else
    {
      
	/* closing succeeded */ 
#if NETIO_USE_STATIC_BUF != 1
	if (ns->buf_ptr != NULL)
	{
	  
	
      
#endif	/* 
	tcp_arg (pcb, NULL);
      
      
      
	{
	  
	
    



netio_recv (void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err) 
{
  
  
  
  
  
  
    {
      
    
  
    {
      
	{
	  
	  
	  
	    {
	      
		{
		  
		  
		
	      else if (ns->state == NETIO_STATE_WAIT_FOR_CMD)
		{
		  
		    {
		      
			/* build up the CMD field */ 
			ns->cmd <<= 8;
		      
		      
		    
		  else if (ns->cntr < 8)
		    {
		      
			/* build up the DATA field */ 
			ns->data_len <<= 8;
		      
		      
		      
			{
			  
			    /* now we have full command and data words */ 
			    ns->cntr = 0;
			  
			  
			  
			    {
			      
			    
			  else if (ns->cmd == NETIO_CMD_S2C)
			    {
			      
			      
				/* start timer */ 
				ns->time_stamp = sys_now ();
			      
				/* send first round of data */ 
				
			      
			      
				LWIP_MIN (len, NETIO_BUF_SIZE - ns->buf_pos);
			      
			      do
				{
				  
				    tcp_write (pcb, ns->buf_ptr + ns->buf_pos,
					       len, TCP_WRITE_FLAG_COPY);
				  
				    {
				      
				    
				
			      while ((err == ERR_MEM) && (len > 1));
			      
			      
			    
			  else
			    {
			      
				/* unrecognized command, punt */ 
				ns->cntr = 0;
			      
			      
			      
			      
			    
			
		    
		  else
		    {
		      
			/* in trouble... shouldn't be in this state! */ 
		    }
		
	      else if (ns->state == NETIO_STATE_RECV_DATA)
		{
		  
		    {
		      
			/* save the first byte of this new round of data
			 * this will not match ns->buf_ptr[0] in the case that
			 *   NETIO_BUF_SIZE is less than ns->data_len.
			 */ 
			ns->first_byte = *data_ptr;
		    
		  
		  
		  
		    {
		      
			/* circularize the buffer */ 
			ns->buf_pos = 0;
		    
		  
		    {
		      
		      
			{
			  
			    /* if this last round did not start with 0,
			     *  go look for another command */ 
			    ns->state = NETIO_STATE_WAIT_FOR_CMD;
			  
			  
			  
			    /* TODO LWIP_DEBUGF( print out some throughput calculation results... ); */ 
			}
		      else
			{
			  
			    /* stay here and wait on more data */ 
			}
		    
		
	      else if (ns->state == NETIO_STATE_SEND_DATA 
		       ||ns->state == NETIO_STATE_SEND_DATA_LAST)
		{
		  
		    /* I don't think this should happen... */ 
		}
	      else
		{
		  
		    /* done / quit */ 
		    netio_close (ns, pcb);
		  
		
	    
	  
	
      
    
  else
    {
      
	/* error or closed by other side */ 
	if (p != NULL)
	{
	  
	
      
	/* close the connection */ 
	netio_close (ns, pcb);
    
  



netio_sent (void *arg, struct tcp_pcb *pcb, u16_t len) 
{
  
  
  
    {
      
	/* done with this round of sending */ 
	ns->buf_pos = 0;
      
      
	/* check if timer expired */ 
	if (sys_now () - ns->time_stamp > 600)
	{
	  
	  
	
      else
	{
	  
	
    
  
	 || ns->state == NETIO_STATE_SEND_DATA)
    {
      
      
      
      
	{
	  
	  do
	    {
	      
		tcp_write (pcb, ns->buf_ptr + ns->buf_pos, len,
			   TCP_WRITE_FLAG_COPY);
	      
		{
		  
		
	    
	  while ((err == ERR_MEM) && (len > 1));
	  
	  
	    {
	      
	    
	  
	
    
  
    {
      
	/* we have buffered up all our data to send this last round, go look for a command */ 
	ns->state = NETIO_STATE_WAIT_FOR_CMD;
      
      
	/* TODO LWIP_DEBUGF( print out some throughput calculation results... ); */ 
    }
  



netio_poll (void *arg, struct tcp_pcb *pcb) 
{
  
  
    {
    
  else if (ns->state == NETIO_STATE_DONE)
    {
      
    
  



#if NETIO_USE_STATIC_BUF == 1
static u8_t netio_buf[NETIO_BUF_SIZE];

#endif	/* 

netio_accept (void *arg, struct tcp_pcb *pcb, err_t err) 
{
  
  
  
  
    {
      
    
  
  
  
  
  
  
#if NETIO_USE_STATIC_BUF == 1
    ns->buf_ptr = netio_buf;
  
#else	/* 
    ns->buf_ptr = (u8_t *) mem_malloc (NETIO_BUF_SIZE);
  
    {
      
      
    
  
#endif	/* 
    
  
  
  
  
  



netio_init (void) 
{
  
  
  
  
  

#endif	/* LWIP_TCP */