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
static int perLine = 32;
long ssize_t new_read(int fd, void *buf, size_t count);
void *new_malloc(size_t size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
int new_strtol(const char *str, char **endptr, int base);
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
	lseek(db, (iPg - 1) * ((long long int)pagesize), 0);
	new_read(db, aData, pagesize);
	fprintf(stdout, "Page %d:\n", iPg);
	for (i = 0; i < pagesize; i += perLine) {
		fprintf(stdout, " %03x: ", i);
		for (j = 0; j < perLine; j++) {
			fprintf(stdout, "%02x ", aData[i + j]);
		}
		for (j = 0; j < perLine; j++) {
			fprintf(stdout, "%c",
				isprint(aData[i + j]) ? aData[i + j] : '.');
		}
		fprintf(stdout, "\n");
	}
	free(aData);
}

int main(int argc, char **argv)
{
	int first_iteration;
	struct stat sbuf;
	if (argc < 2) {
		fprintf(stderr, "Usage: %s FILENAME ?PAGE? ...\n", argv[0]);
		new_exit(1);
	}
	db = open(argv[1], O_RDONLY);
	if (db < 0) {
		fprintf(stderr, "%s: can't open %s\n", argv[0], argv[1]);
		new_exit(1);
	}
	fstat(db, &sbuf);
	mxPage = (sbuf.st_size / pagesize) + 1;
	if (argc == 2) {
		int i;
		for (i = 1; i <= mxPage; i++)
			print_page(i);
	} else {
		int i;
		for (i = 2; i < argc; i++) {
			int iStart;
			int iEnd;
			char *zLeft;
			iStart = new_strtol(argv[i], &zLeft, 0);
			if (zLeft && (strcmp(zLeft, "..end") == 0)) {
				iEnd = mxPage;
			} else
			    if ((zLeft && (zLeft[0] == '.'))
				&& (zLeft[1] == '.')) {
				iEnd = new_strtol(&zLeft[2], 0, 0);
			} else {
				iEnd = iStart;
			}
			if (((iStart < 1) || (iEnd < iStart))
			    || (iEnd > mxPage)) {
				fprintf(stderr,
					"Page argument should be LOWER?..UPPER?.  Range 1 to %d\n",
					mxPage);
				new_exit(1);
			}
			while (iStart <= iEnd) {
				print_page(iStart);
				iStart++;
			}
		}
	}
	close(db);
}

long ssize_t new_read(int fd, void *buf, size_t count);
void *new_malloc(size_t size);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
int new_strtol(const char *str, char **endptr, int base)
{
	int first_iteration;
	return strtol(str, endptr, base);
}

ssize_t new_read(int fd, void *buf, size_t count)
{
	int first_iteration;
	return read(fd, buf, count);
}

void *new_malloc(size_t size);
int new_fprintf(FILE * stream, const char *format, ...);
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
