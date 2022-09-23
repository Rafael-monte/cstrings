#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstrings.h"


typedef struct string string;

typedef struct string_list string_list;

int index_of_char(struct string* str, char value)
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

int last_index_of_char(struct string* str, char value)
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
    __try_alloc(str, strlen(_string)+1);
    strcpy(str->text, _string);
    return str;
}


struct string* reset_string(struct string* str, char* _new_value)
{
    free(str->text);
    __try_alloc(str, strlen(_new_value));
    strcpy(str->text, _new_value);
    return str;
}


void __try_alloc(struct string* str, size_t size)
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

//Separa uma string em uma lista encadeada de substrings de acordo com um separador
//Parâmetro: str - string que se deseja separar
//Parâmetro: _separator - Separador que servirá de base para dividir a string
struct string_list* split(struct string* str, char* _separator)
{
    string_list* list = malloc(sizeof(struct string_list));
    string_list* pivot = list;
    char char_arr[strlen(str->text)+1];
    strcpy(char_arr, str->text);
    char* token = strtok(char_arr, _separator);
    int iteracoes= 0;
    while( token != NULL ) {
      pivot->text = malloc(strlen(token)+1);
      strcpy(pivot->text, token);
      token = strtok(NULL, _separator);
      pivot->next_string = malloc(sizeof(struct string_list));
      pivot = pivot->next_string;
      pivot->next_string = NULL;
      iteracoes++;
   }
   pivot->text = NULL;
   pivot->next_string=NULL;

    return list;
}


struct string* to_upper_case(struct string* str)
{
    for (int i = 0; i < strlen(str->text); i++)
    {
        if(str->text[i] >= 'a' && str->text[i] <= 'z') {
            str->text[i] -= 32; 
        }
    }
    return str;
}

struct string* to_lower_case(struct string* str)
{
    for (int i = 0; i < strlen(str->text); i++)
    {
        if (str->text[i] >= 'A' && str->text[i] <= 'Z')
        {
            str->text[i] += 32;
        }
    }
    return str;
}

int __count_occurrences(char* str_text, char _character)
{
     int num_substrings=0;
    for (int i = 0; i < strlen(str_text); i++)
    {
        if (str_text[i] == _character)
        {
            num_substrings++;
        }
    }

    return num_substrings;
}

void close_string(struct string* str)
{
    free(str->text);
    str->text = NULL;
    free(str);
    str = NULL;
}