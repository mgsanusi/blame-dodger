#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
int
Main (int argc, char **argv, char **envp)
{
  int file = open (argv[1], O_RDONLY);
  size_t size = lseek (file, 0, 2);
  unsigned char *mem = malloc (size);
  lseek (file, 0, 0);
  read (file, mem, size);
  close (file);
  unsigned int str = 0;
  while (str < size)
    {
      if (mem[str] == 0x0a)
	{
	  mem[str] = 0x00;
	}
      if (mem[str] == 0x20)
	{
	  mem[str] = 0x00;
	}
      str++;
    }
  unsigned int cases = atoi (mem);
  str = strlen (mem) + 1;
  fprintf (stderr, "Cases: %u\n", cases);
  unsigned int bpos;
  double exp[1001];
  exp[2] = 2.0;
  unsigned int point;
  double facs[1001];
  facs[0] = 1.0;
  facs[1] = 1.0;
  facs[2] = 2.0;
  double j = 2.0;
  double temp;
  double t = 2.7182818284590452353602874713526624977572;
  bpos = 3;
  while (bpos < 1001)
    {
      j = j * ((double) bpos);
      facs[bpos] = j;
      temp = 0;
      point = 2;
      while (point < bpos)
	{
	  temp +=
	    (floor ((facs[point] / t) + 0.5) /
	     (facs[point] * facs[bpos - point])) * exp[point];
	  point++;
	}
      temp += 1.0;
      temp /= 1.0 - (floor ((facs[bpos] / t) + 0.5) / facs[bpos]);
      exp[bpos] = temp;
      bpos++;
    }
  unsigned int din;
  unsigned int wrong;
  unsigned int caseT = 0;
  while (caseT < cases)
    {
      din = atoi (mem + str);
      str += strlen (mem + str) + 1;
      wrong = 0;
      bpos = 0;
      while (bpos < din)
	{
	  if (atoi (mem + str) != (bpos + 1))
	    {
	      wrong++;
	    }
	  str += strlen (mem + str) + 1;
	  bpos++;
	}
      printf ("Case #%u: %lf\n", caseT + 1, exp[wrong]);
      caseT++;
    }
  return 0;
}
