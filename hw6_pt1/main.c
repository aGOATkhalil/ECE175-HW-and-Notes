//
//
//  hw6
//
//  Created by Khalil Gatto on 10/10/23.
//

/*

 DONT FORGET TO WRITE COMMENTS!

 */

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define NUM_CHOICES 5
#define INDEX_VALS 5

char getMenu(char menu_choice)
{
    char arr_selection[NUM_CHOICES] = { 'u', 'a', 'r', 'o', 'q' };

    printf("\nMENU\n");

    printf("%c - Update player rating\n", arr_selection[0]);
    printf("%c - Output players above a rating\n", arr_selection[1]);
    printf("%c - Replace player\n", arr_selection[2]);
    printf("%c - Output roster\n", arr_selection[3]);
    printf("%c - Quit\n", arr_selection[4]);

    printf("\nChoose an option:\n");
    scanf("%*c%c", &menu_choice);

    return menu_choice;

}

void outputRoster(int *jersey_num_ptr, int *player_rating_ptr)
{

    printf("\nROSTER\n");
    for (int i = 0; i < INDEX_VALS; i++)
    {
        printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersey_num_ptr[i], player_rating_ptr[i]);
    }

}


int updatePlayerStats(int *jersey_num_ptr, int *player_rating_ptr)
{
    
    int temp_jersey_num = NULL;
    int temp_player_rating = NULL;
    

    printf("Enter a jersey number:\n");
    scanf("%d", &temp_jersey_num);

    printf("Enter a new rating for player:\n");
    scanf("%d", &temp_player_rating);

    for (int i = 0; i < INDEX_VALS; i++) //search for index where jersey number is
    {
        if (temp_jersey_num == jersey_num_ptr[i])
        {
            player_rating_ptr[i] = temp_player_rating;
        }

    }
}

int outpPlayersAboveRating(int *jersey_num_ptr, int *player_rating_ptr)
{
    int inp_num;

    printf("Enter a rating:\n");
    scanf("%d", &inp_num);
    printf("\nABOVE %d\n", inp_num);

    for (int i = 0; i < INDEX_VALS; i++)
    {
        if (player_rating_ptr[i] > inp_num)
        {
            printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersey_num_ptr[i], player_rating_ptr[i]);
        }
    }

}

int replacePlayer(int *jersey_num_ptr, int *player_rating_ptr)
{

    int temp_jersey_num;
    int temp_player_rating;
    int new_jersey_num;

    printf("Enter a jersey number:\n");
    scanf("%d", &temp_jersey_num);

    for (int i = 0; i < INDEX_VALS; i++)
    {
        if (jersey_num_ptr[i] == temp_jersey_num) //if someone entered an existing jersey, then replace
        {

            printf("Enter a new jersey number:\n");
            scanf("%d", &new_jersey_num);

            printf("Enter a rating for the new player:\n");
            scanf("%d", &temp_player_rating);

            jersey_num_ptr[i] = new_jersey_num;
            player_rating_ptr[i] = temp_player_rating;
            break;
        }
    }


    
}


int main()
{

    /*
     (1) Prompt the user to input five pairs of numbers: A player's jersey number (0 - 99) and the player's rating (1 - 9). 
     Store the jersey numbers in one int array and the ratings
     in another int array. Output these arrays (i.e., output the roster).
     */

    char menu_choice = NULL;
    //char *menu_choice_ptr = &menu_choice;
    int jersey_numbers[INDEX_VALS];
    int player_rating[INDEX_VALS];

    int* jersey_num_ptr;
    int* player_rating_ptr;

    for (int i = 0; i < INDEX_VALS; i++) //collect player rating and jersey
    {
        printf("Enter player %d's jersey number:\n", i + 1);
        scanf("%d", &jersey_numbers[i]);

        printf("Enter player %d's rating:\n", i + 1);
        scanf("%d", &player_rating[i]);

        printf("\n");

    }

    printf("ROSTER\n");
    for (int i = 0; i < INDEX_VALS; i++)
    {
        printf("Player %d -- Jersey number: %d, Rating: %d\n", i + 1, jersey_numbers[i], player_rating[i]);
    }

    do //show menu until user asks to quit.
    {
        menu_choice = getMenu(menu_choice);

        if (menu_choice == 'o')
        {
            outputRoster(&jersey_numbers, &player_rating);
        }
        else if (menu_choice == 'u')
        {

            updatePlayerStats(&jersey_numbers, &player_rating); //COME BACK HERE TOMORROW. LOOK AT BALLS IN FOR LOOP.
        }
        else if (menu_choice == 'a')
        {
            outpPlayersAboveRating(&jersey_numbers, &player_rating);
        }
        else if (menu_choice == 'r')
        {
            replacePlayer(&jersey_numbers, &player_rating);
        }


    } while (menu_choice != 'q');
    




    //printf("choice: %c\n", menu_choice); //for debugging. 



    return 0;
}
