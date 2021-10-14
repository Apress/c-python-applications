#include <stdio.h>
/* read and display a number */
int main () {
   char c; /* store area where the character read in will be kept */
 
   printf("Enter character: "); /* ask the user to enter a character */
   c = getchar(); /* read the character in */
 
   printf("Character entered: "); /* tell the user what character the program has read */
   putchar(c); /* write the character */

   return(0);
}
