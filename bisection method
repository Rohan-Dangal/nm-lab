#include <stdio.h>
#include <math.h>

// Define the function f(x) here. Example: f(x) = x^2 - 4
double f(double x) {
    return x * x - 4;  // Change this function as needed
}

// Bisection Method to find the root of the function f(x)
double bisection(double a, double b, double tol, int max_iter) {
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval [a, b]. f(a) and f(b) must have opposite signs.\n");
        return -1;
    }

    double c;  // Variable to store mid-point of interval
    int iter = 0;

    // Iterate until the desired tolerance or maximum iterations are reached
    while ((b - a) / 2 > tol && iter < max_iter) {
        c = (a + b) / 2;  // Mid-point
        if (f(c) == 0) {
            return c;  // Exact root found
        } else if (f(a) * f(c) < 0) {
            b = c;  // The root is in the left half
        } else {
            a = c;  // The root is in the right half
        }

        iter++;
    }

    return (a + b) / 2;  // Return the root approximation
}

int main() {
    double a, b, tol;
    int max_iter;

    // Get input from the user
    printf("Enter the interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the tolerance: ");
    scanf("%lf", &tol);
    printf("Enter maximum number of iterations: ");
    scanf("%d", &max_iter);

    // Call bisection method to find the root
    double root = bisection(a, b, tol, max_iter);

    if (root != -1) {
        printf("The root of the function is: %.6lf\n", root);
    } else {
        printf("The bisection method could not find a root in the given interval.\n");
    }

    return 0;
}
