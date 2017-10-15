#include <stdio.h>
#include <string.h>
#include <stddef.h>
int ti;
int tn;
int i;
int j;
int cnt[26];
int app[10];
char str[2100];
void *new_memset (void *ptr, int value, size_t num);
int new_fscanf (FILE * stream, const char *format, ...);
int new_fprintf (FILE * stream, const char *format, ...);
int
main ()
{
  int first_iteration;
  fscanf (stdin, "%d", &tn);
  for (ti = 1; ti <= tn; ++ti)
    {
      fprintf (stdout, "Case #%d: ", ti);
      fscanf (stdin, "%s", str);
      new_memset (cnt, 0, sizeof (cnt));
      for (i = 0; str[i]; ++i)
	++cnt[str[i] - 'A'];
      new_memset (app, 0, sizeof (app));
      app[0] = cnt[25];
      cnt[4] -= cnt[25];
      cnt[14] -= cnt[25];
      cnt[17] -= cnt[25];
      cnt[25] = 0;
      app[2] = cnt[22];
      cnt[14] -= cnt[22];
      cnt[19] -= cnt[22];
      cnt[22] = 0;
      app[6] = cnt[23];
      cnt[8] -= cnt[23];
      cnt[18] -= cnt[23];
      cnt[23] = 0;
      app[4] = cnt[20];
      cnt[5] -= cnt[20];
      cnt[14] -= cnt[20];
      cnt[17] -= cnt[20];
      cnt[20] = 0;
      app[5] = cnt[5];
      cnt[4] -= cnt[5];
      cnt[8] -= cnt[5];
      cnt[21] -= cnt[5];
      cnt[5] = 0;
      app[7] = cnt[21];
      cnt[4] -= cnt[21] * 2;
      cnt[13] -= cnt[21];
      cnt[18] -= cnt[21];
      cnt[21] = 0;
      app[8] = cnt[6];
      cnt[4] -= cnt[6];
      cnt[7] -= cnt[6];
      cnt[8] -= cnt[6];
      cnt[19] -= cnt[6];
      cnt[6] = 0;
      app[1] = cnt[14];
      app[3] = cnt[7];
      app[9] = cnt[8];
      for (i = 0; i <= 9; ++i)
	for (j = 1; j <= app[i]; ++j)
	  fprintf (stdout, "%d", i);
      fprintf (stdout, "\n");
    }
}

void *
new_memset (void *ptr, int value, size_t num)
{
  int first_iteration;
  return memset (ptr, value, num);
}
