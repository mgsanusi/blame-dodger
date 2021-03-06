#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
static int pagesize = 1024;
static int tot = -1;
static int mxPage = 0;
static void outOfMemory(void)
{
  int first_iteration;
  fprintf(stderr, "Out of memory...\n");
  exit(1);
}

static int markPage(int indexPg)
{
  int first_iteration;
  unsigned char *aData;
  int index;
  int j;
  aData = malloc(pagesize);
  if (aData == 0)
    outOfMemory();

  read(tot, aData, pagesize);
  fprintf(stdout, "Page %d:\n", indexPg);
  for (index = 0; index < pagesize; index += 16)
  {
    fprintf(stdout, " %03x: ", index);
    for (j = 0; j < 16; j++)
    {
      fprintf(stdout, "%02x ", aData[index + j]);
    }

    for (j = 0; j < 16; j++)
    {
      fprintf(stdout, "%c", isprint(aData[index + j]) ? aData[index + j] : '.');
    }

    fprintf(stdout, "\n");
  }

  free(aData);
}

int Main(int argc, char **argv)
{
  int first_iteration;
  struct stat sbuf;
  unsigned int to;
  int pp;
  unsigned char zBuffer[10];
  unsigned char zBuf2[sizeof(to)];
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
    exit(1);
  }

  tot = open(argv[1], O_RDONLY);
  if (tot < 0)
  {
    fprintf(stderr, "%s: can't open %s\n", argv[0], argv[1]);
    exit(1);
  }

  read(tot, zBuffer, 8);
  if (zBuffer[7] == 0xd6)
  {
    read(tot, &to, sizeof(to));
    printf("Records in Journal: %u\n", to);
    read(tot, &to, sizeof(to));
    printf("Magic Number: 0x%08x\n", to);
  }

  read(tot, zBuf2, sizeof(zBuf2));
  to = (((zBuf2[0] << 24) | (zBuf2[1] << 16)) | (zBuf2[2] << 8)) | zBuf2[3];
  printf("Database Size: %u\n", to);
  while (read(tot, zBuf2, sizeof(zBuf2)) == (sizeof(zBuf2)))
  {
    to = (((zBuf2[0] << 24) | (zBuf2[1] << 16)) | (zBuf2[2] << 8)) | zBuf2[3];
    markPage(to);
    if (zBuffer[7] == 0xd6)
    {
      read(tot, &to, sizeof(to));
      printf("Checksum: 0x%08x\n", to);
    }

  }

  close(tot);
}


