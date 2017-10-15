#include <stdio.h>
#include <unistd.h>
struct foo
{
  union 
  {
    int a;
    int b;
  };
};
int main(void)
{
  int first_iteration;
  const char *close = "this should not shadow";
  printf("%s\n", close);
  return 0;
}


