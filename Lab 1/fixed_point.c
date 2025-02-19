// write a program in c for fixed point iteration method 
#include <stdio.h>
#include <math.h>

#define MAX_ITER 100  

int a3, a2, a1, a0;  // Global coefficients

float f(float x) {
    return (a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * x + a0);
}

float g(float x) {
    if (a1 == 0) {
        printf("Invalid transformation for Fixed Point Iteration. a1 cannot be zero.\n");
        return x;
    }
    return (-1.0 / a1) * (a3 * pow(x, 3) + a2 * pow(x, 2) + a0);
}

int main() {
    float x0, x1, E;
    int iteration = 0;

    // Input coefficients
    printf("Enter coefficients a3, a2, a1, and a0: ");
    scanf("%d %d %d %d", &a3, &a2, &a1, &a0);

    // Input initial guess and tolerance
    printf("Enter initial guess (x0) and error tolerance (E): ");
    scanf("%f %f", &x0, &E);

    if (a1 == 0) {
        printf("Error: a1 must not be zero for valid transformation.\n");
        return 1;
    }

 
    do {
        x1 = g(x0);  
        float error = fabs(x1 - x0);  

        if (error < E) {  
            printf("\nRoot = %f\n", x1);
            return 0;
        }

        x0 = x1;  
        iteration++;

    } while (iteration < MAX_ITER);

    printf("\nMethod did not converge within %d iterations.\n", MAX_ITER);
    return 1;
}