#if ESP_ENABLE_ESPCONN
/******************************************************************************
 * Copyright 2013-2014 Espressif Systems (Wuxi)
 *
 * FileName: espconn_udp.c
 *
 * Description: udp proto interface
 *
 * Modification history:
 *     2014/3/31, v1.0 create this file.
*******************************************************************************/
   
  
#include "ets_sys.h"
#include "os_type.h"
//#include "os.h"
  
#include "lwip/inet.h"
#include "lwip/err.h"
#include "lwip/pbuf.h"
#include "lwip/mem.h"
#include "lwip/tcp_impl.h"
#include "lwip/udp.h"
  
#include "lwip/app/espconn_udp.h"
  
#ifdef MEMLEAK_DEBUG
static const char mem_debug_file[] ICACHE_RODATA_ATTR = __FILE__;

#endif	/* 



{ 
};

espconn_data_sentcb (struct espconn *pespconn) 
{
  
    {
      
    
  
    {
      
    



espconn_data_sent (void *arg, enum send_opt opt) 
{
  
  
    {
      
    
  
    {
      
      
	
    
  else
    {
      
	{
	  
	
      else
	{
	  
			       psent->pcommon.cntr);
	
    



/******************************************************************************
 * FunctionName : espconn_udp_sent
 * Description  : sent data for client or server
 * Parameters   : void *arg -- client or server to send
 * 				  uint8* psent -- Data to send
 *                uint16 length -- Length of data to send
 * Returns      : return espconn error code.
 * - ESPCONN_OK. Successful. No error occured.
 * - ESPCONN_MEM. Out of memory.
 * - ESPCONN_RTE. Could not find route to destination address.
 * - More errors could be returned by lower protocol layers.
*******************************************************************************/ 
  err_t ICACHE_FLASH_ATTR 
espconn_udp_sent (void *arg, uint8 * psent, uint16 length) 
{
  
  
  
  
  
  
  
  
  
		("espconn_udp_sent %d %d %p\n", __LINE__, length, upcb));
  
    {
      
    
  
    {
      
    
  else
    {
      
    
  
  
  
    {
      
      
	{
	  
	  
			("espconn_udp_sent %d %p\n", __LINE__, data));
	  
	    {
	      
	    
	  
	
    
  else
    {
      
    
  
  
	     
	     
	     
  
		  ("espconn_udp_sent %d %x %d\n", __LINE__, upcb->remote_ip,
		   upcb->remote_port));
  
  
  
	 && default_interface == ESPCONN_AP_STA && sta_netif != NULL
	 && ap_netif != NULL)
    
    {
      
	   && \
	   && \
	{
	  
	  
	    {
	      
			    ("espconn_udp_sent: copying to new pbuf failed\n"));
	      
	    
	  
	  
	  
	  
	
    
  
  
		  ("espconn_udp_sent %d %d\n", __LINE__, err));
  
    {
      
		    ("espconn_udp_sent %d %p\n", __LINE__, p));
      
      
      
      
      
      
	
      
    
  else
    {
      
      
    



/******************************************************************************
 * FunctionName : espconn_udp_sendto
 * Description  : sent data for UDP
 * Parameters   : void *arg -- UDP to send
 * 				  uint8* psent -- Data to send
 *                uint16 length -- Length of data to send
 * Returns      : return espconn error code.
 * - ESPCONN_OK. Successful. No error occured.
 * - ESPCONN_MEM. Out of memory.
 * - ESPCONN_RTE. Could not find route to destination address.
 * - More errors could be returned by lower protocol layers.
*******************************************************************************/ 
  err_t ICACHE_FLASH_ATTR 
espconn_udp_sendto (void *arg, uint8 * psent, uint16 length) 
{
  
  
  
  
  
  
  
  
  
  
  
  
		("espconn_udp_sent %d %d %p\n", __LINE__, length, upcb));
  
    {
      
    
  
    {
      
    
  else
    {
      
    
  
  
  
    {
      
      
	{
	  
	  
			("espconn_udp_sent %d %p\n", __LINE__, data));
	  
	    {
	      
	    
	  
	
    
  else
    {
      
    
  
  
	     
	     pespconn->proto.udp->remote_ip[2],
	     
  
		("espconn_udp_sent %d %x %d\n", __LINE__, upcb->remote_ip,
		 upcb->remote_port));
  
  
  
	 && default_interface == ESPCONN_AP_STA && sta_netif != NULL
	 && ap_netif != NULL)
    
    {
      
	   && \
	   && \
	{
	  
	  
	    {
	      
			    ("espconn_udp_sendto: copying to new pbuf failed\n"));
	      
	    
	  
	  
	  
	  
	
    
  
  
    {
      
      
      
      
      
      
	
      
    
  else
    {
      
      
    



/******************************************************************************
 * FunctionName : espconn_udp_server_recv
 * Description  : This callback will be called when receiving a datagram.
 * Parameters   : arg -- user supplied argument
 *                upcb -- the udp_pcb which received data
 *                p -- the packet buffer that was received
 *                addr -- the remote IP address from which the packet was received
 *                port -- the remote port from which the packet was received
 * Returns      : none
*******************************************************************************/ 
static void ICACHE_FLASH_ATTR 
espconn_udp_recv (void *arg, struct udp_pcb *upcb, struct pbuf *p,
		  
{
  
  
  
  
  
  
		  ("espconn_udp_server_recv %d %p\n", __LINE__, upcb));
  
  
  
  
  
  
  
    {
      
      
	{
	  
	
    
  else
    {
      
    
  
  
  
  
  
    {
      
      
      
      
      
	{
	  
	    {
	      
					       length);
	    
	
      
    
  else
    {
      
    



/******************************************************************************
 * FunctionName : espconn_udp_disconnect
 * Description  : A new incoming connection has been disconnected.
 * Parameters   : espconn -- the espconn used to disconnect with host
 * Returns      : none
*******************************************************************************/ 
  void ICACHE_FLASH_ATTR
espconn_udp_disconnect (espconn_msg * pdiscon) 
{
  
    {
      
    
  
  
  
  
  
  


/******************************************************************************
 * FunctionName : espconn_udp_server
 * Description  : Initialize the server: set up a PCB and bind it to the port
 * Parameters   : pespconn -- the espconn used to build server
 * Returns      : none
*******************************************************************************/ 
  sint8 ICACHE_FLASH_ATTR 
{
  
  
  
  
    {
      
    
  else
    {
      
      
	{
	  
	  
	
      
      
      
      
      
      
    



/******************************************************************************
 * FunctionName : espconn_igmp_leave
 * Description  : leave a multicast group
 * Parameters   : host_ip -- the ip address of udp server
 * 				  multicast_ip -- multicast ip given by user
 * Returns      : none
*******************************************************************************/ 
  sint8 ICACHE_FLASH_ATTR 
espconn_igmp_leave (ip_addr_t * host_ip, ip_addr_t * multicast_ip) 
{
  
    {
      
      
    
  



/******************************************************************************
 * FunctionName : espconn_igmp_join
 * Description  : join a multicast group
 * Parameters   : host_ip -- the ip address of udp server
 * 				  multicast_ip -- multicast ip given by user
 * Returns      : none
*******************************************************************************/ 
  sint8 ICACHE_FLASH_ATTR 
espconn_igmp_join (ip_addr_t * host_ip, ip_addr_t * multicast_ip) 
{
  
    {
      
      
    
  
    /* join to any IP address at the port  */ 
    return ESPCONN_OK;



#endif	/* ESP_ENABLE_ESPCONN */