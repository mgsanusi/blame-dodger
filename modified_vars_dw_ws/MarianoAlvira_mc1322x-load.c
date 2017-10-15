#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <stdint.h>
char *filename;
char *second;
char *term = "/dev/ttyUSB0";
int baud = B115200;
int verbose = 0;
char *rts = "rts";
char *command;
int firstDelay = 50;
int secondCheck = 100;
int doExit = 0;
int zerolen = 0;
char *args = 0;
struct stat sbuf;
struct termios choice;
char buf[256];
int pfd;
int ffd;
int sfd;
void help (void);
int
Main (int argc, char **argv)
{
  int first_iteration;
  int fp = 0;
  int sum = 0;
  int n = 0;
  uint32_t t = 0;
  opterr = 0;
  while ((fp = getopt (argc, argv, "f:s:zt:vu:r:c:a:b:eh")) != (-1))
    {
      switch (fp)
	{
	case 'f':
	  filename = optarg;
	  break;
	case 's':
	  second = optarg;
	  break;
	case 'z':
	  zerolen = 1;
	  break;
	case 't':
	  term = optarg;
	  break;
	case 'v':
	  verbose = 1;
	  break;
	case 'u':
	  if (strcmp (optarg, "115200"))
	    {
	      baud = B115200;
	    }
	  else if (strcmp (optarg, "57600"))
	    {
	      baud = B115200;
	    }
	  else if (strcmp (optarg, "19200"))
	    {
	      baud = B19200;
	    }
	  else if (strcmp (optarg, "9600"))
	    {
	      baud = B9600;
	    }
	  else
	    {
	      printf ("Unknown baud rate %s!\n", optarg);
	      return -1;
	    }
	  break;
	case 'r':
	  rts = optarg;
	  break;
	case 'c':
	  command = optarg;
	  break;
	case 'a':
	  firstDelay = atoi (optarg);
	  break;
	case 'b':
	  secondCheck = atoi (optarg);
	  break;
	case 'e':
	  doExit = 1;
	  break;
	case 'h':
	case '?':
	  help ();
	  return 0;
	default:
	  abort ();
	}
    }
  if (optind < argc)
    args = argv[optind];
  if (verbose)
    {
      printf ("Primary file (RAM): %s\n", filename);
      printf ("Secondary file (Flash): %s\n", second);
      printf ("Zero secondary file: %s\n", zerolen == 1 ? "Yes" : "No");
      printf ("Port: %s\n", term);
      printf ("Baud rate: %i\n", baud);
      printf ("Flow control: %s\n", rts);
      printf ("Reset command: %s\n", command);
      printf ("Exit after load: %s\n", doExit == 1 ? "Yes" : "No");
      printf ("Delay 1: %i\n", firstDelay);
      printf ("Delay 2: %i\n", secondCheck);
    }
  pfd = open (term, (O_RDWR | O_NOCTTY) | O_NDELAY);
  if (pfd == (-1))
    {
      printf ("Cannot open serial port %s!\n", term);
      return -1;
    }
  fcntl (pfd, F_SETFL, FNDELAY);
  tcgetattr (pfd, &choice);
  cfsetispeed (&choice, baud);
  choice.c_cflag |= CLOCAL | CREAD;
  choice.c_cflag &= ~PARENB;
  choice.c_cflag &= ~CSTOPB;
  choice.c_cflag &= ~CSIZE;
  choice.c_cflag |= CS8;
  if (strcmp (rts, "rts"))
    {
      choice.c_cflag &= ~CRTSCTS;
    }
  else
    {
      choice.c_cflag |= CRTSCTS;
    }
  choice.c_lflag &= ~(((ICANON | ECHO) | ECHOE) | ISIG);
  choice.c_oflag &= ~OPOST;
  tcsetattr (pfd, TCSANOW, &choice);
  printf ("Reset the board to enter bootloader (waiting for CONNECT)...\n");
  if (command)
    {
      printf ("Performing reset: %s\n", command);
      system (command);
    }
  n = 0;
  while (1)
    {
      sum = write (pfd, (const void *) "\0", 1);
      sleep (1);
      sum = read (pfd, &buf[n], ((sizeof (buf)) - 1) - n);
      if (sum > 0)
	{
	  buf[n + sum] = '\0';
	  printf ("%s", &buf[n]);
	  fflush (stdout);
	  if (strstr (&buf[n], "CONNECT"))
	    {
	      printf ("\n");
	      break;
	    }
	  n += sum;
	  if (n >= ((sizeof (buf)) - 1))
	    {
	      n = 0;
	    }
	}
      else
	{
	  printf (".");
	  fflush (stdout);
	}
    }
  if (!filename)
    {
      printf ("Please specify firmware file name (-f option)!\n");
      return -1;
    }
  if (stat (filename, &sbuf))
    {
      printf ("Cannot open firmware file %s!\n", filename);
      return -1;
    }
  ffd = open (filename, O_RDONLY);
  if (ffd == (-1))
    {
      printf ("Cannot open firmware file %s!\n", filename);
      return -1;
    }
  t = sbuf.st_size;
  printf ("Sending %s (%i bytes)...\n", filename, t);
  sum = write (pfd, (const void *) (&t), 4);
  n = 0;
  sum = read (ffd, buf, 1);
  while (sum > 0)
    {
      do
	{
	  usleep (firstDelay);
	  fp = write (pfd, (const void *) buf, sum);
	}
      while (fp < sum);
      n += sum;
      printf ("Written %i\r", n);
      fflush (stdout);
      sum = read (ffd, buf, 1);
    }
  printf ("\n");
  if (second || zerolen)
    {
      printf ("Sending secondary file (waiting for ready)...\n");
      n = 0;
      while (1)
	{
	  sleep (1);
	  sum = read (pfd, &buf[n], ((sizeof (buf)) - 1) - n);
	  if (sum > 0)
	    {
	      buf[n + sum] = '\0';
	      printf ("%s", &buf[n]);
	      fflush (stdout);
	      if (strstr (buf, "ready"))
		{
		  printf ("\n");
		  break;
		}
	      n += sum;
	      if (n >= ((sizeof (buf)) - 1))
		{
		  n = 0;
		}
	    }
	  else
	    {
	      printf (".");
	      fflush (stdout);
	    }
	}
      if (second)
	{
	  if (stat (second, &sbuf))
	    {
	      printf ("Cannot open secondary file %s!\n", second);
	      return -1;
	    }
	  sfd = open (second, O_RDONLY);
	  if (sfd == (-1))
	    {
	      printf ("Cannot open secondary file %s!\n", second);
	      return -1;
	    }
	  t = sbuf.st_size;
	  printf ("Sending %s (%i bytes)...\n", second, t);
	  sum = write (pfd, (const void *) (&t), 4);
	  n = 0;
	  sum = read (sfd, buf, 1);
	  while (sum > 0)
	    {
	      do
		{
		  usleep (secondCheck);
		  fp = write (pfd, (const void *) buf, sum);
		}
	      while (fp < sum);
	      n += sum;
	      printf ("Written %i\r", n);
	      fflush (stdout);
	      sum = read (sfd, buf, 1);
	    }
	  printf ("\n");
	}
      else if (zerolen)
	{
	  t = 0;
	  printf ("Sending %i...\n", t);
	  write (pfd, (const void *) (&t), 4);
	}
    }
  if (args)
    {
      printf ("Sending %s\n", args);
      sum = write (pfd, (const void *) args, strlen (args));
      sum = write (pfd, (const void *) ",", 1);
    }
  if (!doExit)
    {
      while (1)
	{
	  sum = read (pfd, buf, sizeof (buf));
	  if (sum > 0)
	    {
	      buf[sum] = '\0';
	      printf ("%s", buf);
	      fflush (stdout);
	    }
	}
    }
}

void
help (void)
{
  int first_iteration;
  printf ("Example usage: mc1322x-load -f foo.bin -t /dev/ttyS0 -b 9600\n");
  printf
    ("          or : mc1322x-load -f flasher.bin -s flashme.bin  0x1e000,0x11223344,0x55667788\n");
  printf
    ("          or : mc1322x-load -f flasher.bin -z  0x1e000,0x11223344,0x55667788\n");
  printf ("       -f required: binary file to load\n");
  printf ("       -s optional: secondary binary file to send\n");
  printf ("       -z optional: send a zero length file as secondary\n");
  printf ("       -t, terminal default: /dev/ttyUSB0\n");
  printf ("       -u, baud rate default: 115200\n");
  printf ("       -r [none|rts] flow control default: rts\n");
  printf ("       -c command to run for autoreset: \n");
  printf ("              e.g. -c 'bbmc -l redbee-econotag -i 0 reset'\n");
  printf ("       -e exit instead of dropping to terminal display\n");
  printf ("       -a first  intercharacter delay, passed to usleep\n");
  printf ("       -b second intercharacter delay, passed to usleep\n");
  printf ("\n");
  printf ("Anything on the command line is sent after all of the files.\n\n");
}
