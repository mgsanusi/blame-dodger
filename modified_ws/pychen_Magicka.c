#include <stdio.h>

#define MAX_N	0x7f
#define MAX_LEN 0x7f
  int
main () 
{
  int t, test_case = 0;
  for (scanf ("%d", &t); t; t--)
    
    {
      int c, d, n, i, j, ans_len;
      char c_str[MAX_N][MAX_LEN];
      char d_str[MAX_N][MAX_LEN];
      char n_str[MAX_LEN];
      char ans_str[MAX_LEN];
       for (scanf ("%d", &c), i = 0; i < c; i++)
	scanf ("%s", &c_str[i]);
      for (scanf ("%d", &d), i = 0; i < d; i++)
	scanf ("%s", &d_str[i]);
      scanf ("%d", &n);
      scanf ("%s", n_str);
       ans_len = 0;
      for (n = 0; n_str[n]; n++)
	
	{
	  ans_str[ans_len] = n_str[n];
	  ans_len++;
	   int combined = 0;
	  if (ans_len > 1)
	    for (i = 0; i < c; i++)
	      if (c_str[i][0] == ans_str[ans_len - 2]
		   && c_str[i][1] == ans_str[ans_len - 1]
		   || c_str[i][1] == ans_str[ans_len - 2]
		   && c_str[i][0] == ans_str[ans_len - 1] )
		
		{
		  ans_str[ans_len - 2] = c_str[i][2];
		  ans_len--;
		  combined = 1;
		  break;
		}
	   int opposed = 0;
	  if (!combined)
	    for (i = 0; i < d; i++)
	      for (j = 0; j < ans_len - 1; j++)
		if (d_str[i][0] == ans_str[ans_len - 1]
		     && d_str[i][1] == ans_str[j]
		     || d_str[i][1] == ans_str[ans_len - 1]
		     && d_str[i][0] == ans_str[j] )
		  
		  {
		    ans_len = 0;
		    opposed = 1;
		    break;
		  }
	}
       test_case++;
      printf ("Case #%d: [", test_case);
      if (!ans_len)
	printf ("]\n");
      
      else
	for (i = 0; i < ans_len; i++)
	  printf ("%c%s", ans_str[i], i == ans_len - 1 ? "]\n" : ", ");
     }
   return 0;
}
