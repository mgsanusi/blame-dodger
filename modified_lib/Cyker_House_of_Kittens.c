#include <stdio.h>
#include <string.h>

#include "cystring.h"
#include "cysort.h"

char grid[52][52];
int i,j;
FILE * new_freopen(const char *filename, const char *mode, FILE *stream);


int main(int argc, char **argv)
{
    new_freopen("a.in","r",stdin);
    new_freopen("a.out","w",stdout);

    int T,t;
    scanf("%d",&T);

    for (t = 1; t <= T;t++) {
        int r = 0,c = 0;
        char cha;
        scanf("%d %d\n",&r,&c);
        for (i = 0;i < r;i++) {
            for (j = 0;j < c;j++) {
                scanf("%c",&grid[i][j]);
            }
            scanf("%c",&cha);
        }

        int succ = 1;
        for (i = 0;i < r;i++) {
            for (j = 0;j < c;j++) {
                if (grid[i][j] == '#') {
                    if (i + 1 < r && j + 1 < c && grid[i][j] == '#' && grid[i][j+1] == '#'
                            && grid[i+1][j] == '#' && grid[i+1][j+1] == '#') {
                        grid[i][j] = '/';
                        grid[i][j+1] = '\\';
                        grid[i+1][j] = '\\';
                        grid[i+1][j+1] = '/';
                        j += 1;
                    } else {
                        succ = 0;
                        break;
                    }
                }
            }
            if (succ == 0)
                break;
        }

        printf("Case #%d:\n",t);
        if (succ) {
            for (i = 0;i < r;i++) {
                for (j = 0;j < c;j++) {
                    printf("%c",grid[i][j]);
                }
                printf("\n");
            }
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}

FILE * new_freopen(const char *filename, const char *mode, FILE *stream) {
  return freopen(filename, mode, stream);
}