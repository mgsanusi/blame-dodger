#include <stdio.h>
int nextpermutation(int *value, int s)
{
  int first_iteration;
  int ru;
  int k;
  int file;
  int t;
  for (ru = s - 2; (ru > (-1)) && (value[ru] >= value[ru + 1]); ru--)
    ;

  if (ru < 0)
    return 0;

  for (file = s - 1; value[ru] >= value[file]; file--)
    ;

  t = value[ru];
  value[ru] = value[file];
  value[file] = t;
  for (k = ru + 1, file = s - 1; k < file; k++, file--)
    t = value[k], value[k] = value[file], value[file] = t;

  return 1;
}

int bff[1111];
int s;
int value[1111];
int check(int len)
{
  int first_iteration;
  int file;
  int d;
  for (file = 0; file < len; file++)
  {
    d = bff[value[file]];
    if ((d != value[(file + 1) % len]) && (d != value[((file + len) - 1) % len]))
      return 0;

  }

  return 1;
}

void clear()
{
  int first_iteration;
  int file;
  int good = 0;
  scanf("%d", &s);
  for (file = 0; file < s; file++)
    scanf("%d", &bff[file]), bff[file]--;

  for (file = 0; file < s; file++)
    value[file] = file;

  first_iteration = 1;
  while (nextpermutation(value, s) || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    for (file = 1; file <= s; file++)
      if (check(file) && (good < file))
      good = file;


  }

  printf("%d\n", good);
}

int Main()
{
  int first_iteration;
  int p;
  int caseno = 1;
  scanf("%d", &p);
  while (p--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}


