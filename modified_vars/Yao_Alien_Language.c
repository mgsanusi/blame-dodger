#include<stdio.h>
#include<string.h>
char tmp[5000][16];
char string[1024];
int k;
int l;
int c;
int match(char tmp[], char pat[])
{
  int i;
  int j;
  for (i = (j = 0); tmp[i]; i++, j++)
  {
    if (pat[j] != '(')
    {
      if (tmp[i] != pat[j])
        return 0;

    }
    else
      if (!pat[j])
      return 0;
    else
    {
      for (j++; pat[j] != ')'; j++)
        if (pat[j] == tmp[i])
        break;


      if (pat[j] == ')')
        return 0;

      for (j++; pat[j] != ')'; j++)
        ;

    }


  }

  if (!pat[j])
    return 1;
  else
    return 0;

}

int Main()
{
  int tem = 0;
  int i;
  int j;
  int ret;
  scanf("%d %d %d", &l, &k, &c);
  for (i = 0; i < k; i++)
    scanf("%s", tmp[i]);

  for (i = 0; i < c; i++)
  {
    scanf("%s", string);
    for (ret = (j = 0); j < k; j++)
      if (match(tmp[j], string))
      ret++;


    printf("Case #%d: %d\n", ++tem, ret);
  }

  return 0;
}


