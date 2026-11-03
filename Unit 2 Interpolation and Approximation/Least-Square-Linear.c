// y = a + bx;
#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    float sx = 0, sy = 0;
    float sx2 = 0, sxy = 0;
    float a, b, den;
    float value, result;

    printf("Enter number of data points: ");
    scanf("%d", &n);
    float x[n], y[n];

    printf("Enter x and y values:\n");

    for (i = 0; i < n; i++)
    {
        printf("X_%d and Y_%d: ", i, i);
        scanf("%f %f", &x[i], &y[i]);

        sx += x[i];
        sy += y[i];
        sx2 += pow(x[i], 2);
        sxy += x[i] * y[i];
    }

    den = n * sx2 - pow(sx, 2);

    if (den != 0)
    {
        b = (n * sxy - sx * sy) / den;
        a = (sy / n) - b * (sx / n);
    }
    else
    {
        printf("Cannot fit a unique straight line.\n");
        return 0;
    }

    printf("\nBest Fit Straight Line:\n");
    printf("y = %.4f + %.4fx\n", a, b);

    printf("\nEnter x value to estimate y: ");
    scanf("%f", &value);

    result = a + b * value;

    printf("Estimated y = %.4f\n", result);

    return 0;
}
