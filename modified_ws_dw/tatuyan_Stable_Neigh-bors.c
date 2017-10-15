#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct tasks
{
  int st;
  int ed;
};
void solve(int cases);
int main(void)
{
  int first_iteration;
  int T;
  int i;
  scanf("%d", &T);
  for (i = 1; i <= T; i++)
    solve(i);

  return 0;
}

void solve(int cases)
{
  int first_iteration;
  int num[2] = {0, 0};
  struct tasks task[2][2];
  int set = 0;
  int i = 0;
  int j = 0;
  int k = 0;
  num[0] = (num[1] = (set = 0));
  for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    task[i][j] = (struct tasks) {0, 0};


  scanf("%d%d", &num[0], &num[1]);
  for (i = 0; i < 2; i++)
    for (j = 0; j < num[i]; j++)
    scanf("%d%d", &task[i][j].st, &task[i][j].ed);


  if ((num[0] + num[1]) == 1)
  {
    printf("Case #%d: 2\n", cases);
    return;
  }
  else
    if ((num[0] == 1) || (num[1] == 1))
  {
    printf("Case #%d: 2\n", cases);
    return;
  }
  else
  {
    set = num[1] == 2 ? 1 : 0;
    if (((task[set][0].ed > task[set][1].ed ? task[set][0].ed : task[set][1].ed) - (task[set][0].st < task[set][1].st ? task[set][0].st : task[set][1].st)) <= 720)
      printf("Case #%d: 2\n", cases);
    else
      if (((task[set][0].st > task[set][1].st ? task[set][0].st : task[set][1].st) - (task[set][0].ed < task[set][1].ed ? task[set][0].ed : task[set][1].ed)) >= 720)
      printf("Case #%d: 2\n", cases);
    else
      printf("Case #%d: 4\n", cases);


  }


}


