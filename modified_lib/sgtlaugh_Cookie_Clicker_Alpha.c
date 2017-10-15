#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include <stddef.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define new_read() new_freopen("lol.txt", "r", stdin)
#define write() new_freopen("output.txt", "w", stdout)

int T = 0, t;
ssize_t new_read(int fd, void *buf, size_t count);
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);



int main(){
    double c, f, x;

    scanf("%d", &t);
    while (t--){
        double gain = 2.0;
        scanf("%lf %lf %lf", &c, &f, &x);

        double res = 0.0;
        for (; ;){
            double y = (x / gain);
            double z = (c / gain) + (x / (gain + f));
            if (z < y){
                res += (c / gain);
                gain += f;
            }
            else{
                res += y;
                break;
            }
        }

        printf("Case #%d: %0.7lf\n", ++T, (res + 1e-9));
    }
    return 0;
}

ssize_t new_read(int fd, void *buf, size_t count) {
  return read(fd, buf, count);
}
FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}