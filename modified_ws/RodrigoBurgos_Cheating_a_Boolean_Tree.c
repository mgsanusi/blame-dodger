#include <stdio.h>
#include <string.h>









{
	
	
		
			
				
				
				
			



{
	
		return 1;
	



{
	
	    //printf("{%d %d}", x, y);
	    if (x < 0 || y < 0 || x >= n || y >= m)
		return;
	
	    //  printf("{-- %d %d, %d %d}", x, y, x + dx[ dir ], y + dy[ dir]);
	    if (sale(x + dx[dir], y + dy[dir])) {
		
		    //    printf("%d %d <-", x, y );
		    *a = position[x][y][dir][0] = x;
		
		
	
	
		
		    //  printf("**");
		    *a = position[x][y][dir][0];
		
		
	
	
	
	



	       int length)
{
	
		return;
	
		return;
	
		return;
	
	    // printf("{%d %d %d %d %d %d %d\n", yx, yy, bx, by,x, y, length);
	    if (vis[yx][yy][bx][by][x][y] == set)
		
	
	
	
	
	
	
	
	
	



{
	
	
	
	
		
		
			scanf("%s", mapa[x]);
		
		
			
				
					continue;
				
					
					
					    //    printf("[%d %d %d, %d %d]\n", x, y, dir, a, b);
					    //     while(1);
				}
			
		
		    //  while(1);
		    //  printf("****\n");
		    find('O', &a, &b);
		
		
		
		
			
				
				
			
			
				
				
				
				
				
				
				
					
					
				
				
				    //  if( len  <= 2 && ( x >= 4 && y >= 0 ))
				    //  printf("%d %d | %d %d %d %d %d , %d\n", x, y, yx, yy, bx, by, len , nq[ len % 2]);
				    for (dir = 0; dir < 4; dir++) {
					
						position[x][y][dir][0],
						position[x][y][dir][1], bx, by,
						x, y, len);
					
						yy, position[x][y][dir][0],
						position[x][y][dir][1], x, y,
						len);
				
				
					
					    //   printf("*");
					    insert((len + 1) % 2,
						   &nq[(len + 1) % 2], yx, yy,
						   bx, by, bx, by, len + 1);
				
				
					
					    // printf(".");
					    insert((len + 1) % 2,
						   &nq[(len + 1) % 2], yx, yy,
						   bx, by, yx, yy, len + 1);
				
				
					
						&nq[(len + 1) % 2], yx, yy, bx,
						by, x + dx[dir], y + dy[dir],
						len + 1);
				
				    //  printf("_----------\n");
			}
			
				break;
			
		
	
	


