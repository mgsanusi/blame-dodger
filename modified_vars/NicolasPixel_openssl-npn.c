#include <stdlib.h>
#include <openssl/ssl.h>
int Main()
{
  SSL_get0_next_proto_negotiated(0, 0, 0);
  return OPENSSL_NPN_UNSUPPORTED;
}


