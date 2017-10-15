#include <config.h>
#include "physmem.h"
#include <unistd.h>
#include <sys/types.h>
typedef WINBOOL (WINAPI *PFN_MS_EX) (lMEMORYSTATUSEX*);
void new_exit(int status);



void new_exit(int status) {
  return exit(status);
}