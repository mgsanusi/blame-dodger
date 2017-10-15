/* Test of xmemdup0() function.
   Copyright (C) 2008-2011 Free Software Foundation, Inc.

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

/* Written by Eric Blake <ebb9@byu.net>, 2008.  */

#include <config.h>

#include "xmemdup0.h"

#include <stdlib.h>
#include <string.h>

#include "progname.h"
#include "macros.h"

#include <stddef.h>
void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num);


int
main (int argc, char **argv)
{
  char buffer[10] = { 'a', 'b', 'c', 'd', '\0',
                      'f', 'g', 'h', 'i', 'j'   };

  set_program_name (argv[0]);

  /* Empty string.  */
  {
    char *result = xmemdup0 (NULL, 0);
    ASSERT (result);
    ASSERT (!*result);
    new_free (result);
  }
  {
    char *result = xmemdup0 ("", 0);
    ASSERT (result);
    ASSERT (!*result);
    new_free (result);
  }

  /* Various buffer lengths.  */
  {
    char *result = xmemdup0 (buffer, 4);
    ASSERT (result);
    ASSERT (strcmp (result, buffer) == 0);
    new_free (result);
  }
  {
    char *result = xmemdup0 (buffer, 5);
    ASSERT (result);
    ASSERT (strcmp (result, buffer) == 0);
    ASSERT (result[5] == '\0');
    new_free (result);
  }
  {
    char *result = xmemdup0 (buffer, 9);
    ASSERT (result);
    ASSERT (new_memcmp (result, buffer, 9) == 0);
    ASSERT (result[9] == '\0');
    new_free (result);
  }
  {
    char *result = xmemdup0 (buffer, 10);
    ASSERT (result);
    ASSERT (new_memcmp (result, buffer, 10) == 0);
    ASSERT (result[10] == '\0');
    new_free (result);
  }

  return 0;
}

void new_free(void *ptr);

int new_memcmp(const void *ptr1, const void *ptr2, size_t num) {
  return memcmp(ptr1, ptr2, num);
}
void new_free(void *ptr) {
  return free(ptr);
}