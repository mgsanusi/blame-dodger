/* Test the gnulib dirname module.
   Copyright (C) 2005-2007, 2009-2011 Free Software Foundation, Inc.
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
#include "dirname.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct test {
	const char *name;	/* Name under test.  */
	const char *dir;	/* dir_name (name).  */
	const char *last;	/* last_component (name).  */
	const char *base;	/* base_name (name).  */
	const char *stripped;	/* name after strip_trailing_slashes (name).  */
	bool modified;		/* result of strip_trailing_slashes (name).  */
	bool absolute;		/* IS_ABSOLUTE_FILE_NAME (name).  */
};
static struct test tests[] = {
	{"d/f", "d", "f", "f", "d/f", false, false},
	{"/d/f", "/d", "f", "f", "/d/f", false, true},
	{"d/f/", "d", "f/", "f/", "d/f", true, false},
	{"d/f//", "d", "f//", "f/", "d/f", true, false},
	{"f", ".", "f", "f", "f", false, false},
	{"/", "/", "", "/", "/", false, true},
#if DOUBLE_SLASH_IS_DISTINCT_ROOT
	{"//", "//", "", "//", "//", false, true},
	{"//d", "//", "d", "d", "//d", false, true},
#else
	{"//", "/", "", "/", "/", true, true},
	{"//d", "/", "d", "d", "//d", false, true},
#endif
	{"///", "/", "", "/", "/", true, true},
	{"///a///", "/", "a///", "a/", "///a", true, true},
	/* POSIX requires dirname("") and basename("") to both return ".",
	   but dir_name and base_name are defined differently.  */
	{"", ".", "", "", "", false, false},
	{".", ".", ".", ".", ".", false, false},
	{"..", ".", "..", "..", "..", false, false},
#if ISSLASH ('\\')
	{"a\\", ".", "a\\", "a\\", "a", true, false},
	{"a\\b", "a", "b", "b", "a\\b", false, false},
	{"\\", "\\", "", "\\", "\\", false, true},
	{"\\/\\", "\\", "", "\\", "\\", true, true},
	{"\\\\/", "\\", "", "\\", "\\", true, true},
	{"\\//", "\\", "", "\\", "\\", true, true},
	{"//\\", "/", "", "/", "/", true, true},
#else
	{"a\\", ".", "a\\", "a\\", "a\\", false, false},
	{"a\\b", ".", "a\\b", "a\\b", "a\\b", false, false},
	{"\\", ".", "\\", "\\", "\\", false, false},
	{"\\/\\", "\\", "\\", "\\", "\\/\\", false, false},
	{"\\\\/", ".", "\\\\/", "\\\\/", "\\\\", true, false},
	{"\\//", ".", "\\//", "\\/", "\\", true, false},
#if DOUBLE_SLASH_IS_DISTINCT_ROOT
	{"//\\", "//", "\\", "\\", "//\\", false, true},
#else
	{"//\\", "/", "\\", "\\", "//\\", false, true},
#endif
#endif
#if ISSLASH ('\\')
#if FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE
	{"c:", "c:", "", "c:", "c:", false, false},
	{"c:/", "c:/", "", "c:/", "c:/", false, true},
	{"c://", "c:/", "", "c:/", "c:/", true, true},
	{"c:/d", "c:/", "d", "d", "c:/d", false, true},
	{"c://d", "c:/", "d", "d", "c://d", false, true},
	{"c:/d/", "c:/", "d/", "d/", "c:/d", true, true},
	{"c:/d/f", "c:/d", "f", "f", "c:/d/f", false, true},
	{"c:d", "c:.", "d", "d", "c:d", false, false},
	{"c:d/", "c:.", "d/", "d/", "c:d", true, false},
	{"c:d/f", "c:d", "f", "f", "c:d/f", false, false},
	{"a:b:c", "a:.", "b:c", "./b:c", "a:b:c", false, false},
	{"a/b:c", "a", "b:c", "./b:c", "a/b:c", false, false},
	{"a/b:c/", "a", "b:c/", "./b:c/", "a/b:c", true, false},
#else				/* ! FILE_SYSTEM_DRIVE_PREFIX_CAN_BE_RELATIVE */
	{"c:", "c:", "", "c:", "c:", false, true},
	{"c:/", "c:", "", "c:", "c:", true, true},
	{"c://", "c:", "", "c:", "c:", true, true},
	{"c:/d", "c:", "d", "d", "c:/d", false, true},
	{"c://d", "c:", "d", "d", "c://d", false, true},
	{"c:/d/", "c:", "d/", "d/", "c:/d", true, true},
	{"c:/d/f", "c:/d", "f", "f", "c:/d/f", false, true},
	{"c:d", "c:", "d", "d", "c:d", false, true},
	{"c:d/", "c:", "d/", "d/", "c:d", true, true},
	{"c:d/f", "c:d", "f", "f", "c:d/f", false, true},
	{"a:b:c", "a:", "b:c", "./b:c", "a:b:c", false, true},
	{"a/b:c", "a", "b:c", "./b:c", "a/b:c", false, false},
	{"a/b:c/", "a", "b:c/", "./b:c/", "a/b:c", true, false},
#endif
#else				/* ! ISSLASH ('\\') */
	{"c:", ".", "c:", "c:", "c:", false, false},
	{"c:/", ".", "c:/", "c:/", "c:", true, false},
	{"c://", ".", "c://", "c:/", "c:", true, false},
	{"c:/d", "c:", "d", "d", "c:/d", false, false},
	{"c://d", "c:", "d", "d", "c://d", false, false},
	{"c:/d/", "c:", "d/", "d/", "c:/d", true, false},
	{"c:/d/f", "c:/d", "f", "f", "c:/d/f", false, false},
	{"c:d", ".", "c:d", "c:d", "c:d", false, false},
	{"c:d/", ".", "c:d/", "c:d/", "c:d", true, false},
	{"c:d/f", "c:d", "f", "f", "c:d/f", false, false},
	{"a:b:c", ".", "a:b:c", "a:b:c", "a:b:c", false, false},
	{"a/b:c", "a", "b:c", "b:c", "a/b:c", false, false},
	{"a/b:c/", "a", "b:c/", "b:c/", "a/b:c", true, false},
#endif
	{"1:", ".", "1:", "1:", "1:", false, false},
	{"1:/", ".", "1:/", "1:/", "1:", true, false},
	{"/:", "/", ":", ":", "/:", false, true},
	{"/:/", "/", ":/", ":/", "/:", true, true},
	/* End sentinel.  */
	{NULL, NULL, NULL, NULL, NULL, false, false}
};

