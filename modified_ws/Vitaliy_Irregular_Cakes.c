#include "stdio.h"
#include "assert.h"

#define myabs(x) ((x) < 0 ? -(x) : (x))

	   double y3)
{
    
	//fprintf (stderr, "%lf\n", x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3);
	//fprintf (stderr, "%lf\n", myabs (x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 - x1 * y3));
	return myabs(x1 * y2 - x2 * y1 + x2 * y3 - x3 * y2 + x3 * y1 -
		     x1 * y3);



#define EPS 1e-12
double poisk(double s, double x, double y1, double y2)
{
    
    
    
	
	
	
	    l = t;
	
	else
	    r = t;
    
    



#define MAXN 1000
int xu[MAXN], yu[MAXN], xl[MAXN], yl[MAXN];


{
    
    
    
    
	
	
	
	
	
	
	    
	
	    
	
	
	
	
	    
		
	    
		
	    
	    
		//fprintf (stderr, "%lf\n", x);
		if (p1 < u && x == xu[p1]) {
		
		
	    
		
		
		    yu[p1 - 1] + (x - xu[p1 - 1]) / (xu[p1] -
						     xu[p1 -
							1]) * (yu[p1] -
							       yu[p1 - 1]);
	    
	    
		
		
	    
		
		
		
		    yl[p2 - 1] + (x - xl[p2 - 1]) / (xl[p2] -
						     xl[p2 -
							1]) * (yl[p2] -
							       yl[p2 - 1]);
	    
	    
		
		
		
		
		    //ss[cc] = sq (xx, yyu, x, tyu, x, tyl) + sq (xx, yyu, x, tyl, xx, yyl);
		    cc++;
	    
		
		
		
		
	    
	    
		//fprintf (stderr, "> %lf %lf %lf %lf %lf\n", x1[cc - 1], ss[cc - 1], y1[cc - 1], tyu, tyl);
		xx = x;
	    
	    
	
	
	
	
	
	
	    
		cur++;
	    
		
		
	    
		
		    //fprintf (stderr, "!!\n");
		    printf("%lf\n",
			   x1[cur - 1] + poisk(s - ss[cur - 1],
					       x1[cur] - x1[cur - 1],
					       y1[cur - 1], y1[cur]));
		
	    
	
    
    


