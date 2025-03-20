#include <stdio.h>

// Function to solve system of linear equations using Gaussian elimination
void gaussianElimination(double matrix[3][4]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        // Make the diagonal element 1
        double factor = matrix[i][i];
        for (j = 0; j < 4; j++) {
            matrix[i][j] /= factor;
        }

        // Make the other elements in column zero
        for (k = 0; k < 3; k++) {
            if (k != i) {
                double temp = matrix[k][i];
                for (j = 0; j < 4; j++) {
                    matrix[k][j] -= temp * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    int n;

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    
    // Input data points
    printf("Enter values of x and y:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }

    // Variables for summations
    double sumX = 0, sumX2 = 0, sumX3 = 0, sumX4 = 0;
    double sumY = 0, sumXY = 0, sumX2Y = 0;

    // Compute summations
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumX2 += x[i] * x[i];
        sumX3 += x[i] * x[i] * x[i];
        sumX4 += x[i] * x[i] * x[i] * x[i];

        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2Y += x[i] * x[i] * y[i];
    }

    // Form the augmented matrix
    double matrix[3][4] = {
        {n, sumX, sumX2, sumY},
        {sumX, sumX2, sumX3, sumXY},
        {sumX2, sumX3, sumX4, sumX2Y}
    };

    // Solve using Gaussian elimination
    gaussianElimination(matrix);

    // Extract coefficients
    double c = matrix[0][3];
    double b = matrix[1][3];
    double a = matrix[2][3];

    // Output the quadratic regression equation
    printf("The best-fit quadratic equation is: y = %.3lfx^2 + %.3lfx + %.3lf\n", a, b, c);

    return 0;
}
