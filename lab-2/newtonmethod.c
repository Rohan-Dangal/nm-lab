#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^3 - 4x - 9
float f(float x) {
    return x * x * x - 4 * x - 9;
}

// Define the derivative of the function f'(x) = 3x^2 - 4
float f_prime(float x) {
    return 3 * x * x - 4;
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
        if (f_prime(x0) == 0) {
            printf("Error: Derivative is zero. Newton's method fails.\n");
            return 1;
        }

        // Newton's Method formula: x1 = x0 - f(x0)/f'(x0)
        x1 = x0 - f(x0) / f_prime(x0);

        // Calculate the error
        float error = fabs(x1 - x0);

        // Print the iteration results
        printf(" %3d  | %8.6f | %8.6f | %8.6f \n", iteration, x0, x1, error);

        // If the error is less than the tolerance, stop
        if (error < E) {
            printf("\nRoot = %f\n", x1);
            return 0;
        }

        // Update x0 for the next iteration
        x0 = x1;
        iteration++;
    } while (iteration < 100); // Max iterations

    printf("\nMethod did not converge within 100 iterations.\n");
    return 1;
}
