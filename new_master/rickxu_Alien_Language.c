#include <stdio.h>
#include <stdlib.h>

int index_of(char * str, char c)
{
  int i = 0;
  while(str[i] && str[i]!=c)
    i++;
  if(str[i]==c)
  {
    return i;
  }
  return -1;
}

int match(char * lang, char * buf, int len)
{
  int i, j=0;
  for(i=0;i<len;i++)
  {
    int k = 0;
    char token[27] = {0};
    if(buf[j]=='(')
    {
      j++;
      while(buf[j]!=')')
      {
        token[k++] = buf[j++];
      }
      j++;
    }
    else
    {
      token[0] = buf[j++];
    }
    if(index_of(token, lang[i])<0)
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int l, d, n, i;
  char language[5000][16] = {{0}};
  scanf("%d %d %d", &l, &d, &n);
  
  for(i=0;i<d;i++)
  {
    scanf("%s", language[i]); 
  }
  for(i=0;i<n;i++)
  {
    int j, num=0;
    char buf[28*28+1] = {0};
    scanf("%s", buf);
    for(j=0;j<d;j++)
    {
      if(match(language[j], buf, l))
      {
        num++;
      }
    }
    printf("Case #%d: %d\n", i+1, num);
  }
  
  return 0;
}
