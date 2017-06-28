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
		while (sscanf(arg, "%"SCNu32"\n", &num) != 1) {
			printf("Incorrect Input: try agin\n");
			printf("Enter a number > 1: ");
			fgets(arg, sizeof(arg), stdin);
		}
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
