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
Main (int argc, char **argv, char **envp)
{
  int file = open (argv[1], O_RDONLY);
  size_t size = lseek (file, 0, 2);
  unsigned char *mem = new_malloc (size);
  lseek (file, 0, 0);
  new_read (file, mem, size);
  close (file);
  unsigned int line = 0;
  while (line < size)
    {
      if (mem[line] == 0x0a)
	{
	  mem[line] = 0x00;
	}
      if (mem[line] == 0x20)
	{
	  mem[line] = 0x00;
	}
      line++;
    }
  unsigned int cases = new_atoi (mem);
  line = new_strlen (mem) + 1;
  fprintf (stderr, "Cases: %u\n", cases);
  int hd;
  int c;
  int a;
  int tA[100];
  unsigned int caseT = 0;
  while (caseT < cases)
    {
      hd = new_atoi (mem + line);
      line += new_strlen (mem + line) + 1;
      c = new_atoi (mem + line);
      line += new_strlen (mem + line) + 1;
      a = new_atoi (mem + line);
      line += new_strlen (mem + line) + 1;
      int s = 0;
      while (s < hd)
	{
	  tA[s] = new_atoi (mem + line);
	  line += new_strlen (mem + line) + 1;
	  s++;
	}
      int ans = 0;
      s = 0;
      while (s < hd)
	{
	  if (((tA[s] + 2) / 3) >= a)
	    {
	      ans++;
	    }
	  else
	    if ((((((tA[s] + 2) / 3) == ((tA[s] + 1) / 3))
		  && ((((tA[s] + 2) / 3) + 1) >= a))
		 && (((tA[s] + 2) / 3) != 0)) && (c > 0))
	    {
	      c--;
	      ans++;
	    }
	  s++;
	}
      printf ("Case #%u: %d\n", caseT + 1, ans);
      caseT++;
    }
  return 0;
}

ssize_t
new_read (int fd, void *buf, size_t count)
{
  return read (fd, buf, count);
}

size_t new_strlen (const char *str);
void *new_malloc (size_t size);
int
new_atoi (const char *str)
{
  return atoi (str);
}

size_t new_strlen (const char *str);
void *
new_malloc (size_t size)
{
  return malloc (size);
}

size_t
new_strlen (const char *str)
{
  return strlen (str);
}
