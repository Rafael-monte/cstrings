#ifndef CSTRINGS_H
#define CSTRINGS_H
#include <stdio.h>
#include <string.h>


struct string 
{
    char* text;
};


struct string_list
{
    char* text;
    struct string_list* next_string;
};

int index_of_char(struct string* str, char value);

int last_index_of_char(struct string* str, char value);

struct string* new_string(char* _string);

struct string* reset_string(struct string* str, char* _new_value);

void __try_alloc(struct string* str, size_t size);

struct string* concat(struct string* str, char* _value_to_concat);

struct string_list* split(struct string* str, char* _separator);

struct string* to_upper_case(struct string* str);

struct string* to_lower_case(struct string* str);

int __count_occurrences(char* str_text, char _character);

void close_string(struct string* str);

#endif