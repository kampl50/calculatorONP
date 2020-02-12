#ifndef STACK_H
#define STACK_H

/*!
* \file
* \brief plik przechowujący prototypy funkcji związanych z operacjami stosu
*/
 struct stack_node_numbers *push_numbers(struct stack_node_numbers *top, double data);
 double pop_numbers(struct stack_node_numbers **top);
 void show_numbers(struct stack_node_numbers *top);
 struct stack_node_char *push_char(struct stack_node_char *top, char data);
 char pop_char(struct stack_node_char **top);
char peek(struct stack_node_char *top);
void show_char(struct stack_node_char *top);
#endif // STACK_H
