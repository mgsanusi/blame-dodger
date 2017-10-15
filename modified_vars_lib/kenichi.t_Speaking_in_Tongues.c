#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fprintf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream);

int new_atoi(const char *str);

void generate_filename(char *out, char *s, char *total)
{
  char *aa;
  sprintf(out, "%s", s);
  for (aa = (out + strlen(out)) - 1; aa >= out; aa--)
  {
    if ((*aa) == '/')
      break;

    if ((*aa) == '\\')
      break;

    if ((*aa) == '.')
    {
      *aa = '\0';
      break;
    }

  }

  sprintf(out + strlen(out), "%s", total);
}

void Main(int argc, char *argv[])
{
  char fname_o[_MAX_PATH];
  FILE *fp_i;
  FILE *fp_o;
  int interval;
  int a;
  int new_cred;
  char dic[] = "yhesocvxduiglbkrztnwjpfmaq";
  char buff[1000];
  char *tok;
  generate_filename(fname_o, argv[1], "_out.txt");
  fp_i = new_fopen(argv[1], "r");
  fp_o = new_fopen(fname_o, "w");
  new_fgets(buff, sizeof(buff), fp_i);
  tok = strtok(buff, "\r\n");
  a = new_atoi(tok);
  for (new_cred = 1; new_cred <= a; new_cred++)
  {
    new_fgets(buff, sizeof(buff), fp_i);
    tok = strtok(buff, "\r\n");
    fprintf(fp_o, "Case #%d: ", new_cred);
    for (interval = 0; tok[interval] != '\0'; interval++)
    {
      if (tok[interval] == ' ')
      {
        fprintf(fp_o, " ");
      }
      else
      {
        fprintf(fp_o, "%c", dic[tok[interval] - 'a']);
      }

    }

    fprintf(fp_o, "\n");
  }

  new_fclose(fp_i);
  new_fclose(fp_o);
}



FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fprintf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream);

int new_atoi(const char *str) {
  return atoi(str);
}
FILE * new_fopen(const char *filename, const char *mode);
int new_fclose(FILE *stream);


int new_fprintf(FILE *stream, const char *format, ...);

char * new_fgets(char *str, int num, FILE *stream) {
  return fgets(str, num, stream);
}
FILE * new_fopen(const char *filename, const char *mode) {
  return fopen(filename, mode);
}
int new_fclose(FILE *stream) {
  return fclose(stream);
}