#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>


char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(){
    printf("%c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n--|---|--");
    printf("\n%c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n--|---|--");
    printf("\n%c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int checkFreeSpaces(){
    int freeSpaces = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                freeSpaces++;
            }
        }
    }
    return freeSpaces;
}

void playerMove(){
    int x;
    int y;
    bool valid = false;
    do{
        printf("Enter row-->");
        scanf("%d", &x);
        x--;
        printf("Enter column-->");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("Invalid move\n");
        }else{
            board[x][y] = PLAYER;
            valid = true;
        }
    }while(!valid);
}

void computerMove(){
    int x;
    int y;
    bool valid = false;
    srand(time(0));
    do{
        x = rand()%3;
        y = rand()%3;

        if(board[x][y] == ' '){
            board[x][y] = COMPUTER;
            valid  = true;
        }
    }while(!valid);
}

char checkWinner(){
    //check rows
    for(int i = 0; i < 3; i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            return board[i][0];
        }
    }
    //check columns
    for(int i = 0; i < 3; i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            return board[0][i];
        }
    }
    //check diagonal
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[0][0] == board[2][0]){
        return board[0][2];
    }

    return ' ';
}

void printWinner(char winner){
    if(winner == PLAYER){
        printf("\nYou win!!!");
    }else if(winner  == COMPUTER){
        printf("\nYou lose :(");
    }else{
        printf("\nNobody wins!");
    }
}

int main(){
    char response;
    do{
        char winner = ' ';
        resetBoard();

        while(winner = ' ' && checkFreeSpaces() != 0){
            printf("Current board:\n");
            printBoard();

            playerMove();
            printf("Your move:\n");
            printBoard();
            winner = checkWinner();

            if(winner != ' ' || checkFreeSpaces() == 0){
                break;
            }

            printf("Computers move:\n");
            computerMove();
            printBoard();
            winner = checkWinner();

            if(winner != ' ' || checkFreeSpaces() == 0){
                break;
            }
        }

        printWinner(winner);
        printf("\nWould you like to play again(Y/N) -->");
        scanf("%c");
        scanf("%c", &response);
        response = toupper(response);
    }while(response == 'Y');
    

    return 0;
}