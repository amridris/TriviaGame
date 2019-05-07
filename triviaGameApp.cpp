/***************************************************************
 * Name:      triviaGameApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Aamer Idris (amridris@gmail.com)
 * Created:   2019-05-03
 * Copyright: Aamer Idris ()
 * License:
 **************************************************************/

#include "triviaGameApp.h"
#include "MainMenuPage.h"
//(*AppHeaders
#include "triviaGameMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(triviaGameApp);

bool triviaGameApp::OnInit()
{

    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {

    	//triviaGameFrame* Frame = new triviaGameFrame(0);
    	//Frame->Show();
    	MainMenuPage *menuPage = new MainMenuPage(0);
    	menuPage->Show();
    	SetTopWindow(menuPage);
    }
    //*)
    return wxsOK;

}
