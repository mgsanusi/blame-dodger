#include <stdio.h>
#include <stdlib.h>
FILE *Fin;
FILE *Fout;
char enter[100][100];
int oku;
int sn;
int functionLeft(int jscore, int w)
{
  int best;
  for (best = w - 1; best >= 0; best--)
  {
    if (enter[jscore][best] != '.')
      return 1;

  }

  printf("NoGoLeft %d %d\n", jscore, w);
  return 0;
}

int goRight(int jscore, int w)
{
  int best;
  for (best = w + 1; best < sn; best++)
  {
    if (enter[jscore][best] != '.')
      return 1;

  }

  printf("NoGoRight %d %d\n", jscore, w);
  return 0;
}

int goUp(int jscore, int w)
{
  int best;
  for (best = jscore - 1; best >= 0; best--)
  {
    if (enter[best][w] != '.')
      return 1;

  }

  printf("NoGoUp %d %d\n", jscore, w);
  return 0;
}

int goDown(int jscore, int w)
{
  int best;
  for (best = jscore + 1; best < oku; best++)
  {
    if (enter[best][w] != '.')
      return 1;

  }

  printf("NoGoDown %d %d\n", jscore, w);
  return 0;
}

int check(int jscore, int w)
{
  switch (enter[jscore][w])
  {
    case '<':
      if (functionLeft(jscore, w))
      return 0;

      if (goRight(jscore, w))
      return 1;

      if (goUp(jscore, w))
      return 1;

      if (goDown(jscore, w))
      return 1;

      printf("%d %d\n", jscore, w);
      return -1;
      break;

    case '>':
      if (goRight(jscore, w))
      return 0;

      if (functionLeft(jscore, w))
      return 1;

      if (goUp(jscore, w))
      return 1;

      if (goDown(jscore, w))
      return 1;

      printf("%d %d\n", jscore, w);
      return -1;
      break;

    case '^':
      if (goUp(jscore, w))
      return 0;

      if (goRight(jscore, w))
      return 1;

      if (functionLeft(jscore, w))
      return 1;

      if (goDown(jscore, w))
      return 1;

      printf("%d %d\n", jscore, w);
      return -1;
      break;

    case 'v':
      if (goDown(jscore, w))
      return 0;

      if (goUp(jscore, w))
      return 1;

      if (goRight(jscore, w))
      return 1;

      if (functionLeft(jscore, w))
      return 1;

      printf("%d %d\n", jscore, w);
      return -1;
      break;

  }

  return -1;
}

void clear()
{
  int best;
  int cx;
  char kk;
  int total = 0;
  fscanf(Fin, "%d %d", &oku, &sn);
  fscanf(Fin, "%c", &kk);
  for (best = 0; best < oku; best++)
  {
    for (cx = 0; cx < sn; cx++)
    {
      fscanf(Fin, "%c", &enter[best][cx]);
    }

    fscanf(Fin, "%c", &kk);
  }

  for (best = 0; best < oku; best++)
  {
    for (cx = 0; cx < sn; cx++)
    {
      if (enter[best][cx] != '.')
      {
        int y2 = check(best, cx);
        if (y2 == (-1))
        {
          fprintf(Fout, "IMPOSSIBLE\n");
          return;
        }
        else
        {
          total += y2;
        }

      }

    }

  }

  fprintf(Fout, "%d\n", total);
}

int Main(int argc, char *argv[])
{
  char kk;
  int total;
  int best;
  Fin = fopen(argv[1], "r");
  Fout = fopen("out", "w");
  if ((Fin == 0) || (Fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(Fin, "%d", &total);
    fscanf(Fin, "%c", &kk);
    for (best = 0; best < total; best++)
    {
      fprintf(Fout, "Case #%d: ", best + 1);
      printf("Case #%d: ", best + 1);
      clear();
    }

    fclose(Fin);
    fclose(Fout);
  }

  return 0;
}


