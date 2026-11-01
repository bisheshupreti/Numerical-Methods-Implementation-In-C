
// dy/dx = x^2 + y^2
// Modified Euler's Method

#include <stdio.h>
#include <math.h>

float function(float x_n, float y_n)
{
    return pow(x_n, 2) + pow(y_n, 2);
}

int main()
{
    float x, x_n, y_n, y_new, h, k1, k2;

    printf("Enter Initial value of x: ");
    scanf("%f", &x_n);

    printf("Enter Initial value of y: ");
    scanf("%f", &y_n);

    printf("Enter Step Size h: ");
    scanf("%f", &h);

    printf("Enter value X at Which You want to know value of Y: ");
    scanf("%f", &x);

    while (x_n < x)
    {
        if (x_n + h > x)
        {
            h = x - x_n;
        }

        printf("\ny(%.4f) = %.4f", x_n, y_n);

        // Predictor
        k1 = function(x_n, y_n);
        y_new = y_n + h * k1;

        k2 = function(x_n + h, y_new);

        // Corrector
        y_new = y_n + (h / 2) * (k1 + k2);

        x_n += h;
        y_n = y_new;
    }

    printf("\ny(%.4f) = %.4f", x_n, y_n);

    return 0;
}
