
#include <stdio.h>
#include <math.h>

float f1(float x, float y, float z)
{
    return z;
}

float f2(float x, float y, float z)
{
    return x + y;
}

// Euler method
float euler(float x, float xa, float ya, float za, float h)
{
    float yn = ya, zn = za, xn = xa;
    float y_new, z_new;
    int i, n = ceil((x - xa) / h);

    for (i = 1; i <= n; i++)
    {
        if (i == n)
            h = x - xn;

        y_new = yn + h * f1(xn, yn, zn);
        z_new = zn + h * f2(xn, yn, zn);

        xn += h;
        yn = y_new;
        zn = z_new;
    }

    return yn;
}

int main()
{
    float xa, ya, xb, yb, h, x;
    float g1, g2, g3;
    float y1, y2, error;
    float E = 0.00001;
    int i;

    printf("Enter xa: ");
    scanf("%f", &xa);

    printf("Enter ya: ");
    scanf("%f", &ya);

    printf("Enter xb: ");
    scanf("%f", &xb);

    printf("Enter yb: ");
    scanf("%f", &yb);

    printf("Enter h: ");
    scanf("%f", &h);

    printf("Enter X to find Y: ");
    scanf("%f", &x);

    // First initial guess
    g1 = (yb - ya) / (xb - xa);

    y1 = euler(xb, xa, ya, g1, h);

    // Second initial guess
    if (y1 < yb)
        g2 = 2 * g1;
    else
        g2 = g1 / 2;

    y2 = euler(xb, xa, ya, g2, h);

    // Shooting method using Secant method
    for (i = 1; i <= 1000; i++)
    {
        error = y2 - yb;

        if (fabs(error) < E)
            break;

        if (fabs(y2 - y1) < 0.0000001)
            break;

        g3 = g2 - (y2 - yb) * (g2 - g1) / (y2 - y1);

        g1 = g2;
        y1 = y2;

        g2 = g3;
        y2 = euler(xb, xa, ya, g2, h);
    }

    if (fabs(y2 - yb) >= E)
    {
        printf("\nSolution did not converge!\n");
        return 1;
    }

    // Calculate Y at required X
    float result = euler(x, xa, ya, g2, h);

    printf("Initial slope = %f\n", g2);
    printf("Y(%f) = %f\n", x, result);

    return 0;
}
