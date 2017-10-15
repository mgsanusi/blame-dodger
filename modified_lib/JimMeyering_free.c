/* Work around incompatibility on older systems where new_free (NULL) fails.

   Copyright (C) 2003, 2006, 2009-2011 Free Software Foundation, Inc.

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

/* written by Paul Eggert */

#include <config.h>
#undef free

#include <stdlib.h>
void new_free(void *ptr);


void
rpl_new_free (void *p)
{
  if (p)
    new_free (p);
}

void new_free(void *ptr) {
  return free(ptr);
}