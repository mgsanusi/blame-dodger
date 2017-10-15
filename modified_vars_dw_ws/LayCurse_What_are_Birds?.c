#include<stdio.h>
int x;
int y;
int len;
int h;
int choose;
int cur[5][5];
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };

void
clear (int depth)
{
  int first_iteration;
  int i;
  int length1;
  int add;
  int t;
  int ni;
  int cases;
  int c[5][5];
  if (cur[len][h] <= 0)
    return;
  if (choose < depth)
    choose = depth;
  add = 0;
  for (t = 0; t < 4; t++)
    {
      ni = len + dx[t];
      cases = h + dy[t];
      if ((((ni < 0) || (cases < 0)) || (ni >= x)) || (cases >= y))
	continue;
      if (cur[ni][cases] > 0)
	add++;
    }
  if (add == 0)
    {
      choose = 1000000000;
      return;
    }
  for (i = 0; i < x; i++)
    for (length1 = 0; length1 < y; length1++)
      c[i][length1] = cur[i][length1];
  for (i = 0; i < x; i++)
    for (length1 = 0; length1 < y; length1++)
      {
	if ((i == len) && (length1 == h))
	  continue;
	if (c[i][length1] <= 0)
	  continue;
	add = 0;
	for (t = 0; t < 4; t++)
	  {
	    ni = i + dx[t];
	    cases = length1 + dy[t];
	    if ((((ni < 0) || (cases < 0)) || (ni >= x)) || (cases >= y))
	      continue;
	    if (add < c[ni][cases])
	      add = c[ni][cases];
	  }
	if (add == 0)
	  continue;
	for (t = 0; t < 4; t++)
	  {
	    ni = i + dx[t];
	    cases = length1 + dy[t];
	    if ((((ni < 0) || (cases < 0)) || (ni >= x)) || (cases >= y))
	      continue;
	    if (add == c[ni][cases])
	      {
		cur[ni][cases] -= c[i][length1];
		break;
	      }
	  }
      }
  clear (depth + 1);
  for (t = 0; t < 4; t++)
    {
      ni = len + dx[t];
      cases = h + dy[t];
      if ((((ni < 0) || (cases < 0)) || (ni >= x)) || (cases >= y))
	continue;
      cur[ni][cases] -= c[len][h];
      clear (depth + 1);
      cur[ni][cases] += c[len][h];
    }
  for (i = 0; i < x; i++)
    for (length1 = 0; length1 < y; length1++)
      cur[i][length1] = c[i][length1];
}

int
Main ()
{
  int first_iteration;
  int i;
  int length1;
  int add;
  int b;
  int m;
  int outputFileName;
  int size;
  int count = 0;
  scanf ("%d", &size);
  while (size--)
    {
      scanf ("%d%d%d%d", &y, &x, &h, &len);
      len--;
      h--;
      for (i = 0; i < x; i++)
	for (length1 = 0; length1 < y; length1++)
	  scanf ("%d", cur[i] + length1);
      choose = 0;
      clear (0);
      printf ("Case #%d: ", ++count);
      if (choose >= 1000000000)
	puts ("forever");
      else
	printf ("%d day(s)\n", choose);
    }
  return 0;
}
