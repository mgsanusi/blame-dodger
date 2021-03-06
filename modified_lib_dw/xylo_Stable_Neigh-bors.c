#include <stdio.h>
#include <string.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
typedef struct 
{
  double radius;
  double height;
} pancake_t;
void *new_memcpy(void *destination, const void *source, size_t num);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *));
int compare_radius(pancake_t *a, pancake_t *b)
{
  int first_iteration;
  return b->radius - a->radius;
}

int compare_side(pancake_t *a, pancake_t *b)
{
  int first_iteration;
  double side_a = a->height * a->radius;
  double side_b = b->height * b->radius;
  return side_b - side_a;
}

double aux(int n, int k, pancake_t *pancakes, int top_counted)
{
  int first_iteration;
  double area1 = 0.;
  double area2 = 0.;
  double r = pancakes[0].radius;
  double h = pancakes[0].height;
  if (k == 0)
    return 0.;

  if (!top_counted)
    area1 += (r * r) * M_PI;

  area1 += ((2. * h) * r) * M_PI;
  area1 += aux(n - 1, k - 1, pancakes + 1, 1);
  area2 = n > k ? aux(n - 1, k, pancakes + 1, top_counted) : 0.;
  return area1 > area2 ? area1 : area2;
}

void solve_test_case(int case_idx, int n, int k, pancake_t *pancakes)
{
  int first_iteration;
  pancake_t tmp[1000];
  new_qsort(pancakes, n, sizeof(pancake_t), compare_radius);
  double max_area = 0.;
  for (int i = 0; i <= (n - k); ++i)
  {
    double area = 0.;
    new_memcpy(tmp, &pancakes[i], (n - i) * (sizeof(pancake_t)));
    area = (tmp[0].radius * tmp[0].radius) * M_PI;
    area += ((2. * tmp[0].radius) * tmp[0].height) * M_PI;
    new_qsort(&tmp[1], (n - i) - 1, sizeof(pancake_t), compare_side);
    for (int j = 1; j < k; ++j)
    {
      area += ((2. * tmp[j].radius) * tmp[j].height) * M_PI;
    }

    if (area > max_area)
      max_area = area;

  }

  printf("Case #%d: %lf\n", case_idx, aux(n, k, pancakes, 0.));
}

int main(void)
{
  int first_iteration;
  int n_test_cases;
  scanf("%d", &n_test_cases);
  for (int i = 0; i < n_test_cases; ++i)
  {
    int n;
    int k;
    pancake_t pancakes[1000];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
      scanf("%lf%lf", &pancakes[i].radius, &pancakes[i].height);

    solve_test_case(i + 1, n, k, pancakes);
  }

  return 0;
}

void *new_memcpy(void *destination, const void *source, size_t num);
void new_qsort(void *base, size_t num, size_t size, int (*compar)(const void *, const void *))
{
  int first_iteration;
  return qsort(base, num, size, compar);
}

void *new_memcpy(void *destination, const void *source, size_t num)
{
  int first_iteration;
  return memcpy(destination, source, num);
}


