// dy/dx = x^2 + y^2
// RK4

#include <stdio.h>
#include <math.h>

// function of x, y
float function(float x_n, float y_n)
{
    return pow(x_n, 2) + pow(y_n, 2);
}

int main()
{

    float x, x_n, y_n, y_new, h, k1, k2, k3, k4;
    int i;

    printf("Enter Initial value of x: ");
    scanf("%f", &x_n);

    printf("Enter Initial value of y: ");
    scanf("%f", &y_n);

    printf("Enter Step Size h: ");
    scanf("%f", &h);

    printf("Enter value X at Which You want to know value of Y: ");
    scanf("%f", &x);

    int n = ceil((x - x_n) / h);

    for (i = 1; i <= n; i++)
    {
        if (i == n)
        {
            h = x - x_n;
        }

        printf("\ny(%.4f) = %.4f", x_n, y_n);

        k1 = function(x_n, y_n);
        k2 = function(x_n + (h / 2), y_n + (h * k1 / 2));
        k3 = function(x_n + (h / 2), y_n + (h * k2 / 2));
        k4 = function(x_n + h, y_n + h * k3);

        y_new = y_n + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);

        x_n += h;
        y_n = y_new;
    }
    printf("\ny(%.4f) = %.4f", x_n, y_n);

    return 0;
}