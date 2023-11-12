/*

Written by Khalil Gatto
10/21/2023

DESCRIBE ALGORITHM/PROGRAM


we'll continue our quest in space.  there will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  
more teachers in space.  nothing ends here;  our hopes and our journeys continue!

*/



#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define _CRT_SECURE_NO_WARNINGS


/* Define your functions here. */
int GetNumOfNonWSCharacters(char usrStr[]);
int GetNumOfWords(char usrStr[]);
void FixCapitalization(char usrStr[]);
void ReplaceExclamation(char usrStr[]);
void PrintMenu(void);
void ExecuteMenu(char option, char usrStr[]);

int main(void) {

	//below are the suggested steps that you may use

	//declare variables including string (array of type char)
	 //print "Enter a sample text:"
	 //let a user enter text/statement using fgets

	 //print the statement that a user just entered 

	 //while (choice is not 'q')
		 // call the function to print a menu
		 // print "Choose an option:"
		 // let a user enter a choice
		 // if the choice is not valid, print the menu and ask for the next choice 
		 // if the choice is valid, call the function "ExecuteMenu" to perform the task 
		 // based on the choice that the user just entered

	char user_inp[500];
	char menu_choice = 'a';

	printf("Enter a sample text:\n");
	fgets(user_inp, 500, stdin);	
	printf("You entered: %s\n", user_inp);

	while (menu_choice != 'q')
	{
		PrintMenu();

		printf("\nChoose an option:\n");
		scanf(" %c", &menu_choice);

		switch (menu_choice)
		{
			case 'c':
			case'w':
			case 'f':
			case 'r':
				ExecuteMenu(menu_choice, user_inp); //short circuit. equal to an or statement in an if statement.
				break;
			default: //if invalid selection, ask again/
				break;
		}

		if (menu_choice == 'q') //quit program.
		{
			break;
		}


	}

	return 0;
}


int GetNumOfNonWSCharacters(char usrStr[])
{
	int counter = 0;

	for (int i = 0; i < strlen(usrStr); i++)
	{
		if (usrStr[i] != ' ')
		{
			counter++;
		}
	}

	return counter - 1; //since it'll count \n, then subtract the counter by 1.
}

int GetNumOfWords(char usrStr[])
{
	int counter = 0;
	int sentence_count = 0;

	for (int i = 0; i < strlen(usrStr); i++)
	{
		if (usrStr[i] == ' ' && usrStr[i+1] != ' ') //No two consecutive whitespaces count as a word.
		{
			if (usrStr[i - 1] == '.') //Words usually end with a space unless its the last word in the sentence.
			{
				continue; //If a whitespace is detected, and the prev char was a period, then this is not a word. 
			}
			else
			{
				counter++;
			}
			
		}

	}

	return counter + 1; //Count the word at the end. This algorithm doesnt account for the last word until the end.
}

void FixCapitalization(char usrStr[])
{

	for (int i = 0; i < strlen(usrStr); i++)
	{
		//First letter is when you have some sort of punctuation (!,?,.) before the sentence besides the first word. 

		if (i == 0)
		{
			if (usrStr[i] >= 'a' && usrStr[i] <= 'z')
			{
				usrStr[i] = usrStr[i] - 32;
			}
		}

		if (usrStr[i] == '.' || usrStr[i] == '!' || usrStr[i] == '?')
		{
			if (usrStr[i + 2] >= 'a' && usrStr[i + 2] <= 'z')
			{
				usrStr[i + 2] = usrStr[i + 2] - 32;
			}
			else if (usrStr[i + 3] >= 'a' && usrStr[i + 3] <= 'z')
			{
				usrStr[i + 3] = usrStr[i + 3] - 32;
			}
			else if (usrStr[i + 4] >= 'a' && usrStr[i + 4] <= 'z')
			{
				usrStr[i + 4] = usrStr[i + 4] - 32;
			}
			else if (usrStr[i + 5] >= 'a' && usrStr[i + 5] <= 'z')
			{
				usrStr[i + 5] = usrStr[i + 5] - 32;
			}
			else
			{
				continue;
			}
			
		}
		else
		{
			continue;
		}
	}

	printf("Edited text: ");
	puts(usrStr);
}

void ReplaceExclamation(char usrStr[])
{
	for (int i = 0; i < strlen(usrStr); i++)
	{

		if (usrStr[i] == '!')
		{
			usrStr[i] = '.';
		}
		else
		{
			continue;
		}
	}

	printf("Edited text: ");
	puts(usrStr);
}

void PrintMenu(void)
{
	printf("MENU\n");
	printf("c - Number of non-whitespace characters\n");
	printf("w - Number of words\n");
	printf("f - Fix capitalization\n");
	printf("r - Replace all !'s\n");
	printf("q - Quit\n");

}

void ExecuteMenu(char option, char usrStr[])
{
	int num_non_WS_character = 0;
	int num_words = 0;

	switch (option)
	{
	case 'c':
		num_non_WS_character = GetNumOfNonWSCharacters(usrStr);
		printf("\nNumber of non-whitespace character: %d\n", num_non_WS_character);
		break;
	case'w':
		num_words = GetNumOfWords(usrStr);
		printf("\nNumber of words: %d\n\n", num_words);
		break;
	case 'f':
		FixCapitalization(usrStr);
		break;
	case 'r':
		ReplaceExclamation(usrStr); 
		break;
	default: //Just shouldnt happen.
		break;
	}
}

