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
int can_place(int k_th_queeen, int position)
{
    for (int j = 1; j <= k_th_queeen; j++)
    {
        // first check wheather any queen is placed in that column 
        // next check wheather any queen can attack from daigonal
        if ((x[j] == position) || (abs(x[j] - position) == abs(j - k_th_queeen)))
            return FALSE;
    }
    return TRUE;
}

void n_queens(int k_th_queeen, int no_queens)
{
    for (int position = 1; position <= no_queens; position++)
    {
        if (can_place(k_th_queeen, position))
        {
            x[k_th_queeen] = position;
            // if all queens are places then print the positionition else place next queen remaining
            if (k_th_queeen == no_queens)
            {
                for (int a = 1; a <= no_queens; a++)
                {
                    printf("%d ", x[a]);
                }
                printf("\n");
            }
            else
            {
                // placing next queen 
                n_queens(k_th_queeen + 1, no_queens);
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