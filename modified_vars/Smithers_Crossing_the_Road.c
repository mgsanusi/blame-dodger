#include <stdio.h>
#include <stdlib.h>
int unhappy[][7] = {{0}, {0}, {0}, {2, 5, 8, 0}, {0}, {4, 13, 18, 0}, {5, 0}, {2, 25, 10, 13, 45, 32, 0}, {4, 5, 13, 20, 52, 0}, {50, 53, 41, 68, 0}, {4, 0}};
int happy(int n, int a)
{
  int next;
  int all_match;
  if ((a == 2) || (a == 4))
    return 1;

  while (n != 1)
  {
    next = 0;
    while (n > 0)
    {
      next += (n % a) * (n % a);
      n /= a;
    }

    n = next;
    for (all_match = 0; unhappy[a][all_match]; all_match++)
      if (n == unhappy[a][all_match])
      return 0;


  }

  return 1;
}

int Main()
{
  int case_cnt;
  int case_index;
  char l[20];
  char *p;
  int base_list[10];
  int n;
  int all_match;
  int l;
  scanf("%d", &case_cnt);
  getchar();
  for (case_index = 1; case_index <= case_cnt; case_index++)
  {
    fgets(l, 20, stdin);
    p = l;
    for (all_match = 0; (*p) != '\0'; all_match++)
    {
      base_list[all_match] = (int) strtol(p, &p, 10);
      p++;
    }

    base_list[all_match] = 0;
    n = (l = 1);
    while (l)
    {
      n++;
      l = 0;
      for (all_match = 0; base_list[all_match]; all_match++)
        l = l || (!happy(n, base_list[all_match]));

    }

    printf("Case #%d: %d\n", case_index, n);
  }

  return 0;
}


