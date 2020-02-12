#ifndef CALCULATOR_H
#define CALCULATOR_H

/*!
* \file
* \brief plik przechowujący prototypy funkcji związanych z klakulatorem
*/
 char* ArithmeticToOnp(struct stack_node_char *stos_char,char* phrase);
 double CalculateOnp(struct stack_node_numbers *stos_numbers,char* phrase);
 int ArithmeticOrOnp (char *phrase);
 int CheckingParenthesis(char *phrase,struct stack_node_numbers *stos_parenthesis);
 int CheckingNumbersAndOperand(char* phrase);
 void writeToFile(char* phrase);
 char* CommaToDot(char *phrase);




#endif // CALCULATOR_H
