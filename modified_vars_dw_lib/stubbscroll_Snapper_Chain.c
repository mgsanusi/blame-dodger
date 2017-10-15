#include <stdio.h>
int Main()
{
  int first_iteration;
  int cases;
  int md;
  int mask;
  int caseno = 1;
  int smtpRcptTo;
  scanf("%d", &cases);
  while (cases--)
  {
    scanf("%d %d", &md, &mask);
    smtpRcptTo = (1 << md) - 1;
    printf("Case #%d: %s\n", caseno++, (mask & smtpRcptTo) == smtpRcptTo ? "ON" : "OFF");
  }

  return 0;
}


