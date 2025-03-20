#include <stdio.h>
#include <math.h>

// Define the function f(x) = x^2 - e^(-x) - 3
double f(double x) {
    return x * x - exp(-x) - 3;
}

// Bisection Method to find the root of the function f(x)
double bisection(double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval [a, b]. f(a) and f(b) must have opposite signs.\n");
        return -1;
    }

    double c;
    int iter = 0;

    printf(" Iter |     a      |     b      |     c      |   f(c)     \n");
    printf("------------------------------------------------------\n");

    while ((b - a) / 2 > tol && iter < max_iter) {
        c = (a + b) / 2;
        printf(" %3d  | %8.6f | %8.6f | %8.6f | %8.6f \n", iter, a, b, c, f(c));

        if (f(c) == 0) {
            return c;
        } else if (f(a) * f(c) < 0) {
            b = c;
        } else {
            a = c;
        }
        iter++;
    }

    return (a + b) / 2;
}

int main() {
    double a, b, tol;
    int max_iter;

    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the tolerance: ");
    scanf("%lf", &tol);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);

    double root = bisection(a, b, tol, max_iter);

    if (root != -1) {
        printf("The root of the function is: %.6lf\n", root);
    } else {
        printf("The bisection method could not find a root in the given interval.\n");
    }

    return 0;
}
