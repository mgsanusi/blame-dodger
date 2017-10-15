/* Titlecase mapping for UTF-16 substrings (locale dependent).
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
/* Specification.  */
#include "unicase.h"
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "unistr.h"
#include "unictype.h"
#include "uniwbrk.h"
#include "uninorm.h"
#include "caseprop.h"
#include "context.h"
#include "special-casing.h"
#define FUNC u16_ct_totitle
#define UNIT uint16_t
#define U_WORDBREAKS u16_wordbreaks
#define U_MBTOUC_UNSAFE u16_mbtouc_unsafe
#define U_UCTOMB u16_uctomb
#define U_CPY u16_cpy
#define U_NORMALIZE u16_normalize
#include "u-ct-totitle.h"
