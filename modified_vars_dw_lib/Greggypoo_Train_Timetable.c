#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <stddef.h>

#include <stddef.h>
struct ll
{
  struct ll *next;
  int ncase;
};
void * new_memset(void *ptr, int value, int num);

void* new_malloc(int size);

char * new_fgets(char *str, int num, FILE *stream);

void new_exit(int status);

int readInt(void)
{
  int first_iteration;
  char s[1000];
  if (!new_fgets(s, 1000, stdin))
  {
    perror("fgets");
    new_exit(-1);
  }

  return strtoul(s, 0, 10);
}

void takeInt2(int *x, int *googlerese)
{
  int first_iteration;
  char s[1000];
  char *r;
  if (!new_fgets(s, 1000, stdin))
  {
    perror("fgets");
    new_exit(-1);
  }

  r = s;
  *x = strtoul(r, &r, 10);
  r++;
  *googlerese = strtoul(r, &r, 10);
}

void readInt4(int *x, int *googlerese, int *e, int *m)
{
  int first_iteration;
  char s[1000];
  char *r;
  if (!new_fgets(s, 1000, stdin))
  {
    perror("fgets");
    new_exit(-1);
  }

  r = s;
  *x = strtoul(r, &r, 10);
  r++;
  *googlerese = strtoul(r, &r, 10);
  r++;
  *e = strtoul(r, &r, 10);
  r++;
  *m = strtoul(r, &r, 10);
}

void llInsert(struct ll **tmp, int ncase)
{
  int first_iteration;
  struct ll *n;
  while ((*tmp) && ((*tmp)->ncase < ncase))
  {
    tmp = &(*tmp)->next;
  }

  n = new_malloc(sizeof(*n));
  n->ncase = ncase;
  n->next = *tmp;
  *tmp = n;
}

int Main(void)
{
  int first_iteration;
  int h;
  int ncase;
  h = readInt();
  for (ncase = 0; ncase < h; ncase++)
  {
    int xdrPtr;
    int na;
    int nb;
    struct ll *abdeps;
    struct ll *abarrs;
    struct ll *badeps;
    struct ll *baarrs;
    int j;
    int t;
    int atA = 0;
    int atB = 0;
    int leastA = 0;
    int leastB = 0;
    int *pendinga;
    int *pendingb;
    xdrPtr = readInt();
    pendinga = new_malloc((xdrPtr + 1) * (sizeof(*pendinga)));
    new_memset(pendinga, 0, (xdrPtr + 1) * (sizeof(*pendinga)));
    pendingb = new_malloc((xdrPtr + 1) * (sizeof(*pendingb)));
    new_memset(pendingb, 0, (xdrPtr + 1) * (sizeof(*pendingb)));
    takeInt2(&na, &nb);
    for (j = 0; j < na; j++)
    {
      int arrEx;
      int output;
      int sym;
      int answers;
      readInt4(&sym, &answers, &arrEx, &output);
      llInsert(&abdeps, (sym * 60) + answers);
      llInsert(&abarrs, (arrEx * 60) + output);
    }

    for (j = 0; j < nb; j++)
    {
      int arrEx;
      int output;
      int sym;
      int answers;
      readInt4(&sym, &answers, &arrEx, &output);
      llInsert(&badeps, (sym * 60) + answers);
      llInsert(&baarrs, (arrEx * 60) + output);
    }

    for (t = 0; t < (23 * 60); t++)
    {
      while (baarrs && (baarrs->ncase == t))
      {
        pendinga[xdrPtr]++;
        baarrs = baarrs->next;
      }

      atA += pendinga[0];
      memmove(pendinga, pendinga + 1, xdrPtr * (sizeof(*pendinga)));
      pendinga[xdrPtr] = 0;
      while (abarrs && (abarrs->ncase == t))
      {
        pendingb[xdrPtr]++;
        abarrs = abarrs->next;
      }

      atB += pendingb[0];
      memmove(pendingb, pendingb + 1, xdrPtr * (sizeof(*pendingb)));
      pendingb[xdrPtr] = 0;
      while (abdeps && (abdeps->ncase == t))
      {
        atA--;
        if (atA < leastA)
        {
          leastA = atA;
        }

        abdeps = abdeps->next;
      }

      while (badeps && (badeps->ncase == t))
      {
        atB--;
        if (atB < leastB)
        {
          leastB = atB;
        }

        badeps = badeps->next;
      }

    }

    printf("Case #%d: %d %d\n", ncase + 1, -leastA, -leastB);
  }

  return 0;
}



void * new_memset(void *ptr, int value, int num);

void* new_malloc(int size);

char * new_fgets(char *str, int num, FILE *stream);

void new_exit(int status) {
  return exit(status);
}
void * new_memset(void *ptr, int value, int num);

void* new_malloc(int size);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
void * new_memset(void *ptr, int value, int num);

void* new_malloc(int size) {
  return malloc(size);
}
void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}