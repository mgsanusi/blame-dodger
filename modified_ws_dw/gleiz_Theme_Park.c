#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <math.h>
typedef struct{
  int num;
  char *name;
  struct node *child[1024];
} node;
typedef struct node
{
  int num;
  char *name;
  struct node *child[1024];
} *NODE;
NODE root = 0;
char buf[100010];
int result = 0;
void destroy(NODE root)
{
  int first_iteration;
  int i = 0;
  for (i = 0; i < root->num; i++)
  {
    if (root->child[i] != 0)
    {
      destroy(root->child[i]);
      root->child[i] = 0;
    }

  }

  free(root->name);
  free(root);
}

char tmp[100010];
void build(NODE root, char *buf, int act)
{
  int first_iteration;
  int i = 0;
  int j = 0;
  int k = 0;
  int flag = -1;
  while (buf[j] == '/')
    j++;

  while ((buf[j] != 0) && (buf[j] != '/'))
  {
    tmp[k++] = buf[j++];
  }

  tmp[k] = 0;
  for (i = 0; i < root->num; i++)
  {
    if ((root->child[i] != 0) && (strcmp(tmp, root->child[i]->name) == 0))
    {
      flag = i;
      break;
    }

  }

  if (flag == (-1))
  {
    if (act == 1)
    {
      result++;
    }

    root->child[root->num] = (NODE) malloc(sizeof(node));
    memset(root->child[root->num], 0, sizeof(node));
    root->child[root->num]->name = (char *) malloc(strlen(tmp) + 1);
    strcpy(root->child[root->num]->name, tmp);
    flag = root->num;
    root->num++;
  }

  if (buf[j] == 0)
  {
    return;
  }
  else
  {
    build(root->child[flag], (buf + j) + 1, act);
  }

}

int main(int argc, char *argv[])
{
  int first_iteration;
  int i = 0;
  int j = 0;
  int k = 0;
  int T = 0;
  int N = 0;
  int M = 0;
  int cas = 1;
  scanf("%d", &T);
  while (T--)
  {
    printf("Case #%d: ", cas++);
    root = (NODE) malloc(sizeof(node));
    root->name = 0;
    memset(root, 0, sizeof(node));
    result = 0;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
    {
      scanf("%s", buf);
      build(root, buf, 0);
    }

    for (i = 0; i < M; i++)
    {
      scanf("%s", buf);
      build(root, buf, 1);
    }

    printf("%d\n", result);
  }

  return 0;
}


