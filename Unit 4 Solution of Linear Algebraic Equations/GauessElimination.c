#include <stdio.h>
#include <math.h>

#define MAX 10
#define EPS 0.00005

int main()
{
    int i, j, k, n;
    double A[MAX][MAX + 1], X[MAX];
    double factor;

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

    // Forward Elimination
    for (k = 0; k < n - 1; k++)
    {
        // Check pivot
        if (fabs(A[k][k]) < EPS)
        {
            printf("\nError: Pivot element approx. to zero\n");
            return 1;
        }

        for (i = k + 1; i < n; i++)
        {
            factor = A[i][k] / A[k][k];

            for (j = k; j <= n; j++)
            {
                A[i][j] = A[i][j] - factor * A[k][j];
            }
        }
    }

    // Check last pivot
    if (fabs(A[n - 1][n - 1]) < EPS)
    {
        printf("\nNo unique solution exists.\n");
        return 1;
    }

    // Back Substitution
    for (i = n - 1; i >= 0; i--)
    {
        X[i] = A[i][n];

        for (j = i + 1; j < n; j++)
        {
            X[i] = X[i] - A[i][j] * X[j];
        }

        X[i] = X[i] / A[i][i];
    }

    // Display Upper Triangular Matrix
    printf("\nUpper Triangular Matrix:\n");
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
        printf("X%d = %.4lf\n", i + 1, X[i]);
    }

    return 0;
}