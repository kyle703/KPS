#ifndef PROGRAMS_H
#define PROGRAMS_H
#endif

#define NUM_PROGRAMS 2
#define NO_FOUND_PROGRAM_ERROR_MESSAGE "No programs with this name were found."

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct _Program{
    char* name;
    char* nickName;
    char* cat;
    void (*func_ptr)(void);
    char* description;
}; typedef struct _Program Program;


void print_names();

void info(char* name);

bool find(char* name);

void run(char* name);



