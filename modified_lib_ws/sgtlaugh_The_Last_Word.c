#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define MAX 10010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("out.txt", "w", stdout)
char str[MAX], out[MAX], lol[MAX];
ssize_t new_read (int fd, void *buf, size_t count);
FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_putchar (int character);
int new_puts (const char *str);
 void
solve (int i, int j)
{
  if (i == j)
    new_putchar (str[i]);
  if (i >= j)
    return;
   int d, k, l, x, y, r, idx, max = 0, counter = 0;
  for (k = i; k <= j; k++)
    {
      if (str[k] > max)
	max = str[k], idx = k;
    }
  for (k = i; k <= j; k++)
    counter += (str[k] == max);
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
  new_read ();
  write ();
  int T = 0, t, n, i, j, k, l;
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

ssize_t new_read (int fd, void *buf, size_t count)
{
  return read (fd, buf, count);
}

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int new_putchar (int character);
int
new_puts (const char *str)
{
  return puts (str);
}

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
new_putchar (int character)
{
  return putchar (character);
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
