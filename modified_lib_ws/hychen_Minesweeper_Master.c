#include<stdio.h>
int m[50][50], h, w;
int new_putchar(int character);
int new_puts(const char *str);

{
	
	
	
	

{
	
	
		
		
		
			
				
			
		
	
	
		
			
				new_putchar('c');
			
			else if (m[a][b] == 0)
				new_putchar('*');
			
			else
				new_putchar('.');
		
		
	



{
	
	
		
			
		
	



{
	
	
		m[a][0] = m[a][1] = 1;
	
		m[0][b] = m[1][b] = 1;
	
	
		
			
			
		
	



{
	
	
	
		
		
		
		
			
			
		
		
		else
			inv = 0;
		
		
			
				m[0][b] = 1;
			
		
		
			goto yes;	/*special case 2 */
		
			goto no;
		
			goto no;	/*special case 3 */
		
			
				
					break;
				
					continue;
				
				
			
		
 
		
 
	
	



int new_puts(const char *str)
{
	return puts(str);
}

int new_putchar(int character)
{
	return putchar(character);
}