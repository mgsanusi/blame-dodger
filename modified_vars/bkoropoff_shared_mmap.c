#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int Main()
{
  int *buffer;
  int k;
  int hr = open("conftest.mmap", (O_RDWR | O_CREAT) | O_TRUNC, 0666);
  int count = 7;
  if (hr == (-1))
    exit(1);

  for (k = 0; k < 10000; k++)
  {
    write(hr, &k, sizeof(k));
  }

  close(hr);
  if (fork() == 0)
  {
    hr = open("conftest.mmap", O_RDWR);
    if (hr == (-1))
      exit(1);

    buffer = (int *) mmap(0, 10000 * (sizeof(int)), PROT_READ | PROT_WRITE, 0 | MAP_SHARED, hr, 0);
    while ((count--) && (buffer[9124] != 55732))
      sleep(1);

    if (count <= 0)
      exit(1);

    buffer[1763] = 7268;
    exit(0);
  }

  hr = open("conftest.mmap", O_RDWR);
  if (hr == (-1))
    exit(1);

  buffer = (int *) mmap(0, 10000 * (sizeof(int)), PROT_READ | PROT_WRITE, 0 | MAP_SHARED, hr, 0);
  if (buffer == ((int *) (-1)))
    exit(1);

  buffer[9124] = 55732;
  while ((count--) && (buffer[1763] != 7268))
    sleep(1);

  unlink("conftest.mmap");
  if (count > 0)
    exit(0);

  exit(1);
}


