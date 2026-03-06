#include <stdio.h>
#include <math.h>

void coeff(double y1, double y2, double x1, double x2, double *m) {
    *m = (y2 - y1) / (x2 - x1); // Attenzione all'ordine: (y2-y1)/(x2-x1)
}

void zeroDiY(double y1, double m, double x1, double *q) {
    *q = y1 - m * x1;
}

int main() {
    double x1, y1, x2, y2;
    double m, q;

    printf("Indica la X del primo punto: ");
    scanf("%lf", &x1);
    printf("Indica la Y del primo punto: ");
    scanf("%lf", &y1);
    printf("Indica la X del secondo punto: ");
    scanf("%lf", &x2);
    printf("Indica la Y del secondo punto: ");
    scanf("%lf", &y2);

    if (x1 == x2) {
        // Retta verticale: x = x1
        printf("La retta è verticale: x = %.2lf\n", x1);
    } else {
        coeff(y1, y2, x1, x2, &m);
        zeroDiY(y1, m, x1, &q);
        printf("La retta passante per i 2 punti è: y = %.2lfx + %.2lf\n", m, q);
    }

    return 0;
}
