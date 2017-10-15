#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
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
  unsigned char *mem = new_malloc (size);
  lseek (file, 0, 0);
  new_read (file, mem, size);
  close (file);
  unsigned int x = 0;
  while (x < size)
    {
      if (mem[x] == 0x0a)
	{
	  mem[x] = 0x00;
	}
      if (mem[x] == 0x20)
	{
	  mem[x] = 0x00;
	}
      x++;
    }
  unsigned int cases = new_atoi (mem);
  x = new_strlen (mem) + 1;
  fprintf (stderr, "Cases: %u\n", cases);
  int64_t c;
  int64_t pD;
  int64_t pG;
  int64_t temp;
  unsigned possible;
  unsigned int caseT = 0;
  while (caseT < cases)
    {
      c = atoll (mem + x);
      x += new_strlen (mem + x) + 1;
      pD = atoll (mem + x);
      x += new_strlen (mem + x) + 1;
      pG = atoll (mem + x);
      x += new_strlen (mem + x) + 1;
      possible = 0;
      temp = 1;
      while ((temp < 101) && (temp <= c))
	{
	  if (((temp * pD) % 100) == 0)
	    {
	      goto Skip;
	    }
	  temp++;
	}
      goto Impossible;
    Skip:
      1;
      if ((((pD == 100) && (pG == 0)) || ((pD != 100) && (pG == 100)))
	  || ((pD != 0) && (pG == 0)))
	{
	  goto Impossible;
	}
      possible = 1;
    Impossible:
      printf ("Case #%u: %s\n", caseT + 1,
	      possible == 1 ? "Possible" : "Broken");
      caseT++;
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
