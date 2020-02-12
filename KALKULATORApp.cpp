/***************************************************************
 * Name:      KALKULATORApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2019-01-09
 * Copyright:  ()
 * License:
 **************************************************************/

#include "KALKULATORApp.h"
/*!
* \file
* \brief plik App aplikacji wxwidget
*/
//(*AppHeaders
#include "KALKULATORMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(KALKULATORApp);

bool KALKULATORApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	KALKULATORFrame* Frame = new KALKULATORFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
