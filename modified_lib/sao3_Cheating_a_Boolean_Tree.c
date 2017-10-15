#include <stdio.h>
#include <string.h>

#include <stddef.h>

int f[102][102];
int map[102][102];
int h, w;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);
void * new_memset(void *ptr, int value, size_t num);



void go(){
	int r, c, x;
	int i, j;
	new_memset(f, 0, sizeof(f));
	new_memset(map, 0, sizeof(map));
	scanf("%d%d%d", &h, &w, &x);
	for(i = 0; i < x; i++){
		scanf("%d%d", &r, &c);
		map[r][c] = 1;
	}
	f[1][1] = 1;
	for(i = 1; i <= h; i++){
		for(j = 1; j <= w; j++){
			if(map[i][j] == 0){
				if(i > 1)
					f[i][j] += f[i - 2][j - 1];
				if(j > 1)
					f[i][j] += f[i - 1][j - 2];
				f[i][j] %= 10007;
			}
		}
	}
}

int main(){
	int cs, i;
	new_freopen("D.in", "r", stdin);
	new_freopen("D.out", "w", stdout);
	scanf("%d", &cs);
	for(i = 1; i <= cs; i++){
		go();
		printf("Case #%d: %d\n", i, f[h][w]);
	}
	return 0;
}

FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}
void * new_memset(void *ptr, int value, size_t num) {
  return memset(ptr, value, num);
}