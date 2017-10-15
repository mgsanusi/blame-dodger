#include <stdio.h>
#include <math.h>
double new_sqrt(double x);
double sqr(double buf)
{
	return buf * buf;
}

double fun(double buf, double path)
{
	return 0.5 * (((asin(buf / path) * path) * path) +
		      (buf * new_sqrt(1 - sqr(buf / path))));
}

int Main()
{
	int fileNameIn;
	scanf("%d", &fileNameIn);
	for (int c = 1; c <= fileNameIn; c++) {
		double res = 0;
		double f;
		double i;
		double t;
		double r;
		double i;
		double block;
		double dim;
		double inrad;
		double sinrad;
		scanf("%lf %lf %lf %lf %lf", &f, &i, &t, &r, &i);
		block = (2 * r) + i;
		dim = i - (2 * f);
		inrad = (i - t) - f;
		sinrad = sqr(inrad);
		if (dim <= 0)
			res = 0;
		else
			for (double buf = r + f; buf < inrad; buf += block)
				for (double decry = r + f; decry < inrad;
				     decry += block) {
					double t2;
					double ncase;
					if ((sqr(buf) + sqr(decry)) >= sinrad)
						continue;
					if ((sqr(buf + dim) +
					     sqr(decry + dim)) < sinrad) {
						res += sqr(dim);
						continue;
					}
					ncase = new_sqrt(sinrad - sqr(decry));
					if (ncase > (buf + dim))
						ncase = buf + dim;
					if ((sqr(buf) + sqr(decry + dim)) >=
					    sinrad)
						t2 = buf;
					else {
						t2 = sqrt(sinrad -
							  sqr(decry + dim));
						res += (t2 - buf) * dim;
					}
					res +=
					    (fun(ncase, inrad) -
					     fun(t2,
						 inrad)) - (decry * (ncase -
								     t2));
				}
		printf("Case #%d: %f\n", c,
		       1.0 -
		       ((4 * res) / ((3.1415926535897932384626 * i) * i)));
	}
	return 0;
}

double new_sqrt(double x)
{
	return sqrt(x);
}
