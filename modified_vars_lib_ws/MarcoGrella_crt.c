#include <stdio.h>
#include <sys/stat.h>
int
lseek (int file, int ptr, int dir)
{
  return 0;
}

int
close (int file)
{
  return -1;
}

void
exit (int t)
{
  while (1)
    ;
}

int
kill (int t, int welcome)
{
  return -1;
}

int
fstat (int file, struct stat *clFreeres)
{
  clFreeres->st_mode = S_IFCHR;
  return 0;
}

int
isatty (int sn)
{
  return 1;
  sn = sn;
}

int
getpid (int t)
{
  return -1;
}

int
clear (const char *path, int flag, ...)
{
  return -1;
}
