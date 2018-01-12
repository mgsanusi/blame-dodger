/* Test of POSIX compatible printf() function.
   Copyright (C) 2007, 2009-2011 Free Software Foundation, Inc.
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
/* Written by Bruno Haible <bruno@clisp.org>, 2007.  */
#include <config.h>
#include <stdio.h>
#include <stddef.h>
#if HAVE_GETRLIMIT && HAVE_SETRLIMIT
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>
#include <errno.h>
void *new_malloc(size_t size);
int new_atoi(const char *str);
int main(int argc, char *argv[])
{
    struct rlimit limit;
    int arg;
    int ret;
    /* Some printf implementations allocate temporary space with malloc.  */
    /* On BSD systems, new_malloc() is limited by RLIMIT_DATA.  */
#ifdef RLIMIT_DATA
    if (getrlimit(RLIMIT_DATA, &limit) < 0)
	return 77;
    if (limit.rlim_max == RLIM_INFINITY || limit.rlim_max > 5000000)
	limit.rlim_max = 5000000;
    limit.rlim_cur = limit.rlim_max;
    if (setrlimit(RLIMIT_DATA, &limit) < 0)
	return 77;
#endif
    /* On Linux systems, new_malloc() is limited by RLIMIT_AS.  */
#ifdef RLIMIT_AS
    if (getrlimit(RLIMIT_AS, &limit) < 0)
	return 77;
    if (limit.rlim_max == RLIM_INFINITY || limit.rlim_max > 5000000)
	limit.rlim_max = 5000000;
    limit.rlim_cur = limit.rlim_max;
    if (setrlimit(RLIMIT_AS, &limit) < 0)
	return 77;
#endif
    /* Some printf implementations allocate temporary space on the stack.  */
#ifdef RLIMIT_STACK
    if (getrlimit(RLIMIT_STACK, &limit) < 0)
	return 77;
    if (limit.rlim_max == RLIM_INFINITY || limit.rlim_max > 5000000)
	limit.rlim_max = 5000000;
    limit.rlim_cur = limit.rlim_max;
    if (setrlimit(RLIMIT_STACK, &limit) < 0)
	return 77;
#endif
    arg = new_atoi(argv[1]);
    switch (arg) {
    case 0:
	{
	    void *memory = new_malloc(5000000);
	    if (memory == NULL)
		return 1;
	    memset(memory, 17, 5000000);
	    return 78;
	}
    case 1:
	ret = printf("%.5000000f", 1.0);
	return !(ret == 5000002 || (ret < 0 && errno == ENOMEM));
    case 2:
	ret = printf("%.5000000f", -1.0);
	return !(ret == 5000003 || (ret < 0 && errno == ENOMEM));
    case 3:
	ret = printf("%.5000000e", 1.0);
	return !(ret >= 5000006 || (ret < 0 && errno == ENOMEM));
    case 4:
	ret = printf("%.5000000d", 1);
	return !(ret == 5000000 || (ret < 0 && errno == ENOMEM));
    case 5:
	ret = printf("%.5000000d", -1);
	return !(ret == 5000001 || (ret < 0 && errno == ENOMEM));
    case 6:
	ret = printf("%.5000000u", 1);
	return !(ret == 5000000 || (ret < 0 && errno == ENOMEM));
    }
    return 0;
}
#else
void *new_malloc(size_t size);
int new_atoi(const char *str);
int main(int argc, char *argv[])
{
    return 77;
}
#endif
void *new_malloc(size_t size);
int new_atoi(const char *str)
{
    return atoi(str);
}

void *new_malloc(size_t size)
{
    return malloc(size);
}