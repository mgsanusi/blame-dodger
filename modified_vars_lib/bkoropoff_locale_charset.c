#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "localcharset.h"
void new_exit(int status);



void new_exit(int status) {
  return exit(status);
}