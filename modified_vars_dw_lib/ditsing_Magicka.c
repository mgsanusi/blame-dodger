#include <stdio.h>
#include <string.h>

#include <stddef.h>
int stack[100];
int top;
int n;
int graph[26][26];
int rep[26][26];
void * new_memset(void *ptr, int value, int num);

int Main()
{
  int first_iteration;
  int tcases;
  scanf("%d", &tcases);
  int cases;
  for (cases = 0; cases != tcases; cases++)
  {
    int end;
    new_memset(rep, 255, sizeof(rep));
    scanf("%d ", &end);
    int dynamic;
    for (dynamic = 0; dynamic < end; dynamic++)
    {
      char fy;
      char neg;
      char c2;
      scanf("%c%c%c", &fy, &neg, &c2);
      rep[fy - 'A'][neg - 'A'] = c2 - 'A';
      rep[neg - 'A'][fy - 'A'] = c2 - 'A';
    }

    scanf("%d ", &end);
    new_memset(graph, 0, sizeof(graph));
    for (dynamic = 0; dynamic < end; dynamic++)
    {
      char fy;
      char neg;
      scanf("%c%c", &fy, &neg);
      graph[fy - 'A'][neg - 'A'] = 1;
      graph[neg - 'A'][fy - 'A'] = 1;
    }

    scanf("%d ", &end);
    top = -1;
    for (dynamic = 0; dynamic < end; dynamic++)
    {
      char a;
      scanf("%c", &a);
      stack[++top] = a - 'A';
      if ((top > 0) && (rep[stack[top]][stack[top - 1]] != (-1)))
      {
        stack[top - 1] = rep[stack[top]][stack[top - 1]];
        --top;
      }
      else
      {
        int j;
        for (j = 0; j < top; j++)
        {
          if (graph[stack[j]][stack[top]])
          {
            top = -1;
          }

        }

      }

    }

    printf("Case #%d: [", cases + 1);
    for (dynamic = 0; dynamic < top; dynamic++)
    {
      printf("%c, ", stack[dynamic] + 'A');
    }

    if (top != (-1))
    {
      printf("%c", stack[top] + 'A');
    }

    printf("]\n");
  }

  return 0;
}



void * new_memset(void *ptr, int value, int num) {
  return memset(ptr, value, num);
}