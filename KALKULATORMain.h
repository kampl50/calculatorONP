/***************************************************************
 * Name:      KALKULATORMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2019-01-09
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef KALKULATORMAIN_H
#define KALKULATORMAIN_H

/*!
* \file
* \brief plik o rzszerzeniu*.h dla pliku Main wxwidgeta
*/

//(*Headers(KALKULATORFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class KALKULATORFrame: public wxFrame
{
    public:

        KALKULATORFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~KALKULATORFrame();

    private:

        //(*Handlers(KALKULATORFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(KALKULATORFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(KALKULATORFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // KALKULATORMAIN_H
