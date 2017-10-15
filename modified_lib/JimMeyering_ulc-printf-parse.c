/* Formatted output to strings.
   Copyright (C) 1999-2000, 2002, 2006-2007, 2009-2011 Free Software
   Foundation, Inc.

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

/* Specification.  */
#include "unistdio/u-printf-parse.h"

#define PRINTF_PARSE ulc_printf_parse
#define CHAR_T char
#define CHAR_T_ONLY_ASCII 1
#define DIRECTIVE char_directive
#define DIRECTIVES char_directives
#include "printf-parse.c"
