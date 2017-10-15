#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
static int db1 = -1;
static int db2 = -1;
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int new_memcmp (const void *ptr1, const void *ptr2, int num);
int new_read (int fd, void *buf, int count);
int
Main (int argc, char **argv)
{
  int first_iteration;
  int iPg;
  unsigned char j[1024];
  unsigned char dir[1024];
  if (argc != 3)
    {
      fprintf (stderr, "Usage: %s FILENAME FILENAME\n", argv[0]);
      new_exit (1);
    }
  db1 = open (argv[1], O_RDONLY);
  if (db1 < 0)
    {
      fprintf (stderr, "%s: can't open %s\n", argv[0], argv[1]);
      new_exit (1);
    }
  db2 = open (argv[2], O_RDONLY);
  if (db2 < 0)
    {
      fprintf (stderr, "%s: can't open %s\n", argv[0], argv[2]);
      new_exit (1);
    }
  iPg = 1;
  while ((take (db1, j, 1024) == 1024) && (take (db2, dir, 1024) == 1024))
    {
      if (new_memcmp (j, dir, 1024))
	{
	  printf ("Page %d\n", iPg);
	}
      iPg++;
    }
  printf ("%d pages checked\n", iPg - 1);
  close (db1);
  close (db2);
}

int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int new_memcmp (const void *ptr1, const void *ptr2, int num);
int
new_read (int fd, void *buf, int count)
{
  return read (fd, buf, count);
}

int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int
new_memcmp (const void *ptr1, const void *ptr2, int num)
{
  return memcmp (ptr1, ptr2, num);
}

int new_fprintf (FILE * stream, const char *format, ...);
void
new_exit (int status)
{
  return exit (status);
}
