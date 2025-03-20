#include <stdio.h>
#include <math.h>

#define MAX_ITER 100  

// Define the function f(x) = cos(x) - 3x + 1
float f(float x) {
    return cos(x) - 3 * x + 1;
}

// Transformation function g(x) for Fixed Point Iteration
float g(float x) {
    return (cos(x) + 1) / 3;  // Rearranged equation for fixed-point iteration
}

int main() {
    float x0, x1, E;
    int iteration = 0;

    // Input initial guess and tolerance
    printf("Enter initial guess (x0) and error tolerance (E): ");
    scanf("%f %f", &x0, &E);

    printf(" Iter |     x0      |     x1      |    Error    \n");
    printf("------------------------------------------------\n");
    
    do {
        x1 = g(x0);
        float error = fabs(x1 - x0);
        
        printf(" %3d  | %8.6f | %8.6f | %8.6f \n", iteration, x0, x1, error);
        
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