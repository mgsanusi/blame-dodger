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
unsigned int Case_T = 0;


int A;
int B;
while ( Case_T < Cases ) {
/* --------------------- */
	A   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );
	B   = atoi(Mem + q ); q += ( strlen(Mem + q) + 1 );

	int ans = 0;

	int x;

	x = 1;
	if ( (x >= A) && (x <= B) ) { ans ++; }
	x = 4;
	if ( (x >= A) && (x <= B) ) { ans ++; }
	x = 9;
	if ( (x >= A) && (x <= B) ) { ans ++; }
	x = 121;
	if ( (x >= A) && (x <= B) ) { ans ++; }
	x = 484;
	if ( (x >= A) && (x <= B) ) { ans ++; }


	printf("Case #%u: %d\n", Case_T + 1, ans );

	Case_T ++;
/* --------------------- */
}

return 0;
}
