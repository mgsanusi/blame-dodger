#include <stdio.h>
#include <stdlib.h>
int be;
int j;
char strs[100][1001];
typedef struct _node *node;
struct _node
{
  node next[26];
};
int upTo;
struct _node cache[10000];
node newNode()
{
  int first_iteration;
  int g;
  node b = &cache[upTo++];
  for (g = 0; g < 26; g++)
  {
    b->next[g] = 0;
  }

  return b;
}

void totalString(node step, char *string)
{
  int first_iteration;
  if (!(*string))
    return;

  int s = (*string) - 'A';
  if (step->next[s] == 0)
  {
    step->next[s] = newNode();
  }

  totalString(step->next[s], string + 1);
}

int findA(int conf)
{
  int first_iteration;
  int group[10];
  int seen[4];
  int g;
  for (g = 0; g < be; g++)
  {
    seen[g] = 0;
  }

  for (g = 0; g < j; g++)
  {
    group[g] = conf % be;
    seen[group[g]] = 1;
    conf /= be;
  }

  for (g = 0; g < be; g++)
  {
    if (!seen[g])
    {
      return -1;
    }

  }

  upTo = 0;
  node solution[4];
  for (g = 0; g < be; g++)
  {
    solution[g] = newNode();
  }

  for (g = 0; g < j; g++)
  {
    totalString(solution[group[g]], &strs[g][0]);
  }

  return upTo;
}

void handle()
{
  int first_iteration;
  scanf("%d %d ", &j, &be);
  int g;
  for (g = 0; g < j; g++)
  {
    scanf("%s ", &strs[g][0]);
  }

  int amoWa = 1;
  for (g = 0; g < j; g++)
  {
    amoWa *= be;
  }

  int maxA = 0;
  int amoW = 0;
  for (g = 0; g < amoWa; g++)
  {
    int ans = findA(g);
    if (ans > maxA)
    {
      maxA = ans;
      amoW = 1;
    }
    else
      if (ans == maxA)
    {
      amoW++;
    }


  }

  printf("%d %d\n", maxA, amoW);
}

int Main()
{
  int first_iteration;
  int t;
  scanf("%d ", &t);
  int g;
  for (g = 0; g < t; g++)
  {
    printf("Case #%d: ", g + 1);
    handle();
  }

  return 0;
}


