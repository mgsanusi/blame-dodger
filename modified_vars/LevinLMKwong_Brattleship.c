#include<stdio.h>
#include<string.h>
int check(char *k, char *k, int lenS, int lenTg)
{
  int guests;
  int d;
  char *temp;
  d = 0;
  for (guests = 0; guests < (lenS - lenTg); guests++)
  {
    strncpy(temp, k, lenTg);
    if (strcmp(k, temp) == 0)
    {
      d++;
    }

  }

  return d;
}

int Main()
{
  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);
  int n;
  int cntSwitch;
  int l;
  int w;
  int guests;
  int cc;
  int jscore;
  int flag;
  int k[100];
  int cnt;
  int pas[26];
  int ans1;
  char ttt[100];
  char k[100];
  char temp1[100];
  char temp2[100];
  double answer;
  scanf("%d", &n);
  for (jscore = 1; jscore <= n; jscore++)
  {
    scanf("%d %d %d\n", &cntSwitch, &l, &w);
    memset(k, 0, sizeof(k));
    memset(pas, 0, sizeof(pas));
    memset(ttt, 0, sizeof(ttt));
    memset(k, 0, sizeof(k));
    for (guests = 0; guests < cntSwitch; guests++)
    {
      scanf("%c", &ttt[guests]);
      pas[ttt[guests] - 'A']++;
    }

    scanf("\n");
    for (guests = 0; guests < l; guests++)
    {
      scanf("%c", &k[guests]);
    }

    k[0] = 1;
    for (guests = 1; guests < l; guests++)
    {
      memset(temp1, 0, sizeof(temp1));
      memset(temp2, 0, sizeof(temp2));
      strncpy(temp1, k, l - guests);
      strncpy(temp2, k + guests, l - guests);
      if (strcmp(temp1, temp2) == 0)
      {
        k[guests] = 1;
      }
      else
      {
        k[guests] = 0;
      }

    }

    answer = 0;
    flag = 1;
    for (guests = 0; guests < l; guests++)
    {
      if (pas[k[guests] - 'A'] == 0)
      {
        flag = 0;
        break;
      }

    }

    if (flag)
    {
      cc = 0;
      cnt = 0;
      for (guests = 0; guests < ((w - l) + 1); guests++)
      {
        if (cc == l)
          cc = 0;

        if (k[cc])
        {
          cnt++;
          cc = 1;
        }
        else
        {
          cc++;
        }

      }

      ans1 = 1;
      for (guests = 0; guests < l; guests++)
      {
        ans1 = ans1 * pas[k[guests] - 'A'];
      }

      ans1 = ans1 * ((w - l) + 1);
      answer = (double) ans1;
      for (guests = 0; guests < l; guests++)
      {
        answer = answer / cntSwitch;
      }

      answer = cnt - answer;
    }

    printf("Case #%d: %f\n", jscore, answer);
  }

}


