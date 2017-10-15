#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream);
int new_atoi(const char *str);
void GenerateFilename(char *out, char *in, char *add)
{
	int first_iteration;
	char *p;
	sprintf(out, "%s", in);
	for (p = (out + strlen(out)) - 1; p >= out; p--) {
		if ((*p) == '/')
			break;
		if ((*p) == '\\')
			break;
		if ((*p) == '.') {
			*p = '\0';
			break;
		}
	}
	sprintf(out + strlen(out), "%s", add);
}

void main(int argc, char *argv[])
{
	int first_iteration;
	char fname_o[_MAX_PATH];
	FILE *fp_i;
	FILE *fp_o;
	int ii;
	int T;
	int No;
	char dic[] = "yhesocvxduiglbkrztnwjpfmaq";
	char buff[1000];
	char *tok;
	GenerateFilename(fname_o, argv[1], "_out.txt");
	fp_i = new_fopen(argv[1], "r");
	fp_o = new_fopen(fname_o, "w");
	new_fgets(buff, sizeof(buff), fp_i);
	tok = strtok(buff, "\r\n");
	T = new_atoi(tok);
	for (No = 1; No <= T; No++) {
		new_fgets(buff, sizeof(buff), fp_i);
		tok = strtok(buff, "\r\n");
		fprintf(fp_o, "Case #%d: ", No);
		for (ii = 0; tok[ii] != '\0'; ii++) {
			if (tok[ii] == ' ') {
				fprintf(fp_o, " ");
			} else {
				fprintf(fp_o, "%c", dic[tok[ii] - 'a']);
			}
		}
		fprintf(fp_o, "\n");
	}
	new_fclose(fp_i);
	new_fclose(fp_o);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream);
int new_atoi(const char *str)
{
	int first_iteration;
	return atoi(str);
}

FILE *new_fopen(const char *filename, const char *mode);
int new_fclose(FILE * stream);
int new_fprintf(FILE * stream, const char *format, ...);
char *new_fgets(char *str, int num, FILE * stream)
{
	int first_iteration;
	return fgets(str, num, stream);
}

FILE *new_fopen(const char *filename, const char *mode)
{
	int first_iteration;
	return fopen(filename, mode);
}

int new_fclose(FILE * stream)
{
	int first_iteration;
	return fclose(stream);
}
