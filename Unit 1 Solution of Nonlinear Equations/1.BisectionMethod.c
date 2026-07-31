#include <stdio.h>
#include <math.h>
int iterCalc(double a, double b, double E)
{
    int i = (int)ceil((log((b - a)/E)) / log(2));
    return (i<1)? 1: i;
}

double f(double x)
{
    double result = exp(cos(x)) - log(x) + x - 3;
    return result;
}

int main()
{
    double a, b, m = 0.0, E;

    do
    {
        printf("Enter initial interval (a b): ");
        scanf("%lf %lf", &a, &b);

        if (a > b)
        {
            double temp = a;
            a = b;
            b = temp;
        }

        if (a <= 0 || b <= 0)
        {
            printf("Invalid interval! a and b must be > 0 (log(x) is undefined otherwise).\n\n");
            continue;
        }

        if (f(a) * f(b) >= 0)
        {
            printf("Invalid interval! f(a) and f(b) must have opposite signs.\n\n");
        }

    } while (a <= 0 || b <= 0 || f(a) * f(b) >= 0);

    do
    {
        printf("Enter error tolerance E > 0: ");
        scanf("%lf", &E);

        if (E <= 0)
            printf("E must be positive.\n");
            
    } while (E <= 0);

    int iter = iterCalc(a, b, E); // Total Number of Iteration Calculation using Furmula

    printf("\nIter\t a\t\t b\t\t m\t\t f(m)\n");

    for(int i = 1; i<=iter; i++)
    {
        m = (a + b) / 2.0;

        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", i, a, b, m, f(m));

        if (f(m) == 0.0) break;
        else if (f(a) * f(m) < 0)
            b = m;
        else
            a = m;
    }

    printf("\nRoot correct to within %.6f  = %.6f\n", E, m);

    return 0;
}