#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of terms:\n");
    scanf("%d", &n);
    
    float X[n], Y[n], x, sum = 0, term;
    int i, j;
    
    printf("Enter values of x:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &X[i]);
    }
    
    printf("Enter the values of y:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &Y[i]);
    }
    
    printf("Enter the value of x for which you want y:\n");
    scanf("%f", &x);
    
    for (i = 0; i < n; i++) {
        term = 1;
        for (j = 0; j < n; j++) {
            if (i != j) {
                term *= (x - X[j]) / (X[i] - X[j]);
            }
        }
        sum += term * Y[i];
    }
    
    printf("\nThe value at x = %g is %f\n", x, sum);
    
    return 0;
}
