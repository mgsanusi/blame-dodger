/*
 * Copyright (c) 2014-2017 Cesanta Software Limited
 * All rights reserved
 */

#include "fw/src/mgos_debug_hal.h"

#include <stdio.h>

#include <lwip/pbuf.h>
#include <lwip/tcpip.h>
#include <lwip/udp.h>

#include "common/cs_dbg.h"
#include "common/mbuf.h"

#include "fw/src/mgos_features.h"
#include "fw/src/mgos_hal.h"
#include "fw/src/mgos_init.h"

#include "fw/platforms/esp8266/src/esp_exc.h"

#if MGOS_ENABLE_DEBUG_UDP
static struct udp_pcb *s_upcb = NULL;
static ip_addr_t s_dst;
static uint16_t s_port;
static bool s_cb_pending;
static struct mbuf s_to_send;

enum mgos_init_result mgos_debug_udp_init(const char *dst) {
  uint32_t ip1, ip2, ip3, ip4, port;
  if (sscanf(dst, "%u.%u.%u.%u:%u", &ip1, &ip2, &ip3, &ip4, &port) != 5) {
    LOG(LL_ERROR, ("Invalid address"));
    return MGOS_INIT_DEBUG_INIT_FAILED;
  }
  s_dst.addr = htonl((ip1 << 24) | (ip2 << 16) | (ip3 << 8) | ip4);
  s_port = port;
  struct udp_pcb *upcb = udp_new();
  if (upcb == NULL || udp_bind(upcb, IP_ADDR_ANY, 0 /* any port */) != ERR_OK) {
    return MGOS_INIT_DEBUG_INIT_FAILED;
  }
  s_upcb = upcb;
  return MGOS_INIT_OK;
}

void udp_flush_cb(void *arg) {
  mgos_lock();
  s_cb_pending--;
  struct pbuf *p = pbuf_alloc(PBUF_TRANSPORT, s_to_send.len, PBUF_RAM);
  if (p != NULL) {
    memcpy(p->payload, s_to_send.buf, s_to_send.len);
    udp_sendto(s_upcb, p, &s_dst, s_port);
    pbuf_free(p);
  }
  mbuf_remove(&s_to_send, s_to_send.len);
  mbuf_trim(&s_to_send);
  mgos_unlock();
  (void) arg;
}

void mgos_debug_udp_send(const struct mg_str prefix, const struct mg_str data) {
  if (s_upcb == NULL) return;
  if (s_to_send.len + prefix.len + data.len > 1500) return;
  mgos_lock();
  mbuf_append(&s_to_send, prefix.p, prefix.len);
  mbuf_append(&s_to_send, data.p, data.len);
  if (!s_cb_pending) {
#ifdef RTOS_SDK
    if (tcpip_callback_with_block(udp_flush_cb, NULL, false /* block */) ==
        ERR_OK) {
      s_cb_pending++;
    }
#else
    if (mgos_invoke_cb(udp_flush_cb, NULL, false /* from_isr */))
      s_cb_pending++;
#endif
  }
  mgos_unlock();
}
#endif /* MGOS_ENABLE_DEBUG_UDP */
