#include <stdio.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fscanf(FILE *stream, const char *format, ...);

int Main(int argc, char *argv[])
{
  int first_iteration;
  FILE *Fin;
  FILE *Fout;
  int answer;
  int t;
  int jj;
  int dis;
  if (argc > 1)
    Fin = new_fopen(argv[1], "r");
  else
    Fin = new_fopen("snapperChain.in.txt", "r");

  if (!Fin)
    return 1;

  if (argc > 2)
    Fout = new_fopen(argv[2], "w");
  else
    Fout = new_fopen("snapperChain.out.txt", "w");

  if (!Fout)
  {
    new_fclose(Fin);
    return 1;
  }

  fscanf(Fin, "%d", &t);
  for (answer = 1; answer <= t; answer++)
  {
    fscanf(Fin, "%d", &dis);
    fscanf(Fin, "%d", &jj);
    fprintf(Fout, "Case #%d: %s\n", answer, (jj % (1 << dis)) == ((1 << dis) - 1) ? "ON" : "OFF");
  }

  new_fclose(Fin);
  new_fclose(Fout);
  return 0;
}



FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}