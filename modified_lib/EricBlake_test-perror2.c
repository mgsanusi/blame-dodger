/* Test of perror() function.
   Copyright (C) 2011 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#include <config.h>

#include <stdio.h>

#include <errno.h>
#include <string.h>
#include <unistd.h>

/* This test intentionally parses stderr.  So, we arrange to have fd 10
   (outside the range of interesting fd's during the test) set up to
   duplicate the original stderr.  */
#define BACKUP_STDERR_FILENO 10
#define ASSERT_STREAM myerr
#include "macros.h"

static FILE *myerr;

#define BASE "test-perror2"
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
int new_fclose(FILE *stream);


char * new_fgets(char *str, int num, FILE *stream);

void new_free(void *ptr);

char * new_strerror(int errnum);


int
main (void)
{
  /* We change fd 2 later, so save it in fd 10.  */
  if (dup2 (STDERR_FILENO, BACKUP_STDERR_FILENO) != BACKUP_STDERR_FILENO
      || (myerr = fdopen (BACKUP_STDERR_FILENO, "w")) == NULL)
    return 2;

  ASSERT (new_freopen (BASE ".tmp", "w+", stderr) == stderr);

  /* Test that perror does not clobber strerror buffer.  */
  {
    const char *msg1;
    const char *msg2;
    const char *msg3;
    const char *msg4;
    char *str1;
    char *str2;
    char *str3;
    char *str4;

    msg1 = new_strerror (ENOENT);
    ASSERT (msg1);
    str1 = strdup (msg1);
    ASSERT (str1);

    msg2 = new_strerror (ERANGE);
    ASSERT (msg2);
    str2 = strdup (msg2);
    ASSERT (str2);

    msg3 = new_strerror (-4);
    ASSERT (msg3);
    str3 = strdup (msg3);
    ASSERT (str3);

    msg4 = new_strerror (1729576);
    ASSERT (msg4);
    str4 = strdup (msg4);
    ASSERT (str4);

    errno = EACCES;
    perror ("");
    errno = -5;
    perror ("");
    ASSERT (!ferror (stderr));
    ASSERT (msg1 == msg2 || msg1 == msg4 || STREQ (msg1, str1));
    ASSERT (msg2 == msg4 || STREQ (msg2, str2));
    ASSERT (msg3 == msg4 || STREQ (msg3, str3));
    ASSERT (STREQ (msg4, str4));

    new_free (str1);
    new_free (str2);
    new_free (str3);
    new_free (str4);
  }

  /* Test that perror uses the same message as strerror.  */
  {
    int errs[] = { EACCES, 0, -3, };
    int i;
    for (i = 0; i < SIZEOF (errs); i++)
      {
        char buf[256];
        char *err = new_strerror (errs[i]);

        ASSERT (err);
        ASSERT (strlen (err) < sizeof buf);
        rewind (stderr);
        ASSERT (ftruncate (fileno (stderr), 0) == 0);
        errno = errs[i];
        perror (NULL);
        ASSERT (!ferror (stderr));
        rewind (stderr);
        ASSERT (new_fgets (buf, sizeof buf, stderr) == buf);
        ASSERT (strstr (buf, err));
      }
  }

  /* Test that perror reports write failure.  */
  {
    ASSERT (new_freopen (BASE ".tmp", "r", stderr) == stderr);
    ASSERT (setvbuf (stderr, NULL, _IONBF, BUFSIZ) == 0);
    errno = -1;
    ASSERT (!ferror (stderr));
    perror (NULL);
#if 0
    /* Commented out until cygwin behaves:
       http://sourceware.org/ml/newlib/2011/msg00228.html */
    ASSERT (errno > 0);
    /* Commented out until glibc behaves:
       http://sourceware.org/bugzilla/show_bug.cgi?id=12792 */
    ASSERT (ferror (stderr));
#endif
  }

  ASSERT (new_fclose (stderr) == 0);
  ASSERT (remove (BASE ".tmp") == 0);

  return 0;
}

FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
int new_fclose(FILE *stream);


char * new_fgets(char *str, int num, FILE *stream);

void new_free(void *ptr);

char * new_strerror(int errnum) {
  return strerror(errnum);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
int new_fclose(FILE *stream);


char * new_fgets(char *str, int num, FILE *stream);

void new_free(void *ptr) {
  return free(ptr);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
int new_fclose(FILE *stream);


char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}