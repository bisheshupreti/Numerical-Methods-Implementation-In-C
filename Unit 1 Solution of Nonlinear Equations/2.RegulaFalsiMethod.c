#include <stdio.h>
#include <math.h>

double f(double x)
{
    return pow(x,3)- 2 * x - 5; // Equation: x^3 - 2x - 5 = 0
}

int main()
{
    double a, b, m = 0.0, E, fa, fb, fm;

    do
    {
        printf("Enter interval (a b): ");
        scanf("%lf %lf", &a, &b);

        if (a > b)
        {
            double t = a;
            a = b;
            b = t;
        }
        if (f(a) * f(b) >= 0)
            printf("Invalid! f(a) and f(b) must have opposite signs.\n");

    } while (f(a) * f(b) >= 0);

    do
    {
        printf("Enter error tolerance E > 0: ");
        scanf("%lf", &E);

        if (E <= 0)
            printf("E must be positive.\n");

    } while (E <= 0);

    printf("\nIter\t a\t\t b\t\t m\t\t f(m)\n");
    int iter = 0;
    do
    {
        fa = f(a);
        fb = f(b);
        m = (a * fb - b * fa) / (fb - fa);
        fm = f(m);
        printf("%d\t %.6f\t %.6f\t %.6f\t %.6f\n", ++iter, a, b, m, fm);

        if (fm == 0.0)
            break;
        if (fa * fm < 0)
            b = m;
        else
            a = m;
    } while (fabs(fm) > E && fabs(b - a) > E);

    printf("\nRoot = %.6f (within tolerance %.6f)\n", m, E);
    return 0;
}