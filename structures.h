#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
/*!
* \file
* \brief plik przechowujący struktury
*/

/// \brief Struktura stosu przechowuj¹cy liczby typu double.
struct stack_node_numbers
{
    double data;
    struct stack_node_numbers *next;
};

/// \brief Struktura stosu przechowuj¹cy znaki char.
struct stack_node_char
{
    char data;
    struct stack_node_char *next;
};


#endif // STRUCTURES_H_INCLUDED
