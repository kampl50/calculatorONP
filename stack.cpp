#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include<windows.h>
#include <errno.h>
#include "stack.h"
#include <stdio.h>
#include "structures.h"



/*!
* \file
* \brief plik przechowujący implementacje funkcji stosu
*/


/// \brief Funkcja w wyniku swojego działania zwróci wskaźnik stosu, który będzie albo taki sam, jaki jej został przekazany - będzie to oznaczało, że nie udało się utworzyć i dodać nowego elementu do stosu, albo będzie wskazywał na nowy element, który znajdzie się na szczycie stosu - w tym ostatnim przypadku stos zwiększy się o jeden element.
/// \param double data liczba, która ma być zapisana w nowym elemencie stosu
/// \param struct stack_node_numbers *top wskaźnik na stos
/// \return wskaźnik na stos
struct stack_node_numbers *push_numbers(struct stack_node_numbers *top, double data)
{
    struct stack_node_numbers *new_node = (struct stack_node_numbers *)malloc(sizeof(struct stack_node_numbers));
    if (NULL != new_node)
    {
        new_node->data = data;
        new_node->next = top;
        top = new_node;
    }
    return top;
}

/// \brief Funkcja zmniejsza stos o jeden element zwracając wartość usuwaną. Jeśli wywołaliśmy stos dla pustego stosu, funkcja zwróci -1;
/// \param struct stack_node_numbers **top podwójny wskaźnik na stos
/// \return usuniety element lub -1 dla pustego stosu
double pop_numbers(struct stack_node_numbers **top)
{
    double result = -1;
    if (NULL != *top)
    {
        result = (*top)->data;
        struct stack_node_numbers *tmp = (*top)->next;
        free(*top);
        *top = tmp;
    }
    return result;
}

/// \brief Funkcja nic nie zwraca. Wyświetla wszytkie liczby stosu.
/// \param wskaźnik na stos
void show_numbers(struct stack_node_numbers *top)
{
    if (NULL == top)
    {
        printf("Stos jest pusty!\n");
        return;
    }
    while(top!=NULL)
    {
        printf("%lf     ",top->data);
        top=top->next;
    }
}



/// \brief Funkcja w wyniku swojego działania zwróci wskaźnik stosu, który będzie albo taki sam, jaki jej został przekazany - będzie to oznaczało, że nie udało się utworzyć i dodaa nowego elementu do stosu, albo bedzie wskazywać na nowy element, który znajdzie sie na szczycie stosu - w tym ostatnim przypadku stos zwiększy sie o jeden element.
/// \param char data znak, który ma być zapisany w nowym elemencie stosu
/// \param struct stack_node_char *top wskaźnik na stos
/// \return top wskaźnik na stos
struct stack_node_char *push_char(struct stack_node_char *top, char data)
{
    struct stack_node_char *new_node = (struct stack_node_char *)malloc(sizeof(struct stack_node_char));
    if (NULL != new_node)
    {
        new_node->data = data;
        new_node->next = top;
        top = new_node;
    }
    return top;
}

/// \brief Funkcja zmniejsza stos o jeden element zwracając wartość usuwaną. Jeśli wywołaliśmy stos dla pustego stosu, funkcja zwróci -1;
/// \param struct stack_node_char **top podwójny wskaźnik na stos
/// \return result usunięty element lub -1 dla pustego stosu
char pop_char(struct stack_node_char **top)
{
    char result = -1;
    if (NULL != *top)
    {
        result = (*top)->data;
        struct stack_node_char *tmp = (*top)->next;
        free(*top);
        *top = tmp;
    }
    return result;
}

/// \brief Funkcja zwraca wartość elementu szczytowego tego stosu. Jesli została ona wywołana dla pustego stosu to funkcja zwraca -1
/// \param struct stack_node_char *top wskaźnik na stos
/// \return element na szczycie stosu lub -1 dla pustego stosu
char peek(struct stack_node_char *top)
{
    if (NULL != top)
        return top->data;
    return -1;
}

/// \brief Funkcja nic nie zwraca. Wyświetla wszytkie znaki stosu.
/// \param struct stack_node_char *top wskaźnik na stos
void show_char(struct stack_node_char *top)
{
    if (NULL == top)
    {
        printf("Stos jest pusty!\n");
        return;
    }

    while(top != NULL)
    {

        printf("%c ", top->data);
        top = top->next;
    }
}
