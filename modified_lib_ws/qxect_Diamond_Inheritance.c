#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>




time_t new_time(time_t * timer);
int new_rand();
double new_sqrt(double x);
double new_fabs(double x);
void new_snew_rand(unsigned int seed);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *));

{
    
    



{
    
    
    
	
	    
	    
	    
	    
	    
	    
	    
		new_sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
	    
		/*
		   printf("disT %lf disN %lf\n",disT,disN);
		 */ 
		if (new_fabs(disN - disT) > 1e-7 && disT > disN)
		return 0;
	
    
    



{
    
    
    
    
    
    
    
	
	
	    
	    
	
	
	
	    
		
		
		
		
		
	    
	    
		break;
	
	
	
	    printf(" %.1lf %.1lf", x[i], y[i]);
	
    
    



int new_rand();
double new_sqrt(double x);
double new_fabs(double x);
void new_snew_rand(unsigned int seed);
void new_qsort(void *base, size_t num, size_t size,
	       int (*compar) (const void *, const void *))
{
    return qsort(base, num, size, compar);
}

time_t new_time(time_t * timer);
int new_rand();
double new_sqrt(double x);
double new_fabs(double x);
void new_snew_rand(unsigned int seed)
{
    return snew_rand(seed);
}

time_t new_time(time_t * timer);
int new_rand();
double new_sqrt(double x);
double new_fabs(double x)
{
    return fabs(x);
}

time_t new_time(time_t * timer);
int new_rand();
double new_sqrt(double x)
{
    return sqrt(x);
}

time_t new_time(time_t * timer)
{
    return time(timer);
}

int new_rand()
{
    return rand();
}