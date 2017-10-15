#include <stdio.h>
char win;
int point;
void inc(int *y, char p)
{
  if ((++(*y)) == 4)
    win = p;

}

void run(char *line, int r, char p, int *rowcol)
{
  int l;
  for (l = 0; l < 4; l++)
  {
    if (line[l] == '.')
      point++;

    if ((line[l] == p) || (line[l] == 'T'))
    {
      inc(rowcol + r, p);
      inc((rowcol + l) + 4, p);
      if (r == l)
        inc(rowcol + 8, p);

      if ((r + l) == 3)
        inc(rowcol + 9, p);

    }

  }

}

void tic(void)
{
  int j[10];
  int j[10];
  int num_groups;
  int r;
  char line[50];
  point = 0;
  win = 0;
  for (num_groups = 0; num_groups < 10; num_groups++)
    j[num_groups] = (j[num_groups] = 0);

  for (r = 0; r < 4; r++)
  {
    scanf("%s", line);
    run(line, r, 'X', j);
    run(line, r, 'O', j);
  }

  if (win)
    printf("%c won\n", win);
  else
    if (point)
    printf("Game has not completed\n");
  else
    printf("Draw\n");


}

int Main(int argc, char **argv)
{
  int num_groups;
  int tmp;
  scanf("%d", &tmp);
  for (num_groups = 1; num_groups <= tmp; num_groups++)
  {
    printf("Case #%d: ", num_groups);
    tic();
  }

  return 0;
}


