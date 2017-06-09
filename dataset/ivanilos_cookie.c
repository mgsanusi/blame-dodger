#include <stdio.h>

int main(void) {
    int t;
    int caso;
    double c, f, x;
    double time;
    double update;
    double best;
    double den;

    scanf(" %d", &t);

    for (caso = 1; caso <= t; caso++) {
        scanf(" %lf %lf %lf", &c, &f, &x);

        time = x / 2;
        best = time;
        den = 2;
        update = c / 2;

        while(update < best) {
            den += f;
            time = update + x / den;
            update += c / den;
            if (time < best) {
                best = time;
            }
        }

        printf("Case #%d: %.7lf\n", caso, best);
    }
    return 0;
}
