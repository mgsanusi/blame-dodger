#include <stdio.h>
char s[5][5];

{
	
	
	
		
			scanf("%s", s[i]);
		
		
			
			
				
					f &= 3;
				
				else if (s[i][j] == 'O')
					f &= 2;
				
				else if (s[i][j] == 'X')
					f &= 1;
				
				else if (s[i][j] == '.') {
					f = 0;
					f1 = 0;
				}
			
			
				goto END;
		
		
			
			
				
					f &= 3;
				
				else if (s[i][j] == 'O')
					f &= 2;
				
				else if (s[i][j] == 'X')
					f &= 1;
				
				else if (s[i][j] == '.') {
					f = 0;
					f1 = 0;
				}
			
			
				goto END;
		
		
		
			
				f &= 3;
			
			else if (s[i][i] == 'O')
				f &= 2;
			
			else if (s[i][i] == 'X')
				f &= 1;
			
			else if (s[i][i] == '.') {
				f = 0;
				f1 = 0;
			}
		
		
			goto END;
		
		
			
				f &= 3;
			
			else if (s[i][3 - i] == 'O')
				f &= 2;
			
			else if (s[i][3 - i] == 'X')
				f &= 1;
			
			else if (s[i][3 - i] == '.') {
				f = 0;
				f1 = 0;
			}
		
 
		
			puts("O won");
		
		else if (f == 1)
			puts("X won");
		
		else if (f1 == 1)
			puts("Draw");
		
		else
			puts("Game has not completed");
	
	
