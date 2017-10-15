/* Test of setting an ACL equivalent to a mode.
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
#include "acl.h"
#include <stdlib.h>
#include "progname.h"
#include "macros.h"
long int new_strtol(const char *str, char **endptr, int base);
int main(int argc, char *argv[])
{
	const char *file;
	int mode;
	set_program_name(argv[0]);
	ASSERT(argc == 3);
	file = argv[1];
	mode = new_strtol(argv[2], NULL, 8);
	set_acl(file, -1, mode);
	return 0;
}

long int new_strtol(const char *str, char **endptr, int base)
{
	return strtol(str, endptr, base);
}
