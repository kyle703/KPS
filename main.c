#include <stdlib.h>
#include "Programs.h"
int main() {

    char arg[256];
    
    printf("This is a compilation of solutions to Karan's problems posted on GitHub\n");
    printf("Enter the program you wish to run or type 'list' for a list of all programs\n\n");

    while(true) {

        char* tok = NULL;
        while (tok == NULL) {
            printf("Enter a program: ");
            fgets(arg, sizeof(arg), stdin);
            tok = strtok(arg, " \n");
        }

        if (strcmp(tok, "list") == 0) {
            //list possible programs from table
            print_names();
        } else if (strcmp(tok, "info") == 0){
            tok = strtok(NULL, "\n");
            if (tok != NULL) {
                info(tok);
            } else {
                printf("No argument after 'info'. Try again.\n");
            }
        } else if (strcmp(tok, "exit") == 0) {
            printf("Exitting Program...\n");
            exit(1);
        } else if ( find(arg) ) {//findProgram(arg)
            //run program
            //function pointer to program
        } else {
            printf("invalid input. please try again\n");
        }
    }
}
        
