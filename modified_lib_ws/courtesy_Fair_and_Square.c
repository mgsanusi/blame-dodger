#include<stdio.h>
#include<math.h>
typedef long long ll;
FILE *new_freopen(const char *filename, const char *mode, FILE * stream);
double new_sqrt(double x);
int palin(ll n) 
{
	int a[20], i, j, k;
	for (i = 0; n > 0; i++, n /= 10)
		a[i] = n % 10;
	for (i--, j = 0; i > j; i--, j++)
		 {
		if (a[i] != a[j])
			return 0;
		}
	return 1;
}

int main() 
{
	new_freopen("C:\\Users\\vivek\\Desktop\\in.txt", "r", stdin);
	new_freopen("C:\\Users\\vivek\\Desktop\\out.txt", "w", stdout);
	 int i, j, k, t, cs, a, b, l;
	scanf("%d", &cs);
	for (t = 1; t <= cs; t++)
		 {
		scanf("%d %d", &a, &b);
		l = new_sqrt(b);
		for (i = sqrt(a), k = 0; i <= l; i++)
			 {
			if (palin(i))
				 {
				j = i * i;
				if ((j >= a) && (j <= b) && palin(j))
					k++;
				}
			}
		printf("Case #%d: %d\n", t, k);
		}
	return 0;
}

FILE * new_freopen(const char *filename, const char *mode, FILE * stream);
double new_sqrt(double x)
{
	return sqrt(x);
}

FILE *new_freopen(const char *filename, const char *mode, FILE * stream)
{
	return freopen(filename, mode, stream);
}
