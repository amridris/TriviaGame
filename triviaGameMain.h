/***************************************************************
 * Name:      triviaGameMain.h
 * Purpose:   Defines Application Frame
 * Author:    Aamer Idris (amridris@gmail.com)
 * Created:   2019-05-03
 * Copyright: Aamer Idris ()
 * License:
 **************************************************************/

#ifndef TRIVIAGAMEMAIN_H
#define TRIVIAGAMEMAIN_H

//(*Headers(triviaGameFrame)
#include <wx/msgdlg.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/statbmp.h>
//*)
#include "triviaGameEngine.h"
#include<random>

class triviaGameFrame: public wxFrame
{
    public:

        triviaGameFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~triviaGameFrame();
        triviaGameEngine *mainGameEngine;
        int random_question_index;
        std::string userName;
        std::string difficultyLevel;
        int rounds_value;
        int current_round;
        bool is_it_correct;


    private:
        void enableBtns();
        void getNextQuestion();
        void incrementRoundAndDisplay();
        //(*Handlers(triviaGameFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnmainPanelPaint(wxPaintEvent& event);
        void OnmainPanelPaint1(wxPaintEvent& event);
        void OnnextQuestionClick(wxCommandEvent& event);
        void Onchoice_a_btnClick(wxCommandEvent& event);
        void Onchoice_b_btnClick(wxCommandEvent& event);
        void Onchoice_c_btnClick(wxCommandEvent& event);
        void Onchoice_d_btnClick(wxCommandEvent& event);
        void OnmainPanelPaint2(wxPaintEvent& event);
        //*)

        //(*Identifiers(triviaGameFrame)
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_STATICBITMAP1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT8;
        static const long ID_BUTTON5;
        static const long ID_PANEL1;
        static const long idStartGame;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_MESSAGEDIALOG1;
        //*)

        //(*Declarations(triviaGameFrame)
        wxStatusBar* statusBar;
        wxMenuItem* startNewGameMenu;
        wxButton* choice_c_btn;
        wxStaticText* questionDisplay;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxButton* choice_a_btn;
        wxButton* nextQuestion;
        wxButton* choice_b_btn;
        wxStaticText* roundDisplay;
        wxMessageDialog* endGameMessage;
        wxStaticText* StaticText4;
        wxPanel* mainPanel;
        wxStaticText* StaticText5;
        wxButton* choice_d_btn;
        wxStaticText* StaticText2;
        wxStaticBitmap* StaticBitmap1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // TRIVIAGAMEMAIN_H
