#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int tr;
int all;
int cell[100][100];
int answer;
int dir_x[] = {0, -1, 1, 0, 0};
int dir_y[] = {0, 0, 0, -1, 1};
int search(int t, int a, int dir)
{
  int node;
  int min;
  node = t + dir_x[dir];
  min = a + dir_y[dir];
  if ((((node < 0) || (node >= tr)) || (min < 0)) || (min >= all))
  {
    return 0;
  }

  if (cell[node][min])
    return 1;

  return search(node, min, dir);
}

void clear(void)
{
  int t;
  int a;
  int dir;
  for (t = 0; t < tr; ++t)
  {
    for (a = 0; a < all; ++a)
    {
      dir = cell[t][a];
      if (!dir)
        continue;

      if (search(t, a, dir))
      {
        continue;
      }

      if (((search(t, a, 1) || search(t, a, 2)) || search(t, a, 3)) || search(t, a, 4))
        answer++;
      else
      {
        answer = -1;
        return;
      }

    }

  }

}

void clear_and_print(void)
{
  int node;
  int min;
  char buffer[102];
  scanf("%d %d", &tr, &all);
  gets(buffer);
  for (node = 0; node < tr; ++node)
  {
    gets(buffer);
    for (min = 0; min < all; ++min)
    {
      switch (buffer[min])
      {
        case '.':
          cell[node][min] = 0;
          break;

        case '^':
          cell[node][min] = 1;
          break;

        case 'v':
          cell[node][min] = 2;
          break;

        case '<':
          cell[node][min] = 3;
          break;

        case '>':
          cell[node][min] = 4;
          break;

        default:
          fprintf(stderr, "input error\n");

      }

    }

  }

  answer = 0;
  clear();
  if (answer < 0)
    printf("IMPOSSIBLE\n");
  else
    printf("%d\n", answer);

}

int Main(void)
{
  int dataset_no;
  int case_no;
  scanf("%d", &dataset_no);
  for (case_no = 1; case_no <= dataset_no; ++case_no)
  {
    printf("Case #%d: ", case_no);
    clear_and_print();
  }

  return 0;
}


