#include <stdio.h>
#include <string.h>
#include <stddef.h>



void *new_memset(void *ptr, int value, size_t num);

{
	
	
	


0, 0, -1};


{
	
	
	
	
	
	
	
	
	q[qe++] = aty;
	
		
		cy = q[qs++];
		
			
			y2 = cy + dy[d];
			
				continue;
			
				continue;
			
			
			q[qe++] = y2;
			
		
	
	



{
	
	
		if (mask & (1ULL << i))
			r++;
	





#define MAXHASH 100000007
int maxhash = MAXHASH;



#define GETHASH(key) key%maxhash
#define HASHBIT(pos) (hash[pos>>3]&(1<<(pos&7)))

{
	
	
		
			return 0;
		
			return 1;
		
		if (pos == maxhash)
			pos = 0;
	



{
	
	
		
			break;
		
			break;
		
		if (pos == maxhash)
			pos = 0;
	
	



{
	
	
	

{
	





{
	
	
	
		for (j = 0; j < y; j++)
			if (cave + 48 == s[i][j])
				goal = 1ULL << calc64(i, j);
	
		return 1;
	
	
//      printf("cave %d goal %I64u\n",cave,goal);
	    inithashdata();
	
	
	
		
		
//              printf("pop %I64u\n",cur);
		    for (d = 0; d < 3; d++) {
			
			
				if (cur & (1ULL << b)) {
					
					
					
						l--;
					
					else if (d == 1)
						l++;
					
					else if (d == 2)
						k++;
					
						k = i, l = j;
					
				
			
//                      printf("  dir %d, visit %I64u\n",d,next);
			    if ((~start) & next)
				continue;
			
				continue;
			
				return 1;
			
//                      printf("  push %I64u\n",next);
			    q[qe++] = next;
			
		
	
	



{
	
	
	
	
		
		
			scanf("%s", s[i]);
		
		
			
				for (j = 0; j < y; j++)
					if (s[i][j] == 48 + cave)
						goto found;
			
 
			
			
				r ? "Lucky" : "Unlucky");
		
	
	



{
	return memset(ptr, value, num);
}