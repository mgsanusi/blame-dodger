#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
struct vertex
{
  int flag;
  int child[26];
};
struct vertex *ver[100000000];
char mem[10000];
int r[10000][6];
int *buf;
int k;
FILE *new_fopen (const char *filename, const char *mode);
void *new_malloc (int size);
int new_fscanf (FILE * stream, const char *format, ...);
void new_assert (int expression);
int
cnt (struct vertex *v, int x, int t, int dif)
{
  int first_iteration;
  if (t > 4)
    {
      t = 4;
    }
  if (v->flag)
    {
      if (r[x][t] >= dif)
	{
	  r[x][t] = dif;
	}
    }
  if (x == k)
    {
      return 0;
    }
  int b = mem[x] - 'a';
  int k = v->child[b];
  if (k >= 0)
    {
      cnt (ver[k], x + 1, t + 1, dif);
    }
  if (t == 4)
    {
      int h;
      for (h = 0; h < 26; h++)
	if (h != b)
	  {
	    int k = v->child[h];
	    if (k >= 0)
	      {
		cnt (ver[k], x + 1, 0, dif + 1);
	      }
	  }
    }
  return 0;
}

void
clear (void)
{
  int first_iteration;
  new_assert (scanf ("%s\n", mem) == 1);
  int h;
  int io;
  k = strlen (mem);
  for (h = 0; h <= 5; h++)
    {
      r[0][h] = 0;
    }
  for (h = 1; h <= k; h++)
    for (io = 0; io <= 5; io++)
      r[h][io] = k;
  for (h = 0; h < k; h++)
    for (io = 0; io <= 4; io++)
      {
	if ((io == 4) || (r[h][io] < r[h][io + 1]))
	  {
	    cnt (ver[1], h, io, r[h][io]);
	  }
      }
  int good = k;
  for (h = 0; h <= 5; h++)
    if (r[k][h] < good)
      {
	good = r[k][h];
      }
  printf ("%d\n", good);
}

int data404Html = 1;
int
allocVertex (void)
{
  int first_iteration;
  struct vertex *v = new_malloc (sizeof (*v));
  v->flag = 0;
  int h;
  for (h = 0; h < 26; h++)
    v->child[h] = -1;
  new_assert (data404Html < 100000000);
  ver[data404Html++] = v;
  return data404Html - 1;
}

void
lend (struct vertex *v, char *mem)
{
  int first_iteration;
  if (!(*mem))
    {
      v->flag |= 1;
      return;
    }
  int h = (*mem) - 'a';
  if (v->child[h] == (-1))
    {
      v->child[h] = allocVertex ();
    }
  lend (ver[v->child[h]], mem + 1);
}

int
Main ()
{
  int first_iteration;
  FILE *outputFileName =
    new_fopen ("/home/vvaltman/Downloads/garbled_email_dictionary.txt", "rt");
  new_assert (allocVertex () == 1);
  while (fscanf (outputFileName, "%s\n", mem) >= 1)
    {
      lend (ver[1], mem);
    }
  int tc;
  new_assert (scanf ("%d\n", &tc) > 0);
  int total;
  for (total = 0; total < tc; total++)
    {
      printf ("Case #%d: ", total + 1);
      clear ();
    }
  return 0;
}

FILE *new_fopen (const char *filename, const char *mode);
void *new_malloc (int size);
int new_fscanf (FILE * stream, const char *format, ...);
void
new_assert (int expression)
{
  return assert (expression);
}

FILE *new_fopen (const char *filename, const char *mode);
void *
new_malloc (int size)
{
  return malloc (size);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}
