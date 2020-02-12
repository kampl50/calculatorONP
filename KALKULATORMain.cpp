/***************************************************************
 * Name:      KALKULATORMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2019-01-09
 * Copyright:  ()
 * License:
 **************************************************************/

#include "KALKULATORMain.h"
#include <wx/msgdlg.h>
#include <iostream>
#include <time.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include "stack.h"
#include "structures.h"
#include "calcu.h"

/*!
* \file
* \brief plik main apliakcji wxwidget
*/
//(*InternalHeaders(KALKULATORFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(KALKULATORFrame)
const long KALKULATORFrame::ID_BUTTON1 = wxNewId();
const long KALKULATORFrame::ID_BUTTON2 = wxNewId();
const long KALKULATORFrame::ID_TEXTCTRL1 = wxNewId();
const long KALKULATORFrame::ID_TEXTCTRL2 = wxNewId();
const long KALKULATORFrame::ID_TEXTCTRL3 = wxNewId();
const long KALKULATORFrame::ID_STATICTEXT1 = wxNewId();
const long KALKULATORFrame::idMenuQuit = wxNewId();
const long KALKULATORFrame::idMenuAbout = wxNewId();
const long KALKULATORFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(KALKULATORFrame,wxFrame)
    //(*EventTable(KALKULATORFrame)
    //*)
END_EVENT_TABLE()

