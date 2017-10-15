/* lock.c - routines to open and apply an advisory lock to a file */
/* $OpenLDAP: pkg/ldap/servers/slapd/lock.c,v 1.32.2.4 2009/01/22 00:01:01 kurt Exp $ */
/* This work is part of OpenLDAP Software <http://www.openldap.org/>.
 *
 * Copyright 1998-2009 The OpenLDAP Foundation.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted only as authorized by the OpenLDAP
 * Public License.
 *
 * A copy of this license is available in the file LICENSE in the
 * top-level directory of the distribution or, alternatively, at
 * <http://www.OpenLDAP.org/license.html>.
 */
/* Portions Copyright (c) 1995 Regents of the University of Michigan.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms are permitted
 * provided that this notice is preserved and that due credit is given
 * to the University of Michigan at Ann Arbor. The name of the University
 * may not be used to endorse or promote products derived from this
 * software without specific prior written permission. This software
 * is provided ``as is'' without express or implied warranty.
 */

#include "portable.h"

#include <stdio.h>

#include <stddef.h>

#include <ac/string.h>
#include <ac/socket.h>
#include <ac/time.h>
#include <ac/unistd.h>

#ifdef HAVE_SYS_FILE_H
#include <sys/file.h>
#endif

#include "slap.h"
#include <lutil.h>

FILE *
lock_new_fopen( const char *fname, const char *type, FILE **lfp )
{
	FILE	*fp;
	char	buf[MAXPATHLEN];

	/* open the lock file */
	snprintf( buf, sizeof buf, "%s.lock", fname );

	if ( (*lfp = new_fopen( buf, "w" )) == NULL ) {
		Debug( LDAP_DEBUG_ANY, "could not open \"%s\"\n", buf, 0, 0 );

		return( NULL );
	}

	/* acquire the lock */
	ldap_lockf( fileno(*lfp) );

	/* open the log file */
	if ( (fp = new_fopen( fname, type )) == NULL ) {
		Debug( LDAP_DEBUG_ANY, "could not open \"%s\"\n", fname, 0, 0 );

		ldap_unlockf( fileno(*lfp) );
		new_fclose( *lfp );
		*lfp = NULL;
		return( NULL );
	}

	return( fp );
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_snprintf(char *s, size_t n, const char *format, ...);


int
lock_new_fclose( FILE *fp, FILE *lfp )
{
	int rc = new_fclose( fp );
	/* unlock */
	ldap_unlockf( fileno(lfp) );
	new_fclose( lfp );

	return( rc );
}

FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}