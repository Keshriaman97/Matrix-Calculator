#include <stdio.h>
#include <conio.h>
#include <math.h>
void adding(int m, int n, int p, int q, int arr[m][n], int brr[p][q])
{
    int c[m][n];
    if (m == p && n == q)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] = 0;
                c[i][j] += arr[i][j] + brr[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("adding is not pssible");
    }
}

void subtract(int m, int n, int p, int q, int arr[m][n], int brr[p][q])
{
    int c[m][n];
    if (m == p && n == q)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                c[i][j] = 0;
                c[i][j] += arr[i][j] - brr[i][j];
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("subtracting is not pssible");
    }
}

void multiplication(int m, int n, int p, int q, int arr[m][n], int brr[p][q])
{
    if (n == p)
    {
        int c[m][q];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < n; k++)
                {
                    c[i][j] += arr[i][k] * brr[k][j];
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < q; j++)
            {
                printf("%d ", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf(" multiplication does not exist ");
    }
}

void transpose(int m, int n, int arr[m][n])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int determinant(int m, int n, int arr[m][n])
{
    if (m == n)
    {
        int det = 0, s = 1;
        int cof[m - 1][n - 1];
        if (n == 1)
        {
            return arr[0][0];
        }
        else
        {
            det = 0;
            int row, col;
            for (int c = 0; c < n; c++)
            {
                row = 0;
                col = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        cof[i][j] = 0;
                        if (i != 0 && j != c)
                        {
                            cof[row][col] = arr[i][j];
                            if (col < n - 2)
                            {
                                col++;
                            }
                            else
                            {
                                col = 0;
                                row++;
                            }
                        }
                    }
                }
                det = det + s * (arr[0][c] * determinant(m - 1, n - 1, cof));
                s = -1 * s;
            }
        }
        return det;
    }
    else
    {
        return 0;
    }
}

void Inverse(int m, int n, int arr[m][n])
{
    int row, col;
    int brr[m - 1][n - 1];
    float trr[m][n];
    float invrs[m][n];
    for (int p = 0; p < m; p++)
    {
        for (int q = 0; q < n; q++)
        {
            row = 0, col = 0;
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {

                    if (i != p && j != q)
                    {
                        brr[row][col] = arr[i][j];
                        if (col < n - 2)
                        {
                            col++;
                        }
                        else
                        {
                            col = 0;
                            row++;
                        }
                    }
                }
            }
            trr[p][q] = pow(-1, p + q) * determinant(m - 1, n - 1, brr);
        }
    }
    // For Cofactor we do transpose
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int temp = trr[i][j];
            trr[i][j] = trr[j][i];
            trr[j][i] = temp;
        }
    }
    int u = determinant(m, n, arr);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            invrs[i][j] = trr[i][j] / u;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%f ", invrs[i][j]);
        }
        printf("\n");
    }
}

int main()
{

    char opt;
    printf("choose an oprator: for multiplication '*',fot subtracion '-',for adding '+',for transpose '#'for determinat 'D'and for inverse '^' \n");
    scanf("%c", &opt);

    int m, n;
    printf("enter the first matrix rows and column \n");
    scanf("%d%d", &m, &n);
    int a1[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }

    int p, q;
    printf("enter the second matrix rows and column \n");
    scanf("%d%d", &p, &q);
    int b1[p][q];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &b1[i][j]);
        }
    }

    printf("\n");

    if (opt == '+')
        adding(m, n, p, q, a1, b1);
    else if (opt == '-')
        subtract(m, n, p, q, a1, b1);
    else if (opt == '*')
        multiplication(m, n, p, q, a1, b1);
    else if (opt == '#')
    {
        transpose(m, n, a1);
        printf("\n");
        transpose(p, q, b1);
    }
    else if (opt == 'D')
    {
        int x = determinant(m, n, a1);
        printf("The value of determinant of matrix a %d", x);
        printf("\n");
        int y = determinant(p, q, b1);
        printf("The value of determinant of matrix b %d", y);
    }
    else if (opt == '^')
    {
        int x = determinant(m, n, a1);
        if (x == 0)
        {
            printf("Inverse does not exist \n");
        }
        else
        {
            Inverse(m, n, a1);
            printf("\n");
        }
        int y = determinant(p, q, b1);
        if (y == 0)
        {
            printf("Inverse does not exist");
        }
        else
        {
            Inverse(p, q, b1);
        }
    }
    return 0;
}
//Special thanks to Dr. Shashank sir for guiding us.....