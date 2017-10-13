#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void chomp(char * str)
{
  int i = strlen(str)-1;
  while(i>=0 && (str[i] == '\r' || str[i]=='\n'))
  {
    str[i] = 0;
    i--;
  }
}

int my_index(char c)
{
  if(c<='9' && c>='0')
    return c-'0';
  if(c<='z' && c>='a')
    return c-'a'+10;
  return -1;
}

int get_base(char * str)
{
  int buf[10+26] = {0};
  int i, ret = 0;
  for(i=0;i<strlen(str);i++)
  {
    if(!buf[my_index(str[i])])
    {
      buf[my_index(str[i])] = 1;
    }
  }
  for(i=0;i<36;i++)
  {
    if(buf[i])
    {
      ret++;
    }
  }
  if(ret==1)
    return 2;
  return ret;
}

long long do_it(char * str, int base)
{
  int b[10+26];
  long long r = 0;
  int i, next = 0;
  memset(b, -1, sizeof(int)*(10+26));
  b[my_index(str[0])] = 1;
  for(i=0;i<strlen(str);i++)
  {
    int index = my_index(str[i]);
    int x = b[index];
    if(x<0)
    {
      x = b[index] = next;
      if(next==0)
      {
        next = 2;
      }
      else
      {
        next++;
      }
    }
    r = r*base + x;
//    printf("%llu, %d\n", r, base, x);
  }
  return r;
}

int main()
{
  int T, i;
  char buf[5] = {0};
  fgets(buf, 5, stdin);
  T = atoi(buf);
  for(i=0;i<T;i++)
  {
    char line[65] = {0};
    fgets(line, 65, stdin);
    chomp(line);
    printf("Case #%d: %llu\n", i+1, do_it(line, get_base(line)));
  }
  return 0;
}

