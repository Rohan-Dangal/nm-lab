#include <stdio.h>
#include <math.h>

#define F(x) (a3 * (x) * (x) * (x) + a2 * (x) * (x) + a1 * (x) + a0)

float a0, a1, a2, a3;

int main() {
    float x0, x1, x2, fx0, fx1, E, Er;
    int i = 0, max_iter = 50;

    printf("Enter coefficients a3, a2, a1, and a0:\n");
    scanf("%f %f %f %f", &a3, &a2, &a1, &a0);

    printf("Enter two initial guesses and tolerance E:\n");
    scanf("%f %f %f", &x0, &x1, &E);

    printf(" Iter |     x0      |     x1      |     x2      |    Error    \n");
    printf("------------------------------------------------------\n");

    do {
        fx0 = F(x0);
        fx1 = F(x1);

        if (fx1 - fx0 == 0) {
            printf("Error: Division by zero. Try different initial guesses.\n");
            return 1;
        }

        x2 = x1 - (fx1 * (x1 - x0)) / (fx1 - fx0);
        Er = fabs(x2 - x1);
        
        printf(" %3d  | %8.6f | %8.6f | %8.6f | %8.6f \n", i, x0, x1, x2, Er);

        if (Er < E) {
            printf("Root = %f\n", x2);
            return 0;
        }

        x0 = x1;
        x1 = x2;
        i++;
    } while (i < max_iter);

    printf("Solution did not converge in %d iterations.\n", max_iter);
    return 1;
}
