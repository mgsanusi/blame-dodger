double h[201];
struct sortt
{
  int id;
  double tmp;
} res[201];
int loops[201];
void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*));

int cmp(const void *a, const void *b)
{
  double m = ((struct sortt *) a)->tmp;
  double bb = ((struct sortt *) b)->tmp;
  if (m > bb)
    return -1;
  else
    if (m < bb)
    return 1;


  return 0;
}

int Main()
{
  int d;
  int p;
  scanf("%d", &d);
  for (p = 1; p <= d; p++)
  {
    int y;
    scanf("%d", &y);
    int rqVers;
    int k = 0;
    for (rqVers = 0; rqVers < y; rqVers++)
    {
      scanf("%d", loops + rqVers);
      k += loops[rqVers];
    }

    printf("Case #%d: ", p);
    for (rqVers = 0; rqVers < y; rqVers++)
    {
      h[rqVers] = ((double) loops[rqVers]) / ((double) k);
      res[rqVers].id = rqVers;
      res[rqVers].tmp = h[rqVers];
    }

    new_qsort(res, y, sizeof(struct sortt), cmp);
    for (rqVers = 0; rqVers < y; rqVers++)
    {
      int counter;
      double tmp = 2.0;
      for (counter = 0; counter < y; counter++)
      {
        if ((tmp / ((double) (y - counter))) >= res[counter].tmp)
          break;

        tmp -= res[counter].tmp;
      }

      double ans = (tmp / ((double) (y - counter))) - h[rqVers];
      printf("%lf ", ans > 0 ? ans * 100.0 : 0.0);
    }

    printf("\n");
  }

  return 0;
}



void new_qsort(void* base, int num, int size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
