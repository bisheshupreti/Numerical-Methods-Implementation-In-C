// dy/dx = x + y

#include <stdio.h>
#include <math.h>
float function(float x_n, float y_n)
{
    return x_n + y_n;
}

int main()
{

    float x, x_n, y_n, y_new, h;
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

        y_new = y_n + h * function(x_n, y_n);

        x_n += h;
        y_n = y_new;
    }
    printf("\ny(%.4f) = %.4f", x_n, y_n);

    return 0;
}