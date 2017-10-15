#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int l;
int d;
int n;
char dictionary[5000][15 + 1];
char pattern[500][15][26];
int count[500];
void register_pattern(int y, char *s_pat)
{
  int first_iteration;
  int i;
  int t;
  int y;
  int pin = 0;
  t = strlen(s_pat);
  y = 0;
  pin = 0;
  for (i = 0; i < t; i++)
  {
    if (pin == 0)
    {
      if (s_pat[i] == '(')
      {
        pin = 1;
      }
      else
      {
        pattern[y][y++][s_pat[i] - 'a'] = 1;
      }

    }
    else
    {
      if (s_pat[i] == ')')
      {
        pin = 0;
        y++;
      }
      else
      {
        pattern[y][y][s_pat[i] - 'a'] = 1;
      }

    }

  }

}

void read_data()
{
  int first_iteration;
  int i;
  char line[512];
  memset(line, 0, sizeof(line));
  memset(dictionary, 0, sizeof(dictionary));
  memset(pattern, 0, sizeof(pattern));
  memset(count, 0, sizeof(count));
  scanf("%d %d %d\n", &l, &d, &n);
  for (i = 0; i < d; i++)
  {
    gets(dictionary[i]);
  }

  for (i = 0; i < n; i++)
  {
    gets(line);
    register_pattern(i, line);
  }

}

void one_case(char *dic)
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < l; j++)
    {
      if (!pattern[i][j][dic[j] - 'a'])
      {
        break;
      }

    }

    if (j == l)
    {
      count[i]++;
    }

  }

}

void clear()
{
  int first_iteration;
  int i;
  for (i = 0; i < d; i++)
  {
    one_case(dictionary[i]);
  }

}

void output()
{
  int first_iteration;
  int i;
  for (i = 0; i < n; i++)
  {
    printf("Case #%d: %d\n", i + 1, count[i]);
  }

}

int Main()
{
  int first_iteration;
  read_data();
  clear();
  output();
  return 0;
}


