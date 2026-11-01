// dy/dx = 3x^2 + 1, y(1) = 2, x = 2; h = 0.25;

#include <stdio.h>
#include <math.h>
float function(float x_n, float y_n)
{
    return 3 * pow(x_n, 2) + 1;
}

int main()
{

    float x = 2, x_n = 1, y_n = 2, y_new, h = 0.25;
    int i;

    printf("Initial value of x: %.4f ", x_n);
    printf("\nInitial value of y: %.4f ", y_n);
    printf("\nStep Size h: %.4f ", h);
    printf("\ny(%.4f) = ? ", x);

    int n = ceil((x - x_n) / h);

    for (i = 1; i <= n; i++)
    {
        if (i == n)
        {
            h = x - x_n;
        }

        printf("\ny(%.4f) = %.4f", x_n, y_n);

        y_new = y_n + h * function(x_n, y_n);

        x_n += h;
        y_n = y_new;
    }
    printf("\ny(%.4f) = %.4f", x_n, y_n);

    return 0;
}