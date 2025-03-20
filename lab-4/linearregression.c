#include <stdio.h>

// Function to calculate linear regression (y = mx + c)
void linearRegression(double x[], double y[], int n, double *m, double *c) {
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    // Calculate sums required for formula
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Compute slope (m) and intercept (c)
    *m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    *c = (sumY - (*m) * sumX) / n;
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

    double m, c;

    // Compute linear regression
    linearRegression(x, y, n, &m, &c);

    // Output the regression equation
    printf("The best-fit line equation is: y = %.3lfx + %.3lf\n", m, c);

    return 0;
}
