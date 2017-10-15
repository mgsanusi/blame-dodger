#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TC, T;
long long int N, L;
char Input[100];
long long int A[200];
long long int B[200];
long long int Try[200];
long long int i, x, y, C, FAns, Mask, Sx, Sy;


long long
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*));
 int Transfer(char In[]){
	long long int Ans, x;
	Ans = 0;
	for (x=0; x<L; x++){
		Ans *= 2;
		Ans += (In[x]=='1');
	}
	return Ans;
}

long long int Decode(long long int x){
	long long int Ans = 0;
	while(x){
		if (x&1) Ans++;
		x /= 2;
	}
	return Ans;
}

int QS(long long int *A, long long int *B){
	if (*A>*B) return 1;
	if (*A<*B) return -1;
	return 0;
}

int main(){
	new_freopen("A-small-attempt0.in", "r", stdin);
	new_freopen("A-small-attempt0.out", "w", stdout);
	
	scanf("%d", &TC);
	for (T=1; T<=TC; T++){
		printf("Case #%lld: ", T);
		scanf("%lld%lld", &N, &L);
		
		for (i=0; i<N; i++){
			scanf("%s", Input);
			A[i] = Transfer(Input);
		}
		for (i=0; i<N; i++){
			scanf("%s", Input);
			B[i] = Transfer(Input);
		}
		new_qsort(A, N, sizeof(A[0]), QS);
		new_qsort(B, N, sizeof(B[0]), QS);
		
		FAns = 10000;
		for (Sy=0; Sy<N; Sy++){
			Mask = A[0]^B[Sy];
			
			for (Sx=0; Sx<N; Sx++) Try[Sx] = A[Sx]^Mask;
			new_qsort(Try, N, sizeof(Try[0]), QS);
			
			for (i=0; i<N; i++) if (Try[i]!=B[i]) break;
			
			if (i==N){
				C = Decode(Mask);
				if (C<FAns) FAns = C;
			}
		}
		
		if (FAns<10000) printf("%lld\n", FAns);
		else new_puts("NOT POSSIBLE");
	}
	
	
	return 0;
}


FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str);

void new_qsort(void* base, size_t num, size_t size, int (*compar)(const void*,const void*)) {
  return qsort(base, num, size, compar);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

int new_puts(const char *str) {
  return puts(str);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}