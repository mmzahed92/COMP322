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
