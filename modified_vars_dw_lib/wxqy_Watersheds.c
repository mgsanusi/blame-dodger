#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int done[128][128];
int a[128][128];
int c[128][128];
char lt[30];
int color;
int h;
int h;
void init()
{
  int first_iteration;
  int i;
  int cont;
  int low;
  scanf("%d%d", &h, &h);
  for (i = 1; i <= h; i++)
    for (cont = 1; cont <= h; cont++)
    scanf("%d", &done[i][cont]);


  for (i = 1; i <= h; i++)
    for (cont = 1; cont <= h; cont++)
  {
    low = 20000;
    if ((((i - 1) >= 1) && (done[i][cont] > done[i - 1][cont])) && (done[i - 1][cont] < low))
    {
      low = done[i - 1][cont];
      a[i][cont] = 0;
    }

    if ((((cont - 1) >= 1) && (done[i][cont] > done[i][cont - 1])) && (done[i][cont - 1] < low))
    {
      low = done[i][cont - 1];
      a[i][cont] = 1;
    }

    if ((((cont + 1) <= h) && (done[i][cont] > done[i][cont + 1])) && (done[i][cont + 1] < low))
    {
      low = done[i][cont + 1];
      a[i][cont] = 2;
    }

    if ((((i + 1) <= h) && (done[i][cont] > done[i + 1][cont])) && (done[i + 1][cont] < low))
    {
      low = done[i + 1][cont];
      a[i][cont] = 3;
    }

    if (low == 20000)
      a[i][cont] = -1;

  }


  memset(c, 0, sizeof(c));
  color = 0;
}

void fill(int i, int cont)
{
  int first_iteration;
  if (c[i][cont])
    return;

  c[i][cont] = color;
  if (((i - 1) >= 1) && (a[i - 1][cont] == 3))
    fill(i - 1, cont);

  if (((i + 1) <= h) && (a[i + 1][cont] == 0))
    fill(i + 1, cont);

  if (((cont - 1) >= 1) && (a[i][cont - 1] == 2))
    fill(i, cont - 1);

  if (((cont + 1) <= h) && (a[i][cont + 1] == 1))
    fill(i, cont + 1);

}

void clear()
{
  int first_iteration;
  int i;
  int cont;
  for (i = 1; i <= h; i++)
    for (cont = 1; cont <= h; cont++)
    if (a[i][cont] == (-1))
  {
    color++;
    fill(i, cont);
  }



}

void print()
{
  int first_iteration;
  int i;
  int cont;
  char letter;
  for (i = 0; i <= color; i++)
    lt[i] = '#';

  letter = 'a';
  for (i = 1; i <= h; i++)
    for (cont = 1; cont <= h; cont++)
  {
    if (lt[c[i][cont]] == '#')
    {
      lt[c[i][cont]] = letter++;
    }

    printf("%c%c", lt[c[i][cont]], cont != h ? ' ' : '\n');
  }


}

int Main()
{
  int first_iteration;
  int p;
  int count;
  scanf("%d", &count);
  for (p = 1; p <= count; p++)
  {
    init();
    clear();
    printf("Case #%d:\n", p);
    print();
  }

  return 0;
}


