#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string>
#include<windows.h>
#include <errno.h>
#include "stack.h"
#include "calcu.h"
#include "structures.h"



/*!
* \file
* \brief plik przechowujący implementacje funkcji związanych z kalkulatorem
*/


/// \brief Funkcja przyjmuje jako drugi parametr wyrażenie arytmetyczne, w którym liczby i znaki oddzielone są spacją i zakończone znakiem "=". Pierwszym parametrem jest wskaźnik na stos, dzięki któremu następuje zamiana wyrażenia. Funkcja zwraca tablice char z przekształconym wyrażeniem zakończonym znakiem "=".
/// \param struct stack_node_char *stos_char wskaźnik na stos
/// \param char* phrase wyrażenie arytmetyczne
/// \return char* phrase wyrażenie w postaci ONP
char* ArithmeticToOnp(struct stack_node_char *stos_char,char* phrase)
{
    //int step = 1;
    int i=0;
    int j=0;
    char element[200]="";
    static char out_phrase[200] = "";
    memset(out_phrase,0,200);

    char operand;
    char assistant_char[2];
    // puts("\n----------ZAMIANA Z WYRAZENIA ARYTMETYCZNEGO NA ONP----------\n");
    while(phrase[i]!='=')
    {
        while(phrase[i]!=' ')
        {
            element[j]=phrase[i];
            i++;
            j++;
        }
        element[j]= '\0';

        //printf("\n--Krok numer %d zamiany wyrazenia na ONP--\n", step++);
        //  printf("Program pracuje nad : %s\n", element);
        if(0==strcmp(element,"="))
        {
            continue;
        }
        if(0==strcmp(element,"("))
        {
            stos_char=push_char(stos_char,'(');
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        if(0==strcmp(element,")"))
        {
            while(peek(stos_char)!='(')
            {
                operand=peek(stos_char);
                assistant_char[0]=operand;
                assistant_char[1] = '\0';
                strcat(out_phrase,assistant_char);
                strcat(out_phrase," ");
                pop_char(&stos_char);
            }
            pop_char(&stos_char);
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        if(0==strcmp(element,"+"))
        {
            while((peek(stos_char)=='*') || (peek(stos_char)=='/') || (peek(stos_char)=='^')  || (peek(stos_char)=='-') || (peek(stos_char)=='%'))
            {
                operand=peek(stos_char);
                assistant_char[0]=operand;
                assistant_char[1] = '\0';
                strcat(out_phrase,assistant_char);
                strcat(out_phrase," ");
                pop_char(&stos_char);
            }
            stos_char=push_char(stos_char,'+');
            //printf("Aktualne operandy na stosie: ");
            show_char(stos_char);
            // puts("");
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        if(0==strcmp(element,"-"))
        {
            while((peek(stos_char)=='*') || (peek(stos_char)=='/') || (peek(stos_char)=='^') || (peek(stos_char)=='+') || (peek(stos_char)=='%'))
            {
                operand=peek(stos_char);
                assistant_char[0]=operand;
                assistant_char[1] = '\0';
                strcat(out_phrase,assistant_char);
                strcat(out_phrase," ");
                pop_char(&stos_char);
            }
            stos_char=push_char(stos_char,'-');
            //printf("Aktualne operandy na stosie: ");
            show_char(stos_char);
            //puts("");
            memset(element, 0,20);
            j=0;
            i++;
            continue;
        }
        if(0==strcmp(element,"*"))
        {
            while((peek(stos_char)=='^') || (peek(stos_char)=='/') || (peek(stos_char)=='%'))
            {
                operand=peek(stos_char);
                assistant_char[0]=operand;
                assistant_char[1] = '\0';
                strcat(out_phrase,assistant_char);
                strcat(out_phrase," ");
                pop_char(&stos_char);
            }
            stos_char=push_char(stos_char,'*');
            //printf("Aktualne operandy na stosie: ");
            show_char(stos_char);
            //puts("");
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        if(0==strcmp(element,"/"))
        {
            while((peek(stos_char)=='^') || (peek(stos_char)=='*') || (peek(stos_char)=='%'))
            {
                operand=peek(stos_char);
                assistant_char[0]=operand;
                assistant_char[1] = '\0';
                strcat(out_phrase,assistant_char);
                strcat(out_phrase," ");
                pop_char(&stos_char);
            }
            stos_char=push_char(stos_char,'/');
            //  printf("Aktualne operandy na stosie: ");
            show_char(stos_char);
            // puts("");
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        if(0==strcmp(element,"^"))
        {
            while((peek(stos_char)=='%'))
            {
                operand=peek(stos_char);
                assistant_char[0]=operand;
                assistant_char[1] = '\0';
                strcat(out_phrase,assistant_char);
                strcat(out_phrase," ");
                pop_char(&stos_char);
            }
            stos_char=push_char(stos_char,'^');
            //printf("Aktualne operandy na stosie: ");
            show_char(stos_char);
            // puts("");
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        if(0==strcmp(element,"%"))
        {
            while((peek(stos_char)=='^'))
            {
                operand=peek(stos_char);
                assistant_char[0]=operand;
                assistant_char[1] = '\0';
                strcat(out_phrase,assistant_char);
                strcat(out_phrase," ");
                pop_char(&stos_char);
            }
            stos_char=push_char(stos_char,'%');
            //printf("Aktualne operandy na stosie: ");
            show_char(stos_char);
            //puts("");
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        strcat(out_phrase,element);
        strcat(out_phrase," ");
        //printf("Aktualne wyjscie: %s\n", out_phrase);
        memset(element, 0,200);
        j=0;
        i++;
    }

    // printf("\nStos po petli while: ");
    show_char(stos_char);

    while(peek(stos_char)!=-1)
    {
        operand=peek(stos_char);
        assistant_char[0]=operand;
        assistant_char[1] = '\0';
        strcat(out_phrase,assistant_char);
        strcat(out_phrase," ");
        pop_char(&stos_char);
    }

    //printf("\n\nOstateczny wynik zamiany: %s\n", out_phrase);
    strcat(out_phrase,"=");

    return (out_phrase);
}
/// \brief Funkcja przyjmuje jako drugi parametr wyrażenie w postaci ONP, w którym liczby i znaki oddzielone są spacjami i zakończone znakiem "=".Pierwszym parametrem jest wskaźnik na stos, dzięki któremu następuje obliczanie wyrażenia. Funkcja zwraca wynik obliczonego wyniku typu double.
/// \param struct stack_node_numbers *stos_numbers wskaźnik na stos
/// \param char* phrase wyrażenie w postaci ONP
/// \return final_result ostateczny wynik wyrażenia
double CalculateOnp(struct stack_node_numbers *stos_numbers,char* phrase)
{
    //int step=1;
    int i=0;
    int j=0;
    double result;
    double one;
    double two;
    char element[200]="";
    double final_result;
    // puts("\n----------------OBLICZANIE----------------");

    while(phrase[i]!='=')
    {
        while(phrase[i]!=' ')
        {
            element[j]=phrase[i];
            i++;
            j++;
        }
        element[j]= '\0';
        //printf("\n--Krok numer %d obliczania wyrazenia ONP--\n", step++);
        //printf("Program pracuje nad : %s\n", element);
        if(0==strcmp(element,"="))
        {
            continue;
        }
        if(0==strcmp(element,"+"))
        {
            result=pop_numbers(&stos_numbers)+pop_numbers(&stos_numbers);
            stos_numbers=push_numbers(stos_numbers,result);
            memset(element, 0,200);
            j=0;
            i++;
            // printf("Aktualne stos: ");
            show_numbers(stos_numbers);
            // puts("");
            continue;
        }
        if(0==strcmp(element,"*"))
        {
            result=pop_numbers(&stos_numbers)*pop_numbers(&stos_numbers);
            stos_numbers=push_numbers(stos_numbers,result);
            memset(element, 0,200);
            j=0;
            i++;
            // printf("Aktualne stos: ");
            show_numbers(stos_numbers);
            // puts("");
            continue;
        }
        if(0==strcmp(element,"-"))
        {
            one=pop_numbers(&stos_numbers);
            two=pop_numbers(&stos_numbers);
            stos_numbers=push_numbers(stos_numbers,two-one);
            memset(element, 0,200);
            j=0;
            i++;
            // printf("Aktualne stos: ");
            show_numbers(stos_numbers);
            // puts("");
            continue;
        }
        if(0==strcmp(element,"/"))
        {
            one=pop_numbers(&stos_numbers);
            if(one==0)
            {
                //puts("ERROR NIE MOZNA DZIELIC PRZEZ 0");
                return -1;
            }
            two=pop_numbers(&stos_numbers);
            stos_numbers=push_numbers(stos_numbers,two/one);
            memset(element, 0,200);
            j=0;
            i++;
            // printf("Aktualne stos: ");
            show_numbers(stos_numbers);
            //puts("");
            continue;
        }
        if(0==strcmp(element,"^"))
        {
            one=pop_numbers(&stos_numbers);
            two=pop_numbers(&stos_numbers);
            stos_numbers=push_numbers(stos_numbers,pow(two,one));
            memset(element, 0,200);
            j=0;
            i++;
            //printf("Aktualne stos: ");
            show_numbers(stos_numbers);
            // puts("");
            continue;
        }
        if(0==strcmp(element,"%"))
        {
            int one;
            int two;
            one=pop_numbers(&stos_numbers);
            two=pop_numbers(&stos_numbers);
            stos_numbers=push_numbers(stos_numbers,two%one);
            memset(element, 0,200);
            j=0;
            i++;
            //printf("Aktualne stos: ");
            show_numbers(stos_numbers);
            //puts("");
            continue;
        }

        stos_numbers=push_numbers(stos_numbers,atof(element));// jeli nie jest wprowadzony zaden operator ciag znakow jest zamieniany na liczby typu double
        // printf("Aktualne stos: ");
        show_numbers(stos_numbers);
        // puts("");
        memset(element, 0,200);
        j=0;
        i++;
    }


    final_result=pop_numbers(&stos_numbers);

    // printf("\nOSTATECZY WYNIK: %lf\n\n",final_result);
    return final_result;
}

/// \brief Funkcja przyjmuje jako parametr wyrażenie, a następnie rozpoznaje czy zostało przekazane wyrazżnie arytmetyczne czy wyrażenie w postaci ONP. Zwraca 2 jeśli jest to wyrażenie arytmetyczne, natomiast gdy jest to wyrażenie w postaci ONP to funkcja zwraca 1.
/// \param char* phrase wyrażenie, które chcemy sprawdzić
/// \return 1 lub 2
int ArithmeticOrOnp (char *phrase)
{
    int i;
    int length=strlen(phrase);
    for(i=0; i<length; i++)
    {
        if(phrase[i]==' ')
            return 1;
    }
    return 2;
}
/// \brief Funkcja jako pierwszy parametr przyjmuje wyrażenie, które będzie sprawdzane pod względem poprawności parowania nawiasów. Realizuje to przez stos, na który wskaźnik przekazany jest przez drugi parametr. Funkcja zwraca 1 jeśli nawiasy są prawidłowo sparowane lub -1 jeśli chociaż jeden nawias nie posiada prawidłowej pary.
/// \param char* phrase wyrażenie, które chcemy sprawdzić
/// \param struct stack_node_numbers *stos_parenthesis wskaźnik na stos
/// \return -1 lub 1
int CheckingParenthesis(char *phrase,struct stack_node_numbers *stos_parenthesis)
{
    char assistant_char[200] ;
    char element[200]="";
    strcpy(assistant_char,phrase);
    int i=0;
    int j=0;

    while(assistant_char[i]!='=')
    {

        while(assistant_char[i]!=' ')
        {
            element[j]=assistant_char[i];
            i++;
            j++;
        }

        element[j]= '\0';
        if(0==strcmp(element,"("))
        {
            stos_parenthesis=push_numbers(stos_parenthesis,1);
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        if(0==strcmp(element,")"))
        {
            if(pop_numbers(&stos_parenthesis)==-1)
            {
                return -1 ;
            }
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        memset(element, 0,200);
        j=0;
        i++;
    }
    if(pop_numbers(&stos_parenthesis)!=-1)
    {
        return -1;
    }
    return 1;
}
/// \brief Funkcja sprawdza wyrażenie podane jako parametr pod względem poprawności liczby operandów do operatorów. Jeśli nie zgadza się liczba(np. 2 3 4 + =), funkcja zwraca -1. Jeśli w wyrażeniu jest niepoprawny znak(np. 4 * # =), funkcja zwróci -2. W przeciwnym wypadku funkcja zwróci 1, co oznacza poprawność wyrażenia pod opisywanymi względami
/// \param char* phrase wyrażenie
/// \return -1, -2 lub 1
int CheckingNumbersAndOperand(char* phrase)
{
    int i=0;
    int j=0;
    int counter_of_operands=0;
    int counter_of_numbers=0;
    char element[200]="";

    while(phrase[i]!='=')
    {
        while(phrase[i]!=' ')
        {
            element[j]=phrase[i];
            i++;
            j++;
        }
        element[j]= '\0';
        if(0==strcmp(element,"0"))
        {
            counter_of_numbers++;
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }
        if(0==strcmp(element,"+") ||  0==strcmp(element,"-") ||  0==strcmp(element,"*") ||  0==strcmp(element,"/") ||  0==strcmp(element,"^") ||  0==strcmp(element,"%"))
        {
            counter_of_operands++;
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }

        if(0==strcmp(element,"(") ||  0==strcmp(element,")"))
        {
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }


        if(atof(element) != 0)
        {
            counter_of_numbers++;
            memset(element, 0,200);
            j=0;
            i++;
            continue;
        }




        return -2;

        memset(element, 0,200);
        j=0;
        i++;
    }
    if(counter_of_numbers!=counter_of_operands+1)
    {
        return -1;
    }
    return 1;
}

/// \brief Funkcja jako parametr przyjmuje tekst, który następnie dopisany jest do pliku tekstowego wyniki.txt
/// \param char* phrase wyraźenie
void writeToFile(char* phrase)
{
    FILE *file = fopen("wyniki.txt", "a");
    if (file)
    {
        fprintf(file,"%s\n",phrase);
        fclose(file);
    }
}
/// \brief Funkcja jako parametr przyjmuje wyrażenie, w którym każdy przecinek zamieniany jest na kropkę. Funkcja zwraca poprawione wyrażenie
/// \param char* phrase wyrażenie
/// \return phrase wyrażenie
char* CommaToDot(char *phrase)
{
    int i;
    int length=strlen(phrase);
    for(i=0; i<length; i++)
    {
        if(phrase[i]==',')
            phrase[i]='.';
    }
    return (phrase);

}


