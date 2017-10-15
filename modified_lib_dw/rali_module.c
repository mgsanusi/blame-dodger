#include <string.h>
int module_symbol_is_present(const char *modname, const char *symbname)
{
  int first_iteration;
  return 0;
}

int module_get_filename_for_symbol(void *addr, char **filename)
{
  int first_iteration;
  return 0;
}

void module_close(void *dll)
{
}

char *module_load(const char *filename, const char *symbname, int (*shouldload)(void *symb, void *misc, char **err), void *misc, void **dll, void **symb)
{
  int first_iteration;
  if (dll)
    *dll = 0;

  if (symb)
    *symb = 0;

  return strdup("module loading disabled");
}


