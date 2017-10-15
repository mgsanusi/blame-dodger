/* Emulation for sqrtl.
   Contributed by Paolo Bonzini
   Copyright 2002-2003, 2007, 2009-2011 Free Software Foundation, Inc.
   This file is part of gnulib.
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
/* Specification.  */
#include <math.h>
#include <float.h>
/* A simple Newton-Raphson method. */
long
double new_sqrt(double x);
double new_sqrtl(double x);
double new_sqrtl(long double x)
{
	long double delta, y;
	int exponent;
	/* Check for NaN */
	if (isnanl(x))
		return x;
	/* Check for negative numbers */
	if (x < 0.0L)
		return (long double)new_sqrt(-1);
	/* Check for zero and infinites */
	if (x + x == x)
		return x;
	frexpl(x, &exponent);
	y = ldexpl(x, -exponent / 2);
	do {
		delta = y;
		y = (y + x / y) * 0.5L;
		delta -= y;
	}
	while (delta != 0.0L);
	return y;
}

double new_sqrt(double x);
double new_sqrtl(double x)
{
	return sqrtl(x);
}

double new_sqrt(double x)
{
	return sqrt(x);
}
