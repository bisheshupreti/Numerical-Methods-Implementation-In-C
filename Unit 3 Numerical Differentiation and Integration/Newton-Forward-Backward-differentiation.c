#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j;
    float h, result, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);
    float x[n], y[n], d[n][n];

    printf("Enter x and y values:\n");

    for (i = 0; i < n; i++)
    {
        printf("X_%d and Y_%d: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
        d[i][0] = y[i];
    }

    h = x[1] - x[0];

    if (fabs(h) < 0.00001)
    {
        printf("Error: x values must be distinct.\n");
        return 0;
    }

    for (i = 1; i < n; i++)
    {
        if (fabs(x[i] - x[i - 1] - h) > 0.00001)
        {
            printf("Error: x values must be equally spaced.\n");
            return 0;
        }
    }

    // Construct forward difference table
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            d[i][j] = d[i + 1][j - 1] - d[i][j - 1];
        }
    }

    result = 0;
    // Forward differentiation at x0
    for (j = 1; j < n; j++)
    {
        term = d[0][j] / j;

        if (j % 2 == 0)
            result = result - term;
        else
            result = result + term;
    }
    printf("\nFirst Derivative at X_0 = %.4f\n", result / h);

    result = 0;
    // Backward differentiation at xn
    for (j = 1; j < n; j++)
    {
        result = result + d[n - 1 - j][j] / j;
    }

    printf("First Derivative at X_n = %.4f\n", result / h);

    return 0;
}
