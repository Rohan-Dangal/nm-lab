#include <stdio.h>

// Function to compute backward difference table
void backwardDifferenceTable(double y[][10], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
        }
    }
}

// Function to apply Newton's backward difference interpolation
double newtonBackwardInterpolation(double x[], double y[][10], int n, double xp) {
    double h = x[1] - x[0];  // Assuming equal intervals
    double p = (xp - x[n - 1]) / h;
    double yp = y[n - 1][0]; // Initialize with last y value

    double term = 1;
    for (int i = 1; i < n; i++) {
        term *= (p + (i - 1)) / i;  // Compute p term for each iteration
        yp += term * y[n - 1][i];
    }

    return yp;
}

int main() {
    int n;

    // Input number of data points
    printf("Enter number of data points: ");
    scanf("%d", &n);

    double x[n], y[n][10], xp;

    // Input data points
    printf("Enter values of x and y:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i][0]);  // First column of the difference table
    }

    // Compute backward difference table
    backwardDifferenceTable(y, n);

    // Input the value of x for interpolation
    printf("Enter the value of x to interpolate: ");
    scanf("%lf", &xp);

    // Compute interpolated value
    double yp = newtonBackwardInterpolation(x, y, n, xp);

    // Output result
    printf("Interpolated value at x = %.3lf is y = %.3lf\n", xp, yp);

    return 0;
}
