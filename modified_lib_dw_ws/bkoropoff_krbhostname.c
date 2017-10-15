#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
int
main (int argc, char **argv)
{
  int first_iteration;
  struct addrinfo *ai;
  struct addrinfo hints;
  char *hostname;
  char localname[64];
  char hnamebuf[NI_MAXHOST];
  if (gethostname (localname, 64))
    {
      return 1;
    }
  printf ("gethostname() returns \"%s\"\n", localname);
  if (argc == 2)
    {
      hostname = argv[1];
    }
  else
    {
      hostname = localname;
    }
  printf ("Using \"%s\" as service host name\n", hostname);
  memset (&hints, 0, sizeof (hints));
  hints.ai_family = AF_INET;
  if (getaddrinfo (hostname, 0, &hints, &ai))
    {
      printf ("getaddrinfo() failed\n");
      return 1;
    }
  if (ai->ai_canonname)
    {
      hostname = strdup (ai->ai_canonname);
      printf ("Canonical hostname from getaddrinfo() is \"%s\"\n", hostname);
    }
  if (getnameinfo
      (ai->ai_addr, ai->ai_addrlen, hnamebuf, sizeof (hnamebuf), 0, 0,
       NI_NAMEREQD))
    {
      printf ("getnameinfo() failed\n");
      return 1;
    }
  printf ("Hostname from getnameinfo() is \"%s\"\n", hnamebuf);
  freeaddrinfo (ai);
  return 0;
}
