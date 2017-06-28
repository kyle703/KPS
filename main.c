#include <stdlib.h>
#include <limits.h>
#include "Programs.h"
#define LINE_MAX 256
int main() {

    char arg[ LINE_MAX ] = {'0'};
    char parsed[ LINE_MAX ] = {'0'};
    
    printf("This is a compilation of solutions to Karan's problems posted on GitHub\n");
    printf("Enter the program you wish to run or type 'list' for a list of all programs\n-------------\n");

    while(true) {

        char* tok = NULL;
        while (tok == NULL) {
            printf("Enter a program: ");
            fgets(arg, LINE_MAX, stdin);
            strcpy(parsed, arg);
            tok = strtok(parsed, " \n");
        }
		arg[ strlen(arg) - 1] = '\0';
        if (strcmp(tok, "list") == 0) {
            print_names();
        } else if (strcmp(tok, "info") == 0){
            tok = strtok(NULL, "\n");
            if (tok != NULL) {
                info(tok);
            } else {
                printf("No argument after 'info'. Try again.\n");
            }
        } else if (strcmp(tok, "exit") == 0 || strcmp(tok, "quit") == 0) {
            printf("Exiting...\n");
            exit(1);
        } else if ( find(arg) ) {
            printf("Type exit to return to program selection\n");
            run(arg);
            printf("Exiting %s...\n", arg);
        } else {
            printf("invalid input. please try again\n");
        }
    }
}
        
