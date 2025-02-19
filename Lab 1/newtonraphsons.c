// C program for Newton-Raphson method
#include <stdio.h>
#include <math.h>

#define F(x) (a3*x*x*x + a2*x*x + a1*x + a0)  
#define FD(x) (3*a3*x*x + 2*a2*x + a1)        
float a0, a1, a2, a3;

int main() {
    float x0, x1, fx0, fdx0, E, Er;
    int i = 0, max_iter = 50;  

    printf("Enter coefficients a3, a2, a1, and a0:\n");
    scanf("%f %f %f %f", &a3, &a2, &a1, &a0);

    printf("Enter initial guess and tolerance E:\n");
    scanf("%f %f", &x0, &E);

    do {
        fx0 = F(x0);
        fdx0 = FD(x0);

        if (fdx0 == 0) {  
            printf("Derivative is zero. No solution found.\n");
            return 1;
        }

        x1 = x0 - fx0 / fdx0;
        Er = fabs(x1 - x0); // Error calculation

        if (Er < E) {  // Convergence check
            printf("Root = %f\n", x1);
            return 0;
        }

        x0 = x1;
        i++;
    } while (i < max_iter);  

    printf("Solution did not converge in %d iterations.\n", max_iter);
    return 1;
}
