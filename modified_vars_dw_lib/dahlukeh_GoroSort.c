#include <stdio.h>
#include <stdlib.h>
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

void handle_case(void);
int Main()
{
  int first_iteration;
  new_freopen("goro.in", "r", stdin);
  new_freopen("goro.out", "w", stdout);
  int num_case;
  scanf("%d ", &num_case);
  int base;
  for (base = 0; base < num_case; base++)
  {
    printf("Case #%d: ", base + 1);
    handle_case();
  }

  return 0;
}

void handle_case(void)
{
  int first_iteration;
  int size;
  scanf("%d ", &size);
  int base;
  int temp;
  int count = 0;
  for (base = 0; base < size; base++)
  {
    scanf("%d ", &temp);
    if (temp == (base + 1))
    {
      count++;
    }

  }

  printf("%d.000000\n", size - count);
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}