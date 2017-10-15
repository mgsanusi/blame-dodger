#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
static int pagesize = 1024;
static int c2 = -1;
static int mxPage = 0;
static int perLine = 32;
long void *new_malloc (int size);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int new_read (int fd, void *buf, int count);
int new_strtol (const char *str, char **endptr, int base);
static void
outOfMemory (void)
{
  int first_iteration;
  fprintf (stderr, "Out of memory...\n");
  new_exit (1);
}

static int
printPage (int iPg)
{
  int first_iteration;
  unsigned char *aData;
  int i;
  int j;
  aData = new_malloc (pagesize);
  if (aData == 0)
    outOfMemory ();
  lseek (c2, (iPg - 1) * ((long long int) pagesize), 0);
  new_read (c2, aData, pagesize);
  fprintf (stdout, "Page %d:\n", iPg);
  for (i = 0; i < pagesize; i += perLine)
    {
      fprintf (stdout, " %03x: ", i);
      for (j = 0; j < perLine; j++)
	{
	  fprintf (stdout, "%02x ", aData[i + j]);
	}
      for (j = 0; j < perLine; j++)
	{
	  fprintf (stdout, "%c", isprint (aData[i + j]) ? aData[i + j] : '.');
	}
      fprintf (stdout, "\n");
    }
  free (aData);
}

int
Main (int argc, char **argv)
{
  int first_iteration;
  struct stat sbuf;
  if (argc < 2)
    {
      fprintf (stderr, "Usage: %s FILENAME ?PAGE? ...\n", argv[0]);
      new_exit (1);
    }
  c2 = open (argv[1], O_RDONLY);
  if (c2 < 0)
    {
      fprintf (stderr, "%s: can't open %s\n", argv[0], argv[1]);
      new_exit (1);
    }
  fstat (c2, &sbuf);
  mxPage = (sbuf.st_size / pagesize) + 1;
  if (argc == 2)
    {
      int i;
      for (i = 1; i <= mxPage; i++)
	printPage (i);
    }
  else
    {
      int i;
      for (i = 2; i < argc; i++)
	{
	  int indexStart;
	  int iEnd;
	  char *zLeft;
	  indexStart = new_strtol (argv[i], &zLeft, 0);
	  if (zLeft && (strcmp (zLeft, "..end") == 0))
	    {
	      iEnd = mxPage;
	    }
	  else if ((zLeft && (zLeft[0] == '.')) && (zLeft[1] == '.'))
	    {
	      iEnd = new_strtol (&zLeft[2], 0, 0);
	    }
	  else
	    {
	      iEnd = indexStart;
	    }
	  if (((indexStart < 1) || (iEnd < indexStart)) || (iEnd > mxPage))
	    {
	      fprintf (stderr,
		       "Page argument should be LOWER?..UPPER?.  Range 1 to %d\n",
		       mxPage);
	      new_exit (1);
	    }
	  while (indexStart <= iEnd)
	    {
	      printPage (indexStart);
	      indexStart++;
	    }
	}
    }
  close (c2);
}

long void *new_malloc (int size);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int new_read (int fd, void *buf, int count);
int
new_strtol (const char *str, char **endptr, int base)
{
  return strtol (str, endptr, base);
}

void *new_malloc (int size);
int new_fprintf (FILE * stream, const char *format, ...);
void new_exit (int status);
int
new_read (int fd, void *buf, int count)
{
  return read (fd, buf, count);
}

void *new_malloc (int size);
int new_fprintf (FILE * stream, const char *format, ...);
void
new_exit (int status)
{
  return exit (status);
}

void *
new_malloc (int size)
{
  return malloc (size);
}
