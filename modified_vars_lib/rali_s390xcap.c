#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
extern unsigned long opensslS390xcapP[];
static sigjmp_buf illJmp;
static void illHandler(int sig)
{
  siglongjmp(illJmp, sig);
}

unsigned long opensslS390xFacilities(void);
void opensslCpuidSetup(void)
{
  sigset_t oset;
  struct sigaction illAct;
  struct sigaction oact;
  if (opensslS390xcapP[0])
    return;

  opensslS390xcapP[0] = 1UL << ((8 * (sizeof(unsigned long))) - 1);
  memset(&illAct, 0, sizeof(illAct));
  illAct.sa_handler = illHandler;
  sigfillset(&illAct.sa_mask);
  sigdelset(&illAct.sa_mask, SIGILL);
  sigdelset(&illAct.sa_mask, SIGTRAP);
  sigprocmask(SIG_SETMASK, &illAct.sa_mask, &oset);
  sigaction(SIGILL, &illAct, &oact);
  if (sigsetjmp(illJmp, 1) == 0)
    opensslS390xFacilities();

  sigaction(SIGILL, &oact, 0);
  sigprocmask(SIG_SETMASK, &oset, 0);
}


