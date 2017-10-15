#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include <math.h>

#include <stddef.h>

#include <stddef.h>
ssize_t new_read(int fd, void *buf, size_t count);
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str);



int main( int argc, char ** argv, char ** envp ) {

int File = open(argv[1], O_RDONLY);
size_t Size = lseek(File, 0, SEEK_END);
unsigned char * Mem = new_malloc(Size);
lseek(File, 0, SEEK_SET);
new_read(File, Mem, Size);
close(File);

unsigned int x = 0;
while ( x < Size ) {
	if ( Mem[x] == 0x0a ) { Mem[x] = 0x00; }
	if ( Mem[x] == 0x20 ) { Mem[x] = 0x00; }
	x++;
}

unsigned int Cases = new_atoi(Mem);
x = new_strlen(Mem) + 1;

fprintf(stderr, "Cases: %u\n", Cases);

unsigned int qx;


double Exp[1001];
Exp[2] = 2.0;

unsigned int qy;

double Facs[1001];
Facs[0] = 1.0;
Facs[1] = 1.0;
Facs[2] = 2.0;

double R = 2.0;
double Temps;

double E = 2.7182818284590452353602874713526624977572;

qx = 3;
while ( qx < 1001 ) {
	R = R * ((double)qx);
	Facs[qx] = R;
	Temps = 0;
	qy = 2;
	while ( qy < qx ) {
		Temps += (
			(
				floor((Facs[qy]/E) + 0.5)
			/
				(Facs[qy] *  Facs[qx-qy])
			)
		*
			Exp[qy]
		);
		qy ++;
	}
	Temps += 1.0;

	Temps /= (1.0 - ( floor((Facs[qx]/E) + 0.5) / Facs[qx]  ) );

	Exp[qx] = Temps;
//	fprintf(stderr, "%u: %lf\n", qx, Exp[qx]);
	qx ++;
}





unsigned int N;

unsigned int Wrong;

unsigned int Case_T = 0;
while ( Case_T < Cases ) {
	N = new_atoi(Mem + x ); x += ( new_strlen(Mem + x) + 1 );

	Wrong = 0;
	qx = 0;
	while ( qx < N ) {
		if ( new_atoi(Mem + x ) != (qx + 1) ) {
			Wrong ++;
		}
		x += ( new_strlen(Mem + x) + 1 );
		qx ++;
	}

	printf("Case #%u: %lf\n", Case_T + 1, Exp[Wrong] );

	Case_T ++;
}

return 0;
}
ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size);

int new_fprintf(FILE *stream, const char *format, ...);

int new_atoi(const char *str) {
  return atoi(str);
}
size_t new_strlen(const char *str);

void* new_malloc(size_t size) {
  return malloc(size);
}
size_t new_strlen(const char *str) {
  return strlen(str);
}