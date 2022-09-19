#ifndef CSTRINGS_H
#define CSTRINGS_H
#include <stdio.h>
#include <string.h>


struct string 
{
    char* text;
};

int index_of(struct string* str, char value);


int last_index_of(struct string* str, char value);

struct string* new_string(char* _string);

struct string* reset_string(struct string* str, char* _new_value);

void try_alloc(struct string* str, size_t size);

struct string* concat(struct string* str, char* _value_to_concat);

void close_string(struct string* str);

#endif