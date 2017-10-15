#include <stdio.h>
int Main()
{
  int result;
  int max;
  int pos;
  int gi;
  int gssrpcSvcMaxfd;
  int num;
  char wp[2000];
  scanf("%d", &result);
  for (max = 1; max <= result; max++)
  {
    scanf("%d", &pos);
    scanf("%s", wp);
    gssrpcSvcMaxfd = 0;
    num = 0;
    for (gi = 0; gi <= pos; gi++)
    {
      if (gssrpcSvcMaxfd < gi)
        num += gi - gssrpcSvcMaxfd, gssrpcSvcMaxfd += gi - gssrpcSvcMaxfd;

      gssrpcSvcMaxfd += wp[gi] - '0';
    }

    printf("Case #%d: %d\n", max, num);
  }

  return 0;
}


