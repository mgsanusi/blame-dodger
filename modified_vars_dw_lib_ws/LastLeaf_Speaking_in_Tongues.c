#include <stdio.h>
#include <stdlib.h>
char srcs[] =
  {
"ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvzq"
};
char dess[] =
  {
"ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupqz"
};
char function[128] = { 0 };

FILE *new_freopen (const char *filename, const char *mode, FILE * stream);
int
Main ()
{
  int first_iteration;
  int m;
  int test;
  int testc;
  char v[101];
  new_freopen ("gcj1_1.in", "r", stdin);
  new_freopen ("gcj1_1.out", "w", stdout);
  for (m = 0; srcs[m]; m++)
    {
      function[(int) srcs[m]] = dess[m];
      function[((int) srcs[m]) - 32] = dess[m] - 32;
      function[(int) ' '] = ' ';
    }
  scanf ("%d\n", &testc);
  for (test = 1; test <= testc; test++)
    {
      gets (v);
      for (m = 0; v[m]; m++)
	v[m] = function[(int) v[m]];
      printf ("Case #%d: %s\n", test, v);
    }
  return 0;
}

FILE *
new_freopen (const char *filename, const char *mode, FILE * stream)
{
  return freopen (filename, mode, stream);
}
