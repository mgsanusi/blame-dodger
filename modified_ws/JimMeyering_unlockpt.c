/* Unlock the slave side of a pseudo-terminal from its master side.
   Copyright (C) 1998, 2010-2011 Free Software Foundation, Inc.
   Contributed by Zack Weinberg <zack@rabi.phys.columbia.edu>, 1998.
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
#include <unistd.h>
int unlockpt(int fd)
{
    /* Platforms which have the TIOCSPTLCK ioctl (Linux) already have the
       unlockpt function.  */
#if HAVE_REVOKE
    /* MacOS X 10.3, OpenBSD 3.8 do not have the unlockpt function, but they
       have revoke().  */
    char *name = ptsname(fd);
    if (name == NULL)
	return -1;
    return revoke(name);
#else
    /* Assume that the slave side of a pseudo-terminal is already unlocked
       by default.  */
    return 0;
#endif
}
