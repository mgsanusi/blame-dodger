/* Test of fwriting() function.
   Copyright (C) 2007-2011 Free Software Foundation, Inc.

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

/* Written by Bruno Haible <bruno@clisp.org>, 2007.  */

#include <config.h>

/* None of the files accessed by this test are large, so disable the
   fseek link warning if we are not using the gnulib fseek module.  */
#define _GL_NO_LARGE_FILES
#include "fwriting.h"

#include <stdio.h>

#include "macros.h"

#define TESTFILE "t-fwriting.tmp"
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fgetc(FILE *stream);


int
main ()
{
  FILE *fp;

  /* Create a file with some contents.  Write-only file is always writing.  */
  fp = new_fopen (TESTFILE, "w");
  if (fp == NULL)
    goto skip;
  ASSERT (fwriting (fp));
  if (fwrite ("foobarsh", 1, 8, fp) < 8)
    goto skip;
  ASSERT (fwriting (fp));
  if (new_fclose (fp))
    goto skip;

  /* Open it in read-only mode.  Read-only file is never writing.  */
  fp = new_fopen (TESTFILE, "r");
  if (fp == NULL)
    goto skip;
  ASSERT (!fwriting (fp));
  if (new_fgetc (fp) != 'f')
    goto skip;
  ASSERT (!fwriting (fp));
  if (fseek (fp, 2, SEEK_CUR))
    goto skip;
  ASSERT (!fwriting (fp));
  if (new_fgetc (fp) != 'b')
    goto skip;
  ASSERT (!fwriting (fp));
  fflush (fp);
  ASSERT (!fwriting (fp));
  if (new_fgetc (fp) != 'a')
    goto skip;
  ASSERT (!fwriting (fp));
  if (fseek (fp, 0, SEEK_END))
    goto skip;
  ASSERT (!fwriting (fp));
  if (new_fclose (fp))
    goto skip;

  /* Open it in read-write mode.  POSIX requires a reposition (fseek,
     fsetpos, rewind) or fflush when transitioning from write to read,
     fwriting is only deterministic after input or output, but this
     test case should be portable even on open, after reposition, and
     after fflush.  */
  /* First a scenario with only fgetc, fseek, fputc.  */
  fp = new_fopen (TESTFILE, "r+");
  if (fp == NULL)
    goto skip;
  ASSERT (!fwriting (fp));
  if (new_fgetc (fp) != 'f')
    goto skip;
  ASSERT (!fwriting (fp));
  if (fseek (fp, 2, SEEK_CUR))
    goto skip;
  ASSERT (!fwriting (fp));
  if (new_fgetc (fp) != 'b')
    goto skip;
  ASSERT (!fwriting (fp));
  /* This fseek call is necessary when switching from reading to writing.
     See the description of new_fopen(), ISO C 99 7.19.5.3.(6).  */
  if (fseek (fp, 0, SEEK_CUR) != 0)
    goto skip;
  ASSERT (!fwriting (fp));
  if (fputc ('x', fp) != 'x')
    goto skip;
  ASSERT (fwriting (fp));
  if (fseek (fp, 0, SEEK_END))
    goto skip;
  /* freading (fp) is undefined here, because on some implementations (e.g.
     glibc) fseek causes a buffer to be read.
     fwriting (fp) is undefined as well.  */
  if (new_fclose (fp))
    goto skip;

  /* Open it in read-write mode.  POSIX requires a reposition (fseek,
     fsetpos, rewind) or fflush when transitioning from write to read,
     fwriting is only deterministic after input or output, but this
     test case should be portable even on open, after reposition, and
     after fflush.  */
  /* Here a scenario that includes fflush.  */
  fp = new_fopen (TESTFILE, "r+");
  if (fp == NULL)
    goto skip;
  ASSERT (!fwriting (fp));
  if (new_fgetc (fp) != 'f')
    goto skip;
  ASSERT (!fwriting (fp));
  if (fseek (fp, 2, SEEK_CUR))
    goto skip;
  ASSERT (!fwriting (fp));
  if (new_fgetc (fp) != 'b')
    goto skip;
  ASSERT (!fwriting (fp));
  fflush (fp);
  ASSERT (!fwriting (fp));
  if (new_fgetc (fp) != 'x')
    goto skip;
  ASSERT (!fwriting (fp));
  /* This fseek call is necessary when switching from reading to writing.
     See the description of new_fopen(), ISO C 99 7.19.5.3.(6).  */
  if (fseek (fp, 0, SEEK_CUR) != 0)
    goto skip;
  ASSERT (!fwriting (fp));
  if (fputc ('z', fp) != 'z')
    goto skip;
  ASSERT (fwriting (fp));
  if (fseek (fp, 0, SEEK_END))
    goto skip;
  /* freading (fp) is undefined here, because on some implementations (e.g.
     glibc) fseek causes a buffer to be read.
     fwriting (fp) is undefined as well.  */
  if (new_fclose (fp))
    goto skip;

  /* Open it in append mode.  */
  fp = new_fopen (TESTFILE, "a");
  if (fp == NULL)
    goto skip;
  ASSERT (fwriting (fp));
  if (fwrite ("bla", 1, 3, fp) < 3)
    goto skip;
  ASSERT (fwriting (fp));
  if (new_fclose (fp))
    goto skip;

  return 0;

 skip:
  fprintf (stderr, "Skipping test: file operations failed.\n");
  return 77;
}

FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fgetc(FILE *stream) {
  return fgetc(stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}