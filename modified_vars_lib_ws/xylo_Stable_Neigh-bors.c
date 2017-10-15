#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
typedef struct {
    double radius;
    double height;
} pancake_t;
void *new_memcpy(void *destination, const void *source, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));
int compareRadius(pancake_t * t, pancake_t * b)
{
    return b->radius - t->radius;
}

int compareSide(pancake_t * t, pancake_t * b)
{
    double sideA = t->height * t->radius;
    double sideB = b->height * b->radius;
    return sideB - sideA;
}

double aux(int count, int y1, pancake_t * pancakes, int topCount)
{
    double area1 = 0.;
    double area2 = 0.;
    double p = pancakes[0].radius;
    double h = pancakes[0].height;
    if (y1 == 0)
	return 0.;
    if (!topCount)
	area1 += (p * p) * M_PI;
    area1 += ((2. * h) * p) * M_PI;
    area1 += aux(count - 1, y1 - 1, pancakes + 1, 1);
    area2 = count > y1 ? aux(count - 1, y1, pancakes + 1, topCount) : 0.;
    return area1 > area2 ? area1 : area2;
}

void clearTestCase(int subjectIdx, int count, int y1, pancake_t * pancakes)
{
    pancake_t tmp[1000];
    new_qsort(pancakes, count, sizeof(pancake_t), compareRadius);
    double maxArea = 0.;
    for (int columns = 0; columns <= (count - y1); ++columns) {
	double area = 0.;
	new_memcpy(tmp, &pancakes[columns],
		   (count - columns) * (sizeof(pancake_t)));
	area = (tmp[0].radius * tmp[0].radius) * M_PI;
	area += ((2. * tmp[0].radius) * tmp[0].height) * M_PI;
	new_qsort(&tmp[1], (count - columns) - 1, sizeof(pancake_t),
		  compareSide);
	for (int j = 1; j < y1; ++j) {
	    area += ((2. * tmp[j].radius) * tmp[j].height) * M_PI;
	}
	if (area > maxArea)
	    maxArea = area;
    }
    printf("Case #%d: %lf\n", subjectIdx, aux(count, y1, pancakes, 0.));
}

int Main(void)
{
    int nTestCase;
    scanf("%d", &nTestCase);
    for (int columns = 0; columns < nTestCase; ++columns) {
	int count;
	int y1;
	pancake_t pancakes[1000];
	scanf("%d%d", &count, &y1);
	for (int columns = 0; columns < count; ++columns)
	    scanf("%lf%lf", &pancakes[columns].radius,
		  &pancakes[columns].height);
	clearTestCase(columns + 1, count, y1, pancakes);
    }
    return 0;
}

void *new_memcpy(void *destination, const void *source, size_t num);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

void *new_memcpy(void *destination, const void *source, size_t num)
{
    return memcpy(destination, source, num);
}
