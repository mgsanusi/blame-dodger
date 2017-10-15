#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int Main(int argc, char **argv, char **envp)
{
  int file = open(argv[1], O_RDONLY);
  size_t size = lseek(file, 0, 2);
  unsigned char *mem = malloc(size);
  lseek(file, 0, 0);
  read(file, mem, size);
  close(file);
  unsigned int s = 0;
  while (s < size)
  {
    if (mem[s] == 0x0a)
    {
      mem[s] = 0x00;
    }

    if (mem[s] == 0x20)
    {
      mem[s] = 0x00;
    }

    s++;
  }

  unsigned int cases = atoi(mem);
  s = strlen(mem) + 1;
  fprintf(stderr, "Cases: %u\n", cases);
  unsigned int i;
  unsigned int min;
  unsigned int hot_flow;
  unsigned char cdel[256 * 256];
  unsigned char ddel[256 * 256];
  unsigned char dels[256];
  unsigned int mintime;
  unsigned int smax;
  unsigned char lst[101];
  unsigned int length;
  unsigned char exist[256];
  unsigned int case_t = 0;
  while (case_t < cases)
  {
    i = atoi(mem + s);
    s += strlen(mem + s) + 1;
    bzero(cdel, 256 * 256);
    mintime = 0;
    while (mintime < i)
    {
      cdel[(mem[s] * 256) + mem[s + 1]] = mem[s + 2];
      cdel[(mem[s + 1] * 256) + mem[s]] = mem[s + 2];
      s += strlen(mem + s) + 1;
      mintime++;
    }

    min = atoi(mem + s);
    s += strlen(mem + s) + 1;
    bzero(ddel, 256 * 256);
    bzero(dels, 256);
    mintime = 0;
    while (mintime < min)
    {
      ddel[(mem[s] * 256) + dels[mem[s]]] = mem[s + 1];
      ddel[(mem[s + 1] * 256) + dels[mem[s + 1]]] = mem[s];
      dels[mem[s]]++;
      dels[mem[s + 1]]++;
      s += strlen(mem + s) + 1;
      mintime++;
    }

    hot_flow = atoi(mem + s);
    s += strlen(mem + s) + 1;
    bzero(exist, 256);
    bzero(lst, 101);
    length = 0;
    mintime = 0;
    while (mintime < hot_flow)
    {
      if (length != 0)
      {
        if (cdel[(lst[length - 1] * 256) + mem[s + mintime]] != 0)
        {
          exist[lst[length - 1]]--;
          lst[length - 1] = cdel[(lst[length - 1] * 256) + mem[s + mintime]];
          lst[length] = 0x00;
        }
        else
          if (dels[mem[s + mintime]] > 0)
        {
          smax = 0;
          while (smax < dels[mem[s + mintime]])
          {
            if (exist[ddel[(mem[s + mintime] * 256) + smax]] > 0)
            {
              length = 0;
              lst[length] = 0x00;
              bzero(exist, 256);
              break;
            }

            smax++;
          }

          if (smax == dels[mem[s + mintime]])
          {
            goto a;
          }

        }
        else
        {
          a:
          lst[length] = mem[s + mintime];

          exist[mem[s + mintime]]++;
          length++;
          lst[length] = 0x00;
        }


      }
      else
      {
        lst[length] = mem[s + mintime];
        exist[mem[s + mintime]]++;
        length++;
        lst[length] = 0x00;
      }

      mintime++;
    }

    s += strlen(mem + s) + 1;
    printf("Case #%u: [", case_t + 1);
    mintime = 0;
    while (mintime < length)
    {
      if (mintime != 0)
      {
        printf(", ");
      }

      printf("%c", (char) lst[mintime]);
      mintime++;
    }

    printf("]\n");
    case_t++;
  }

  return 0;
}


