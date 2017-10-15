#include <config.h>
#include <stdio.h>
#include <stddef.h>
ssize_t
new_read (int fd, void *buf, size_t count)
{
  return read (fd, buf, count);
}

int new_fscanf (FILE * stream, const char *format, ...);
int new_getchar ();
int new_fgetc (FILE * stream);
char *new_fgets (char *str, int num, FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_getchar ();
int new_fgetc (FILE * stream);
char *
new_fgets (char *str, int num, FILE * stream)
{
  return fgets (str, num, stream);
}

int new_fscanf (FILE * stream, const char *format, ...);
int new_getchar ();
int
new_fgetc (FILE * stream)
{
  return fgetc (stream);
}

int new_fscanf (FILE * stream, const char *format, ...);
int
new_getchar ()
{
  return getchar ();
}
