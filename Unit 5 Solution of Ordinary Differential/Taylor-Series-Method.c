
// dy/dx = x + y
// Taylor's Series Method

#include <stdio.h>
#include <math.h>

int main()
{
    float x, x0, h, y0, d1, d2, d3, d4, y_new;

    printf("Enter Initial value of x: ");
    scanf("%f", &x0);

    printf("Enter Initial value of y: ");
    scanf("%f", &y0);

    printf("Enter Step Size h: ");
    scanf("%f", &h);

    printf("Enter value X at Which You want to know value of Y: ");
    scanf("%f", &x);

    while (x0 < x)
    {
        if (x0 + h > x)
        {
            h = x - x0;
        }

        printf("\ny(%.4f) = %.4f", x0, y0);

        d1 = x0 + y0;
        d2 = 1 + d1;
        d3 = d2;
        d4 = d3;

        y_new = y0 + h * d1 + pow(h, 2) * d2 / 2 + pow(h, 3) * d3 / 6 + pow(h, 4) * d4 / 24;

        x0 = x0 + h;
        y0 = y_new;
    }

    printf("\ny(%.4f) = %.4f", x0, y0);

    return 0;
}