size_t new_strlen(const char *str);
int new_strcmp(const char *str1, const char *str2);
void new_free(void *ptr);
int main(void)
{
	struct test *t;
	bool ok = true;
	for (t = tests; t->name; t++) {
		char *dir = dir_name(t->name);
		int dirlen = dir_len(t->name);
		char *last = last_component(t->name);
		char *base = base_name(t->name);
		int baselen = base_len(base);
		char *stripped = strdup(t->name);
		bool modified = strip_trailing_slashes(stripped);
		bool absolute = IS_ABSOLUTE_FILE_NAME(t->name);
		if (!(new_strcmp(dir, t->dir) == 0 && (dirlen == new_strlen(dir)
						       || (dirlen + 1 ==
							   new_strlen(dir)
							   && dir[dirlen] ==
							   '.')))) {
			ok = false;
			printf
			    ("dir_name `%s': got `%s' len %d, expected `%s' len %ld\n",
			     t->name, dir, dirlen, t->dir,
			     (unsigned long)new_strlen(t->dir));
		}
		if (new_strcmp(last, t->last)) {
			ok = false;
			printf("last_component `%s': got `%s', expected `%s'\n",
			       t->name, last, t->last);
		}
		if (!(new_strcmp(base, t->base) == 0
		      && (baselen == new_strlen(base)
			  || (baselen + 1 == new_strlen(base)
			      && ISSLASH(base[baselen]))))) {
			ok = false;
			printf
			    ("base_name `%s': got `%s' len %d, expected `%s' len %ld\n",
			     t->name, base, baselen, t->base,
			     (unsigned long)new_strlen(t->base));
		}
		if (new_strcmp(stripped, t->stripped)
		    || modified != t->modified) {
			ok = false;
			printf
			    ("strip_trailing_slashes `%s': got %s %s, expected %s %s\n",
			     t->name, stripped,
			     modified ? "changed" : "unchanged", t->stripped,
			     t->modified ? "changed" : "unchanged");
		}
		if (t->absolute != absolute) {
			ok = false;
			printf("`%s': got %s, expected %s\n", t->name,
			       absolute ? "absolute" : "relative",
			       t->absolute ? "absolute" : "relative");
		}
		new_free(dir);
		new_free(base);
		new_free(stripped);
	}
	return ok ? 0 : 1;
}

size_t new_strlen(const char *str);
int new_strcmp(const char *str1, const char *str2);
void new_free(void *ptr)
{
	return free(ptr);
}

size_t new_strlen(const char *str);
int new_strcmp(const char *str1, const char *str2)
{
	return strcmp(str1, str2);
}

size_t new_strlen(const char *str)
{
	return strlen(str);
}
