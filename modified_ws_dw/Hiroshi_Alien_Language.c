#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int LL;
static int DD;
static int NN;
static char *words[5000];
void setup(void)
{
  int first_iteration;
  char buf[512];
  int i;
  fgets(buf, 512, stdin);
  sscanf(buf, "%d %d %d", &LL, &DD, &NN);
  for (i = 0; i < DD; i++)
  {
    fgets(buf, 512, stdin);
    words[i] = strdup(buf);
  }

}

int check_word(int d, char *l[15])
{
  int first_iteration;
  char *w;
  int i;
  int n;
  w = words[d];
  for (i = 0; i < LL; i++)
  {
    if ((*l[i]) == '(')
    {
      n = 0;
      while (l[i][n] != w[i])
      {
        if (l[i][n] == ')')
          return 0;

        ++n;
      }

    }
    else
      if ((*l[i]) != w[i])
      return 0;


  }

  return 1;
}

int solve_one(char *p)
{
  int first_iteration;
  int x = 0;
  int i;
  char *letter[15];
  i = 0;
  while (*p)
  {
    if ((*p) == '\n')
      break;

    if ((*p) == '(')
    {
      letter[i++] = p;
      while ((*p) != ')')
        ++p;

    }
    else
    {
      letter[i++] = p;
    }

    ++p;
  }

  if (i != LL)
  {
    fprintf(stderr, "BUG!\n");
    exit(1);
  }

  x = 0;
  for (i = 0; i < DD; i++)
    x += check_word(i, letter);

  return x;
}

void solve(void)
{
  int first_iteration;
  char buf[512];
  int i;
  int x;
  for (i = 0; i < NN; i++)
  {
    fgets(buf, 512, stdin);
    x = solve_one(buf);
    printf("Case #%d: %d\n", i + 1, x);
  }

}

int main(int argc, char **argv)
{
  int first_iteration;
  setup();
  solve();
  return 0;
}


