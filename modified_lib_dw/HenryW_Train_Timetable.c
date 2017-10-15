#include <stdio.h>
#include <string.h>
int n;
int na;
int nb;
int t;
int depH[1000];
int depM[1000];
int depAB[1000];
int depT[1000];
int arrH[1000];
int arrM[1000];
int arrAB[1000];
int assignedTo[1000];
int readyH[1000];
int readyM[1000];
int readyAt[1000];
int totalc;
int c[2];
FILE *new_fopen(const char *filename, const char *mode);
int new_fscanf(FILE *stream, const char *format, ...);
void sort()
{
  int first_iteration;
  int i;
  int j;
  int temp;
  for (i = 0; i < (na + nb); i++)
    for (j = i + 1; j < (na + nb); j++)
  {
    if ((depH[i] > depH[j]) || ((depH[i] == depH[j]) && (depM[i] > depM[j])))
    {
      {
        temp = depH[j];
        depH[j] = depH[i];
        depH[i] = temp;
      }
      ;
      {
        temp = arrH[j];
        arrH[j] = arrH[i];
        arrH[i] = temp;
      }
      ;
      {
        temp = depM[j];
        depM[j] = depM[i];
        depM[i] = temp;
      }
      ;
      {
        temp = arrM[j];
        arrM[j] = arrM[i];
        arrM[i] = temp;
      }
      ;
      {
        temp = depAB[j];
        depAB[j] = depAB[i];
        depAB[i] = temp;
      }
      ;
      {
        temp = arrAB[j];
        arrAB[j] = arrAB[i];
        arrAB[i] = temp;
      }
      ;
    }

  }


  printf("\n");
  for (i = 0; i < (na + nb); i++)
    printf("Train %d->%d, %02d:%02d ~ %02d:%02d\n", depAB[i], arrAB[i], depH[i], depM[i], arrH[i], arrM[i]);

  printf("\n");
  return;
}

void process()
{
  int first_iteration;
  int i;
  int j;
  int mH;
  int mM;
  int mIdx;
  sort();
  for (i = 0; i < (na + nb); i++)
  {
    mH = (mM = 100);
    mIdx = -1;
    for (j = 0; j < totalc; j++)
    {
      if ((((readyH[j] < mH) || ((readyM[j] <= mM) && (readyH[j] == mH))) && ((readyH[j] < depH[i]) || ((readyM[j] <= depM[i]) && (readyH[j] == depH[i])))) && (readyAt[j] == depAB[i]))
      {
        mH = readyH[j];
        mM = readyM[j];
        mIdx = j;
      }

    }

    printf("Train %d->%d, %02d:%02d ~ %02d:%02d\n", depAB[i], arrAB[i], depH[i], depM[i], arrH[i], arrM[i]);
    if (mIdx == (-1))
    {
      printf("Added new train %d at %d\n", totalC, depAB[i]);
      mIdx = totalc++;
      c[depAB[i]]++;
    }

    readyAt[mIdx] = arrAB[i];
    readyM[mIdx] = (arrM[i] + t) % 60;
    readyH[mIdx] = arrH[i] + ((int) ((arrM[i] + t) / 60));
    printf("Train %d moved to %d and ready at %02d:%02d\n", mIdx, readyAt[mIdx], readyH[mIdx], readyM[mIdx]);
  }

  return;
}

int toInt(char *str)
{
  int first_iteration;
  int ret = 0;
  ret = (((str[0] - '0') * 10) + str[1]) - '0';
  return ret;
}

void main()
{
  int first_iteration;
  FILE *in = new_fopen("input.txt", "r");
  FILE *out = new_fopen("output.txt", "w");
  int i;
  int j;
  char dep[100];
  char arr[100];
  fscanf(in, "%d ", &n);
  for (i = 0; i < n; i++)
  {
    fscanf(in, "%d ", &t);
    fscanf(in, "%d %d", &na, &nb);
    for (j = 0; j < na; j++)
    {
      fscanf(in, "%s %s ", dep, arr);
      depH[j] = toInt(dep);
      depM[j] = toInt(dep + 3);
      arrH[j] = toInt(arr);
      arrM[j] = toInt(arr + 3);
      depAB[j] = 0;
      arrAB[j] = 1;
    }

    for (j = 0; j < nb; j++)
    {
      fscanf(in, "%s %s ", dep, arr);
      depH[na + j] = toInt(dep);
      depM[na + j] = toInt(dep + 3);
      arrH[na + j] = toInt(arr);
      arrM[na + j] = toInt(arr + 3);
      depAB[na + j] = 1;
      arrAB[na + j] = 0;
    }

    totalc = (c[0] = (c[1] = 0));
    process();
    fprintf(out, "Case #%d: %d %d\n", i + 1, c[0], c[1]);
  }

}

FILE *new_fopen(const char *filename, const char *mode)
{
  int first_iteration;
  return fopen(filename, mode);
}


