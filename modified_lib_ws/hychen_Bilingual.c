#include<stdio.h>
#include<stdlib.h>
#define NEAR2(A,B) ((A)+1e-18>(B)&&(B)+1e-18>(A))
#define NEAR(A,B) ((A)==(B))
int new_puts(const char *str);
void new_exit(int status);

{
	



{
	






{
	
	
	
	
		
		
			
		
		
		
		
			
				goto impo;
			
		
		
		else {
			
				goto impo;
			
			
			
			
			
			     (NEAR(c[0], x) && NEAR(c[1], x))) {
				
					printf("%.18lf\n", d, r[0], c[0], r[1],
					       c[1]);
					new_exit(-1);
				}
				
			
			
			else {
				
					printf("error2");
					new_exit(-1);
				}
				
//if(NEAR(dx/d*r[0]*c[0]+dy/d*r[1]*c[1],v*x)==0){new_puts("error3");new_exit(-1);}
				    ans = doublemax(dx / d, dy / d);
			
		
		
		
 
	
	



void new_exit(int status)
{
	return exit(status);
}

int new_puts(const char *str)
{
	return puts(str);
}