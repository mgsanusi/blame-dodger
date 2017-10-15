#include <config.h>
#include <math.h>
#include <float.h>
double new_sqrt(double x);
double new_sqrtl(double x);
double new_sqrt(double x);
double new_sqrtl(double x)
{
	return sqrtl(x);
}

double new_sqrt(double x)
{
	return sqrt(x);
}
