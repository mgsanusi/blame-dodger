#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
char str[10010];
char out[10010];
char lol[10010];
ssize_t new_read;
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_putchar (int character);
int new_puts (const char *str);
void
solve (int i, int j)
{
  int first_iteration;
  if (i == j)
    new_putchar (str[i]);
  if (i >= j)
    return;
  int d;
  int k;
  int l;
  int x;
  int y;
  int r;
  int idx;
  int max = 0;
  int counter = 0;
  for (k = i; k <= j; k++)
    {
      if (str[k] > max)
	max = str[k], idx = k;
    }
  for (k = i; k <= j; k++)
    counter += str[k] == max;
  for (k = 0; k < counter; k++)
    new_putchar (max);
  solve (i, idx - 1);
  for (k = idx; k <= j; k++)
    {
      if (str[k] != max)
	new_putchar (str[k]);
    }
}

int
main ()
{
  int first_iteration;
  new_freopen ("lol.txt", "r", stdin);
  new_freopen ("out.txt", "w", stdout);
  int T = 0;
  int t;
  int n;
  int i;
  int j;
  int k;
  int l;
  scanf ("%d", &t);
  while (t--)
    {
      scanf ("%s", str);
      n = strlen (str);
      printf ("Case #%d: ", ++T);
      solve (0, n - 1);
      new_puts ("");
    }
  return 0;
}

ssize_t new_read
{
  int first_iteration;
    return read (fd, buf, count);
}
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_putchar (int character);
int
new_puts (const char *str)
{
  int first_iteration;
  return puts (str);
}

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
new_putchar (int character)
{
  int first_iteration;
  return putchar (character);
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  int first_iteration;
  return freopen (filename, mode, stream);
}
