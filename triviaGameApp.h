/***************************************************************
 * Name:      triviaGameApp.h
 * Purpose:   Defines Application Class
 * Author:    Aamer Idris (amridris@gmail.com)
 * Created:   2019-05-03
 * Copyright: Aamer Idris ()
 * License:
 **************************************************************/

#ifndef TRIVIAGAMEAPP_H
#define TRIVIAGAMEAPP_H

#include <wx/app.h>
#include "triviaGameEngine.h"


class triviaGameApp : public wxApp
{
    public:

        virtual bool OnInit();
};

#endif // TRIVIAGAMEAPP_H
