#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct tasks
{
  int t;
  int tt;
};
void clear (int cases);
int
Main (void)
{
  int a;
  int grid;
  scanf ("%d", &a);
  for (grid = 1; grid <= a; grid++)
    clear (grid);
  return 0;
}

void
clear (int cases)
{
  int num[2] = { 0, 0 };
  struct tasks task[2][2];
  int place = 0;
  int grid = 0;
  int ch = 0;
  int t = 0;
  num[0] = (num[1] = (place = 0));
  for (grid = 0; grid < 2; grid++)
    for (ch = 0; ch < 2; ch++)
      task[grid][ch] = (struct tasks)
      {
      0, 0};
  scanf ("%d%d", &num[0], &num[1]);
  for (grid = 0; grid < 2; grid++)
    for (ch = 0; ch < num[grid]; ch++)
      scanf ("%d%d", &task[grid][ch].t, &task[grid][ch].tt);
  if ((num[0] + num[1]) == 1)
    {
      printf ("Case #%d: 2\n", cases);
      return;
    }
  else if ((num[0] == 1) || (num[1] == 1))
    {
      printf ("Case #%d: 2\n", cases);
      return;
    }
  else
    {
      place = num[1] == 2 ? 1 : 0;
      if (((task[place][0].tt >
	    task[place][1].tt ? task[place][0].tt : task[place][1].tt) -
	   (task[place][0].t <
	    task[place][1].t ? task[place][0].t : task[place][1].t)) <= 720)
	printf ("Case #%d: 2\n", cases);
      else
	if (((task[place][0].t >
	      task[place][1].t ? task[place][0].t : task[place][1].t) -
	     (task[place][0].tt <
	      task[place][1].tt ? task[place][0].tt : task[place][1].tt)) >=
	    720)
	printf ("Case #%d: 2\n", cases);
      else
	printf ("Case #%d: 4\n", cases);
    }
}
