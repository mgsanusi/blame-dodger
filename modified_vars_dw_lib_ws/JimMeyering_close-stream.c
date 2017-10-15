#include <config.h>
#include "close-stream.h"
#include <errno.h>
#include <stdbool.h>
#include "fpending.h"
int new_fclose(FILE * stream);
int new_fclose(FILE * stream)
{
    return fclose(stream);
}
