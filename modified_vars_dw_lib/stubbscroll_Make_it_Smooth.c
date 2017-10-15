#include <stdio.h>
char total[64][64];
char orange_pos[64][64];
int cc;
int k;
void rot()
{
  int first_iteration;
  int i;
  int q;
  for (i = 0; i < cc; i++)
    for (q = 0; q < cc; q++)
    orange_pos[(cc - q) - 1][i] = total[i][q];


  for (i = 0; i < cc; i++)
    for (q = 0; q < cc; q++)
    total[i][q] = orange_pos[i][q];


}

void fall()
{
  int first_iteration;
  int i;
  int q;
  int n;
  for (i = 0; i < cc; i++)
  {
    q = cc - 1;
    for (n = cc - 1; n >= 0; n--)
      if (total[n][i] != '.')
      total[q--][i] = total[n][i];


    while (q >= 0)
      total[q--][i] = '.';

  }

}

int ans[] = {1, 1, 0, -1};
int dy[] = {0, 1, 1, 1};
int check(char t)
{
  int first_iteration;
  int i;
  int q;
  int n;
  int no;
  int x;
  int y;
  for (i = 0; i < cc; i++)
    for (q = 0; q < cc; q++)
    if (total[i][q] == t)
  {
    for (n = 0; n < 4; n++)
    {
      for (no = 1; no < k; no++)
      {
        x = i + (ans[n] * no);
        y = q + (dy[n] * no);
        if ((((x < 0) || (y < 0)) || (x >= cc)) || (y >= cc))
          break;

        if (total[x][y] != t)
          break;

      }

      if (no == k)
        return 1;

    }

  }



  return 0;
}

int Main()
{
  int first_iteration;
  int cases;
  int caseno = 1;
  int i;
  int answer;
  scanf("%d", &cases);
  while (cases--)
  {
    scanf("%d %d", &cc, &k);
    for (i = 0; i < cc; i++)
      scanf("%s", total[i]);

    rot();
    rot();
    rot();
    fall();
    answer = check('R') + (2 * check('B'));
    printf("Case #%d: %s\n", caseno++, answer < 2 ? answer ? "Red" : "Neither" : answer > 2 ? "Both" : "Blue");
  }

  return 0;
}


