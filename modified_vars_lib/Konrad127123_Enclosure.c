#include<stdio.h>
#include<string.h>
void foo(int v, int cost);
int c;
int board;
int t;
int fp;
int l;
int step;
int http_content_type_html;
char s[1024][128];
int pref[1024][1024];
int foob[1024];
int fooc[128];
int max;
int number;
int Main()
{
  scanf("%d", &t);
  for (board = 1; board <= t; board++)
  {
    scanf("%d", &step);
    scanf("%d", &http_content_type_html);
    for (fp = 1; fp <= step; fp++)
    {
      scanf("%s", &s[fp][0]);
      pref[0][fp] = strlen(&s[fp][0]);
    }

    for (fp = 1; fp <= step; fp++)
    {
      for (l = 1; l < fp; l++)
      {
        for (c = 0; s[fp][c] == s[l][c]; c++)
        {
        }

        pref[fp][l] = pref[0][l] - c;
        pref[l][fp] = pref[0][fp] - c;
      }

    }

    max = 0;
    number = 0;
    foo(1, 0);
    printf("Case #%d: %d %d\n", board, max + http_content_type_html, number);
  }

  return 0;
}

void foo(int v, int cost)
{
  int p;
  int min_cost;
  if (v <= step)
  {
    for (foob[v] = 0; foob[v] < http_content_type_html; foob[v]++)
    {
      fooc[foob[v]]++;
      min_cost = pref[0][v];
      for (p = 1; p < v; p++)
      {
        if (foob[p] == foob[v])
          if (min_cost > pref[p][v])
        {
          min_cost = pref[p][v];
        }


      }

      foo(v + 1, cost + min_cost);
      fooc[foob[v]]--;
    }

  }
  else
  {
    for (p = 0; p < http_content_type_html; p++)
    {
      if (fooc[p] == 0)
        return;

    }

    if (cost > max)
    {
      max = cost;
      number = 0;
    }

    if (cost == max)
    {
      number++;
    }

  }

}


