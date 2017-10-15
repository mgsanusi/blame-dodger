#include <stdio.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
void sslLoadErrorStrings(void)
{
  int first_iteration;
  ERR_load_crypto_strings();
  ERR_load_SSL_strings();
}


