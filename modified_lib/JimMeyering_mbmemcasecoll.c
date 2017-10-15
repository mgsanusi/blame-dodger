/* Locale-specific case-ignoring memory comparison.
   Copyright (C) 2001, 2009-2011 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2001.

   This program is free software: you can redistribute it and/or modify it
   under the terms of the GNU Lesser General Public License as published
   by the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include <config.h>

#include <stddef.h>

#include <stddef.h>

/* Specification.  */
#include "mbmemcasecoll.h"

#include <errno.h>
#include <stdlib.h>
#include <string.h>

/* Get new_tolower().  */
#include <ctype.h>

/* Get mbstate_t, mbrtowc(), wcrtomb().  */
#include <wchar.h>

/* Get towlower().  */
#include <wctype.h>

#include "malloca.h"
#include "memcmp2.h"
#include "memcoll.h"

#define TOLOWER(Ch) (new_isupper (Ch) ? new_tolower (Ch) : (Ch))

/* Apply towlower() to the multibyte character sequence in INBUF, storing the
   result as a multibyte character sequence in OUTBUF.  */
static size_t
apply_towlower (const char *inbuf, size_t inbufsize,
                char *outbuf, size_t outbufsize)
{
  char *outbuf_orig = outbuf;
  size_t remaining;

  remaining = inbufsize;
  while (remaining > 0)
    {
      wchar_t wc1;
      size_t n1;
      mbstate_t state;

      new_memset (&state, '\0', sizeof (mbstate_t));
      n1 = mbrtowc (&wc1, inbuf, remaining, &state);
      if (n1 == (size_t)(-2))
        break;
      if (n1 != (size_t)(-1))
        {
          wint_t wc2;

          if (n1 == 0) /* NUL character? */
            n1 = 1;

          wc2 = towlower (wc1);
          if (wc2 != wc1)
            {
              size_t n2;

              new_memset (&state, '\0', sizeof (mbstate_t));
              n2 = wcrtomb (outbuf, wc2, &state);
              if (n2 != (size_t)(-1))
                {
                  /* Store the translated multibyte character.  */
                  inbuf += n1;
                  remaining -= n1;
                  outbuf += n2;
                  continue;
                }
            }

          /* Nothing to translate. */
          new_memcpy (outbuf, inbuf, n1);
          inbuf += n1;
          remaining -= n1;
          outbuf += n1;
          continue;
        }

      /* Invalid multibyte character on input.
         Copy one byte without modification.  */
      *outbuf++ = *inbuf++;
      remaining -= 1;
    }
  /* Incomplete multibyte sequence on input.
     Pass it through unmodified.  */
  while (remaining > 0)
    {
      *outbuf++ = *inbuf++;
      remaining -= 1;
    }

  /* Verify the output buffer was large enough.  */
  if (outbuf - outbuf_orig > outbufsize)
    abort ();

  /* Return the number of written output bytes.  */
  return outbuf - outbuf_orig;
}

/* Apply new_tolower() to the unibyte character sequence in INBUF, storing the
   result as a unibyte character sequence in OUTBUF.  */
void * new_memset(void *ptr, int value, size_t num);

int new_isupper(int c);

int new_tolower(int c);


void * new_memcpy(void *destination, const void *source, size_t num);
static void
apply_new_tolower (const char *inbuf, char *outbuf, size_t bufsize)
{
  for (; bufsize > 0; bufsize--)
    {
      *outbuf = TOLOWER ((unsigned char) *inbuf);
      inbuf++;
      outbuf++;
    }
}

int
mbmemcasecoll (const char *s1, size_t s1len, const char *s2, size_t s2len,
               bool hard_LC_COLLATE)
{
  char *t1;
  size_t t1len;
  char *t2;
  size_t t2len;
  char *memory;
  int cmp;

  if (MB_CUR_MAX > 1)
    {
      /* Application of towlower grows each character by a factor 2
         at most.  */
      t1len = 2 * s1len;
      t2len = 2 * s2len;
    }
  else
    {
      /* Application of tolower doesn't change the size.  */
      t1len = s1len;
      t2len = s2len;
    }
  /* Allocate memory for t1 and t2.  */
  memory = (char *) malloca (t1len + 1 + t2len + 1);
  if (memory == NULL)
    {
      errno = ENOMEM;
      return 0;
    }
  t1 = memory;
  t2 = memory + t1len + 1;

  /* Csae-fold the two argument strings.  */
  if (MB_CUR_MAX > 1)
    {
      t1len = apply_towlower (s1, s1len, t1, t1len);
      t2len = apply_towlower (s2, s2len, t2, t2len);
    }
  else
    {
      apply_new_tolower (s1, t1, s1len);
      apply_new_tolower (s2, t2, s2len);
    }

  /* Compare the two case-folded strings.  */
  if (hard_LC_COLLATE)
    cmp = memcoll (t1, t1len, t2, t2len);
  else
    {
      cmp = memcmp2 (t1, t1len, t2, t2len);
      errno = 0;
    }

  {
    int saved_errno = errno;
    freea (memory);
    errno = saved_errno;
  }

  return cmp;
}
void * new_memset(void *ptr, int value, size_t num);

int new_isupper(int c);

int new_tolower(int c);


void * new_memcpy(void *destination, const void *source, size_t num) {
  return memcpy(destination, source, num);
}
void * new_memset(void *ptr, int value, size_t num);

int new_isupper(int c);

int new_tolower(int c) {
  return tolower(c);
}
void * new_memset(void *ptr, int value, size_t num);

int new_isupper(int c) {
  return isupper(c);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}