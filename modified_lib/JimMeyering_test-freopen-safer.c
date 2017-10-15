/* Test of reopening a stream.
   Copyright (C) 2009-2011 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by Eric Blake <ebb9@byu.net>, 2009.  */

#include <config.h>

/* Specification.  */
#include "stdio--.h"

/* Helpers.  */
#include <unistd.h>

/* This test intentionally closes stderr.  So, we arrange to have fd 10
   (outside the range of interesting fd's during the test) set up to
   duplicate the original stderr.  */

#define BACKUP_STDERR_FILENO 10
#define ASSERT_STREAM myerr
#include "macros.h"

static FILE *myerr;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);




int
main (void)
{
  FILE *fp;

  /* We close fd 2 later, so save it in fd 10.  */
  if (dup2 (STDERR_FILENO, BACKUP_STDERR_FILENO) != BACKUP_STDERR_FILENO
      || (myerr = fdopen (BACKUP_STDERR_FILENO, "w")) == NULL)
    return 2;

  {
    FILE *tmp;
    ASSERT (tmp = new_fopen ("/dev/null", "r"));
    ASSERT (STDERR_FILENO < fileno (tmp));
    ASSERT (fp = new_fopen ("/dev/null", "w"));
    ASSERT (fileno (tmp) < fileno (fp));
    ASSERT (new_fclose (tmp) == 0);
  }

  /* Gap in fds.  */
  ASSERT (new_freopen ("/dev/null", "r+", fp) == fp);
  ASSERT (STDERR_FILENO < fileno (fp));

  ASSERT (new_freopen ("/dev/null", "r", stdin) == stdin);
  ASSERT (STDIN_FILENO == fileno (stdin));

  ASSERT (new_freopen ("/dev/null", "w", stdout) == stdout);
  ASSERT (STDOUT_FILENO == fileno (stdout));

  ASSERT (new_freopen ("/dev/null", "w", stderr) == stderr);
  ASSERT (STDERR_FILENO == fileno (stderr));

  /* fd 0 closed.  */
  ASSERT (close (STDIN_FILENO) == 0);

  ASSERT (new_freopen ("/dev/null", "w", stdout) == stdout);
  ASSERT (STDOUT_FILENO == fileno (stdout));

  ASSERT (new_freopen ("/dev/null", "w", stderr) == stderr);
  ASSERT (STDERR_FILENO == fileno (stderr));

  ASSERT (new_freopen ("/dev/null", "a", fp) == fp);
  ASSERT (STDERR_FILENO < fileno (fp));

  /* fd 1 closed.  */
  ASSERT (close (STDOUT_FILENO) == 0);

  ASSERT (new_freopen ("/dev/null", "w", stderr) == stderr);
  ASSERT (STDERR_FILENO == fileno (stderr));

  ASSERT (new_freopen ("/dev/null", "a+", fp) == fp);
  ASSERT (STDERR_FILENO < fileno (fp));

  /* fd 2 closed.  */
  ASSERT (close (STDERR_FILENO) == 0);

  ASSERT (new_freopen ("/dev/null", "w+", fp) == fp);
  ASSERT (STDERR_FILENO < fileno (fp));

  return 0;
}

FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}