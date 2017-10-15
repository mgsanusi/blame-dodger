#include <stdio.h>
int nextpermutation(int *value, int s)
{
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
  int file;
  int good = 0;
  scanf("%d", &s);
  for (file = 0; file < s; file++)
    scanf("%d", &bff[file]), bff[file]--;

  for (file = 0; file < s; file++)
    value[file] = file;

  do
  {
    for (file = 1; file <= s; file++)
      if (check(file) && (good < file))
      good = file;


  }
  while (nextpermutation(value, s));
  printf("%d\n", good);
}

int Main()
{
  int p;
  int caseno = 1;
  scanf("%d", &p);
  while (p--)
    printf("Case #%d: ", caseno++), clear();

  return 0;
}


