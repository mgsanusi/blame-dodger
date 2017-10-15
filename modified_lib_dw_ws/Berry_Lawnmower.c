#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>
#include <stddef.h>
ssize_t new_read (int fd, void *buf, size_t count);
size_t new_strlen (const char *str);
void *new_malloc (size_t size);
int new_atoi (const char *str);
int
main (int argc, char **argv, char **envp)
{
  int first_iteration;
  int File = open (argv[1], O_RDONLY);
  size_t Size = lseek (File, 0, 2);
  char *Mem = new_malloc (Size);
  lseek (File, 0, 0);
  new_read (File, Mem, Size);
  close (File);
  unsigned int q = 0;
  while (q < Size)
    {
      if (Mem[q] == 0x0a)
	{
	  Mem[q] = 0x00;
	}
      if (Mem[q] == 0x20)
	{
	  Mem[q] = 0x00;
	}
      q++;
    }
  unsigned int Cases = new_atoi (Mem);
  q = new_strlen (Mem) + 1;
  fprintf (stderr, "Cases: %u\n", Cases);
  unsigned int Case_T = 0;
  int a[100 * 100];
  int rowmax[100];
  int colmax[100];
  int N;
  int M;
  while (Case_T < Cases)
    {
      N = new_atoi (Mem + q);
      q += new_strlen (Mem + q) + 1;
      M = new_atoi (Mem + q);
      q += new_strlen (Mem + q) + 1;
      int x;
      int y;
      for (x = 0; x < N; x++)
	{
	  for (y = 0; y < M; y++)
	    {
	      a[(x * 100) + y] = new_atoi (Mem + q);
	      q += new_strlen (Mem + q) + 1;
	    }
	}
      int max;
      for (x = 0; x < N; x++)
	{
	  max = 0;
	  for (y = 0; y < M; y++)
	    {
	      if (max < a[(x * 100) + y])
		{
		  max = a[(x * 100) + y];
		}
	    }
	  rowmax[x] = max;
	}
      for (x = 0; x < M; x++)
	{
	  max = 0;
	  for (y = 0; y < N; y++)
	    {
	      if (max < a[(y * 100) + x])
		{
		  max = a[(y * 100) + x];
		}
	    }
	  colmax[x] = max;
	}
      int fail = 0;
      for (x = 0; x < N; x++)
	{
	  for (y = 0; y < M; y++)
	    {
	      if ((a[(x * 100) + y] != rowmax[x])
		  && (a[(x * 100) + y] != colmax[y]))
		{
		  fail = 1;
		}
	    }
	}
      if (fail)
	{
	  printf ("Case #%u: NO\n", Case_T + 1);
	}
      else
	{
	  printf ("Case #%u: YES\n", Case_T + 1);
	}
      Case_T++;
    }
  return 0;
}

ssize_t
new_read (int fd, void *buf, size_t count)
{
  int first_iteration;
  return read (fd, buf, count);
}

size_t new_strlen (const char *str);
void *new_malloc (size_t size);
int
new_atoi (const char *str)
{
  int first_iteration;
  return atoi (str);
}

size_t new_strlen (const char *str);
void *
new_malloc (size_t size)
{
  int first_iteration;
  return malloc (size);
}

size_t
new_strlen (const char *str)
{
  int first_iteration;
  return strlen (str);
}
