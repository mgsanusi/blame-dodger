#include <stdio.h>

int main() 
{
	long T,A,B,i,c,n,m,ten;

	scanf("%ld", &T);
	for (i=0; i<T; i++)
	{
		printf("Case #%ld: ", i+1);
		scanf("%ld %ld", &A, &B);
		c = 0;
		ten = 1;
		while (ten*10<=A) ten = ten*10;
		for (n=A; n<B; n++)
		{
			m = n;
			do {
				//printf("m=%ld\n",m);
				m = (m%10)*ten+m/10;
				if ((m>n)&&(m<=B)) c++;
			} while (n!=m);
		}
		printf("%ld\n",c);
	}
	return 0;
}