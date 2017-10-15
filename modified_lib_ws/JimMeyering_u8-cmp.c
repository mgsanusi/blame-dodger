/* Compare pieces of UTF-8 strings.
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
int new_memcmp(const void *ptr1, const void *ptr2, size_t num);
int u8_cmp(const uint8_t * s1, const uint8_t * s2, size_t n)
{
	/* Use the fact that the UTF-8 encoding preserves lexicographic order.  */
	return new_memcmp((const char *)s1, (const char *)s2, n);
}

int new_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	return memcmp(ptr1, ptr2, num);
}
