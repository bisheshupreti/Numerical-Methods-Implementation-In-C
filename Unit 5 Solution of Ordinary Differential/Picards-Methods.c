// DE: dy/dx = x + y
// Initial Condition: y(0) = 1

#include <stdio.h>
#include <math.h>

// First Approximation
float picard_y1(float x, float x0, float y0)
{
    return y0 + (pow(x, 2) - pow(x0, 2)) / 2 + y0 * (x - x0);
}

// Second Approximation
float picard_y2(float x, float x0, float y0)
{
    return y0 + (pow(x, 3) - pow(x0, 3)) / 6 + (1 + y0) * (pow(x, 2) - pow(x0, 2)) / 2 - (pow(x0, 2) / 2 + y0 * x0) * (x - x0);
}

int main()
{
    float x0 = 0, y0 = 1, x, y;

    printf("DE: dy/dx = x + y");
    printf("\nInitial Condition: y(0) = 1");

    printf("\n\nEnter value of X at which you want to know Y: ");
    scanf("%f", &x);

    y = picard_y1(x, x0, y0);
    printf("\nFirst Approximation:");
    printf("\ny1(%.4f) = %.4f", x, y);

    y = picard_y2(x, x0, y0);
    printf("\n\nSecond Approximation:");
    printf("\ny2(%.4f) = %.4f\n", x, y);

    return 0;
}
