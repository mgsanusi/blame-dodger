/* Word breaks in UTF-8 strings.
   Copyright (C) 2009-2011 Free Software Foundation, Inc.
   Written by Bruno Haible <bruno@clisp.org>, 2009.
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
#include <stddef.h>
#include <stddef.h>
/* Specification.  */
#include "uniwbrk.h"
#include <string.h>
#include "unistr.h"
#include "uniwbrk/wbrktable.h"
#define FUNC u8_wordbreaks
#define UNIT uint8_t
#define U_MBTOUC_UNSAFE u8_mbtouc_unsafe
#include "u-wordbreaks.h"
#ifdef TEST
#include <stdio.h>
#include <stdlib.h>
/* Read the contents of an input stream, and return it, terminated with a NUL
   byte. */
void *new_malloc(size_t size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
void *new_realloc(void *ptr, size_t size);
char *read_file(FILE * stream)
{
#define BUFSIZE 4096
    char *buf = NULL;
    int alloc = 0;
    int size = 0;
    int count;
    while (!feof(stream)) {
	if (size + BUFSIZE > alloc) {
	    alloc = alloc + alloc / 2;
	    if (alloc < size + BUFSIZE)
		alloc = size + BUFSIZE;
	    buf = new_realloc(buf, alloc);
	    if (buf == NULL) {
		fprintf(stderr, "out of memory\n");
		new_exit(1);
	    }
	}
	count = fread(buf + size, 1, BUFSIZE, stream);
	if (count == 0) {
	    if (ferror(stream)) {
		perror("fread");
		new_exit(1);
	    }
	} else
	    size += count;
    }
    buf = new_realloc(buf, size + 1);
    if (buf == NULL) {
	fprintf(stderr, "out of memory\n");
	new_exit(1);
    }
    buf[size] = '\0';
    return buf;
#undef BUFSIZE
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
	/* Display all the word breaks in the input string.  */
	char *input = read_file(stdin);
	int length = strlen(input);
	char *breaks = new_malloc(length);
	int i;
	u8_wordbreaks((uint8_t *) input, length, breaks);
	for (i = 0; i < length; i++) {
	    switch (breaks[i]) {
	    case 1:
		/* U+2027 in UTF-8 encoding */
		putc(0xe2, stdout);
		putc(0x80, stdout);
		putc(0xa7, stdout);
		break;
	    case 0:
		break;
	    default:
		abort();
	    }
	    putc(input[i], stdout);
	}
	free(breaks);
	return 0;
    } else
	return 1;
}
#endif				/* TEST */
void *new_malloc(size_t size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
void *new_realloc(void *ptr, size_t size)
{
    return realloc(ptr, size);
}

void *new_malloc(size_t size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status)
{
    return exit(status);
}

void *new_malloc(size_t size)
{
    return malloc(size);
}
