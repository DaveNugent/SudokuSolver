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
    printf("------------\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", board[i][j]);
            if (((j+1) % 3) == 0) {
                printf("|");
            }
        }
        printf("\n");
        if (((i+1) % 3) == 0) {
            printf("------------\n");
        }
        //printf("\n---------------------------\n");
        //printf("|\n");
    }
}
int main(){
    int board[9][9] = { {3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0} };
    printBoard(board);
}
