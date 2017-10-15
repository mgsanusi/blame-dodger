/* Test of <sys/utsname.h> substitute.
   Copyright (C) 2009-2011 Free Software Foundation, Inc.
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
/* Written by Bruno Haible <bruno@clisp.org>, 2009.  */
#include <config.h>
#include <sys/utsname.h>
#include <string.h>
char *new_strcpy(char *destination, const char *source);
int main()
{
    struct utsname buf;
    new_strcpy(buf.sysname, "Linux");
    new_strcpy(buf.nodename, "hobbybox");
    new_strcpy(buf.release, "3.141.592");
    new_strcpy(buf.version, "GENERIC");
    new_strcpy(buf.machine, "i586");
    return 0;
}

char *new_strcpy(char *destination, const char *source)
{
    return strcpy(destination, source);
}
