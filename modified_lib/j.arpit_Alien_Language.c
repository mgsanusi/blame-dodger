#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stddef.h>

char buffer[10000] ;
char dict[5010][20] ;
int fc, flag[5010], f[5010] ;
int L, D, N ;
void * new_memset(void *ptr, int value, size_t num);

int new_getchar();


void get_dict()
{
    int d ;
    for (d = 0 ; d < D ; ++d) gets(dict[d]) ;
}

/* void elim_dict(int l, char c) */
/* { */
/*     int d ; */
/*     for (d = 0 ; d < D ; ++d) */
/*     { */
/* 	if (flag[d] == 0) */
/* 	{ */
/* 	    if (dict[d][l] != c) */
/* 	    { */
/* 		flag[d] = 1 ; */
/* 		--fc ; */
/* 	    } */
/* 	} */
/*     } */
/* } */

int main()
{
    int n, l, d ;
    char c ;
    gets(buffer) ;
    //    L = D = N = 0 ;
    sscanf(buffer, "%d %d %d", &L, &D, &N) ;
    //    printf("%d %d %d\n", L, D, N) ;
    get_dict() ;
    for (n = 1 ; n <= N ;++n)
    {
	new_memset(flag, 0, sizeof(flag)) ;
	fc = D ;
/* 	gets(buffer) ; */
/* 	printf("%s\n", buffer) ; */
	for (l = 0 ; (c = new_getchar()) != '\n' && l < L ; ++l)
	{
	    if (c == '(')
	    {
		new_memset(f, 0, sizeof(f)) ;
		while((c = new_getchar()) != ')')
		{
		    for (d = 0 ; d < D ; ++d)
		    {
			if (flag[d] == 0 && dict[d][l] == c)
			{
			    f[d] = 1 ;
			}
		    }
		}
		for (d = 0 ; d < D ; ++d)
		{
		    if (flag[d] == 0 && f[d] == 0)
		    {
			flag[d] = 1 ;
			--fc ;
		    }
		}
	    }
	    else
	    {
		for (d = 0 ; d < D ; ++d)
		{
		    if (flag[d] == 0 && dict[d][l] != c)
		    {
			flag[d] = 1 ;
			--fc ;
		    }
		}
	    }
	}
	printf("Case #%d: %d\n", n, fc) ;
    }
    return 0 ;
}

void * new_memset(void *ptr, int value, size_t num);

int new_getchar() {
  return getchar();
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}