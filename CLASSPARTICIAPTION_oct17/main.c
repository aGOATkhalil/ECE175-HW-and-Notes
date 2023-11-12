//
//  main.c
//  oct17_activity
//
//  Created by Khalil Gatto on 10/17/23.
//

//README
//First step, write functions (skip the main function for now)
//second step, write the code in main function

#include <stdio.h>
#include <stdlib.h> //rand()
#include <time.h>   //time()

#define _CRT_SECURE_NO_WARNINGS
#define ROW 3
#define COL 3

//print the board (print x for 1, O for 0)
void print_board(int x[][COL]);

//check the board
//return 0 when O win,
//       1 when X wins,
//       2 ñ Tie

int check_fun(int x[][COL]);
void generate_game(int x[][COL]);


int main(void)
{

    int outcome;
    char user_inp = 'y';

    srand(1);                  //fixed seed when writing the code
    srand((int)time(0));    // Unique seed

    int game[ROW][COL];


    
    while (user_inp != 'n')
    {
        generate_game(game);
        print_board(game);
        outcome = check_fun(game);

        if (outcome == 1)
        {
            printf("X won");
            outcome = NULL;
        }
        else if (outcome == 0)
        {
            printf("O won");
            outcome = NULL;
        }
        else
        {
            printf("Tie");
            outcome = NULL;
        }

        printf("\n");

        printf("play another game (y/n)?: ");
        scanf("%c%*c", &user_inp);
    }

    return 0;
}


void print_board(int x[][COL])
{
    //write the code here
    //print X when the element is 1,
    //print O when the element is 0

    for (int i = 0; i < ROW; i++)
    {

        for (int j = 0; j < COL; j++)
        {
            if (x[i][j] == 1)
            {
                printf("X");
            }
            else
            {
                printf("O");
            }
        }
        printf("\n");
    }

}

int check_fun(int x[][COL])
{
    int outcome; // returned value
    int temp_arr[ROW][COL];

    //write your code here to check whether there is a winner or a tie
    //Return 1 -> X win,  0-> O wins, 2 ñ Tie

    for (int i = 0; i < ROW; i++)
    {

        for (int j = 0; j < COL; j++)
        {
            temp_arr[i][j] = x[i][j];

        }
    }


    for (int i = 0; i < ROW * COL; i++)
    {
        if (temp_arr[i][0] == temp_arr[i][1] && temp_arr[i][1] == temp_arr[i][2]) //rows
        {
            switch (temp_arr[i][0])
            {
            case 1:
                outcome = 1;
                break;
            case 0:
                outcome = 0;
                break;
            default:
                printf("huh\n");
                break;
            }
        }
        else if (temp_arr[0][i] == temp_arr[1][i] && temp_arr[1][i] == temp_arr[2][i]) //columns
        {
            switch (temp_arr[0][i])
            {
            case 1:
                outcome = 1;
                break;
            case 0:
                outcome = 0;
                break;
            default:
                printf("huh\n");
                break;
            }
        }
        else
        {
            outcome = 2;
        }

    }

    if (temp_arr[0][0] == temp_arr[1][1] && temp_arr[1][1] == temp_arr[2][2])
    {
        switch (temp_arr[0][0])
        {
        case 1:
            outcome = 1;
            break;
        case 0:
            outcome = 0;
            break;
        default:
            printf("huh\n");
            break;
        }
    }
    else if (temp_arr[2][0] == temp_arr[1][1] && temp_arr[1][1] == temp_arr[0][2])
    {
        switch (temp_arr[2][0])
        {
        case 1:
            outcome = 1;
            break;
        case 0:
            outcome = 0;
            break;
        default:
            printf("huh\n");
            break;
        }
    }
    else
    {
        outcome = 2;
    }

    return outcome;
}
//////////////////////////////////////////////////////////////
//function below is used to generate a game of tic-tac-toe
void generate_game(int x[][COL])
{
    int sum, num_1pos = 0;
    int i, j;
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            x[i][j] = 0;

    if ((rand() % 2) == 0)  //want 5 O on the board
        num_1pos = 4;
    else //want 5 X on the board
        num_1pos = 5;

    //pick num_1pos positions to put 1
    while (1) {
        x[rand() % 3][rand() % 3] = 1;
        sum = 0;
        for (i = 0; i < ROW; i++)
            for (j = 0; j < COL; j++)
                sum = sum + x[i][j];
        if (sum == num_1pos)
            break;  // has num_1pos of 1's on the board
    }
}
