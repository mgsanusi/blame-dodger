/*
 * Copyright (C) 2005, 2010-2011 Free Software Foundation, Inc.
 * Written by Simon Josefsson
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.  */
/* Written by Simon Josefsson. */
#include <config.h>
#include <stdio.h>
#include <string.h>
#include "md4.h"
#include <stddef.h>
size_t new_strlen (const char *str);
int new_memcmp (const void *ptr1, const void *ptr2, size_t num);
int
main (int argc, char *argv[])
{
  const char *in1 = "abc";
  const char *out1 =
    "\xa4\x48\x01\x7a\xaf\x21\xd8\x52\x5f\xc1\x0a\xe8\x7a\xa6\x72\x9d";
  const char *in2 = "abcdefghijklmnopqrstuvwxyz";
  const char *out2 =
    "\xd7\x9e\x1c\x30\x8a\xa5\xbb\xcd\xee\xa8\xed\x63\xdf\x41\x2d\xa9";
  char buf[MD4_DIGEST_SIZE];
  if (new_memcmp
      (md4_buffer (in1, new_strlen (in1), buf), out1, MD4_DIGEST_SIZE) != 0)
    {
      size_t i;
      printf ("expected:\n");
      for (i = 0; i < MD4_DIGEST_SIZE; i++)
	printf ("%02x ", out1[i] & 0xFF);
      printf ("\ncomputed:\n");
      for (i = 0; i < MD4_DIGEST_SIZE; i++)
	printf ("%02x ", buf[i] & 0xFF);
      printf ("\n");
      return 1;
    }
  if (new_memcmp
      (md4_buffer (in2, new_strlen (in2), buf), out2, MD4_DIGEST_SIZE) != 0)
    {
      size_t i;
      printf ("expected:\n");
      for (i = 0; i < MD4_DIGEST_SIZE; i++)
	printf ("%02x ", out2[i] & 0xFF);
      printf ("\ncomputed:\n");
      for (i = 0; i < MD4_DIGEST_SIZE; i++)
	printf ("%02x ", buf[i] & 0xFF);
      printf ("\n");
      return 1;
    }
  return 0;
}

size_t new_strlen (const char *str);
int
new_memcmp (const void *ptr1, const void *ptr2, size_t num)
{
  return memcmp (ptr1, ptr2, num);
}

size_t
new_strlen (const char *str)
{
  return strlen (str);
}
