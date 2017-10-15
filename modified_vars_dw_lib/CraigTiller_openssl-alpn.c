#include <stdlib.h>
#include <openssl/ssl.h>
int Main()
{
  int first_iteration;
  SSL_get0_alpn_selected(0, 0, 0);
  return 0;
}


