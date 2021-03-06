#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **num;
char **chars;
int N;
FILE *fin;
FILE *fout;
int value;
void readLine(int j)
{
  int first_iteration;
  char a;
  char b;
  int k = 0;
  fscanf(fin, "%c", &a);
  while (a != '\n')
  {
    chars[j][k] = a;
    num[j][k]++;
    fscanf(fin, "%c", &b);
    if (b != a)
    {
      k++;
      a = b;
    }

  }

  chars[j][k] = '\0';
}

int findBest(int k)
{
  int first_iteration;
  int min = 100000;
  int max = 0;
  int best = 1000000;
  int i;
  int j;
  int sum;
  for (i = 0; i < N; i++)
  {
    if (min > num[i][k])
    {
      min = num[i][k];
    }

    if (max < num[i][k])
    {
      max = num[i][k];
    }

  }

  for (j = min; j <= max; j++)
  {
    sum = 0;
    for (i = 0; i < N; i++)
    {
      sum += abs(num[i][k] - j);
    }

    if (sum < best)
    {
      best = sum;
    }

  }

  return best;
}

int game(int k)
{
  int first_iteration;
  int best;
  if (k == value)
  {
    return 0;
  }
  else
  {
    best = findBest(k);
    return game(k + 1) + best;
  }

}

int main(int argc, char *argv[])
{
  int first_iteration;
  char kk;
  char a;
  int total;
  int i;
  int j;
  int k;
  int n;
  int error;
  fin = fopen(argv[1], "r");
  fout = fopen("out", "w");
  if ((fin == 0) || (fout == 0))
  {
    printf("Fitxer out.\n");
  }
  else
  {
    fscanf(fin, "%d", &total);
    fscanf(fin, "%c", &kk);
    for (i = 0; i < total; i++)
    {
      fscanf(fin, "%d", &N);
      chars = (char **) malloc((sizeof(char *)) * N);
      for (j = 0; j < N; j++)
      {
        chars[j] = (char *) calloc(101, sizeof(char));
      }

      num = (int **) calloc(N, sizeof(int *));
      for (j = 0; j < N; j++)
      {
        num[j] = (int *) calloc(100, sizeof(int));
      }

      fscanf(fin, "%c", &kk);
      for (j = 0; j < N; j++)
      {
        readLine(j);
      }

      value = strlen(chars[0]);
      for (int k = 1; k < N; k++)
      {
        if (strlen(chars[k]) > value)
        {
          value = strlen(chars[k]);
        }

      }

      error = 0;
      for (j = 0; j < value; j++)
      {
        a = chars[0][j];
        for (k = 1; k < N; k++)
        {
          if (chars[k][j] != a)
          {
            error = 1;
            break;
          }

        }

      }

      if (error)
      {
        fprintf(fout, "Case #%d: Fegla Won\n", i + 1);
      }
      else
      {
        n = game(0);
        fprintf(fout, "Case #%d: %d\n", i + 1, n);
      }

      for (j = 0; j < N; j++)
      {
        free(chars[j]);
      }

      for (j = 0; j < N; j++)
      {
        free(num[j]);
      }

      free(chars);
      free(num);
    }

    fclose(fin);
    fclose(fout);
  }

  return 0;
}


