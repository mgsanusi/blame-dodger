#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int L;
int D;
int N;
char dictionary[5000][15 + 1];
char pattern[500][15][26];
int count[500];
void register_pattern(int n, char *s_pat)
{
  int first_iteration;
  int i;
  int l;
  int p;
  int flag = 0;
  l = strlen(s_pat);
  p = 0;
  flag = 0;
  for (i = 0; i < l; i++)
  {
    if (flag == 0)
    {
      if (s_pat[i] == '(')
      {
        flag = 1;
      }
      else
      {
        pattern[n][p++][s_pat[i] - 'a'] = 1;
      }

    }
    else
    {
      if (s_pat[i] == ')')
      {
        flag = 0;
        p++;
      }
      else
      {
        pattern[n][p][s_pat[i] - 'a'] = 1;
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
  scanf("%d %d %d\n", &L, &D, &N);
  for (i = 0; i < D; i++)
  {
    gets(dictionary[i]);
  }

  for (i = 0; i < N; i++)
  {
    gets(line);
    register_pattern(i, line);
  }

}

void single_case(char *dic)
{
  int first_iteration;
  int i;
  int j;
  for (i = 0; i < N; i++)
  {
    for (j = 0; j < L; j++)
    {
      if (!pattern[i][j][dic[j] - 'a'])
      {
        break;
      }

    }

    if (j == L)
    {
      count[i]++;
    }

  }

}

void solve()
{
  int first_iteration;
  int i;
  for (i = 0; i < D; i++)
  {
    single_case(dictionary[i]);
  }

}

void output()
{
  int first_iteration;
  int i;
  for (i = 0; i < N; i++)
  {
    printf("Case #%d: %d\n", i + 1, count[i]);
  }

}

int main()
{
  int first_iteration;
  read_data();
  solve();
  output();
  return 0;
}


