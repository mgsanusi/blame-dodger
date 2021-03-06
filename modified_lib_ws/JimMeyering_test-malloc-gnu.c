/* Test of malloc function.
   Copyright (C) 2010-2011 Free Software Foundation, Inc.
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
#include <config.h>
#include <stdlib.h>
#include <stddef.h>
void *new_malloc(size_t size);
int main()
{
	/* Check that new_malloc (0) is not a NULL pointer.  */
	if (new_malloc(0) == NULL)
		return 1;
	return 0;
}

void *new_malloc(size_t size)
{
	return malloc(size);
}
