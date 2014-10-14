/******************************************************************************************
                              Name: sudoku.c
                              Author: Caprar Andrei Alex
                              Date: 13.10.2014

******************************************************************************************/

#include <stdio.h>

//check if spot is available
int available(int puzzle[][9], int row, int col, int num)
{
    int row_begin = (row/3) * 3;
    int col_begin = (col/3) * 3;
    int i, j;

    for(i=0; i<9; ++i)
    {
        if (puzzle[row][i] == num)
            return 0;
        if (puzzle[i][col] == num)
            return 0;
        if (puzzle[row_begin + (i%3)][col_begin + (i/3)] == num)
            return 0;
    }
    return 1;
}

//function to fill the puzzle
int fill(int puzzle[][9], int row, int col)
{
    int i;
    if(row<9 && col<9)
    {
        if(puzzle[row][col] != 0)
        {
            if((col+1)<9)
                return fill(puzzle, row, col+1);
            else if((row+1)<9)
                return fill(puzzle, row+1, 0);
            else return 1;
        }
        else
        {
            for(i=0; i<9; ++i)
            {
                if(available(puzzle, row, col, i+1))
                {
                    puzzle[row][col] = i+1;
                    if((col+1)<9)
                    {
                        if(fill(puzzle, row, col +1))
                            return 1;
                        else
                            puzzle[row][col] = 0;
                    }
                    else if((row+1)<9)
                    {
                        if(fill(puzzle, row+1, 0))
                            return 1;
                        else
                            puzzle[row][col] = 0;
                    }
                    else return 1;
                }
            }
        }
        return 0;
    }
    else return 1;
}

int main()
{
    int i, j;

    //set puzzle start values
    int puzzle[9][9]={{0, 0, 0, 0, 0, 0, 0, 9, 0},
                      {1, 9, 0, 4, 7, 0, 6, 0, 8},
                      {0, 5, 2, 8, 1, 9, 4, 0, 7},
                      {2, 0, 0, 0, 4, 8, 0, 0, 0},
                      {0, 0, 9, 0, 0, 0, 5, 0, 0},
                      {0, 0, 0, 7, 5, 0, 0, 0, 9},
                      {9, 0, 7, 3, 6, 4, 1, 8, 0},
                      {5, 0, 6, 0, 8, 1, 0, 7, 4},
                      {0, 8, 0, 0, 0, 0, 0, 0, 0}};

    if(fill(puzzle, 0, 0))
    {
        for(i=1; i<10; ++i)
        {
            for(j=1; j<10; ++j)
                printf("|%d", puzzle[i-1][j-1]);
            printf("|\n");
        }
    }
    else printf("\n\nNo more moves\n\n");

    return 0;
}