#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<assert.h>



	
	

double new_sqrt(double x);
void new_assert(int expression);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));

{
	
	
		return (c->ang < d->ang ? 1 : -1);
	



#define CROSS(A,B,C,D) ((A)*(D)-(B)*(C))
#define DOT(A,B,C,D) ((A)*(C)+(B)*(D))
#define DIS(A,B) new_sqrt(DOT(A,B,A,B))
double computeang(double x, double y, double x0, double y0)
{
	
	
	
		ang = -1 - ang;
	
	else
		ang += 1;
	



{
	
	
	
		
		
			
		
		
		
			
				puts("0");
			
		
		
			
			
			
				
					continue;
				
				
				    
						p_[b][1] - pa[1], 0, 1);
				
			
			
			
				
			
			
/*
      for(b=0;b<c;b++){
      printf(" %.2lf %.0lf %.0lf  %.0lf %.0lf\n"
      ,p[b].ang,p_[a][0],p_[a][1],p[b].coor[0],p[b].coor[1]
      );}
*/ 
			int ans = 100000;
			
			
				
					
						prev = b;
				
				
				else {
					
				
				
					
					     (
					      p[next].coor[1] - pa[1],
					      
					      p[b].coor[1] - pa[1]) < 0)
						
					
				
				
					
					
				
				
				
					    (
					     p[next - 1].coor[1] - pa[1],
					     
					     p[b].coor[1] - pa[1]) >= 0 
				
				
					ans = ans2;
			
			
		
	
	



void new_assert(int expression);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
	return qsort(base, num, size, compar);
}

double new_sqrt(double x);
void new_assert(int expression)
{
	return assert(expression);
}

double new_sqrt(double x)
{
	return sqrt(x);
}