#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NEAR(Z,Y) ((Z)<(Y)&&(Z)>-(Y))
#define ABSOL(A) ((A)>=0?(A):-(A))
double new_sqrt(double x);

{
	int c;
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

char room[32][32];
int raytrace(const int a, const int b, int x, int y, const int dist)
{
	int path[128][2], npath, ix, iy, c, d, refx, refy;
	
	
		int c;
		for (c = 0; room[x + c * a][y] != '#'; c++) ;
		return c * 2 - 1 <= dist;
	}
	if (a == 0) {
		int c;
		for (c = 0; room[x][y + c * b] != '#'; c++) ;
		return c * 2 - 1 <= dist;
	}
	
	
	
		npath--;
	
	
	for (c = 0; c < npath; c++) {
		
		
		
		
		
		
		
			iscorner = 1;
		
		else
			iscorner = 0;
		
			fprintf(stderr, "corner\n");
		
			
			
				py += ((ix + (a > 0) - px) / a) * b;
			
		
		
			
			
				px += ((iy + (b > 0) - py) / b) * a;
			
		
		
			fprintf(stderr, "t1t2error\n");
		
		
	
	
	
		
			
			
			
			
				
					goto loopfinish;	/*through */
				
				     && room[x][y + dy] != '#')
					return 0;	/*destroy */
			
			
				
				
			
			
				
				
			
 
			
		
		
			return 1;
	
	return 0;
}

int main(int argc, char *argv[])
{
	int a, b, d, e, dist, h, w, x, y, count;
	scanf("%d", &e);
	for (d = 1; d <= e; d++) {
		scanf("%d%d%d", &h, &w, &dist);
		x = y = -1;
		for (a = 0; a < h; a++) {
			scanf("%s", room[a]);
			for (b = 0; x == -1 && b < w; b++) {
				if (room[a][b] != 'X')
					continue;
				x = a;
				y = b;
			}
		}
		count = 0;
		for (a = -dist; a <= dist; a++) {
			for (b = -dist; b <= dist; b++) {
				if (a == 0 && b == 0)
					continue;
				if (a * a + b * b > dist * dist)
					continue;
				if (gcd(a, b) != 1)
					continue;
				count += raytrace(a, b, x, y, dist);
			}
		}
		printf("Case #%d: %d\n", d, count);
	}
	return 0;
}

double new_sqrt(double x)
{
	return sqrt(x);
}