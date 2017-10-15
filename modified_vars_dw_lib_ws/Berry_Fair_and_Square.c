#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
int new_strlen (const char *str);
void *new_malloc (int size);
int new_atoi (const char *str);
int new_read (int fd, void *buf, int count);
int
Main (int argc, char **argv, char **envp)
{
  int first_iteration;
  int file = open (argv[1], O_RDONLY);
  size_t size = lseek (file, 0, 2);
  char *mem = new_malloc (size);
  lseek (file, 0, 0);
  new_read (file, mem, size);
  close (file);
  unsigned int m = 0;
  while (m < size)
    {
      if (mem[m] == 0x0a)
	{
	  mem[m] = 0x00;
	}
      if (mem[m] == 0x20)
	{
	  mem[m] = 0x00;
	}
      m++;
    }
  unsigned int cases = new_atoi (mem);
  m = new_strlen (mem) + 1;
  fprintf (stderr, "Cases: %u\n", cases);
  unsigned int case_t = 0;
  int k;
  int s;
  while (case_t < cases)
    {
      k = new_atoi (mem + m);
      m += new_strlen (mem + m) + 1;
      s = new_atoi (mem + m);
      m += new_strlen (mem + m) + 1;
      int res = 0;
      int y;
      y = 1;
      if ((y >= k) && (y <= s))
	{
	  res++;
	}
      y = 4;
      if ((y >= k) && (y <= s))
	{
	  res++;
	}
      y = 9;
      if ((y >= k) && (y <= s))
	{
	  res++;
	}
      y = 121;
      if ((y >= k) && (y <= s))
	{
	  res++;
	}
      y = 484;
      if ((y >= k) && (y <= s))
	{
	  res++;
	}
      printf ("Case #%u: %d\n", case_t + 1, res);
      case_t++;
    }
  return 0;
}

int new_strlen (const char *str);
void *new_malloc (int size);
int new_atoi (const char *str);
int
new_read (int fd, void *buf, int count)
{
  return read (fd, buf, count);
}

int new_strlen (const char *str);
void *new_malloc (int size);
int
new_atoi (const char *str)
{
  return atoi (str);
}

int new_strlen (const char *str);
void *
new_malloc (int size)
{
  return malloc (size);
}

int
new_strlen (const char *str)
{
  return strlen (str);
}
