#include <stdio.h>
#include <string.h>

#define MAX 5000
#define MAX2 12000000
int dp[11][MAX2];


{
	
		dp[base][num] = 1;
	



{
	
 
	
		d = num % base, num /= base, sum += d * d;
	
		return 1;
	
		return dp[base][sum];
	
		return 0;
	
	
	




{
	
	
	
	
	
		
//      if(base==4) continue;
//   for(base=7;base<8;base++) {
		    for (i = 2; i < MAX2; i++) {
			
			
			
//         if(dp[base][i]==1) printf("base %d happy: %d\n",base,i);
		}
	
	
	
	
		
		
		
			if (s[i] >= '2'
			    && s[i] <= '9' /*&& s[i]!=4 && s[i]!=2 */ )
				bases[bn++] = s[i] - '0';
		
			else if (s[i] == '1')
				bases[bn++] = 10;
		i++;
		
			
				if (!dp[bases[i]][ans])
					goto neste;
			
 
		
		
	
	


