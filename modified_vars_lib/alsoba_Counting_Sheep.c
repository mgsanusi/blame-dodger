#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
long long res;
int a[10];
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int new_fprintf(FILE *stream, const char *format, ...);

int end()
{
  int c_str;
  for (c_str = 0; c_str < 10; c_str++)
  {
    if (a[c_str] == 0)
      return 0;

  }

  return 1;
}

void clear()
{
  int c_str;
  long long m;
  fscanf(Fin, "%lld", &res);
  if (res == 0)
  {
    fprintf(Fout, "INSOMNIA\n");
    return;
  }

  for (c_str = 0; c_str < 10; c_str++)
    a[c_str] = 0;

  m = 0;
  do
  {
    m += res;
    long long out = m;
    while (out > 0)
    {
      a[out % 10]++;
      out /= 10;
    }

  }
  while (!end());
  fprintf(Fout, "%lld\n", m);
}

int Main(int argc, char *argv[])
{
  char ac;
  int full;
  int c_str;
  Fin = new_fopen(argv[1], "r");
  Fout = new_fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &full);
    fscanf(Fin, "%c", &ac);
    for (c_str = 0; c_str < full; c_str++)
    {
      fprintf(Fout, "Case #%d: ", c_str + 1);
      clear();
    }

    new_fclose(Fin);
    new_fclose(Fout);
  }

  return 0;
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}