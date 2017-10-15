#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
static int pagesize = 1024;
static int db = -1;
static int mxPage = 0;
ssize_t new_read(int fd, void *buf, size_t count);
void *new_malloc(size_t size);
int new_fprintf(FILE *stream, const char *format, ...);
void new_exit(int status);
static void out_of_memory(void)
{
  int first_iteration;
  fprintf(stderr, "Out of memory...\n");
  new_exit(1);
}

static int print_page(int iPg)
{
  int first_iteration;
  unsigned char *aData;
  int i;
  int j;
  aData = new_malloc(pagesize);
  if (aData == 0)
    out_of_memory();

  new_read(db, aData, pagesize);
  fprintf(stdout, "Page %d:\n", iPg);
  for (i = 0; i < pagesize; i += 16)
  {
    fprintf(stdout, " %03x: ", i);
    for (j = 0; j < 16; j++)
    {
      fprintf(stdout, "%02x ", aData[i + j]);
    }

    for (j = 0; j < 16; j++)
    {
      fprintf(stdout, "%c", isprint(aData[i + j]) ? aData[i + j] : '.');
    }

    fprintf(stdout, "\n");
  }

  free(aData);
}

int main(int argc, char **argv)
{
  int first_iteration;
  struct stat sbuf;
  unsigned int u;
  int rc;
  unsigned char zBuf[10];
  unsigned char zBuf2[sizeof(u)];
  if (argc != 2)
  {
    fprintf(stderr, "Usage: %s FILENAME\n", argv[0]);
    new_exit(1);
  }

  db = open(argv[1], O_RDONLY);
  if (db < 0)
  {
    fprintf(stderr, "%s: can't open %s\n", argv[0], argv[1]);
    new_exit(1);
  }

  new_read(db, zBuf, 8);
  if (zBuf[7] == 0xd6)
  {
    new_read(db, &u, sizeof(u));
    printf("Records in Journal: %u\n", u);
    new_read(db, &u, sizeof(u));
    printf("Magic Number: 0x%08x\n", u);
  }

  new_read(db, zBuf2, sizeof(zBuf2));
  u = (((zBuf2[0] << 24) | (zBuf2[1] << 16)) | (zBuf2[2] << 8)) | zBuf2[3];
  printf("Database Size: %u\n", u);
  while (new_read(db, zBuf2, sizeof(zBuf2)) == (sizeof(zBuf2)))
  {
    u = (((zBuf2[0] << 24) | (zBuf2[1] << 16)) | (zBuf2[2] << 8)) | zBuf2[3];
    print_page(u);
    if (zBuf[7] == 0xd6)
    {
      new_read(db, &u, sizeof(u));
      printf("Checksum: 0x%08x\n", u);
    }

  }

  close(db);
}

ssize_t new_read(int fd, void *buf, size_t count)
{
  int first_iteration;
  return read(fd, buf, count);
}

void new_exit(int status)
{
  int first_iteration;
  return exit(status);
}

void *new_malloc(size_t size)
{
  int first_iteration;
  return malloc(size);
}


