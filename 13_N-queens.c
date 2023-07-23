/*
Consider the n-queens puzzle in which the goal is to place N queens on
an N×N chessboard such that no two queens attack each other. A queen can
attack horizontally, vertically, or diagonally. Given an integer N, return all
distinct solutions to the N-queens puzzle. Note: Use Backtracking technique.
*/

#include <stdio.h>
#include <math.h>
#define FALSE 0
#define TRUE 1

int x[20];
int place(int k, int i)
{
    for (int j = 1; j <= k; j++)
    {
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return FALSE;
    }
    return TRUE;
}

void n_queens(int k, int no_queens)
{
    for (int i = 1; i <= no_queens; i++)
    {
        if (place(k, i))
        {
            x[k] = i;
            // if all queens are places then print the position else place next queen remaining
            if (k == no_queens)
            {
                for (int a = 1; a <= no_queens; a++)
                {
                    printf("%d ", x[a]);
                }
                printf("\n");
            }
            else
            {
                n_queens(k + 1, no_queens);
            }
        }
    }
}

int main()
{
    int no_queens;
    printf("Enter number of queeens : ");
    scanf("%d", &no_queens);
    printf("The solution for N Queens problem is : ");
    n_queens(1, no_queens);

    return 0;
}

/* Sample input and output

Enter number of queeens : 4
The solution for N Queens problem is : 3 1 4 2

*/