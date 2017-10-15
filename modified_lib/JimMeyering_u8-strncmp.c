/* Compare UTF-8 strings.
   Copyright (C) 2002, 2006, 2009-2011 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2002.

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

/* Specification.  */
#include "unistr.h"

#include <string.h>
int new_strncmp(const char *str1, const char *str2, size_t num);


int
u8_new_strncmp (const uint8_t *s1, const uint8_t *s2, size_t n)
{
  /* Use the fact that the UTF-8 encoding preserves lexicographic order.  */
  return new_strncmp ((const char *) s1, (const char *) s2, n);
}

int new_strncmp(const char *str1, const char *str2, size_t num) {
  return strncmp(str1, str2, num);
}