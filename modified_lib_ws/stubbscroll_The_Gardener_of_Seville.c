#include <stdio.h>


int new_putchar(int character);
int new_puts(const char *str);

{
	
		*x2 = p, *y2 = 0, *dx = 0, *dy = 1;
		return;
	}
	
	
		*x2 = x - 1, *y2 = p, *dx = -1, *dy = 0;
		return;
	}
	
	
		*x2 = x - p - 1, *y2 = y - 1, *dx = 0, *dy = -1;
		return;
	}
	
	
	*y2 = y - p - 1;
	*dx = 1;
	*dy = 0;



{
	
	
		
		
		do {
			
				dy = -dx, dx = 0;
			
			else if (dx && g[y2][x2] == '\\')
				dy = dx, dx = 0;
			
			else if (dy && g[y2][x2] == '/')
				dx = -dy, dy = 0;
			
			else if (dy && g[y2][x2] == '\\')
				dx = dy, dy = 0;
			
			y2 += dy;
		
		
			out = x2;
		
		else if (x2 == x)
			out = y2 + x;
		
		else if (y2 == y)
			out = x + y + x - x2 - 1;
		
		else
			out = x + y + x + y - y2 - 1;
		
			return 0;
	
	



{
	
	
	
	
	
		scanf("%d", &par[i]), par[i]--;
	
		
			if (mask & (1 << i))
				g[i % y][i / y] = '/';
		
			else
				g[i % y][i / y] = '\\';
		
			
				
					new_putchar(g[i][j]);
				
			
			
		
	
	



{
	
	
	
		printf("Case #%d:\n", caseno++), solve();
	



int new_puts(const char *str)
{
	return puts(str);
}

int new_putchar(int character)
{
	return putchar(character);
}