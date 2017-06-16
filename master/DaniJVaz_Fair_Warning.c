/* Compiled with MinGW */

#include <stdio.h>

void doTestCase();
unsigned long long gcd (unsigned long long a,unsigned long long b);
unsigned long long gcdF (unsigned long long a,unsigned long long b);

int main(){
	int i,n;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		printf("Case #%d: ",i);
		doTestCase();
	}
	return 0;
}

void doTestCase(){
	int n,i,t;
	scanf("%d",&n);
	
	unsigned long long arr[n];
	unsigned long long diff[n-1];
	unsigned long long g;
	unsigned long long min;
	
	/* If T divides all numbers + y, it divides the differences, which are the difference between the numbers*/
	/* Then, it's enough to find the gcd of the differences and from there it's easy to get y*/
	
	for (i=0;i<n;i++){
		scanf("%llu",&arr[i]);
		
		if (i>0){
			if (arr[i]>arr[i-1])
				diff[i-1]=arr[i]-arr[i-1];
			else
				diff[i-1]=arr[i-1]-arr[i];
				
			min=(arr[i]<min)?arr[i]:min;
		}
		else
			min=arr[0];
	}
		
	g=diff[0];
	for (i=1;i<n-1;i++){
		g=gcd(g,diff[i]);
	}
	//printf("%llu\n",g);
	min=min%g;
	if (min!=0)
		min=g-min;
	printf("%llu\n",min);
		
}

unsigned long long gcd (unsigned long long a,unsigned long long b){
	if (a<b)
		return gcdF(b,a);
	else if (a==b)
		return a;
	else
		return gcdF(a,b);
}

unsigned long long gcdF (unsigned long long a,unsigned long long b){
	if (b==0)
		return a;
	return gcd(b,a%b);
}
