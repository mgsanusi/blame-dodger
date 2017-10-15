#include <config.h>
#include "physmem.h"
#include <unistd.h>
#include <sys/pstat.h>
#include <sys/sysmp.h>
#include <sys/sysinfo.h>
#include <machine/hal_sysinfo.h>
#include <sys/table.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/sysctl.h>
#include <sys/systemcfg.h>
#include <windows.h>
typedef WINBOOL(WINAPI * PFN_MS_EX) (lMEMORYSTATUSEX *);
#include <stdio.h>
#include <stdlib.h>

