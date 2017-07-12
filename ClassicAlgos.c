#include "ClassicAlgos.h"

/**
 * bug notes: if number is larger than uint32 max number of steps
 * repeats with the overflow digits
 **/
void collatz () {
	
	while(1) {
		char arg[20];
		uint32_t num;
		printf("Enter a number > 1: ");
		fgets(arg, sizeof(arg), stdin);
		if (strcmp(arg, "exit\n") == 0) {
			return;
		}
		if (sscanf(arg, "%"SCNu32"\n", &num) != 1) {
			printf("Incorrect Input: try agin\n");
		} else {
			int count = 0;
			while (num != 1) {
				if (num % 2 == 1) {
					num = (num * 3) + 1;
					count++;
				} else {
					num /= 2;
					count++;
				}
			}
			printf("Number of steps taken: %d\n", count);
		}
	}
}

/**
 * NOTES:
 * 		-malloc prime_size?
 * 		-transition to a bit array
 **/
void sieve_of_eratosthenes() {
	
	printf("Pick a number from 0 - %"SCNu32"\n", PRIME_SIZE);
	while(1) {
		char arg[20];
		uint32_t num;
		printf("How many primes do you want: ");
		fgets(arg, sizeof(arg), stdin);
		if (strcmp(arg, "exit\n") == 0) {
			return;
		} else if (sscanf(arg, "%"SCNu32"\n", &num) != 1) {
			printf("Incorrect Input: try agin\n");
		} else if (num > PRIME_SIZE) {
			printf("Pick a number from 0 - %"SCNu32"\n", PRIME_SIZE);
		} else {
			uint32_t numPrimes = 0;
			uint8_t primes [PRIME_SIZE] = {[2 ... PRIME_SIZE - 1] = 1}; //all innocent until proven guilty
			uint32_t i = 0;
			bool repeat = false;
			for ( next_prime(&i, primes); i < PRIME_SIZE && numPrimes < num && !repeat ; numPrimes++) {
				printf( "prime %"SCNu32": %"SCNu32"\n", numPrimes + 1, i); 
				for ( uint32_t j = 2*i ; j < PRIME_SIZE; j += i) {
					primes[j] = 0;
				}
				if (!next_prime(&i, primes)) {
					printf("No more primes from 0 to  %"SCNu32"\n", num);
					repeat = true;
				}
			}
		}
	}
	
}

bool next_prime(uint32_t * num, uint8_t table[]) {
	for ( uint32_t i = *num + 1; i < PRIME_SIZE; i++) {
		if (table[i]) {
			*num = i;
			return true;
		}
	}
	return false;
}
				
