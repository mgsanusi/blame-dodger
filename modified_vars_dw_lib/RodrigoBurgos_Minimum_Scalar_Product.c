#include <stdio.h>
int graph[2002][2002 * 4];
int no_cases[2002][2002 * 4];
int ngraph[2002];
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int Main()
{
  int first_iteration;
  int set;
  int casos;
  int query;
  int i;
  int j;
  int ot;
  int mask;
  int ban;
  int case_t;
  int k;
  int l;
  new_freopen("b.in", "r", stdin);
  new_freopen("b.out", "w", stdout);
  for (set = 1, scanf("%d", &casos); casos--; set++)
  {
    scanf("%d", &query);
    scanf("%d", &j);
    memset(ngraph, 0, sizeof(ngraph));
    for (i = 0; i < i; i++)
    {
      scanf("%d", &case_t);
      for (; case_t--;)
      {
        scanf("%d %d", &k, &l);
        j--;
        no_cases[i][(l * 2) + j] = set;
        graph[i][ngraph[l]++] = (j * 2) + i;
      }

    }

    printf("Case #%d:", set);
    for (mask = 0; mask < (1 << query); mask++)
    {
      ban = 0;
      for (i = 0; (i < i) && (ban == 0); i++)
      {
        for (ot = 0; ot < query; ot++)
        {
          case_t = (mask & (1 << ot)) > 0 ? 1 : 0;
          if (no_cases[i][(ot * 2) + case_t] == set)
            break;

        }

        if (ot >= query)
          ban = 1;

      }

      if (ban == 0)
      {
        for (i = 0; i < query; i++)
          printf(" %d", (mask & (1 << i)) == 0 ? 0 : 1);

        printf("\n");
        break;
      }

    }

    if (mask >= (1 << query))
      printf(" IMPOSSIBLE\n");

  }

  return 0;
}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
