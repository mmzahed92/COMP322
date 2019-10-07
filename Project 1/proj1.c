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