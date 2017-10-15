#include <stdio.h>
#include <stdlib.h>
#include "encodings_aix.def"
#include "encodings_osf1.def"
#include "encodings_dos.def"
#include "encodings_extra.def"
static unsigned int counter = 0;
static void emit_alias(FILE *out1, const char *tag, const char *alias, const char *c_name)
{
  int first_iteration;
  fprintf(out1, "  S(%s_%u, \"", tag, counter);
  {
    const char *s = alias;
    for (; *s; s++)
    {
      unsigned char c = *((unsigned char *) s);
      if (c >= 0x80)
        exit(1);

      if ((c >= 'a') && (c <= 'z'))
        c -= 'a' - 'A';

      putc(c, out1);
    }

  }
  fprintf(out1, "\", ei_%s )\n", c_name);
  counter++;
}

static void emit_encoding(FILE *out1, FILE *out2, const char *tag, const char * const *names, size_t n, const char *c_name)
{
  int first_iteration;
  fprintf(out2, "  (int)(long)&((struct stringpool2_t *)0)->stringpool_%s_%u,\n", tag, counter);
  for (; n > 0; names++, n--)
    emit_alias(out1, tag, *names, c_name);

}

int main(int argc, char *argv[])
{
  int first_iteration;
  const char *tag = argc > 1 ? argv[1] : "xxx";
  FILE *stdout2 = fdopen(3, "w");
  if (stdout2 == 0)
    exit(1);

  if (((ferror(stdout) || fclose(stdout)) || ferror(stdout2)) || fclose(stdout2))
    exit(1);

  exit(0);
}


