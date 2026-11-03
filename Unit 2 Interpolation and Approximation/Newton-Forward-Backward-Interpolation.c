
#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, choice;
    float h, value, u, p;
    float result, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);
    float x[n], y[n], d[n][n];

    printf("Enter x and y values:\n");

    for (i = 0; i < n; i++)
    {
        printf("X_%d and Y_%d : ", i, i);
        scanf("%f %f", &x[i], &y[i]);
        d[i][0] = y[i];
    }

    h = x[1] - x[0];

    for (i = 1; i < n; i++)
    {
        if (fabs(x[i] - x[i - 1] - h) > 0.00001)
        {
            printf("Error: x values must be equally spaced.\n");
            return 0;
        }
    }

    // Construct  difference table
    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            d[i][j] = d[i + 1][j - 1] - d[i][j - 1];
        }
    }

    printf("\n1. Newton Forward Interpolation");
    printf("\n2. Newton Backward Interpolation");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value of x: ");
    scanf("%f", &value);

    result = 0;

    if (choice == 1)
    {
        u = (value - x[0]) / h;
        result = y[0];
        term = 1;

        for (j = 1; j < n; j++)
        {
            term = term * (u - (j - 1)) / j;
            result = result + term * d[0][j];
        }
    }
    else if (choice == 2)
    {
        p = (value - x[n - 1]) / h;
        result = y[n - 1];
        term = 1;

        for (j = 1; j < n; j++)
        {
            term = term * (p + (j - 1)) / j;
            result = result + term * d[n - 1 - j][j];
        }
    }
    else
    {
        printf("Invalid choice.\n");
        return 0;
    }

    printf("\nInterpolated value = %.4f\n", result);

    return 0;
}
