#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-10
void doubleIntSort(double d[], int m[], int s)
{
	int i, j, r;
	double k1, k2, t;
	if (s <= 1)
		return;
	k1 = (d[0] + d[s - 1]) / 2.0;
	k2 = k1 + EPS;
	k1 -= EPS;
	i = -1;
	j = s;
	for (;;) {
		while (d[++i] < k1) ;
		while (d[--j] > k2) ;
		if (i >= j)
			break;
		t = d[i];
		d[i] = d[j];
		d[j] = t;
		r = m[i];
		m[i] = m[j];
		m[j] = r;
	}
	doubleIntSort(d, m, i);
	doubleIntSort(d + j + 1, m + j + 1, s - j - 1);
}


{
	
	
	
	
	
	
	
	int ind[1200];
	
	
	
	
		
		
		
		
		
		
			
			
		
		
		
		
		
		
		
		
			
			
			
			
				need = run_time;
			
			
			
			
			
		
		
	
	


