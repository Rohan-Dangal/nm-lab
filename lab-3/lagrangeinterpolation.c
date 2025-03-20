#include <stdio.h>

// Function to implement Lagrange Interpolation
double lagrangeInterpolation(double x[], double y[], int n, double xp) {
    double yp = 0.0;

    for (int i = 0; i < n; i++) {
        double term = y[i];
        
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        
        yp += term;
    }

    return yp;
}

int main() {
    int n;
    
    // Input number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);

    double x[n], y[n], xp;
    
    // Input data points
    printf("Enter values of x and y:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i]);
    }

    // Input the value of x for interpolation
    printf("Enter the value of x to interpolate: ");
    scanf("%lf", &xp);

    // Compute interpolated value
    double yp = lagrangeInterpolation(x, y, n, xp);

    // Output result
    printf("Interpolated value at x = %.3lf is y = %.3lf\n", xp, yp);

    return 0;
}
