#ifndef CLASSIC_ALGOS_H
#define CLASSIC_ALGOS_H
#endif

#define PRIME_SIZE  100000 //can increase to your content 

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

void collatz();

void sieve_of_eratosthenes();

bool next_prime(uint32_t * num, uint8_t table[]);