KALKULATORFrame::KALKULATORFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(KALKULATORFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(500,300));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
    Button1 = new wxButton(this, ID_BUTTON1, _("OBLICZ"), wxPoint(107,123), wxSize(60,25), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("OBLICZ"), wxPoint(328,123), wxSize(60,25), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("SCIEZKA"), wxPoint(47,70), wxSize(180,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("ROWNANIE"), wxPoint(273,70), wxSize(180,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, _("WYNIK"), wxPoint(273,176), wxSize(180,25), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("KALKULATOR"), wxPoint(128,16), wxSize(200,32), 0, _T("ID_STATICTEXT1"));
    StaticText1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    wxFont StaticText1Font(22,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KALKULATORFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&KALKULATORFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&KALKULATORFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&KALKULATORFrame::OnAbout);
    //*)
}

KALKULATORFrame::~KALKULATORFrame()
{
    //(*Destroy(KALKULATORFrame)
    //*)
}

void KALKULATORFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void KALKULATORFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
/// \brief Funkcja jako parametr przyjmuje tekst, i zwraca ten sam tekst poddany modyfikacji. mianowicie rozdzela liczby od operandów w wyrażeniu arytemtycznym.
/// \param wxString napis tekst
/// \return tmp zwracany tekst
wxString funkcja_rozdzielajaca(wxString napis)
{
    wxString tmp;
    int i;

    for(i = 0; i<napis.length(); i++)
    {
        int  a = napis[i];
        int  b = napis[i+1];
        int c = napis[i-1];

        if(napis[i]== ' ')
            continue;

        if(napis[i]== '.'||napis[i]== ',')
        {
            tmp += (char)napis[i];
            continue;
        }

        if(a>=48&&a<=57)
        {
            tmp += (char)napis[i];
            continue;
        }
        if(c>=48&&c<=57)
        {
            tmp += " ";
            tmp += (char)napis[i];
            tmp += " ";
            continue;
        }
        tmp += (char)napis[i];
        tmp += " ";
    }

    return tmp;
}

/// \brief Funkcja odczytuje wyrażenie z pliku podanego przez ścieżkę w ostatnim parametrze. Wyrażenie jest walidowane i obliczane po czym wywoływana jest funkcja writeToFile();. Jeśli nie uda sie otworzyć lub znaleźć pliku podanego przez ścieżkę wyświetlony zostanie odpowiedni komunikat i funkcja zakończy swoje działanie.
/// \param struct stack_node_char *stos_char wskaźnik na stos
/// \param struct stack_node_numbers *stos_numbers wskaźnik na stos
/// \param struct stack_node_numbers *stos_parenthesis wskaźnik na stos
/// \param const char *filepath ścieżka do pliku tekstowego
void readFile(struct stack_node_char *stos_char,struct stack_node_numbers *stos_numbers,struct stack_node_numbers *stos_parenthesis,const char *filepath)
{
    FILE *file = fopen(filepath, "r");
    char zapis[200];
    if (file) {
            double result=0;
        char textLine[200];
        while (!feof(file) && fgets(textLine, 200, file)) {

            printf(" %s\n", textLine);


   if(ArithmeticOrOnp(textLine)==1)
    {
        if(CheckingNumbersAndOperand(textLine)==-1)
        {
            writeToFile("ERROR ZLA LICZBA OPERANDOW" );
            continue;
        }
         if(CheckingNumbersAndOperand(textLine)==-2)
        {
            writeToFile("ERROR ZLY ZNAK W ROWNANIU" );
            continue;
        }
        result=CalculateOnp(stos_numbers,textLine);
    }
    if(ArithmeticOrOnp(textLine)==2)
    {
        strcpy(textLine,funkcja_rozdzielajaca(textLine));

        if(CheckingNumbersAndOperand(textLine)==-1)
        {
            writeToFile("ERROR ZLA LICZBA OPERANDOW" );
            continue;
        }
        if(CheckingNumbersAndOperand(textLine)==-2)
        {
            writeToFile("ERROR ZLY ZNAK W ROWNANIU" );
            continue;
        }
        if(CheckingParenthesis(textLine,stos_parenthesis)==-1)
        {
            writeToFile("ERROR NAWIASY W WYRAZENIU NIE SA POPRAWNIE SPAROWANE" );
            continue;
        }
        result=CalculateOnp(stos_numbers,ArithmeticToOnp(stos_char,textLine));
    }


 snprintf(zapis, 200, "%f", result);
    writeToFile(zapis);
        }
        fclose(file);
    }
    else
        wxMessageBox( wxT("ERROR NIE ZNALEZIONO PLIKU O PODANEJ SCIEZCE") );

}
/// \brief Funkcja jako parametr przyjmuje zdarzenie będące kliknieciem w przycisk i wykonuje funkcje rozpoznania rownania, które jest pobrane z TextCtrl2 (ROWNANIE) a nastepnie obliczane za pomoca funkcji CalculateOnp i wypisywane w TextCtrl3(WYNIK)
/// \param wxCommandEvent& event zdarzenie będące kliknięciem w przycisk
void KALKULATORFrame::OnButton2Click(wxCommandEvent& event)
{
    double wynik=0;
    wxString tekst=wxT(""); //zmeinna na wartosc tesxtctrl2
    tekst=TextCtrl2->GetValue();
    char*cstr =new char[tekst.length()+1]; // zmienna przechowjaca 'tekst' o typie char*
    memset(cstr,0,tekst.length()+1);
    strcpy(cstr,tekst.c_str());
    strcpy(cstr,CommaToDot(cstr));
    struct stack_node_char *stos_char=NULL;    //deklaracaj stosu przegowuj¹cy znaki
    struct stack_node_numbers *stos_numbers=NULL;
    struct stack_node_numbers *stos_parenthesis=NULL;    //deklaracaj stosu przegowuj¹cy cyfre "1" do walidacji nawiasów w wyra¿eniu
    wxString res=wxT("");
    if(ArithmeticOrOnp(cstr)==1)
    {
        if(CheckingNumbersAndOperand(cstr)==-1)
        {
            wxMessageBox( wxT("ERROR ZLA LICZBA OPERANDOW") );
            return;
        }
         if(CheckingNumbersAndOperand(cstr)==-2)
        {
            wxMessageBox( wxT("ERROR ZLY ZNAK W ROWNANIU") );
            return;
        }
        wynik=CalculateOnp(stos_numbers,cstr);
    }
    if(ArithmeticOrOnp(cstr)==2)
    {
        strcpy(cstr,funkcja_rozdzielajaca(cstr));

        if(CheckingNumbersAndOperand(cstr)==-1)
        {
            wxMessageBox( wxT("ERROR ZLA LICZBA OPERANDOW") );
            return;
        }
        if(CheckingNumbersAndOperand(cstr)==-2)
        {
            wxMessageBox( wxT("ERROR ZLY ZNAK W ROWNANIU") );
            return;
        }
        if(CheckingParenthesis(cstr,stos_parenthesis)==-1)
        {
            wxMessageBox( wxT("ERROR NAWIASY W WYRAZENIU NIE SA POPRAWNIE SPAROWANE") );
            return;
        }
        wynik=CalculateOnp(stos_numbers,ArithmeticToOnp(stos_char,cstr));
    }

    res<<wynik;
    TextCtrl3->SetValue(res);
}
/// \brief Funkcja jako parametr przyjmuje zdarzenie będące kliknieciem w przycisk i wykonuje funkcje odczytu z pliku o podanej scieżxe w TextCtrl1 (SCIEZKA).
/// \param wxCommandEvent& event zdarzenie będące kliknięciem w przycisk
void KALKULATORFrame::OnButton1Click(wxCommandEvent& event)
{
    system("del wyniki.txt");
    wxString x;
    x=TextCtrl1->GetValue();
    char *cstr = new char[x.length() + 1];
    strcpy(cstr, x.c_str());

    struct stack_node_char *stos_char=NULL;             //deklaracaj stosu przegowuj¹cy znaki
    struct stack_node_numbers *stos_numbers=NULL;     //deklaracaj stosu przegowuj¹cy liczbt
    struct stack_node_numbers *stos_parenthesis=NULL;
    readFile(stos_char,stos_numbers,stos_parenthesis,cstr);
}
