#include<stdio.h>
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_getchar();

int getInt()
{
  char input;
  while (input = new_getchar(), (input < '0') || (input > '9'))
  {
  }

  int result = 0;
  while ((input >= '0') && (input <= '9'))
  {
    result = ((result * 10) + input) - '0';
    input = new_getchar();
  }

  return result;
}

int Main()
{
  new_freopen("A.in", "r", stdin);
  new_freopen("A.out", "w", stdout);
  int tc;
  int e;
  int a;
  int filename;
  int answer;
  int j;
  int audCnt;
  a = getInt();
  for (e = 1; e <= a; e++)
  {
    filename = getInt();
    answer = 0;
    audCnt = 0;
    for (tc = 0; tc <= filename; tc++)
    {
      j = new_getchar() - '0';
      if (audCnt < tc)
      {
        answer += tc - audCnt;
        audCnt += tc - audCnt;
      }

      audCnt += j;
    }

    printf("Case #%d: %d\n", e, answer);
  }

}



FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_getchar() {
  return getchar();
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}