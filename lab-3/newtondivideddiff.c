#include <stdio.h>

// Function to calculate divided difference table
void dividedDifferenceTable(double x[], double y[][10], int n) {
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = (y[i + 1][j - 1] - y[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Function to apply Newton's divided difference interpolation
double newtonInterpolation(double x[], double y[][10], int n, double xp) {
    double yp = y[0][0]; // Initialize result with first term

    double term;
    for (int i = 1; i < n; i++) {
        term = y[0][i]; // Get coefficient
        for (int j = 0; j < i; j++) {
            term *= (xp - x[j]);
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

    double x[n], y[n][10], xp;

    // Input data points
    printf("Enter values of x and y:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("y[%d] = ", i);
        scanf("%lf", &y[i][0]); // First column of divided difference table
    }

    // Generate divided difference table
    dividedDifferenceTable(x, y, n);

    // Input the value of x for interpolation
    printf("Enter the value of x to interpolate: ");
    scanf("%lf", &xp);

    // Compute interpolated value
    double yp = newtonInterpolation(x, y, n, xp);

    // Output result
    printf("Interpolated value at x = %.3lf is y = %.3lf\n", xp, yp);

    return 0;
}
