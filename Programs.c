#include "Programs.h"
#include "ClassicAlgos.h"

static Program ProgramTable[NUM_PROGRAMS] = {
    {"Collatz 12342134 Conjecture", "collatz", "Classic Algorithms", collatz,
        "Collatz Conjecture - Start with a number n > 1. Find the number of steps it takes to reach one using the following process: If n is even, divide it by 2. If n is odd, multiply it by 3 and add 1."},
	{"Sieve of Eratosthenes", "sieve", "Classic Algorithms", sieve_of_eratosthenes,
		"The sieve of Eratosthenes is one of the most efficient ways to find all of the smaller primes (below 10 million or so)."}
};


void print_names() {
    for (int i = 0; i < NUM_PROGRAMS; i++) {
        printf("%s\n", ProgramTable[i].name);
    }
}

void info(char* name) {
    for(int i = 0; i < NUM_PROGRAMS; i++) {
        if (strcmp(name, ProgramTable[i].name) == 0 || strcmp(name, ProgramTable[i].nickName) == 0) {
            printf("----%s----\n", ProgramTable[i].cat);
            printf("%s\n", ProgramTable[i].description);
            return; 
        }
    }
    printf("%s\n", NO_FOUND_PROGRAM_ERROR_MESSAGE);
}

bool find(char* name) {
    for(int i = 0; i < NUM_PROGRAMS; i++) {
        if (strcmp(name, ProgramTable[i].name) == 0 || strcmp(name, ProgramTable[i].nickName) == 0) {
            printf("running program: %s\n\n", ProgramTable[i].name);
            return true; 
        }
    }
    printf("%s\n", NO_FOUND_PROGRAM_ERROR_MESSAGE);
    return false;
}  

void run(char* name) {
	 for(int i = 0; i < NUM_PROGRAMS; i++) {
        if (strcmp(name, ProgramTable[i].name) == 0 || strcmp(name, ProgramTable[i].nickName) == 0) {
			ProgramTable[i].func_ptr();
		}
	}
}
			
