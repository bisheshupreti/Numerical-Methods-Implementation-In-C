#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPS 0.00005

int main()
{
    int i, j, k, n;
    double A[MAX][MAX + 1], X[MAX];
    double factor, pivot;

    printf("Enter the number of variables: ");
    scanf("%d", &n);

    // Input Augmented Matrix
    printf("\nEnter the augmented coefficient matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (j == n)
                printf("b[%d] = ", i + 1);
            else
                printf("a[%d][%d] = ", i + 1, j + 1);

            scanf("%lf", &A[i][j]);
        }
    }

    for (k = 0; k < n; k++)
    {
        // Check pivot
        if (fabs(A[k][k]) < EPS)
        {
            printf("\nError: Pivot element approx. to zero\n");
            return 1;
        }

        //Making 1 to pivot
        pivot = A[k][k];
        for (j = 0; j <= n; j++)
        {
            A[k][j] = A[k][j] / pivot;
        }

        //Elimination
        for (i = 0; i < n; i++)
        {
            if (i != k)
            {
                factor = A[i][k];

                for (j = 0; j <= n; j++)
                {
                    A[i][j] = A[i][j] - factor * A[k][j];
                }
            }
        }
    }

    // Display Final Matrix
    printf("\nReduced Row Echelon Form (Identity Matrix):\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            printf("%10.4lf ", A[i][j]);
        }
        printf("\n");
    }

    // Display Solution
    printf("\nSolution:\n");

    for (i = 0; i < n; i++)
    {
        printf("X%d = %.4lf\n", i + 1, A[i][n]);
    }

    return 0;
}
