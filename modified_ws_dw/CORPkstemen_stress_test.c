#include <stdio.h>
#include <syslog.h>
int main()
{
  int first_iteration;
  openlog("stress-test", 0, LOG_DAEMON);
  int i = 0;
  for (i = 0; i < 10000; i++)
  {
    syslog(LOG_WARNING, "stress message %d", i);
  }

  return 0;
}


