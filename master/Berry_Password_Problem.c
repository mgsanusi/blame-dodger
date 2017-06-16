#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>


int main( int argc, char ** argv, char ** envp ) {
int File = open(argv[1], O_RDONLY);
size_t Size = lseek(File, 0, SEEK_END);
char * Mem = malloc(Size);
lseek(File, 0, SEEK_SET);
read(File, Mem, Size);
close(File);
unsigned int q = 0;
while ( q < Size ) {
	if ( Mem[q] == 0x0a ) { Mem[q] = 0x00; }
	if ( Mem[q] == 0x20 ) { Mem[q] = 0x00; }
	q++;
}
unsigned int Cases = atoi(Mem);
q = strlen(Mem) + 1;
fprintf(stderr, "Cases: %u\n", Cases);


double P[100000];
double R[100000];
double rs;

double Best;

double E;

int A;
int B;

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	A   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	B   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );

	int x = 0;
	while ( x < A ) {
		P[x]   = atof(Mem + q ); q += ( strlen(Mem + q) + 1 );
		x ++;
	}

	rs = 1.0;
	x = 0;
	while ( x < A ) {
		R[x] = rs;
		rs *= P[x];
		x ++;
	}
	R[x] = rs;

	Best = 2110000.0;

	x = 0;
	while ( x <= A ) {
		E = ((double)((B + A + 1) - (2*x))) + ((B+1) * (1.0 - (R[x]) ));
		if ( Best > E ) {
			 Best = E;
		}
		x ++;
	}

	if ( Best > ((double)(B+2)) ) {
		 Best = ((double)(B+2));
	}

	printf("Case #%u: %lf\n", Case_T + 1,   Best    );

	Case_T ++;
}

return 0;
}
