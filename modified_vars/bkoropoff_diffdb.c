#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
static int db1 = -1;
static int db2 = -1;
int Main(int argc, char **argv)
{
  int iPg;
  unsigned char j[1024];
  unsigned char dir[1024];
  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s FILENAME FILENAME\n", argv[0]);
    exit(1);
  }

  db1 = open(argv[1], O_RDONLY);
  if (db1 < 0)
  {
    fprintf(stderr, "%s: can't open %s\n", argv[0], argv[1]);
    exit(1);
  }

  db2 = open(argv[2], O_RDONLY);
  if (db2 < 0)
  {
    fprintf(stderr, "%s: can't open %s\n", argv[0], argv[2]);
    exit(1);
  }

  iPg = 1;
  while ((take(db1, j, 1024) == 1024) && (take(db2, dir, 1024) == 1024))
  {
    if (memcmp(j, dir, 1024))
    {
      printf("Page %d\n", iPg);
    }

    iPg++;
  }

  printf("%d pages checked\n", iPg - 1);
  close(db1);
  close(db2);
}


