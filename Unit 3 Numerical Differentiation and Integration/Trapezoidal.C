// f(x) = x^2 + 2x + 1;
#include <stdio.h>

float f(float x)
{
    return x * x + 2 * x + 1;
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


    h = (b - a) / n;

    for (i = 1; i < n; i++)
    {
        x = a + i * h;
        sum = sum + 2 * f(x);
    }

    result = (h / 2) * (f(a) + f(b) + sum);

    printf("\nIntegration Result = %.6f\n", result);

    return 0;
}
