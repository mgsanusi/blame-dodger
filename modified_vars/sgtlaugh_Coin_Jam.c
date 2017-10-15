#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char str[50];
char out[512][50];
int l;
int m;
int counter;
int s[12][27];
int res[512][12];
const int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
void backtrack(int ok)
{
  if (counter == m)
    return;

  int flg;
  int d;
  int ru;
  if (ok == l)
  {
    for (flg = 2; flg <= 10; flg++)
    {
      for (ru = 0; ru < 25; ru++)
      {
        if (s[flg][ru] == 0)
          break;

      }

      if (ru == 25)
        return;

      res[counter][flg] = prime[ru];
    }

    str[l] = 0;
    strcpy(out[counter++], str);
    return;
  }

  int temp[12][27];
  for (d = 0; d < 2; d++)
  {
    if ((d == 0) && ((ok == 0) || ((ok + 1) == l)))
      continue;

    for (flg = 2; flg <= 10; flg++)
    {
      for (ru = 0; ru < 25; ru++)
      {
        temp[flg][ru] = s[flg][ru];
        s[flg][ru] = ((s[flg][ru] * flg) + d) % prime[ru];
      }

    }

    str[ok] = d + 48;
    backtrack(ok + 1);
    for (flg = 2; flg <= 10; flg++)
    {
      for (ru = 0; ru < 25; ru++)
      {
        s[flg][ru] = temp[flg][ru];
      }

    }

  }

}

int Main()
{
  freopen("lol.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int t = 0;
  int p;
  int ok;
  int ru;
  scanf("%d", &p);
  while (p--)
  {
    counter = 0;
    scanf("%d %d", &l, &m);
    backtrack(0);
    printf("Case #%d:\n", ++t);
    for (ok = 0; ok < counter; ok++)
    {
      printf("%s", out[ok]);
      for (ru = 2; ru <= 10; ru++)
        printf(" %d", res[ok][ru]);

      puts("");
    }

  }

  return 0;
}


