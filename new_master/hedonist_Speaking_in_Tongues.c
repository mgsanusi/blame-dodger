#include <stdio.h>

int main() 
{
	int T,i,j;
	char s[200];
	char map[26] = 
	{'y', 'h', 'e', 's', 'o', 'c', 'v',
	 'x', 'd', 'u', 'i', 'g', 'l', 'b',
	 'k', 'r', 'z', 't', 'n', 'w',
	 'j', 'p', 'f', 'm', 'a', 'q'};	
	// m q v
	scanf("%d", &T);
	for (i=0; i<T; i++)
	{
		printf("Case #%d: ", i+1);
		gets(s);
		while (s[0] == '\0') gets(s);
		j=0; 
		while (s[j] != '\0') {
			if (s[j]==' ') 
				printf(" ");
			else
				printf("%c", map[s[j]-'a']);
			j++;
		}
		printf("\n");
	}
	return 0;
}