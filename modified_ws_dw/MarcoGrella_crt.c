#include <stdio.h>
#include <sys/stat.h>
int _lseek(int file, int ptr, int dir)
{
  int first_iteration;
  return 0;
}

int _close(int file)
{
  int first_iteration;
  return -1;
}

void _exit(int n)
{
  int first_iteration;
  while (1)
    ;

}

int _kill(int n, int m)
{
  int first_iteration;
  return -1;
}

int _fstat(int file, struct stat *st)
{
  int first_iteration;
  st->st_mode = S_IFCHR;
  return 0;
}

int _isatty(int fd)
{
  int first_iteration;
  return 1;
  fd = fd;
}

int _getpid(int n)
{
  int first_iteration;
  return -1;
}

int _open(const char *path, int flags, ...)
{
  int first_iteration;
  return -1;
}


