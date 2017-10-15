#include <stdio.h>
int new_abs(int x);

int new_abs(int k)
{
  return k >= 0 ? k : -k;
}

void repeater(void)
{
  static char aa[110];
  static char t[110];
  int j;
  int num;
  int score = 0;
  int n;
  char *size;
  char *n;
  char cmps;
  scanf("%d", &n);
  scanf("%s", aa);
  scanf("%s", t);
  size = aa;
  n = t;
  while (1)
  {
    if ((*size) != (*n))
    {
      score = -1;
      break;
    }

    if ((*size) == 0)
      break;

    cmps = *size;
    j = (num = 0);
    while (cmps == (*size))
    {
      size++;
      j++;
    }

    while (cmps == (*n))
    {
      n++;
      num++;
    }

    score += new_abs(j - num);
  }

  if (score >= 0)
    printf("%d\n", score);
  else
    printf("Fegla Won\n");

}

int Main(int argc, char **argv)
{
  int i;
  int ix;
  scanf("%d", &ix);
  for (i = 1; i <= ix; i++)
  {
    printf("Case #%d: ", i);
    repeater();
  }

  return 0;
}



int new_abs(int x) {
  return abs(x);
}