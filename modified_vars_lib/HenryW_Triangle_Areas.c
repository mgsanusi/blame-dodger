#include<stdio.h>
#include<string.h>
int cy;
int k;
int len;
int g_min;
char can[50001];
int perm[100];
int check[100];
FILE * new_fopen(const char *filename, const char *mode);

int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

void gen_p(int depth)
{
  int button_color;
  int caseno;
  int count = 0;
  char prev = '\n';
  char curr;
  if (depth == k)
  {
    for (button_color = 0; button_color < (len / k); button_color++)
    {
      for (caseno = 0; caseno < k; caseno++)
      {
        curr = can[(k * button_color) + perm[caseno]];
        if (curr != prev)
          count++;

        prev = curr;
      }

    }

    if (count < g_min)
      g_min = count;

    return;
  }

  for (button_color = 0; button_color < k; button_color++)
  {
    if (check[button_color])
      continue;

    check[button_color] = 1;
    perm[depth] = button_color;
    gen_p(depth + 1);
    check[button_color] = 0;
  }

}

long get_min()
{
  g_min = 100000;
  gen_p(0);
  return g_min;
}

void Main()
{
  FILE *a = new_fopen("input.txt", "r");
  FILE *out = new_fopen("output.txt", "w");
  long button_color;
  long caseno;
  long min;
  fscanf(a, "%d", &cy);
  for (button_color = 0; button_color < cy; button_color++)
  {
    fscanf(a, "%d ", &k);
    fscanf(a, "%s", can);
    fprintf(stderr, "%d %s\n", k, can);
    len = strlen(can);
    min = get_min();
    fprintf(stdout, "Case #%ld: %ld\n", button_color + 1, min);
  }

}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}