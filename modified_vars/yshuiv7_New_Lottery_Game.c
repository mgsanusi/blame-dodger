#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int queue[10];
int stack[10][10];
int pin[10];
int g[10][10];
int t;
int done;
int xp_freeargs;
struct post
{
  int number;
  int original;
} qy[10];
void search(int depth, int next, int top)
{
  int count;
  if (top == 0)
  {
    pin[next] = 1;
    stack[0][0] = next;
    queue[0] = next;
    for (count = 0; count < t; count++)
      if ((!pin[count]) && (!done))
      search(1, count, 1);


  }
  else
  {
    int device;
    for (device = top - 1; device >= 0; device--)
      if (g[stack[depth - 1][device]][next])
      break;


    if (device < 0)
      return;

    pin[next] = 1;
    int new_top = device + 2;
    memcpy(stack[depth], stack[depth - 1], (sizeof(int)) * (device + 1));
    stack[depth][device + 1] = next;
    queue[depth] = next;
    if (depth >= (t - 1))
    {
      done = 1;
      printf("Case #%d: ", xp_freeargs);
      for (count = 0; count < t; count++)
        printf("%d", qy[queue[count]].number);

      printf("\n");
      pin[next] = 0;
      return;
    }

    for (device = 0; device < t; device++)
      if ((!pin[device]) && (!done))
      search(depth + 1, device, new_top);


  }

  pin[next] = 0;
}

int cmp(const void *d, const void *l)
{
  const struct post *num = d;
  const struct post *_b = l;
  return num->number - _b->number;
}

int map[10];
int Main()
{
  int cases;
  scanf("%d", &cases);
  for (xp_freeargs = 1; xp_freeargs <= cases; xp_freeargs++)
  {
    int t;
    scanf("%d%d", &t, &t);
    int count;
    memset(g, 0, sizeof(g));
    for (count = 0; count < t; count++)
    {
      scanf("%d", &qy[count].number);
      qy[count].original = count + 1;
    }

    if (t == 1)
    {
      printf("Case #%d: %d\n", xp_freeargs, qy[0].number);
      continue;
    }

    qsort(qy, t, sizeof(struct post), cmp);
    for (count = 0; count < t; count++)
      map[qy[count].original] = count;

    for (count = 0; count < t; count++)
    {
      int x;
      int ans;
      scanf("%d%d", &x, &ans);
      g[map[x]][map[ans]] = 1;
      g[map[ans]][map[x]] = 1;
    }

    for (count = 0; count < t; count++)
      if (!done)
      search(0, count, 0);


    done = 0;
  }

  return 0;
}


