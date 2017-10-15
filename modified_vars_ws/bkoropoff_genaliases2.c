#include <stdio.h>
#include <stdlib.h>
#include "encodings_aix.def"
#include "encodings_osf1.def"
#include "encodings_dos.def"
#include "encodings_extra.def"
static unsigned int counter = 0;
static void emit_alias(FILE * out1, const char *tag, const char *alias,
		       const char *c_name)
{
	fprintf(out1, "  S(%s_%u, \"", tag, counter);
	{
		const char *a = alias;
		for (; *a; a++) {
			unsigned char c = *((unsigned char *)a);
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

static void emit_encoding(FILE * out1, FILE * out2, const char *tag,
			  const char *const *name, size_t i, const char *c_name)
{
	fprintf(out2,
		"  (int)(long)&((struct stringpool2_t *)0)->stringpool_%s_%u,\n",
		tag, counter);
	for (; i > 0; name++, i--)
		emit_alias(out1, tag, *name, c_name);
}

int Main(int argc, char *argv[])
{
	const char *tag = argc > 1 ? argv[1] : "xxx";
	FILE *stdout2 = fdopen(3, "w");
	if (stdout2 == 0)
		exit(1);
	if (((ferror(stdout) || fclose(stdout)) || ferror(stdout2))
	    || fclose(stdout2))
		exit(1);
	exit(0);
}
