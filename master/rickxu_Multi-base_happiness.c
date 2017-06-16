#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_happy(int v, int base, int result[])
{
  int orig=v, left = 0;
  while(v)
  {
    int t = v%base;
    left += t*t; 
    v /= base;
  }

  if(left/base==0)
  {
    if(left==1)
    {
      result[orig] = 1;
      return 1;
    }
  }
  if(result[left]==1)
  {
    return 1;
  }
  if(result[left]==-1)
  {
    return 0;
  }
  result[orig] = -1;
  int ret = is_happy(left, base, result);
  if(ret)
  {
    result[orig] = 1;
  }
  return ret;
}

int main()
{
  int T, i;
  char buf[200] = {0};
  fgets(buf, 10, stdin);
  T = atoi(buf);
  for(i=0;i<T;i++)
  {
    int j=0, v[4] = {0}, result[3][100000]= {{0}};
    fgets(buf, 200, stdin);
    sscanf(buf, "%d %d %d", &v[0], &v[1], &v[2]);
    j = 2;
    while(1)
    {
      if(is_happy(j, v[0], result[0])==1 && is_happy(j, v[1],result[1])==1)
      {
        if(v[2] == 0)
        {
          printf("Case #%d: %d\n", i+1, j);
          break;
        }
 
        if(v[2] && is_happy(j, v[2], result[2]))
        {
          printf("Case #%d: %d\n", i+1, j);
          break;
        }
     }
      j++;
    }
  }
  return 0;
}
