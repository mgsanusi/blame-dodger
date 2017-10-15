#include <stdio.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
void sslLoadErrorStrings(void)
{
  ERR_load_crypto_strings();
  ERR_load_SSL_strings();
}


