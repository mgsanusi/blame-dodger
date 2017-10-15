#include<stdio.h>
int s[2000];
int num[2000][2000];
int type[2000][2000];
int choose;
int res[2000];
int tmp[2000];
int Main()
{
  int first_iteration;
  int http_content_type_gif;
  int j;
  int k;
  int l;
  int m;
  int input_file_name;
  int t;
  int hs;
  int a;
  int b;
  int c;
  int size;
  int cnt = 0;
  scanf("%d", &size);
  while (size--)
  {
    scanf("%d%d", &input_file_name, &m);
    for (http_content_type_gif = 0; http_content_type_gif < m; http_content_type_gif++)
    {
      scanf("%d", s + http_content_type_gif);
      for (j = 0; j < s[http_content_type_gif]; j++)
      {
        scanf("%d%d", num[http_content_type_gif] + j, type[http_content_type_gif] + j);
        num[http_content_type_gif][j]--;
      }

    }

    choose = input_file_name + 1;
    for (k = 0; k < (1 << input_file_name); k++)
    {
      t = 0;
      for (http_content_type_gif = 0; http_content_type_gif < input_file_name; http_content_type_gif++)
        if (k & (1 << http_content_type_gif))
        tmp[http_content_type_gif] = 1, t++;
      else
        tmp[http_content_type_gif] = 0;


      if (choose <= t)
        continue;

      for (http_content_type_gif = 0; http_content_type_gif < m; http_content_type_gif++)
      {
        for (j = 0; j < s[http_content_type_gif]; j++)
          if (tmp[num[http_content_type_gif][j]] == type[http_content_type_gif][j])
          break;


        if (j == s[http_content_type_gif])
          break;

      }

      if (http_content_type_gif == m)
      {
        choose = t;
        for (http_content_type_gif = 0; http_content_type_gif < input_file_name; http_content_type_gif++)
          res[http_content_type_gif] = tmp[http_content_type_gif];

      }

    }

    printf("Case #%d:", ++cnt);
    if (choose > input_file_name)
      puts(" IMPOSSIBLE");
    else
    {
      for (http_content_type_gif = 0; http_content_type_gif < input_file_name; http_content_type_gif++)
        printf(" %d", res[http_content_type_gif]);

      puts("");
    }

  }

  return 0;
}


