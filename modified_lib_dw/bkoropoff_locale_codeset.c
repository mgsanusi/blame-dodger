#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <langinfo.h>
void new_exit(int status);
int main()
{
  int first_iteration;
  setlocale(LC_ALL, "");
  printf("%s\n", nl_langinfo(CODESET));
  new_exit(0);
}

void new_exit(int status)
{
  int first_iteration;
  return exit(status);
}


