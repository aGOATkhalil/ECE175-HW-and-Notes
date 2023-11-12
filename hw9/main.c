/*

    main.c
    hw9

    Created by Khalil Gatto on 10/31/23.


    # UNDERSTANDING THE ASSIGNMENT

        ## Characteristics of the program:
             * Must have dynamic arrays. The size is adjusted and filled.
             * Interactive. (q/Q to quit).

        ## Algorithm Description:
        Given a set of data in a .txt file, this program seperates the movie titles, years, ratings, and minutes
        of movie length from the given file. Then, it asks the user to choose whether they would like to see
        movies at a given, or more than, movie duration, movie length, movie year, and rating. 

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNINGS

typedef struct movie_s {

    char title[100];
    double rating; //rating from 1 - 10
    int duration; //in minutes
    int year;

}movies;

void Load_Struct(movies* ptr, FILE* inp) { //used for all cases.

    /*   DATA SET 1
    ------------------------------------------------
        The Lord of the Rings: The Two Towers
        8.70  179 2002
    ------------------------------------------------
        - Title (string)
        - rating (double)
        - duration (minutes)
        - year

    */

    fgets(ptr->title, 100, inp);

    int strlength = strlen(ptr->title); //info can be organized without this loop. however, the output is a little funky.
    for (int i = 0; i < strlength; i++)
    {
        if (ptr->title[strlength - 1] == '\n') { //remove newline
            ptr->title[strlength - 1] = 0;
        }
    }

    fscanf(inp, "%lf", &ptr->rating);
    fscanf(inp, "%d", &ptr->duration);
    fscanf(inp, "%d", &ptr->year);

    char newline[5];
    fgets(newline, 5, inp); //read next line correctly
}


