// f(x) = e^x;
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return exp(x);
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

    if (n <= 0 || n % 3 != 0)
    {
        printf("Error: n must be a positive multiple of 3.\n");
        return 0;
    }

    h = (b - a) / n;

    for (i = 1; i < n; i++)
    {
        x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * f(x);

        else
            sum += 3 * f(x);
    }

    result = (3 * h / 8) * (f(a) + f(b) + sum);

    printf("\nIntegration Result = %.6f\n", result);

    return 0;
}
