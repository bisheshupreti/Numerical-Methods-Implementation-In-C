// f(x) = 1 / (1+x^2)
#include <stdio.h>

float f(float x)
{
    return 1.0 / (1 + x * x);
}

int main()
{
    int n, i;
    float a, b, h, x;
    float sum = 0, result;

    printf("Enter lower limit: ");
    scanf("%f", &a);

    printf("Enter upper limit: ");
    scanf("%f", &b);

    printf("Enter number of subintervals: ");
    scanf("%d", &n);

    if (n <= 0 || n % 2 != 0)
    {
        printf("Error: Number of subintervals must be positive and even.\n");
        return 0;
    }

    h = (b - a) / n;

    for (i = 1; i < n; i++)
    {
        x = a + i * h;

        if (i % 2 == 0)
            sum = sum + 2 * f(x);
        else
            sum = sum + 4 * f(x);
    }

    result = (h / 3) * (f(a) + f(b) + sum);

    printf("\nIntegration Result = %.6f\n", result);

    return 0;
}
