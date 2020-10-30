// C code to illustrate working of 
// getch() to accept hidden inputs 
  
#include <stdio.h> 
  
main() 
{ 
  
    // Taking the password of 8 characters 
    char pwd[9]; 
    int i; 
  
  
    printf("Enter Password: "); 
    for (i = 0; i < 8; i++) { 
  
        // Get the hidden input 
        // using getch() method 
        pwd[i] = getch(); 
  
        // Print * to show that 
        // a character is entered 
        printf("%c\n", pwd[i]); 
    } 
} 
