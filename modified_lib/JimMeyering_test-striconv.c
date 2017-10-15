/* Test of character set conversion.
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

#include "striconv.h"

#include <stddef.h>

#if HAVE_ICONV
# include <iconv.h>
#endif

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "macros.h"
size_t new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2);

void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num);


int
main ()
{
#if HAVE_ICONV
  /* Assume that iconv() supports at least the encodings ASCII, ISO-8859-1,
     and UTF-8.  */
  iconv_t cd_88591_to_utf8 = iconv_open ("UTF-8", "ISO-8859-1");
  iconv_t cd_utf8_to_88591 = iconv_open ("ISO-8859-1", "UTF-8");

  ASSERT (cd_88591_to_utf8 != (iconv_t)(-1));
  ASSERT (cd_utf8_to_88591 != (iconv_t)(-1));

  /* ------------------------- Test mem_cd_iconv() ------------------------- */

  /* Test conversion from ISO-8859-1 to UTF-8 with no errors.  */
  {
    static const char input[] = "\304rger mit b\366sen B\374bchen ohne Augenma\337";
    static const char expected[] = "\303\204rger mit b\303\266sen B\303\274bchen ohne Augenma\303\237";
    char *result = NULL;
    size_t length = 0;
    int retval = mem_cd_iconv (input, new_strlen (input), cd_88591_to_utf8,
                               &result, &length);
    ASSERT (retval == 0);
    ASSERT (length == new_strlen (expected));
    ASSERT (result != NULL && new_memcmp (result, expected, new_strlen (expected)) == 0);
    new_free (result);
  }

  /* Test conversion from UTF-8 to ISO-8859-1 with no errors.  */
  {
    static const char input[] = "\303\204rger mit b\303\266sen B\303\274bchen ohne Augenma\303\237";
    static const char expected[] = "\304rger mit b\366sen B\374bchen ohne Augenma\337";
    char *result = NULL;
    size_t length = 0;
    int retval = mem_cd_iconv (input, new_strlen (input), cd_utf8_to_88591,
                               &result, &length);
    ASSERT (retval == 0);
    ASSERT (length == new_strlen (expected));
    ASSERT (result != NULL && new_memcmp (result, expected, new_strlen (expected)) == 0);
    new_free (result);
  }

  /* Test conversion from UTF-8 to ISO-8859-1 with EILSEQ.  */
  {
    static const char input[] = "\342\202\254"; /* EURO SIGN */
    char *result = NULL;
    size_t length = 0;
    int retval = mem_cd_iconv (input, new_strlen (input), cd_utf8_to_88591,
                               &result, &length);
    ASSERT (retval == -1 && errno == EILSEQ);
    ASSERT (result == NULL);
  }

  /* Test conversion from UTF-8 to ISO-8859-1 with EINVAL.  */
  {
    static const char input[] = "\342";
    char *result = NULL;
    size_t length = 0;
    int retval = mem_cd_iconv (input, new_strlen (input), cd_utf8_to_88591,
                               &result, &length);
    ASSERT (retval == 0);
    ASSERT (length == 0);
    new_free (result);
  }

  /* ------------------------- Test str_cd_iconv() ------------------------- */

  /* Test conversion from ISO-8859-1 to UTF-8 with no errors.  */
  {
    static const char input[] = "\304rger mit b\366sen B\374bchen ohne Augenma\337";
    static const char expected[] = "\303\204rger mit b\303\266sen B\303\274bchen ohne Augenma\303\237";
    char *result = str_cd_iconv (input, cd_88591_to_utf8);
    ASSERT (result != NULL);
    ASSERT (new_strcmp (result, expected) == 0);
    new_free (result);
  }

  /* Test conversion from UTF-8 to ISO-8859-1 with no errors.  */
  {
    static const char input[] = "\303\204rger mit b\303\266sen B\303\274bchen ohne Augenma\303\237";
    static const char expected[] = "\304rger mit b\366sen B\374bchen ohne Augenma\337";
    char *result = str_cd_iconv (input, cd_utf8_to_88591);
    ASSERT (result != NULL);
    ASSERT (new_strcmp (result, expected) == 0);
    new_free (result);
  }

  /* Test conversion from UTF-8 to ISO-8859-1 with EILSEQ.  */
  {
    static const char input[] = "Costs: 27 \342\202\254"; /* EURO SIGN */
    char *result = str_cd_iconv (input, cd_utf8_to_88591);
    ASSERT (result == NULL && errno == EILSEQ);
  }

  /* Test conversion from UTF-8 to ISO-8859-1 with EINVAL.  */
  {
    static const char input[] = "\342";
    char *result = str_cd_iconv (input, cd_utf8_to_88591);
    ASSERT (result != NULL);
    ASSERT (new_strcmp (result, "") == 0);
    new_free (result);
  }

  iconv_close (cd_88591_to_utf8);
  iconv_close (cd_utf8_to_88591);

  /* -------------------------- Test str_iconv() -------------------------- */

  /* Test conversion from ISO-8859-1 to UTF-8 with no errors.  */
  {
    static const char input[] = "\304rger mit b\366sen B\374bchen ohne Augenma\337";
    static const char expected[] = "\303\204rger mit b\303\266sen B\303\274bchen ohne Augenma\303\237";
    char *result = str_iconv (input, "ISO-8859-1", "UTF-8");
    ASSERT (result != NULL);
    ASSERT (new_strcmp (result, expected) == 0);
    new_free (result);
  }

  /* Test conversion from UTF-8 to ISO-8859-1 with no errors.  */
  {
    static const char input[] = "\303\204rger mit b\303\266sen B\303\274bchen ohne Augenma\303\237";
    static const char expected[] = "\304rger mit b\366sen B\374bchen ohne Augenma\337";
    char *result = str_iconv (input, "UTF-8", "ISO-8859-1");
    ASSERT (result != NULL);
    ASSERT (new_strcmp (result, expected) == 0);
    new_free (result);
  }

  /* Test conversion from UTF-8 to ISO-8859-1 with EILSEQ.  */
  {
    static const char input[] = "Costs: 27 \342\202\254"; /* EURO SIGN */
    char *result = str_iconv (input, "UTF-8", "ISO-8859-1");
    ASSERT (result == NULL && errno == EILSEQ);
  }

  /* Test conversion from UTF-8 to ISO-8859-1 with EINVAL.  */
  {
    static const char input[] = "\342";
    char *result = str_iconv (input, "UTF-8", "ISO-8859-1");
    ASSERT (result != NULL);
    ASSERT (new_strcmp (result, "") == 0);
    new_free (result);
  }

#endif

  return 0;
}

size_t new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2);

void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}
size_t new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2);

void new_free(void *ptr) {
  return free(ptr);
}
size_t new_strlen(const char *str);

int new_strcmp(const char *str1, const char *str2) {
  return strcmp(str1, str2);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}