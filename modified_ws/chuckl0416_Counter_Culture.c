#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>





{
	
		
		
			for (x = 1; x < C; x++)
				if (Map[y][x - 1])
					if (Map[y][x])
						Ans++;
		
			for (y = 1; y < R; y++)
				if (Map[y - 1][x])
					if (Map[y][x])
						Ans++;
		
			FAns = Ans;
		
	
	
		
		
	
	
		return;
	
	
	
	
	



{
	
	
	
	
		
		
		
		
			for (x = 0; x < C; x++)
				Map[y][x] = 1;
		
		
			for (x = 0; x < C; x++)
				DFS(0, y, x);
		
	
	


