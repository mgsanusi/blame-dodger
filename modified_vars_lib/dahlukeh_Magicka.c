#include <stdio.h>
#include <stdlib.h>
int badEvoke[30][30];
int formsPair[30][30];
int numEles;
int elemList[1000];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void handleCase(void);
int Main()
{
  new_freopen("magika.in", "r", stdin);
  new_freopen("magika.out", "w", stdout);
  int noCase;
  scanf("%d ", &noCase);
  int rate;
  for (rate = 0; rate < noCase; rate++)
  {
    printf("Case #%d: ", rate + 1);
    handleCase();
  }

  return 0;
}

FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void handleCase(void)
{
  int rate;
  int j;
  for (rate = 0; rate < 30; rate++)
  {
    for (j = 0; j < 30; j++)
    {
      badEvoke[rate][j] = 0;
      formsPair[rate][j] = -1;
    }

  }

  int numPair;
  char pair[40];
  scanf("%d ", &numPair);
  for (rate = 0; rate < numPair; rate++)
  {
    scanf("%s ", &pair[0]);
    formsPair[pair[0] - 'A'][pair[1] - 'A'] = pair[2] - 'A';
    formsPair[pair[1] - 'A'][pair[0] - 'A'] = pair[2] - 'A';
  }

  int noDes;
  char des[30];
  scanf("%d ", &noDes);
  for (rate = 0; rate < noDes; rate++)
  {
    scanf("%s ", &des[0]);
    badEvoke[des[0] - 'A'][des[1] - 'A'] = 1;
    badEvoke[des[1] - 'A'][des[0] - 'A'] = 1;
  }

  numEles = 0;
  int size;
  scanf("%d ", &size);
  char cur;
  for (rate = 0; rate < size; rate++)
  {
    scanf("%c ", &cur);
    elemList[numEles] = cur - 'A';
    numEles++;
    while ((numEles > 1) && (formsPair[elemList[numEles - 1]][elemList[numEles - 2]] != (-1)))
    {
      elemList[numEles - 2] = formsPair[elemList[numEles - 1]][elemList[numEles - 2]];
      numEles--;
    }

    for (j = 0; j < numEles; j++)
    {
      if (badEvoke[elemList[j]][elemList[numEles - 1]])
      {
        numEles = 0;
      }

    }

  }

  printf("[");
  for (rate = 0; rate < (numEles - 1); rate++)
  {
    printf("%c, ", elemList[rate] + 'A');
  }

  if (numEles > 0)
  {
    printf("%c", elemList[rate] + 'A');
  }

  printf("]\n");
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}