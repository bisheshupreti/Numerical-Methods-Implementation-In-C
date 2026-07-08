#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 1.0 / (1.0 + x * x);
}

int main()
{
    double x, x_next, E, error;
    int iter = 0;

    printf("Enter initial guess (x0): ");
    scanf("%lf", &x);

    do
    {
        printf("Enter tolerance (E > 0): ");
        scanf("%lf", &E);

        if (E <= 0)
            printf("Tolerance must be positive.\n");

    } while (E <= 0);

    printf("\nIter\t x_n\t\t x_(n+1)\n");

    while (1)
    {
        x_next = f(x);

        printf("%d\t %.6f\t %.6f\n", ++iter, x, x_next);

        if (fabs(x_next - x) <= E)
            break;

        x = x_next;

        if (iter >= 100)
        {
            printf("\nMethod did not converge.\n");
            return 1;
        }
    }

    printf("\nFixed Point = %.6f\n", x_next);
    printf("Iterations = %d\n", iter);

    return 0;
}