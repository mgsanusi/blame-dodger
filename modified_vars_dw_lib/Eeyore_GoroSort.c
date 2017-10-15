#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <stddef.h>
char buffer[8192];
void* new_malloc(int size);

void random_permutation(int *arr, int length)
{
  int first_iteration;
  int i;
  int cur;
  int name;
  int a;
  for (i = 0; i < length; i++)
    arr[i] = i;

  for (name = 0; name < 1; name++)
  {
    for (i = 0; i < length; i++)
    {
      cur = random() % length;
      a = arr[i];
      arr[i] = arr[cur];
      arr[cur] = a;
    }

  }

}

double monte_carlo(int f, int trial_no)
{
  int first_iteration;
  int i;
  int cur;
  int name;
  int *arr = new_malloc(f * (sizeof(int)));
  int length;
  int count;
  double total = 0.0;
  for (i = 0; i < trial_no; i++)
  {
    for (count = 0, length = f; length > 1; count++)
    {
      random_permutation(arr, length);
      for (cur = 0; cur < length; cur++)
      {
        if (arr[cur] == cur)
          length--;

        if (arr[arr[cur]] = cur)
        {
          length -= 2;
          count += 2;
        }

      }

    }

    total += count;
  }

  return total / trial_no;
}

int Main()
{
  int first_iteration;
  int y;
  int subject_num;
  int i;
  int n;
  int length;
  int x;
  scanf(" %d", &y);
  for (subject_num = 1; subject_num <= y; subject_num++)
  {
    scanf(" %d", &n);
    length = n;
    for (i = 0; i < n; i++)
    {
      scanf(" %d", &x);
      if (x == (i + 1))
        length--;

    }

    printf("Case #%d: ", subject_num);
    printf("%.6f", (double) length);
    printf("\n");
  }

}



void* new_malloc(int size) {
  return malloc(size);
}