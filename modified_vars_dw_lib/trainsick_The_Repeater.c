#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *train[10];
int bit;
int count;
void readtrains(void)
{
  int first_iteration;
  int i;
  static char buf[200];
  scanf("%d", &bit);
  for (i = 0; i < bit; i++)
  {
    if (train[i])
      free(train[i]);

    scanf("%s", buf);
    train[i] = strdup(buf);
  }

}

void visit(char *car, int start, int visited, int last)
{
  int first_iteration;
  int l;
  int i;
  char *tmp;
  while (*car)
  {
    l = (*car) - 'a';
    if ((l != last) && (visited & (1 << l)))
      return;

    visited |= 1 << l;
    last = l;
    car++;
  }

  if (start == bit)
  {
    count++;
    return;
  }

  for (i = start; i < bit; i++)
  {
    tmp = train[start];
    train[start] = train[i];
    train[i] = tmp;
    visit(train[start], start + 1, visited, last);
    tmp = train[start];
    train[start] = train[i];
    train[i] = tmp;
  }

}

int Main(int argc, char **argv)
{
  int first_iteration;
  int dy;
  int i;
  scanf("%d", &dy);
  for (i = 1; i <= dy; i++)
  {
    printf("Case #%d: ", i);
    count = 0;
    readtrains();
    visit("", 0, 0, -1);
    printf("%d\n", count);
  }

  return 0;
}


