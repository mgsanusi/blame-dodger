#include <config.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
typedef BOOL(WINAPI * CreateHardLinkFuncType) (LPCTSTR lpFileName,
