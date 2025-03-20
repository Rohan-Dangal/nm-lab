#include <stdio.h>
#include <math.h>

#define F(x) (x*x*x*x - x - 10)  
#define FD(x) (4*x*x*x - 1)        

int main() {
    float x0, x1, fx0, fdx0, E, Er;
    int i = 0, max_iter = 50;  

    printf("Enter initial guess and tolerance E:\n");
    scanf("%f %f", &x0, &E);

    printf(" Iter |     x0      |     f(x0)     |    f'(x0)    |      x1      |    Error   \n");
    printf("----------------------------------------------------------------------------\n");

    do {
        fx0 = F(x0);
        fdx0 = FD(x0);

        if (fdx0 == 0) {  
            printf("Derivative is zero. No solution found.\n");
            return 1;
        }

        x1 = x0 - fx0 / fdx0;
        Er = fabs(x1 - x0); // Error calculation

        printf(" %3d  | %10.6f | %12.6f | %12.6f | %10.6f | %10.6f \n", i, x0, fx0, fdx0, x1, Er);

        if (Er < E) { 
            printf("Root = %f\n", x1);
            return 0;
        }

        x0 = x1;
        i++;
    } while (i < max_iter);  

    printf("Solution did not converge in %d iterations.\n", max_iter);
    return 1;
}
