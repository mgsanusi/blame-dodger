#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char temp[10];
char min[10];
char max[10];
char cur[10];
int factor(int u1)
{
  int first_iteration;
  int length;
  int area;
  int num;
  int f;
  int flag;
  sprintf(temp, "%d", u1);
  length = strlen(temp);
  for (area = 1; area <= length; area++)
  {
    if (length % area)
      continue;

    flag = 0;
    for (num = 0; num < area; num++)
    {
      f = num;
      while ((f + area) < length)
      {
        if (temp[f] != temp[f + area])
          flag = 1;

        f = f + area;
      }

    }

    if (flag == 0)
      return area;

  }

}

int Main()
{
  int first_iteration;
  freopen("out.txt", "w", stdout);
  freopen("C-small-attempt0.in", "r", stdin);
  int area;
  int num;
  int f;
  int l;
  int u1;
  int c;
  int a;
  int r;
  int curnum;
  int con;
  int nlen;
  int length;
  scanf("%d", &c);
  for (area = 1; area <= c; area++)
  {
    con = 0;
    scanf("%d%d", &a, &r);
    sprintf(min, "%d", a);
    sprintf(max, "%d", r);
    nlen = strlen(min);
    for (num = a; num <= r; num++)
    {
      length = factor(num);
      sprintf(cur, "%d", num);
      for (f = 1; f < length; f++)
      {
        curnum = 0;
        for (l = 0; l < nlen; l++)
        {
          u1 = (f + l) % nlen;
          curnum = ((curnum * 10) + cur[u1]) - '0';
        }

        if (((curnum <= r) && (curnum >= a)) && (num < curnum))
        {
          con++;
        }

      }

    }

    printf("Case #%d: %d\n", area, con);
  }

  return 0;
}


