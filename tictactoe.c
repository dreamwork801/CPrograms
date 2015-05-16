//Zach Colby Insert Date

//included libraries
#include <stdio.h>
#define SIZE 4

int main() {
    int x, y, i, j;
    int flag, winner = 0;
    char board[SIZE][SIZE] = {
    {'0','1','2','3'} ,
    {'1','-','-','-'} ,
    {'2','-','-','-'} ,
    {'3','-','-','-'}
    };

    printBoard(board);
    printf("Player 1 shall be X, Player 2 shall be Y\n");

    //loop while until there is a winner or draw
    while (winner == 0){

        //Get Player 1's postion.
        printf("Player 1, where would you like to go? (row column) Example: 1 2\n");
        scanf("%d %d", &x, &y);

        //Validate the input.
        flag = validateInput(x,y, board);
        while (flag != 0){
            printf("Player 1, please give a valid input\n");
            scanf("%d %d", &x, &y);
            flag = validateInput(x,y, board);
        }

        //Set Player 1's move
        board[x][y] = 'X';
        flag = 0;
        printBoard(board);

        //Check for Player 1 win.
        if (checkForWin(board, 1, x, y) == 1){
            printf("Congrats Player 1! You won!");
            break;
        }

        //Check if the board is filled up, therefore a draw.
        if (checkForDraw(board) == 1){
            printf("CAT! No one wins");
            break;
        }

        //Get Player 2's position
        printf("Player 2, where would you like to go? (row column) Example: 1 2\n");
        scanf("%d %d", &x, &y);

        //Validate the input.
        flag = validateInput(x,y, board);
        while (flag != 0){
            printf("Player 2, please give a valid input\n");
            scanf("%d %d", &x, &y);
            flag = validateInput(x,y, board);
        }
        board[x][y] = 'O';
        flag = 0;
        printBoard(board);

        //Check for Player 2 win.
        if (checkForWin(board, 2, x, y) == 1){
            printf("Congrats Player 2! You won!");
            break;
        }
    }

    return 0;
}

//Method that prints out the current playing board
void printBoard(char board[SIZE][SIZE]){
    int i,j;
    for (i=0; i<=3; i++){
        for (j=0; j<=3; j++){
            printf("%c",board[i][j]);
            }
        printf("\n");
    }
}

//Method that validates the input is a valid space
//The input must be a number <=SIZE and not 0.
//The point given also must also be a blank space on the board.
int validateInput(int x, int y, char board[SIZE][SIZE]){
    if (x == 0 || y == 0){
        printf("Please give a valid nonzero input.\n");
        return 1;
    }
    if (x > SIZE || y > SIZE){
        printf("The row or column given does not exists.\n");
        return 1;
    }
    if (board[x][y] != '-'){
        printf("That space has already been taken.\n");
        return 1;
    }
    return 0;
}

//Method that checks if the entire board is filled up
int checkForDraw(char board[SIZE][SIZE]){
    int i,j;
    for (i=1; i<=3; i++){
        for (j=1; j<=3; j++){
            if (board[i][j] == '-')
                return 0;
            }
    }
    return 1;
}

//Method that checks for a win
int checkForWin(char board[SIZE][SIZE], int player, int x, int y){

    //Assume there is a winner, try to prove not
    char t = ' ';
    int win = 1;
    int i = 1;
    if (player == 1)
        t = 'X';
    else
        t = 'O';

    //Check current row
    for (i=1; i<SIZE; i++){
        if (board[x][i] != t)
            win = 0;
    }
    //Winner for the row?
    if (win == 1)
        return 1;
    win = 1;

    //Check current column
    for (i=1; i<SIZE; i++){
        if (board[i][y] != t)
            win = 0;
    }
    //Winner for column?
    if (win == 1)
        return 1;
    win = 1;

    //Check forward diagonal.
    for (i=1; i<SIZE; i++){
        if (board[i][i] != t)
            win = 0;
    }
    //Winner for forward diagonal?
    if (win == 1)
        return 1;
    win = 1;

    //Check backward diagonal.
    for (i=1; i<SIZE; i++){
        if (board[i][SIZE-i] != t)
            win = 0;
    }
    //Winner for backward diagonal?
    if (win == 1)
        return 1;

    return 0;
}

