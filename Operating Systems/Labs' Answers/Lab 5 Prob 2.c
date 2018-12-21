#include <cstdio>
#include <cstring>
 
using namespace std;
 
int main (int argc, char *argv [])
{
    char string [11];
     
    printf ("Enter id: ");
    scanf ("%s", string);
     
    unsigned long length = strlen (string) - 1;
     
    // true -> if we found any letter
    bool letter = false;
     
    // checking if the first character is a capital letter 
    if ( string [0] >= 'A' && string [0] <= 'Z' )
        letter = true;
     
    // checking if the first character is a small letter 
    if ( string [0] >= 'a' && string [0] <= 'z' )
        letter = true;
     
    // true -> if there is no underscore at the end
    bool underScore = true;
     
    // checking if there is any underscore at the end 
    if ( string [length] == '_' )
        underScore = false;
     
    int flag = 0;
     
    // we have already checked the first character
    // so starting the loop from 1 
    for ( int i = 1; i <= length; i++ ) {
         
        // if we found an underscore, its a warning, flag++ 
        if ( string [i] == '_' )
            flag++;
        else
            flag = 0;
         
        // if flag == 2, we have two consecutive underscore 
        if ( flag == 2 ) {
            underScore = false;
            break;
        }
    }
     
    // if letter and uderscore both are true, then our identifier is clear
    if ( letter && underScore )
        printf ("Answer: %s is a valid identifier\n", string);
    else
        printf ("Answer: %s is not a valid identifier\n", string);
     
    return 0;
}