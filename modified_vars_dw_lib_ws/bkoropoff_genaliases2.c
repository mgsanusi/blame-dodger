#include <stdio.h>
#include <stdlib.h>
#include "encodings_aix.def"
#include "encodings_osf1.def"
#include "encodings_dos.def"
#include "encodings_extra.def"
int new_fclose(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status);
int new_fclose(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
void new_exit(int status)
{
    return exit(status);
}

int new_fclose(FILE * stream)
{
    return fclose(stream);
}
