#include <stdio.h>
#include <assert.h>
#include <string.h>
char x[4][5];
char check(int x1, int total, int k, int file_name_out, int x3, int res, int len, int tn)
{
  int first_iteration;
  if (((((x[x1][total] == 'X') || (x[x1][total] == 'T')) && ((x[k][file_name_out] == 'X') || (x[k][file_name_out] == 'T'))) && ((x[x3][res] == 'X') || (x[x3][res] == 'T'))) && ((x[len][tn] == 'X') || (x[len][tn] == 'T')))
  {
    return 'X';
  }

  if (((((x[x1][total] == 'O') || (x[x1][total] == 'T')) && ((x[k][file_name_out] == 'O') || (x[k][file_name_out] == 'T'))) && ((x[x3][res] == 'O') || (x[x3][res] == 'T'))) && ((x[len][tn] == 'O') || (x[len][tn] == 'T')))
  {
    return 'O';
  }

  return 0;
}

void solve(void)
{
  int first_iteration;
  int d = 0;
  while (d < 4)
  {
    assert(scanf("%s\n", x[d]) >= 1);
    assert(strlen(x[d]) == 4);
    d++;
  }

  int file_header_html;
  int ss;
  for (file_header_html = 0; file_header_html < 4; file_header_html++)
  {
    char t = check(file_header_html, 0, file_header_html, 1, file_header_html, 2, file_header_html, 3);
    if (t)
    {
      printf("%c won\n", t);
      return;
    }

    t = check(0, file_header_html, 1, file_header_html, 2, file_header_html, 3, file_header_html);
    if (t)
    {
      printf("%c won\n", t);
      return;
    }

  }

  char t = check(0, 0, 1, 1, 2, 2, 3, 3);
  if (t)
  {
    printf("%c won\n", t);
    return;
  }

  t = check(0, 3, 1, 2, 2, 1, 3, 0);
  if (t)
  {
    printf("%c won\n", t);
    return;
  }

  for (file_header_html = 0; file_header_html < 4; file_header_html++)
    for (ss = 0; ss < 4; ss++)
    if (x[file_header_html][ss] == '.')
  {
    printf("Game has not completed\n");
    return;
  }



  printf("Draw\n");
}

int Main()
{
  int first_iteration;
  int try;
  assert(scanf("%d\n", &try) > 0);
  int r;
  for (r = 0; r < try; r++)
  {
    printf("Case #%d: ", r + 1);
    solve();
  }

  return 0;
}


