char line[10000];
int vis[100];
int path[100];
int t;
int length;
int min(int k, int fileNameOut)
{
  return k < fileNameOut ? k : fileNameOut;
}

int perm(int level)
{
  int m;
  int cont = 0;
  int p;
  char ant;
  int result = 1 << 22;
  if (level == t)
  {
    ant = ' ';
    for (m = 0; m < length; m++)
    {
      p = m / t;
      if (line[((p * t) + path[m % t]) - 1] != ant)
      {
        cont++;
        ant = line[((p * t) + path[m % t]) - 1];
      }

    }

    return cont;
  }

  for (m = 1; m <= t; m++)
  {
    if (vis[m] == 1)
      continue;

    vis[m] = 1;
    path[level] = m;
    result = min(result, perm(level + 1));
    vis[m] = 0;
  }

  return result;
}

int Main()
{
  int casos;
  int set;
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
  for (scanf("%d", &casos), set = 1; set <= casos; set++)
  {
    scanf("%d", &t);
    scanf("%s", line);
    length = strlen(line);
    printf("Case #%d: %d\n", set, perm(0));
  }

  return 0;
}


