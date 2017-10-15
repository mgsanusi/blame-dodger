#include <stdio.h>
struct pattern
{
  int l;
  int k;
  int r;
};
int Main()
{
  int first_iteration;
  int case_index;
  int case_cnt;
  int altitude;
  int width;
  struct pattern light_grid[20][20];
  unsigned int time[2 * 20][2 * 20];
  int reach[2 * 20][2 * 20];
  int index;
  int j;
  int next_index;
  int next_j;
  struct pattern *light_p;
  unsigned int temp;
  unsigned int temp2;
  int rel_time;
  int l;
  int k;
  int r;
  scanf("%d", &case_cnt);
  for (case_index = 1; case_index <= case_cnt; case_index++)
  {
    scanf("%d %d", &altitude, &width);
    for (index = 0; index < altitude; index++)
      for (j = 0; j < width; j++)
      scanf("%d %d %d", &light_grid[index][j].l, &light_grid[index][j].k, &light_grid[index][j].r);


    for (index = 0; index < (2 * altitude); index++)
      for (j = 0; j < (2 * width); j++)
    {
      reach[index][j] = 0;
      time[index][j] = ~0;
    }


    next_index = (2 * altitude) - 1;
    next_j = 0;
    time[next_index][next_j] = 0;
    while ((next_index != 0) || (next_j != ((2 * width) - 1)))
    {
      index = next_index, j = next_j;
      next_index = index % 2 ? index + 1 : index - 1;
      next_j = j % 2 ? j + 1 : j - 1;
      temp = time[index][j] + 2;
      if (((next_index >= 0) && (next_index < (2 * altitude))) && (temp < time[next_index][j]))
        time[next_index][j] = temp;

      if (((next_j >= 0) && (next_j < (2 * width))) && (temp < time[index][next_j]))
        time[index][next_j] = temp;

      next_index = index ^ 1;
      next_j = j ^ 1;
      light_p = &light_grid[index / 2][j / 2];
      l = light_p->l;
      k = light_p->k;
      r = light_p->r;
      rel_time = (((int) time[index][j]) - r) % (l + k);
      if (rel_time < 0)
        rel_time += l + k;

      if (rel_time < l)
      {
        temp = time[index][j] + 1;
        temp2 = ((time[index][j] + l) - rel_time) + 1;
      }
      else
      {
        temp = (((time[index][j] + l) + k) - rel_time) + 1;
        temp2 = time[index][j] + 1;
      }

      if (((next_index >= 0) && (next_index < (2 * altitude))) && (temp < time[next_index][j]))
        time[next_index][j] = temp;

      if (((next_j >= 0) && (next_j < (2 * width))) && (temp2 < time[index][next_j]))
        time[index][next_j] = temp2;

      reach[index][j] = 1;
      temp = ~0;
      for (index = 0; index < (2 * altitude); index++)
        for (j = 0; j < (2 * width); j++)
        if ((!reach[index][j]) && (time[index][j] < temp))
        next_index = index, next_j = j, temp = time[index][j];



    }

    printf("Case #%d: %d\n", case_index, time[next_index][next_j]);
  }

  return 0;
}


