/* Prints the portable name for the current locale's charset. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "localcharset.h"
void new_exit(int status);


int main ()
{
  setlocale(LC_ALL, "");
  printf("%s\n", locale_charset());
  new_exit(0);
}

void new_exit(int status) {
  return exit(status);
}