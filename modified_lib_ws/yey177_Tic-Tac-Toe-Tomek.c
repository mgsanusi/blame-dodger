#include <stdio.h>
char s[5][5];
int new_puts(const char *str);

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
	
      
	
	    new_puts("O won");
	
	else if (f == 1)
	    new_puts("X won");
	
	else if (f1 == 1)
	    new_puts("Draw");
	
	else
	    new_puts("Game has not completed");
    
    


int new_puts(const char *str)
{
    return puts(str);
}