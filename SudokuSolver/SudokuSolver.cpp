#include <iostream>

bool fitsRow(int number, int row, int board[9][9]){
    bool result = true;
    for (int i = 0; i < 9; i++) {
        if (number == board[row][i]) {
            result = false;
        }
    }
    return result;
}

bool fitsCol(int number, int col, int board[9][9]) {
    bool result = true;
    for (int i = 0; i < 9; i++) {
        if (number == board[i][col]) {
            result = false;
        }
    }
    return result;
}
/*
Box labeling
-----------------
|0,0 | 1,0 | 2,0|
-----------------
|0,1 | 1,1 | 2,1|
-----------------
|0,2 | 1,2 | 2,2|
-----------------
*/
bool fitsBox(int number, int row, int col, int board[9][9]) {
    bool result = true;
    int xBox = (row / 3) * 3; // making it round to top corner of box
    int yBox = (col / 3) * 3; // making it round to top corner of box
    for (int i = xBox; i < 3; i++) {
        for (int j = yBox; j < 3; j++) {
            if (number == board[i][j]) {
                result = false;
            }
        }
    }
    return result;
}

bool checkFits(int number, int row, int col, int board[9][9]) {
    return fitsRow(number, row, board) &&
           fitsCol(number, col, board) &&
           fitsBox(number, row, col, board);
                    
}

void printBoard(int board[9][9]) {
    printf("-------------\n");
    for (int i = 0; i < 9; i++) {
        printf("|");
        for (int j = 0; j < 9; j++) {
            printf("%d", board[i][j]);
            if (((j+1) % 3) == 0) {
                printf("|");
            }
        }
        printf("\n");
        if (((i+1) % 3) == 0) {
            printf("-------------\n");
        }
    }
}

bool findEmptyBox(int& row, int& col, int board[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool SolveSudoku(int board[9][9])
{
    int row, col;

    if (!findEmptyBox(row, col, board)) {
        return true;
    }

    for (int num = 1; num <= 9; num++)
    {
        if (checkFits(num, row, col, board))
        {
            board[row][col] = num;

            if (SolveSudoku(board)) {
                return true;
            }

            board[row][col] = 0;
        }
        //printBoard(board);
    }
    return false;
}

int main(){
  
    //normal puzzle
    int board[9][9] =   { {5, 3, 0, 0, 7, 0, 0, 0, 0},
                          {6, 0, 0, 1, 9, 5, 0, 0, 0},
                          {0, 9, 8, 0, 0, 0, 0, 6, 0},
                          {8, 0, 0, 0, 6, 0, 0, 0, 3},
                          {4, 0, 0, 8, 0, 3, 0, 0, 1},
                          {7, 0, 0, 0, 2, 0, 0, 0, 6},
                          {0, 6, 0, 0, 0, 0, 2, 8, 0},
                          {0, 0, 0, 4, 1, 9, 0, 0, 5},
                          {0, 0, 0, 0, 8, 0, 0, 7, 9} };
  
    /*
    //worlds hardest sudoku, too hard...
    int board[9][9] = { {8, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 3, 6, 0, 0, 0, 0, 0},
                        {0, 7, 0, 0, 9, 0, 2, 0, 0},
                        {0, 5, 0, 0, 0, 7, 0, 0, 0},
                        {0, 0, 0, 0, 4, 5, 7, 0, 0},
                        {0, 0, 1, 0, 0, 0, 0, 6, 8},
                        {0, 0, 1, 0, 0, 0, 0, 6, 8},
                        {0, 0, 8, 5, 0, 0, 0, 1, 0},
                        {0, 9, 0, 0, 0, 0, 4, 0, 0} };
    */
    printBoard(board);
    if (SolveSudoku(board)) {
        printf("\n");
        printBoard(board);
    }
    else {
        printf("Could not find a solution\n");
    }

}
