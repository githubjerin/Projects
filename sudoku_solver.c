/*
Date : 28.03.2022
Place : India
|||||||||||||||||SUDOKU SOLVER||||||||||||||||||||
This program generates the solution for a given 
Sudoku board in a non-recursive fashion. The time 
complexity of this program is O(9^(n*n)).

The progress of the code can be viewed by uncommenting 
the section in the main function. The time complexity is
then O(n^(9^(n*n)))!!

Contributed by JERIN B S.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//*************MODIFY THIS BOARD****************
int board[9][9] = { {0, 0, 4, 0, 5, 0, 0, 0, 0}, 
                    {0, 0, 6, 0, 0, 0, 0, 3, 0},
                    {5, 3, 0, 7, 0, 0, 0, 0, 8},
                    {1, 2, 0, 0, 6, 0, 0, 8, 0},
                    {0, 0, 3, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 9, 0, 0, 7},
                    {4, 0, 0, 0, 0, 0, 0, 0, 0},
                    {8, 5, 0, 0, 1, 0, 0, 2, 0},
                    {0, 0, 0, 6, 0, 0, 1, 0, 0}};
int availability[9][9]; //to keep track of which elements can be modified

int isbroken(int board[9][9], int row, int column, int element);
int isavailable(int availability[9][9], int row, int column);
void traverse(int board[9][9]);

int main(){
    int i, j, k;
    clock_t start, end;
    double time_used;

    start = clock();
    //Creating an availability array 
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(board[i][j] != 0){
                continue;
            }
            else{
                availability[i][j] = 1;
            }
        }
    }

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            k = 0;
            wing_1:
            if(isavailable(availability, i, j)){
                do{
                    ++k;
                    if(k > 9){
                        board[i][j] = 0;
                        do{
                            --j;
                            if(j < 0){
                                j = 8;
                                --i;
                            }
                            else{};
                        }while(!isavailable(availability, i, j));
                        k = board[i][j];
                        goto wing_1;
                    }
                    //************UNCOMMENT THIS SECTION TO SEE THE PROGRESS*********
                    /*printf("\e[1;H\e[2J");//Clear screen using Regex
                    traverse(board);*/
                }while(isbroken(board, i, j, k));
                board[i][j] = k;
            }
            else{};
        }
    }
    end = clock();
    time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\e[1;H\e[2J");//Clear screen using Regex
    traverse(board);
    printf("Time elapsed = %lf s", time_used);
    
    return 0;
}

int isbroken(int board[9][9], int row, int column, int element){
    int i, j;
    //Checking rows and columns
    for(i = 0; i < 9; i++){
        if((board[row][i] == element) /*&& (i != column)*/){
            return 1;
        }
        else if((board[i][column] == element) /*&& (i != row)*/){
            return 1;
        }
        else{
            continue;
        }
    }
    //moving to the first position in the sub grid.
    while((row % 3) != 0){
        --row;
    }
    while((column % 3) != 0){
        --column;
    }
    //Checking sub grid
    for(i = row; i < (row + 3); i++){
        for(j = column; j < (column + 3); j++){
            if((board[i][j] == element) /*&& (i != row) && (j != column)*/){
                return 1;
            }
            else{};
        }
    }

    return 0;
}

int isavailable(int availability[9][9], int row, int column){
    if(availability[row][column] == 0){
        return 0;
    }
    else{
        return 1;
    }
}

void traverse(int board[9][9]){
    int i, j;

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            printf("%d   ", board[i][j]);
        }
        printf("\n");
    }
}