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

#include <stddef.h>

#if HAVE_ICONV
# include <iconv.h>
#endif

#include <errno.h>
#include <string.h>

#include "macros.h"
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);


int
main ()
{
#if HAVE_ICONV
  /* Assume that iconv() supports at least the encoding UTF-8.  */

  /* The text is "Japanese (日本語) [\U0001D50D\U0001D51E\U0001D52D]".  */

  /* Test conversion from UTF-8 to UTF-16BE with no errors.  */
  {
    static const char input[] =
      "Japanese (\346\227\245\346\234\254\350\252\236) [\360\235\224\215\360\235\224\236\360\235\224\255]";
    static const char expected[] =
      "\000J\000a\000p\000a\000n\000e\000s\000e\000 \000(\145\345\147\054\212\236\000)\000 \000[\330\065\335\015\330\065\335\036\330\065\335\055\000]";
    iconv_t cd;
    char buf[100];
    const char *inptr;
    size_t inbytesleft;
    char *outptr;
    size_t outbytesleft;
    size_t res;

    cd = iconv_open ("UTF-16BE", "UTF-8");
    ASSERT (cd != (iconv_t)(-1));

    inptr = input;
    inbytesleft = sizeof (input) - 1;
    outptr = buf;
    outbytesleft = sizeof (buf);
    res = iconv (cd,
                 (ICONV_CONST char **) &inptr, &inbytesleft,
                 &outptr, &outbytesleft);
    ASSERT (res == 0 && inbytesleft == 0);
    ASSERT (outptr == buf + (sizeof (expected) - 1));
    ASSERT (new_memcmp (buf, expected, sizeof (expected) - 1) == 0);

    ASSERT (iconv_close (cd) == 0);
  }

  /* Test conversion from UTF-8 to UTF-16LE with no errors.  */
  {
    static const char input[] =
      "Japanese (\346\227\245\346\234\254\350\252\236) [\360\235\224\215\360\235\224\236\360\235\224\255]";
    static const char expected[] =
      "J\000a\000p\000a\000n\000e\000s\000e\000 \000(\000\345\145\054\147\236\212)\000 \000[\000\065\330\015\335\065\330\036\335\065\330\055\335]\000";
    iconv_t cd;
    char buf[100];
    const char *inptr;
    size_t inbytesleft;
    char *outptr;
    size_t outbytesleft;
    size_t res;

    cd = iconv_open ("UTF-16LE", "UTF-8");
    ASSERT (cd != (iconv_t)(-1));

    inptr = input;
    inbytesleft = sizeof (input) - 1;
    outptr = buf;
    outbytesleft = sizeof (buf);
    res = iconv (cd,
                 (ICONV_CONST char **) &inptr, &inbytesleft,
                 &outptr, &outbytesleft);
    ASSERT (res == 0 && inbytesleft == 0);
    ASSERT (outptr == buf + (sizeof (expected) - 1));
    ASSERT (new_memcmp (buf, expected, sizeof (expected) - 1) == 0);

    ASSERT (iconv_close (cd) == 0);
  }

  /* Test conversion from UTF-8 to UTF-32BE with no errors.  */
  {
    static const char input[] =
      "Japanese (\346\227\245\346\234\254\350\252\236) [\360\235\224\215\360\235\224\236\360\235\224\255]";
    static const char expected[] =
      "\000\000\000J\000\000\000a\000\000\000p\000\000\000a\000\000\000n\000\000\000e\000\000\000s\000\000\000e\000\000\000 \000\000\000(\000\000\145\345\000\000\147\054\000\000\212\236\000\000\000)\000\000\000 \000\000\000[\000\001\325\015\000\001\325\036\000\001\325\055\000\000\000]";
    iconv_t cd;
    char buf[100];
    const char *inptr;
    size_t inbytesleft;
    char *outptr;
    size_t outbytesleft;
    size_t res;

    cd = iconv_open ("UTF-32BE", "UTF-8");
    ASSERT (cd != (iconv_t)(-1));

    inptr = input;
    inbytesleft = sizeof (input) - 1;
    outptr = buf;
    outbytesleft = sizeof (buf);
    res = iconv (cd,
                 (ICONV_CONST char **) &inptr, &inbytesleft,
                 &outptr, &outbytesleft);
    ASSERT (res == 0 && inbytesleft == 0);
    ASSERT (outptr == buf + (sizeof (expected) - 1));
    ASSERT (new_memcmp (buf, expected, sizeof (expected) - 1) == 0);

    ASSERT (iconv_close (cd) == 0);
  }

  /* Test conversion from UTF-8 to UTF-32LE with no errors.  */
  {
    static const char input[] =
      "Japanese (\346\227\245\346\234\254\350\252\236) [\360\235\224\215\360\235\224\236\360\235\224\255]";
    static const char expected[] =
      "J\000\000\000a\000\000\000p\000\000\000a\000\000\000n\000\000\000e\000\000\000s\000\000\000e\000\000\000 \000\000\000(\000\000\000\345\145\000\000\054\147\000\000\236\212\000\000)\000\000\000 \000\000\000[\000\000\000\015\325\001\000\036\325\001\000\055\325\001\000]\000\000\000";
    iconv_t cd;
    char buf[100];
    const char *inptr;
    size_t inbytesleft;
    char *outptr;
    size_t outbytesleft;
    size_t res;

    cd = iconv_open ("UTF-32LE", "UTF-8");
    ASSERT (cd != (iconv_t)(-1));

    inptr = input;
    inbytesleft = sizeof (input) - 1;
    outptr = buf;
    outbytesleft = sizeof (buf);
    res = iconv (cd,
                 (ICONV_CONST char **) &inptr, &inbytesleft,
                 &outptr, &outbytesleft);
    ASSERT (res == 0 && inbytesleft == 0);
    ASSERT (outptr == buf + (sizeof (expected) - 1));
    ASSERT (new_memcmp (buf, expected, sizeof (expected) - 1) == 0);

    ASSERT (iconv_close (cd) == 0);
  }

  /* Test conversion from UTF-16BE to UTF-8 with no errors.  */
  {
    static const char input[] =
      "\000J\000a\000p\000a\000n\000e\000s\000e\000 \000(\145\345\147\054\212\236\000)\000 \000[\330\065\335\015\330\065\335\036\330\065\335\055\000]";
    static const char expected[] =
      "Japanese (\346\227\245\346\234\254\350\252\236) [\360\235\224\215\360\235\224\236\360\235\224\255]";
    iconv_t cd;
    char buf[100];
    const char *inptr;
    size_t inbytesleft;
    char *outptr;
    size_t outbytesleft;
    size_t res;

    cd = iconv_open ("UTF-8", "UTF-16BE");
    ASSERT (cd != (iconv_t)(-1));

    inptr = input;
    inbytesleft = sizeof (input) - 1;
    outptr = buf;
    outbytesleft = sizeof (buf);
    res = iconv (cd,
                 (ICONV_CONST char **) &inptr, &inbytesleft,
                 &outptr, &outbytesleft);
    ASSERT (res == 0 && inbytesleft == 0);
    ASSERT (outptr == buf + (sizeof (expected) - 1));
    ASSERT (new_memcmp (buf, expected, sizeof (expected) - 1) == 0);

    ASSERT (iconv_close (cd) == 0);
  }

  /* Test conversion from UTF-16LE to UTF-8 with no errors.  */
  {
    static const char input[] =
      "J\000a\000p\000a\000n\000e\000s\000e\000 \000(\000\345\145\054\147\236\212)\000 \000[\000\065\330\015\335\065\330\036\335\065\330\055\335]\000";
    static const char expected[] =
      "Japanese (\346\227\245\346\234\254\350\252\236) [\360\235\224\215\360\235\224\236\360\235\224\255]";
    iconv_t cd;
    char buf[100];
    const char *inptr;
    size_t inbytesleft;
    char *outptr;
    size_t outbytesleft;
    size_t res;

    cd = iconv_open ("UTF-8", "UTF-16LE");
    ASSERT (cd != (iconv_t)(-1));

    inptr = input;
    inbytesleft = sizeof (input) - 1;
    outptr = buf;
    outbytesleft = sizeof (buf);
    res = iconv (cd,
                 (ICONV_CONST char **) &inptr, &inbytesleft,
                 &outptr, &outbytesleft);
    ASSERT (res == 0 && inbytesleft == 0);
    ASSERT (outptr == buf + (sizeof (expected) - 1));
    ASSERT (new_memcmp (buf, expected, sizeof (expected) - 1) == 0);

    ASSERT (iconv_close (cd) == 0);
  }

  /* Test conversion from UTF-32BE to UTF-8 with no errors.  */
  {
    static const char input[] =
      "\000\000\000J\000\000\000a\000\000\000p\000\000\000a\000\000\000n\000\000\000e\000\000\000s\000\000\000e\000\000\000 \000\000\000(\000\000\145\345\000\000\147\054\000\000\212\236\000\000\000)\000\000\000 \000\000\000[\000\001\325\015\000\001\325\036\000\001\325\055\000\000\000]";
    static const char expected[] =
      "Japanese (\346\227\245\346\234\254\350\252\236) [\360\235\224\215\360\235\224\236\360\235\224\255]";
    iconv_t cd;
    char buf[100];
    const char *inptr;
    size_t inbytesleft;
    char *outptr;
    size_t outbytesleft;
    size_t res;

    cd = iconv_open ("UTF-8", "UTF-32BE");
    ASSERT (cd != (iconv_t)(-1));

    inptr = input;
    inbytesleft = sizeof (input) - 1;
    outptr = buf;
    outbytesleft = sizeof (buf);
    res = iconv (cd,
                 (ICONV_CONST char **) &inptr, &inbytesleft,
                 &outptr, &outbytesleft);
    ASSERT (res == 0 && inbytesleft == 0);
    ASSERT (outptr == buf + (sizeof (expected) - 1));
    ASSERT (new_memcmp (buf, expected, sizeof (expected) - 1) == 0);

    ASSERT (iconv_close (cd) == 0);
  }

  /* Test conversion from UTF-32LE to UTF-8 with no errors.  */
  {
    static const char input[] =
      "J\000\000\000a\000\000\000p\000\000\000a\000\000\000n\000\000\000e\000\000\000s\000\000\000e\000\000\000 \000\000\000(\000\000\000\345\145\000\000\054\147\000\000\236\212\000\000)\000\000\000 \000\000\000[\000\000\000\015\325\001\000\036\325\001\000\055\325\001\000]\000\000\000";
    static const char expected[] =
      "Japanese (\346\227\245\346\234\254\350\252\236) [\360\235\224\215\360\235\224\236\360\235\224\255]";
    iconv_t cd;
    char buf[100];
    const char *inptr;
    size_t inbytesleft;
    char *outptr;
    size_t outbytesleft;
    size_t res;

    cd = iconv_open ("UTF-8", "UTF-32LE");
    ASSERT (cd != (iconv_t)(-1));

    inptr = input;
    inbytesleft = sizeof (input) - 1;
    outptr = buf;
    outbytesleft = sizeof (buf);
    res = iconv (cd,
                 (ICONV_CONST char **) &inptr, &inbytesleft,
                 &outptr, &outbytesleft);
    ASSERT (res == 0 && inbytesleft == 0);
    ASSERT (outptr == buf + (sizeof (expected) - 1));
    ASSERT (new_memcmp (buf, expected, sizeof (expected) - 1) == 0);

    ASSERT (iconv_close (cd) == 0);
  }
#endif

  return 0;
}

int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}