#include <stdio.h>
#include <stdlib.h>
#define MAXPATH 2048

int main (int argc, char *argv [ ] )
{

    FILE *fp ;
    char path [MAXPATH] ;
    int s, status ;
    char c ;
    fp = popen("whoami", "r");
    if ( fp == NULL)
    {
        printf( "Failed to run command\n" );
        exit(1);
    }
    s=0;
    // read character by character from the bytes stream until end of file
    while ((c = fgetc(fp)) != EOF)
    {
        printf( "%c", c ) ;
        path [ s ] = c ;
        s++;
    }
    path [ s ]= '\0' ; // Bytes stream to string
    status = pclose ( fp ) ;
    // check status from command execution
    if(status != 0)
    {
        printf("Something went wrong ... try again \n") ;
    }
    return 0 ;