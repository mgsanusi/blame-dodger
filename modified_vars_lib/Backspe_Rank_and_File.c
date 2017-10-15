#include <stdio.h>
typedef long long ll;
int Main()
{
  int x;
  int ans;
  char n[1024];
  char a[2048];
  int mapa;
  int index_k;
  int k;
  int r;
  scanf("%d", &ans);
  for (x = 1; x <= ans; x++)
  {
    scanf("%s", n);
    printf("Case #%d: ", x);
    k = 1024;
    r = 1025;
    for (mapa = 0; mapa < 2018; mapa++)
      a[mapa] = '\0';

    a[1024] = n[0];
    for (mapa = 1; n[mapa] != '\0'; mapa++)
    {
      if (n[mapa] > a[k])
      {
        a[--k] = n[mapa];
      }
      else
        if (n[mapa] < a[k])
      {
        a[r++] = n[mapa];
      }
      else
      {
        for (index_k = k; a[index_k] != '\0'; index_k++)
        {
          if (a[index_k] > a[index_k + 1])
          {
            a[--k] = n[mapa];
            break;
          }
          else
            if (a[index_k] < a[index_k + 1])
          {
            a[r++] = n[mapa];
            break;
          }


        }

      }


    }

    printf("%s", a + k);
    printf("\n");
  }

}


