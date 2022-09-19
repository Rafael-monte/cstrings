#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstrings.h"


typedef struct string string;

int index_of(struct string* str, char value)
{
    int index = -1;
    for (int i = 0; i < strlen(str->text); i++)
    {
        if (str->text[i] == value)
        {
            index = i;
            break;
        }
    }

    return index;
}

int last_index_of(struct string* str, char value)
{
    int index = -1;
    for (int i = 0; i < strlen(str->text); i++)
    {
        if (str->text[i] == value)
        {
            index = i;
        }
    }

    return index;
}


struct string* new_string(char* _string)
{
    string* str = malloc(sizeof(string));
    try_alloc(str, strlen(_string)+1);
    strcpy(str->text, _string);
    return str;
}


struct string* reset_string(struct string* str, char* _new_value)
{
    free(str->text);
    try_alloc(str, strlen(_new_value));
    strcpy(str->text, _new_value);
    return str;
}


void try_alloc(struct string* str, size_t size)
{
    if (!(str->text = malloc(size)))
    {
        printf("Ocorreu um erro ao inicializar string");
        exit(1);
    }
}


struct string* concat(struct string* str, char* _value_to_concat)
{
    char* new_str = malloc(strlen(str->text)+strlen(_value_to_concat)+1);
    strcpy(new_str, str->text);
    strcat(new_str, _value_to_concat);
    reset_string(str, new_str);
    free(new_str);
    return str;
}


void close_string(struct string* str)
{
    free(str->text);
    str->text = NULL;
    free(str);
    str = NULL;
}