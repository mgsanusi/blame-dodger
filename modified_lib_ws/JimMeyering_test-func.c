/* Test whether __func__ is available
   Copyright (C) 2008-2011 Free Software Foundation, Inc.
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
/* Written by Bruno Haible <bruno@clisp.org>, 2008.  */
#include <config.h>
#include <string.h>
#include "macros.h"
size_t new_strlen(const char *str);
int main()
{
	ASSERT(new_strlen(__func__) > 0);
	/* On SunPRO C 5.9, sizeof __func__ evaluates to 0.  The compiler warns:
	   "warning: null dimension: sizeof()".  */
#if !defined __SUNPRO_C
	ASSERT(new_strlen(__func__) + 1 == sizeof __func__);
#endif
	ASSERT(strcmp(__func__, "main") == 0
	       || strcmp(__func__, "<unknown function>") == 0);
	return 0;
}

size_t new_strlen(const char *str)
{
	return strlen(str);
}