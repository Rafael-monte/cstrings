#include "./src/cstrings.c"
#include <stdio.h>
#include <string.h>


int main(void)
{
    // string* str = new_string("Ola mundo! Meu nome e rafael monteiro e estou criando uma lib de strings em c");
    // printf("%s\n", str->text);

    // str = reset_string(str, "Agora sou outra string");
    // printf("%s\n", str->text);
    // str = concat(str, " e fui concatenada!");
    // printf("%s\n", str->text);
    // str = concat(str, " Na verdade eu sou um homem simples, se eu vejo uma string, eu concateno!");
    // printf("%s\n", str->text);

    // printf("Indice do caractere 'd' na string anterior: %d\n", index_of(str, 'd'));

    // printf("Ultimo indice da letra 'o' na string %s: %d\n", str->text, last_index_of(str, 'o'));

    // printf("Vou fechar a string\n");

    // close_string(str);

    // printf("Agora nao tem mais nada aqui -> %s\n", str->text);


    string* nova_string = new_string("Esse e um teste de estrutura, eu gosto de usar virgulas, porem ainda e um teste");

    string_list* lista_strings = split(nova_string, ",");
    string_list* pivot=lista_strings;
     while(pivot->text != NULL)
     {
         printf("String atual: %s\n", pivot->text);
         pivot = pivot->next_string;
     }
}