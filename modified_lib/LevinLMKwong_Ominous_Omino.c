#include<stdio.h>
#include<string.h>
#include<math.h>
static const int GABRIEL = 1;
static const int RICHARD = 2;
static const char g_win[] = "GABRIEL";
static const char r_win[] = "RICHARD";
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

double new_sqrt(double x);

char * new_strcpy(char *destination, const char *source);

int new_getchar();

int get_int(){
	char c;
	while (c=new_getchar(),c<'0'||c>'9'){}
	int result = 0;
	while (c>='0'&&c<='9'){
		result = result*10+c-'0';
		c = new_getchar();
	}
	return result;
}
int main(){
	new_freopen("D.in","r",stdin);
	new_freopen("D.out","w",stdout);
	int t,T,X,R,C,ans;
	char ans_str[10];
	T = get_int();
	for (t=1;t<=T;t++){
		X = get_int(); R = get_int(); C = get_int();
		ans = RICHARD;
		if (X==1) {ans = GABRIEL;}
		if (X>1&&X<7) {
			if (R<X&&C<X) ans = RICHARD;
			else {
				if (X>2 && (R<=new_sqrt(X)||C<=sqrt(X))) {
					ans = RICHARD;
				} else {
					if ((R*C)%X==0) ans = GABRIEL;
					else ans = RICHARD;
				}
			}
		}
		if (ans == GABRIEL) {
			new_strcpy(ans_str, g_win);
		} else {
			new_strcpy(ans_str, r_win);
		}
		//printf("%d %d %d\n",X,R,C);
		printf("Case #%d: %s\n",t,ans_str);
	}
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

double new_sqrt(double x);

char * new_strcpy(char *destination, const char *source);

int new_getchar() {
  return getchar();
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

double new_sqrt(double x);

char * new_strcpy(char *destination, const char *source) {
  return strcpy(destination, source);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);

double new_sqrt(double x) {
  return sqrt(x);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}