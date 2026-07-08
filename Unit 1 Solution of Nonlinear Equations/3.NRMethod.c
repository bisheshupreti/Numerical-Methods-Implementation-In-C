#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x*x-3*x+2;
}

double df(double x)
{
    return 2*x-3;
}

int main()
{
    double x, x_next, fx, dfx, E;
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

    printf("\nIter\t x_n\t\t f(x_n)\t\t x_(n+1)\n");

    while (1)
    {
        fx = f(x);
        dfx = df(x);

        if (fabs(dfx) < 1e-12)
        {
            printf("\nDerivative is zero. Method fails.\n");
            return 1;
        }

        x_next = x - fx / dfx;

        printf("%d\t %.6f\t %.6f\t %.6f\n", ++iter, x, fx, x_next);

        if (fabs(x_next - x) <= E || fabs(f(x_next)) <= E)
            break;

        x = x_next;
    }

    printf("\nApproximate Root = %.6f\n", x_next);
    printf("Iterations = %d\n", iter);

    return 0;
}