void swap(movies* x, movies* y) {

    movies temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(movies* x, int size) {

    int i, j, max;
    for (i = 0; i < size; i++)
    {
        max = i;// start searching from currently unsorted
        for (j = i; j < size; j++)
        {
            if (x[j].rating > x[max].rating) //change it to use “rating” member of movies
            {
                max = j; //if found a larger element, move it to the front
            }
        }
        swap(&x[i], &x[max]);
    }
}


void print_menu() {

    printf("\n");
    printf("1: search movie(s) with a keyword\n");
    printf("2: search movie(s) by above rating\n");
    printf("3: search movie(s) by year\n");
    printf("4: search movie(s) by above duration\n\n");

}


int main() {

    movies* movie_search; //pointer for all info of movies related to user search
    FILE* inp = fopen("movies_database.txt", "r");
    char get_consent = 'a';
    int user_choice = -1;
    int num_movies;

    if (inp == NULL) {
        printf("ERROR: This file cannot be opened.\n");
        return 0;
    }

    printf("Enter number of movies you want to use from the database: ");
    while (scanf("%d", &num_movies) == 0) //if scanf failed to scan an integer
    {
        printf("Enter number of movies you want to use from the database: ");

        int c;
        while ((c = getchar()) != '\n' && c != EOF); //clear the stdin

        //thanks to Spikatrix on StackOverflow. March 7 2015
    }

    do
    {
        int get_duration;
        double get_rating;
        int get_year;
        char get_keyword[50];

        int count = 0;
        int limit_count = 0;
        print_menu();

        while (user_choice > 4 || user_choice < 1) //must force user to select 1-4
        {
            printf("Choose 1-4 from the above options: ");
            scanf("%d", &user_choice);

            int c;
            while ((c = getchar()) != '\n' && c != EOF); //flush input buffer
        }

        printf("\n");
        movie_search = (movies*)malloc(num_movies * sizeof(movies));

        for (int i = 0; i < num_movies; i++) //load info into struct for comparison later.
        {
            Load_Struct(&movie_search[i], inp);
            //printf("%s %lf %d\n", movie_search[i].title, movie_search[i].rating, movie_search[i].duration); //for debugging
        }

        selection_sort(movie_search, num_movies); //sort movie data by rating.

        switch (user_choice)
        {
        case 1:
            printf("Enter the keyword: ");
            scanf("%s", get_keyword);

            for (int i = 0; i < num_movies; i++) //count first then display
            {
                const char* position = movie_search[i].title;
                position = strstr(position, get_keyword);

                if (position != NULL) //keyword exists at i
                {
                    count++;
                }
            }
            if (count == 0)
            {
                printf("No movies with %s\n", get_keyword);
            }
            else if (count >= 10)
            {
                printf("%d movies with %s\n", count, get_keyword);
                printf("First 10 movies sorted by rating are\n");
                for (int i = 0; i < num_movies; i++) //now compare and find search
                {
                    const char* position = movie_search[i].title;
                    position = strstr(position, get_keyword);

                    if (position != NULL) //keyword exists at i
                    {
                        //printf("%s\n", movie_search[i].title); //correctly reads the titles
                        printf("%.2lf %s(%d,%d mins)\n", movie_search[i].rating, movie_search[i].title, movie_search[i].year, movie_search[i].duration);
                        limit_count++;
                        if (limit_count == 10) {
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("%d movies with %s\n", count, get_keyword);

                for (int i = 0; i < num_movies; i++) //now compare and find search
                {
                    const char* position = movie_search[i].title;
                    position = strstr(position, get_keyword);

                    if (position != NULL) //keyword exists at i
                    {
                        //printf("%s\n", movie_search[i].title); //correctly reads the titles
                        printf("%.2lf %s(%d,%d mins)\n", movie_search[i].rating, movie_search[i].title, movie_search[i].year, movie_search[i].duration);

                    }
                }
            }
            user_choice = -1;
            break;

        case 2:
            //above rating function
            printf("Enter the rating: ");
            scanf("%lf", &get_rating);

            for (int i = 0; i < num_movies; i++) //count first then display
            {
                if (get_rating <= movie_search[i].rating) //keyword exists at i
                {
                    count++;
                }
            }
            if (count == 0)
            {
                printf("No movies greater than %.2lf rating\n", get_rating);
            }
            else if (count >= 10)
            {
                printf("%d movies greater than %.2lf rating\n", count, get_rating);
                printf("First 10 movies sroted by rating are\n");
                for (int i = 0; i < num_movies; i++) //now compare and find search
                {
                    if (get_rating < movie_search[i].rating)
                    {
                        printf("%.2lf %s(%d,%d mins)\n", movie_search[i].rating, movie_search[i].title, movie_search[i].year, movie_search[i].duration);
                        limit_count++;
                        if (limit_count == 10) {
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("%d movies greater than %.2lf rating\n", count, get_rating);
                for (int i = 0; i < num_movies; i++) //now compare and find search
                {
                    if (get_rating < movie_search[i].rating)
                    {
                        printf("%.2lf %s(%d,%d mins)\n", movie_search[i].rating, movie_search[i].title, movie_search[i].year, movie_search[i].duration);

                    }
                }
            }
            user_choice = -1;
            break;

        case 3:
            //year function
            printf("Enter the year: ");
            scanf("%d", &get_year);

            for (int i = 0; i < num_movies; i++) //count first then display
            {
                if (get_year == movie_search[i].year) 
                {
                    count++;
                }
            }
            if (count == 0)
            {
                printf("No movies with year %d\n", get_year);
            }
            else if (count >= 10)
            {
                printf("%d movies in the year %d\n", count, get_year);
                printf("First 10 movies sorted by rating are\n");
                for (int i = 0; i < num_movies; i++) //now compare and find search
                {
                    if (get_year == movie_search[i].year)
                    {
                        printf("%.2lf %s(%d,%d mins)\n", movie_search[i].rating, movie_search[i].title, movie_search[i].year, movie_search[i].duration);
                        limit_count++;
                        if (limit_count == 10) {
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("%d movies in the year %d\n", count, get_year);
                for (int i = 0; i < num_movies; i++) //now compare and find search
                {
                    if (get_year == movie_search[i].year)
                    {
                        printf("%.2lf %s(%d,%d mins)\n", movie_search[i].rating, movie_search[i].title, movie_search[i].year, movie_search[i].duration);
                    }
                }
            }
            user_choice = -1;
            break;

        case 4:
            //above duration function
            printf("Enter duration (in mins): ");
            scanf("%d", &get_duration);

            for (int i = 0; i < num_movies; i++) //count first then display
            {
                if (get_duration <= movie_search[i].duration) 
                {
                    count++;
                }
            }
            if (count == 0)
            {
                printf("No movies greater than %d minutes\n", get_duration);
            }
            else if (count >= 10)
            {
                printf("%d movies greater than %d minutes\n", count, get_duration);
                printf("First 10 movies sroted by rating are\n");
                for (int i = 0; i < num_movies; i++) //now compare and find search
                {
                    if (get_duration <= movie_search[i].duration)
                    {
                        printf("%.2lf %s(%d,%d mins)\n", movie_search[i].rating, movie_search[i].title, movie_search[i].year, movie_search[i].duration);
                        limit_count++;
                        if (limit_count == 10) {
                            break;
                        }
                    }
                }
            }
            else
            {
                printf("%d movies with duration higher than %d minutes\n", count, get_duration);
                for (int i = 0; i < num_movies; i++) //now compare and find search
                {
                    if (get_rating < movie_search[i].duration)
                    {
                        printf("%.2lf %s(%d,%d mins)\n", movie_search[i].rating, movie_search[i].title, movie_search[i].year, movie_search[i].duration);
                    }
                }
            }
            user_choice = -1;
            break;

        default:
            printf("Something went wrong.\n"); //will never reach this since while loop ensures this.
            break;
        }

        printf("Press (q/Q) to quit:");
        scanf(" %c", &get_consent);

        free(movie_search); //free my boy movie_search he aint do nothing wrong
        movie_search = NULL;
        rewind(inp); //restart pointer from beginning of file.
        printf("\n");

    } while (get_consent != 'Q' && get_consent != 'q');


    fclose(inp);
    return 0;
}
