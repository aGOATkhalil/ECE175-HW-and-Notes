#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

//int main(void) 
//{
//	//char nameAndTitle[50];
//	//char subString[20];
//	//char* stringPointer = NULL;
//
//	//strcpy(nameAndTitle, "Ms. Ann Hill");
//
//	//stringPointer = strchr(nameAndTitle, 'H');
//	//strcpy(subString, stringPointer);
//
//	//printf("%s\n", subString);
//	
//
//
//	return 0;
//
//}


//#include <stdio.h>
//#include <string.h>
//
//int main(void) {
//	char nameAndTitle[50];
//	char subString[20];
//	char* stringPointer = NULL;
//
//	strcpy(nameAndTitle, "Dr. Armando Ace Webb");
//
//	stringPointer = strrchr(nameAndTitle, 'A');
//	strcpy(subString, stringPointer);
//
//	printf("%s\n", subString);
//
//	return 0;
//
//}

//#include <stdio.h>
//#include <string.h>
//
//int main(void) {
//    char nameAndTitle[50];
//    char subString[20];
//    char* stringPointer = NULL;
//
//    strcpy(nameAndTitle, "Dr. Lily Allen");
//
//    stringPointer = strstr(nameAndTitle, "Mr.");
//    if (stringPointer != NULL) {
//        printf("Hello sir\n");
//    }
//    else {
//        printf("Hello Dr. Allen\n");
//    }
//
//    return 0;
//}



#include <stdio.h>
#include <string.h>

int main(void) {
    char userString[50];
    char* stringPointer = NULL;

    strcpy(userString, "I.love.to.code!");

    stringPointer = strchr(userString, '.');
    while (stringPointer != NULL) {
        *stringPointer = ' ';
        stringPointer = strchr(userString, '.');
    }

    printf("%s\n", userString);

    return 0;
}