/*                                      **
** COMP 322/L Project 1                 **
**                                      **
** This little project simulates some   **
** Linux commands in C.                 **
**				  - Mohammad M. Zahed   **
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


// Method to print the current working directory.
void pwd(){
	
	char *temp;
	
	temp = ( char * )malloc( 100 * sizeof( char ) );
	getcwd( temp,100 );
	
	printf( "\nThe current working directory is: %s \n", temp );
}

/*********************************************************/

// Method to print any extra arguments
void echo( char str[300] ){
	
	printf( "\n%s", str );
}

/*********************************************************/

// Method to print all folders and files in a working directory
void ls(){
	
	DIR *temp;
    struct dirent *dir;
	
    temp = opendir( "." );
	
	printf("\n Listing all folders and files in the current directory: \n");
	
    if ( temp ){
		
        while ( ( dir = readdir( temp ) ) != NULL ){
			
            printf("%s\n", dir -> d_name);
        }
		
        closedir( temp );
    }
}

/*********************************************************/

// Method printed when user types 'help'
void helpList(){
	
	printf( "\nList of commands available in this program: " );
	printf( "\n pwd - Displays the current working directory. Does not accept arguments." );
	printf( "\n echo - Displays any extra arguments to screen. Accepts arguments." );
	printf( "\n ls - Displays all files and folders in the current directory." );
	printf( "\n 	 Arguments not needed." );
	printf( "\n help - Displays a list of all commands available in this program." );
	printf( "\n exit - Quits the program. \n" );
}

/*********************************************************/

int main(){
	
	
	char str[200];
    char stringArr[100][100]; // This can store 100 words, each 100 characters long
	
	// These 5 char arrays
	// are used to compare strings the user enters
	char pwdStr[3] = { 'p', 'w', 'd' };
	char echoStr[4] = {'e', 'c', 'h', 'o'};
	char lsStr[2] = { 'l', 's' };
	char helpStr[4] = {'h', 'e', 'l', 'p'};
	char exitStr[4] = {'e', 'x', 'i', 't'};
	int i, j, counter;
	int pwdCounter, echoCounter, lsCounter;
	int helpCounter, exitCounter, invalidCounter;
	_Bool pwdBool, echoBool, lsBool, helpBool;
	
	pwdBool = echoBool = lsBool = helpBool = 0;
	pwdCounter = echoCounter = lsCounter = 0;
	helpCounter = exitCounter = invalidCounter = 0;
	
	while( exitCounter < 1 ){
		
		gets(str);
	 
		j = 0;
		counter = 0;
		
		// Gets the length of the user's input
		for( i = 0; i <=( strlen(str)); i++ ){
			
			if( str[i]==' '||str[i]=='\0' ){
				
				stringArr[counter][j]='\0';
				counter++;  // Next word
				j = 0;
			} else {
				
				stringArr[counter][j]=str[i];
				j++;
			}
		}
		
				for( i = 0; i < counter; i++ ){
			
			for( j = 0; j <= (strlen(stringArr[i])); j++ ){
				
				// If the character matches the 'p' in pwd...
				if( stringArr[i][j] == pwdStr[j] ){
					
					//... Then pwdCounter++ and check the next character
					//		on the next loop
					pwdCounter++;
					
				} else if( stringArr[i][j] == echoStr[j] ){
					
					echoCounter++;
					
				} else if( stringArr[i][j] == lsStr[j] ){
					
					lsCounter++;
					
				} else if( stringArr[i][j] == helpStr[j] ){
					
					helpCounter++;
					
				} else if( stringArr[i][j] == exitStr[j] ){
					
					exitCounter++;
					
					// If the letter doesn't start with and/or contain any of the valid characters...
				} else if( pwdBool == 0 && echoBool == 0 && lsBool == 0 && helpBool == 0 ){
					
					invalidCounter++; // ... Then it is an invalid command
				}
				
				// If the characters entered match pwd
				// then we call pwd() and print the working directory
				if( pwdCounter >= 3 ){
					
					pwd();
					pwdBool = 1;
					pwdCounter = 0;
					
				} else if( echoCounter >= 4 ){
					
					printf("%s\n",stringArr[i+1]);
					echoBool = 1;
					echoCounter = 0;
					
				} else if( lsCounter >= 2 ){
					
					ls();
					lsBool = 1;
					lsCounter = 0;
					
				} else if( helpCounter >= 4 ){
					
					helpList();
					helpBool = 1;
					helpCounter = 0;
					
				} else if( exitCounter > 0 ){
					
					//exitCounter = 0;
					break;
				}
			}
		}
		
		// If the invalidCounter != then it must be an invalid command
		if(invalidCounter != 0){
			
			printf("\nInvalid command. Please try again or type 'help' for the list of commands: ");
			invalidCounter = 0;
		}
			
	}
	
	// This is for when the user types 'exit'
	printf("\nProgram has terminated.\n");
	
    return 0;
}
