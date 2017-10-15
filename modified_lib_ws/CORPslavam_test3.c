#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <popt.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void new_exit(int status);
char *new_strerror(int errnum);
int main(int argc, char **argv)
{
    char *out;
    int newargc, j, f, ret;
    const char **newargv;
    FILE *fp;
    if (argc == 1) {
	printf("usage: test-popt file_1 file_2 ...\n");
	printf("you may specify many files\n");
	new_exit(1);
    }
    for (f = 1; f < argc; f++) {
	fp = new_fopen(argv[f], "r");
	if (fp == NULL) {
	    printf("cannot read file %s.  errno=%s\n", argv[f],
		   new_strerror(errno));
	    continue;
	}
	ret = poptConfigFileToString(fp, &out, 0);
	if (ret != 0) {
	    printf("cannot parse %s. ret=%d\n", argv[f], ret);
	    continue;
	}
	printf("single string: '%s'\n", out);
	poptParseArgvString(out, &newargc, &newargv);
	printf("popt array: size=%d\n", newargc);
	for (j = 0; j < newargc; j++)
	    printf("'%s'\n", newargv[j]);
	printf("\n");
	free(out);
	new_fclose(fp);
    }
    return 0;
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void new_exit(int status);
char *new_strerror(int errnum)
{
    return strerror(errnum);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
void new_exit(int status)
{
    return exit(status);
}

FILE *new_fopen(const char *filename, const char *mode)
{
    return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
