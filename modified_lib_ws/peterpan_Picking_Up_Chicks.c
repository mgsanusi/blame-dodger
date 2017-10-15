#include <stdio.h>
#include <string.h>
FILE *new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int new_strncmp (const char *str1, const char *str2, size_t num);
 int
main (int argc, char *argv[])
{
  FILE * fin, *fout;
  int i, j, tcase, T, N, M, counter, pos;
  char dirs[200][102];
   if (argc > 1)
    fin = new_fopen (argv[1], "r");
  
  else
    fin = new_fopen ("fixit.in", "r");
  if (!fin)
    return 1;
  if (argc > 2)
    fout = new_fopen (argv[2], "w");
  
  else
    fout = new_fopen ("fixit.out", "w");
  if (!fout)
    {
      new_fclose (fin);
      return 1;
    }
  fscanf (fin, "%d", &T);
  for (tcase = 1; tcase <= T; tcase++)
    
    {
      fscanf (fin, "%d", &N);
      fscanf (fin, "%d", &M);
      for (i = 0; i < N; i++)
	fscanf (fin, "%s", dirs[i]);
      for (i = 0; i < M; i++)
	fscanf (fin, "%s", dirs[i + N]);
      counter = 0;
      for (i = N; i < N + M; i++)
	
	{
	  pos = 0;
	  j = 0;
	  while (dirs[i][pos])
	    
	    {
	      pos++;
	      while (dirs[i][pos] && dirs[i][pos] != '/')
		pos++;
	      while (j < i)
		
		{
		  if (new_strncmp (dirs[i], dirs[j], pos) == 0
		       && (dirs[j][pos] == '/' || dirs[j][pos] == 0))
		    break;
		  j++;
		}
	      if (j == i)
		
		{
		  while (dirs[i][pos])
		    
		    {
		      if (dirs[i][pos++] == '/')
			counter++;
		    }
		  counter++;
		  break;
		}
	    }
	}
       fprintf (fout, "Case #%d: %d\n", tcase, counter);
    }
  new_fclose (fin);
  new_fclose (fout);
  return 0;
}

FILE * new_fopen (const char *filename, const char *mode);
int new_fclose (FILE * stream);
int new_fscanf (FILE * stream, const char *format, ...);
int
new_strncmp (const char *str1, const char *str2, size_t num)
{
  return strncmp (str1, str2, num);
}

FILE *
new_fopen (const char *filename, const char *mode)
{
  return fopen (filename, mode);
}

int
new_fclose (FILE * stream)
{
  return fclose (stream);
}
