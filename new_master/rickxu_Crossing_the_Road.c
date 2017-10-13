#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chomp(char * str)
{
  int i = strlen(str)-1;
  while(str[i]=='\n' || str[i]=='\r')
  {
    i--;
  }
  str[i+1] = 0;
}

void sort(char * str)
{
  int i;
  for(i=1;i<strlen(str);i++)
  {
    int j;
    char c = str[i];
    for(j=i;j>0;j--)
    {
      if(str[j]<c)
      {
        break;
      }
      str[j] = str[j-1];
    }
    str[j] = c;
   }
   for(i=0;i<strlen(str);i++)
   {
      if(str[i]!='0')
      {
        char x = str[i];
        str[i] = str[0];
        str[0] = x;
        break;
      }
   }
}

char * do_it(char * perm, int index, char * min)
{
  int i;
  char c = perm[index];
  char * ret = 0;
  if(perm[index+1]==0)
  {
    return strdup(perm);
  }

  for(i=index;i<strlen(perm);i++)
  {
    char t = perm[i];
    perm[index] = t;
    perm[i] = c;
    char * x = do_it(perm, index+1, min);
    if(x && strcmp(x,min)>0)
    {
      if(ret==0 || strcmp(x,ret)<0)
        ret = x;
    }
    perm[i] = perm[index];
    perm[index] = c;
  }
  return ret;
}

int main()
{
  int T,i;
  char buf[5] = {0};
  fgets(buf, 5, stdin);
  T = atoi(buf);
  for(i=0;i<T;i++)
  {
    char str[25] = {0};
    fgets(str, 25, stdin);
    chomp(str);
    char * s = do_it(str, 0, strdup(str));
    if(!s || strlen(str)==1)
    {
      sort(str);
      int j;
      for(j=strlen(str);j>1;j--)
      {
        str[j] = str[j-1];
      }
      str[1] = '0';
      printf("Case #%d: %s\n", i+1, str);
    }
    else
    {
      printf("Case #%d: %s\n", i+1, s);
    }
  }
  return 0;
}
