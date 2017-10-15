#include <stdio.h>
#include <string.h>
int foo[111][111];
int try[111][111];
int m;
int k;
int can()
{
  int first_iteration;
  int i;
  int res;
  int maks;
  int lo;
  for (i = 0; i < m; i++)
    for (res = 0; res < k; res++)
    try[i][res] = 100;


  first_iteration = 1;
  while (lo || (first_iteration == 1))
  {
    if (first_iteration)
      first_iteration = 0;

    lo = 0;
    for (i = 0; i < m; i++)
    {
      maks = 0;
      for (res = 0; res < k; res++)
        if (maks < foo[i][res])
        maks = foo[i][res];


      for (res = 0; res < k; res++)
        if (try[i][res] > maks)
        try[i][res] = maks, lo = 1;


    }

    for (res = 0; res < k; res++)
    {
      maks = 0;
      for (i = 0; i < m; i++)
        if (maks < foo[i][res])
        maks = foo[i][res];


      for (i = 0; i < m; i++)
        if (try[i][res] > maks)
        try[i][res] = maks, lo = 1;


    }

  }

  for (i = 0; i < m; i++)
    for (res = 0; res < k; res++)
    if (try[i][res] != foo[i][res])
    return 0;



  return 1;
}

int Main()
{
  int first_iteration;
  int arr;
  int no = 1;
  int i;
  int res;
  scanf("%d", &arr);
  while (arr--)
  {
    scanf("%d %d", &m, &k);
    for (i = 0; i < m; i++)
      for (res = 0; res < k; res++)
      scanf("%d", &foo[i][res]);


    printf("Case #%d: %s\n", no++, can() ? "YES" : "NO");
  }

  return 0;
}


