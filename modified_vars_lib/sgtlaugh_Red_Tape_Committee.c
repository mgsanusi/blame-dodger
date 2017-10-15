#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>
int t;
int inputFileNameDefault;
char str[100010];
char temp[100010];
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

char * new_strcpy(char *destination, const char *source);


int Main()
{
  new_freopen("lol.txt", "r", stdin);
  new_freopen("out.txt", "w", stdout);
  int q = 0;
  int i;
  int ii;
  int next;
  int y;
  int w;
  int answer;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%s", str);
    inputFileNameDefault = strlen(str), answer = 0;
    while (inputFileNameDefault >= 2)
    {
      for (i = 0, next = 0; (i + 1) < inputFileNameDefault; i++)
      {
        if (str[i] == str[i + 1])
        {
          next = 1, y = inputFileNameDefault;
          answer += 10, inputFileNameDefault = 0;
          for (ii = 0; ii < i; ii++)
            temp[inputFileNameDefault++] = str[ii];

          for (ii = i + 2; ii < y; ii++)
            temp[inputFileNameDefault++] = str[ii];

          temp[inputFileNameDefault] = 0;
          new_strcpy(str, temp);
          break;
        }

      }

      if (!next)
      {
        answer += 5 * (inputFileNameDefault >> 1);
        break;
      }

    }

    printf("Case #%d: %d\n", ++q, answer);
  }

  return 0;
}



ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}