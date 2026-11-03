// Lagrange-Interpolation
#include <stdio.h>

int main()
{
    int n, i, j;
    float x[20], y[20];
    float value, result = 0, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter the values of x and y:\n");

    for (i = 0; i < n; i++)
    {
        printf("X_%d and Y_%d : ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    printf("Enter the value of x to interpolate: ");
    scanf("%f", &value);

    for (i = 0; i < n; i++)
    {
        term = y[i];

        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                term = term * (value - x[j]) / (x[i] - x[j]);
            }
        }

        result = result + term;
    }

    printf("Interpolated value = %.4f\n", result);

    return 0;
}
