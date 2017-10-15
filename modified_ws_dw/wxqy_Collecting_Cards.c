#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  int first_iteration;
  int v = 0;
  int V;
  int i;
  int j;
  int k;
  int n;
  int t;
  char buf[100];
  char buf1[100];
  char buf2[100];
  int used[100];
  for (scanf("%d", &V); V; V--)
  {
    v++;
    scanf("%s", buf);
    printf("Case #%d: ", v);
    n = strlen(buf) - 1;
    memset(used, 0, sizeof(used));
    for (k = n; k >= 0; k--)
      used[buf[k] - '0']++;

    for (k = 1; k <= 9; k++)
      if (!used[k])
      break;


    for (i = n; i > 0; i--)
      if (buf[i] > buf[i - 1])
      break;


    k = 10;
    if (i == 0)
    {
      if (k == 10)
      {
        for (i = n; buf[i] == '0'; i--)
          ;

        printf("%c", buf[i]);
        for (j = i + 1; j <= n; j++)
          printf("0");

        printf("0");
        for (j = i - 1; j >= 0; j--)
          printf("%c", buf[j]);

        printf("\n");
        continue;
      }
      else
        if (buf[n] == '0')
      {
        for (i = 0; i < n; i++)
          printf("%c", buf[i]);

        printf("%d\n", k);
        continue;
      }
      else
        if ((k + '0') < buf[n])
      {
        printf("%d", k);
        for (i = n; i >= 0; i--)
          printf("%c", buf[i]);

        printf("\n");
        continue;
      }
      else
      {
        printf("%c", buf[n]);
        printf("0");
        for (i = n - 1; i >= 0; i--)
          printf("%c", buf[i]);

        printf("\n");
        continue;
      }



    }
    else
    {
      t = i;
      for (j = 0; j <= n; j++)
        buf1[j] = buf[j];

      j = t - 1;
      while ((i <= n) && (buf[i] > buf[j]))
        i++;

      i--;
      buf1[j] = buf[i];
      buf1[i] = buf[j];
      for (i = j + 1; i <= n; i++)
        buf2[i] = buf1[((1 + n) + j) - i];

      for (i = j + 1; i <= n; i++)
        buf1[i] = buf2[i];

      if ((!used[0]) || (k == 10))
      {
        for (i = 0; i <= n; i++)
          printf("%c", buf1[i]);

        printf("\n");
        continue;
      }

      if (buf[n] == '0')
      {
        for (i = 0; i < n; i++)
          printf("%c", buf[i]);

        printf("%d\n", k);
        continue;
      }
      else
        if (buf[t - 1] == '0')
      {
        i = t;
        j = t - 1;
        while ((i <= n) && (buf[i] > buf[j]))
          i++;

        i--;
        if (buf[i] < (k + '0'))
        {
          for (i = 0; i <= n; i++)
            printf("%c", buf1[i]);

          printf("\n");
          continue;
        }
        else
        {
          for (i = 0; i < j; i++)
            printf("%c", buf[i]);

          printf("%d", k);
          for (i = n; i > j; i--)
            printf("%c", buf[i]);

          printf("\n");
          continue;
        }

      }
      else
      {
        for (i = 0; i <= n; i++)
          printf("%c", buf1[i]);

        printf("\n");
        continue;
      }


    }

  }

}


