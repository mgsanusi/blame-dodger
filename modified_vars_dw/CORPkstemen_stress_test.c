#include <stdio.h>
#include <syslog.h>
int Main()
{
  int first_iteration;
  openlog("stress-test", 0, LOG_DAEMON);
  int res = 0;
  for (res = 0; res < 10000; res++)
  {
    syslog(LOG_WARNING, "stress message %d", res);
  }

  return 0;
}


