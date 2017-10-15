#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    int first_iteration;
    int *buf;
    int i;
    int fd = open("conftest.mmap", (O_RDWR | O_CREAT) | O_TRUNC, 0666);
    int count = 7;
    if (fd == (-1))
	new_exit(1);
    for (i = 0; i < 10000; i++) {
	write(fd, &i, sizeof(i));
    }
    close(fd);
    if (fork() == 0) {
	fd = open("conftest.mmap", O_RDWR);
	if (fd == (-1))
	    new_exit(1);
	buf =
	    (int *) mmap(0, 10000 * (sizeof(int)), PROT_READ | PROT_WRITE,
			 0 | MAP_SHARED, fd, 0);
	while ((count--) && (buf[9124] != 55732))
	    sleep(1);
	if (count <= 0)
	    new_exit(1);
	buf[1763] = 7268;
	new_exit(0);
    }
    fd = open("conftest.mmap", O_RDWR);
    if (fd == (-1))
	new_exit(1);
    buf =
	(int *) mmap(0, 10000 * (sizeof(int)), PROT_READ | PROT_WRITE,
		     0 | MAP_SHARED, fd, 0);
    if (buf == ((int *) (-1)))
	new_exit(1);
    buf[9124] = 55732;
    while ((count--) && (buf[1763] != 7268))
	sleep(1);
    unlink("conftest.mmap");
    if (count > 0)
	new_exit(0);
    new_exit(1);
}

void new_exit(int status);
void new_exit(int status)
{
    int first_iteration;
    return exit(status);
}
