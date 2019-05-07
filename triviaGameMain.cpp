/***************************************************************
 * Name:      triviaGameMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Aamer Idris (amridris@gmail.com)
 * Created:   2019-05-03
 * Copyright: Aamer Idris ()
 * License:
 **************************************************************/

#include "triviaGameMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(triviaGameFrame)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/image.h>
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

//(*IdInit(triviaGameFrame)
const long triviaGameFrame::ID_BUTTON1 = wxNewId();
const long triviaGameFrame::ID_STATICTEXT1 = wxNewId();
const long triviaGameFrame::ID_STATICTEXT3 = wxNewId();
const long triviaGameFrame::ID_BUTTON2 = wxNewId();
const long triviaGameFrame::ID_BUTTON3 = wxNewId();
const long triviaGameFrame::ID_BUTTON4 = wxNewId();
const long triviaGameFrame::ID_STATICBITMAP1 = wxNewId();
const long triviaGameFrame::ID_STATICTEXT2 = wxNewId();
const long triviaGameFrame::ID_STATICTEXT4 = wxNewId();
const long triviaGameFrame::ID_STATICTEXT5 = wxNewId();
const long triviaGameFrame::ID_STATICTEXT6 = wxNewId();
const long triviaGameFrame::ID_STATICTEXT8 = wxNewId();
const long triviaGameFrame::ID_BUTTON5 = wxNewId();
const long triviaGameFrame::ID_PANEL1 = wxNewId();
const long triviaGameFrame::idStartGame = wxNewId();
const long triviaGameFrame::idMenuQuit = wxNewId();
const long triviaGameFrame::idMenuAbout = wxNewId();
const long triviaGameFrame::ID_STATUSBAR1 = wxNewId();
const long triviaGameFrame::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(triviaGameFrame,wxFrame)
    //(*EventTable(triviaGameFrame)
    //*)
END_EVENT_TABLE()

triviaGameFrame::triviaGameFrame(wxWindow* parent,wxWindowID id)
{

    srand(time(nullptr));
    current_round = 1;
    //(*Initialize(triviaGameFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenuBar* menuBar;
    wxMenu* fileMenu;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Trivia Game"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(800,720));
    mainPanel = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    mainPanel->SetForegroundColour(wxColour(0,0,0));
    mainPanel->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    choice_a_btn = new wxButton(mainPanel, ID_BUTTON1, _("Label"), wxPoint(72,320), wxSize(200,32), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    choice_a_btn->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENUTEXT));
    choice_a_btn->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BACKGROUND));
    questionDisplay = new wxStaticText(mainPanel, ID_STATICTEXT1, _("Label"), wxPoint(112,234), wxSize(680,24), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(mainPanel, ID_STATICTEXT3, _("Question:"), wxPoint(8,232), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText2Font(13,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    choice_b_btn = new wxButton(mainPanel, ID_BUTTON2, _("Label"), wxPoint(72,392), wxSize(200,32), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    choice_c_btn = new wxButton(mainPanel, ID_BUTTON3, _("Label"), wxPoint(480,320), wxSize(200,32), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    choice_d_btn = new wxButton(mainPanel, ID_BUTTON4, _("Label"), wxPoint(480,392), wxSize(200,32), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    StaticBitmap1 = new wxStaticBitmap(mainPanel, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/aamer/CodeBlocksProjects/TriviaGame/triviaGame/assests/trivia.jpeg")).Rescale(wxSize(800,192).GetWidth(),wxSize(800,192).GetHeight())), wxPoint(0,0), wxSize(800,192), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
    StaticText1 = new wxStaticText(mainPanel, ID_STATICTEXT2, _("1"), wxPoint(8,328), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    StaticText3 = new wxStaticText(mainPanel, ID_STATICTEXT4, _("2"), wxPoint(8,400), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText3Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    StaticText4 = new wxStaticText(mainPanel, ID_STATICTEXT5, _("3"), wxPoint(424,328), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxFont StaticText4Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    StaticText5 = new wxStaticText(mainPanel, ID_STATICTEXT6, _("4"), wxPoint(424,400), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    wxFont StaticText5Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    roundDisplay = new wxStaticText(mainPanel, ID_STATICTEXT8, _("Round: "), wxPoint(264,488), wxSize(208,32), 0, _T("ID_STATICTEXT8"));
    wxFont roundDisplayFont(15,wxFONTFAMILY_SWISS,wxFONTSTYLE_ITALIC,wxFONTWEIGHT_BOLD,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    roundDisplay->SetFont(roundDisplayFont);
    nextQuestion = new wxButton(mainPanel, ID_BUTTON5, _("Next Question"), wxPoint(288,576), wxSize(128,33), 0, wxDefaultValidator, _T("ID_BUTTON5"));
    menuBar = new wxMenuBar();
    fileMenu = new wxMenu();
    startNewGameMenu = new wxMenuItem(fileMenu, idStartGame, _("New Game"), _("Start a new game"), wxITEM_NORMAL);
    fileMenu->Append(startNewGameMenu);
    MenuItem1 = new wxMenuItem(fileMenu, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    fileMenu->Append(MenuItem1);
    menuBar->Append(fileMenu, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Fun Trivia Game Demo for CMPE 135 Class"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    menuBar->Append(Menu2, _("Help"));
    SetMenuBar(menuBar);
    statusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    statusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
    statusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(statusBar);
    endGameMessage = new wxMessageDialog(this, _("Thank you for playing the game."), _("Game Over"), wxOK, wxDefaultPosition);
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&triviaGameFrame::Onchoice_a_btnClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&triviaGameFrame::Onchoice_b_btnClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&triviaGameFrame::Onchoice_c_btnClick);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&triviaGameFrame::Onchoice_d_btnClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&triviaGameFrame::OnnextQuestionClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&triviaGameFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&triviaGameFrame::OnAbout);
    //*)
    mainGameEngine = triviaGameEngine::instance();
    random_question_index = mainGameEngine->randomQuestionGenerator();
    questionDisplay->SetLabel(mainGameEngine->getQuestionat(random_question_index));
    choice_a_btn->SetLabel(mainGameEngine->getChoiceA(random_question_index));
    choice_b_btn->SetLabel(mainGameEngine->getChoiceB(random_question_index));
    choice_c_btn->SetLabel(mainGameEngine->getChoiceC(random_question_index));
    choice_d_btn->SetLabel(mainGameEngine->getChoiceD(random_question_index));
    wxString mystring = "Round   ";
    mystring.Append(wxString::Format(wxT("%d"), current_round));
    roundDisplay->SetLabel(mystring);


}

triviaGameFrame::~triviaGameFrame()
{
    //(*Destroy(triviaGameFrame)
    //*)

}

void triviaGameFrame::OnQuit(wxCommandEvent& event)
{
    Hide();
}

void triviaGameFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void triviaGameFrame::getNextQuestion(){
    random_question_index = mainGameEngine->randomQuestionGenerator();
    questionDisplay->SetLabel(mainGameEngine->getQuestionat(random_question_index));
    choice_a_btn->SetLabel(mainGameEngine->getChoiceA(random_question_index));
    choice_b_btn->SetLabel(mainGameEngine->getChoiceB(random_question_index));
    choice_c_btn->SetLabel(mainGameEngine->getChoiceC(random_question_index));
    choice_d_btn->SetLabel(mainGameEngine->getChoiceD(random_question_index));
}

void triviaGameFrame::incrementRoundAndDisplay(){
    wxString mystring = "Round   ";
    mystring.Append(wxString::Format(wxT("%d"), current_round));
    roundDisplay->SetLabel(mystring);
}
void triviaGameFrame::OnnextQuestionClick(wxCommandEvent& event)
{

    if(current_round == rounds_value){

        roundDisplay->SetLabel("End of Round. Thanks for Playing");
        wxMessageDialog *ending;
        float ave = mainGameEngine->winPercentageValue(rounds_value);
        ave = ave * 100;
        wxString finalMessage = wxString::Format(wxT("Thank you for playing.\n\nNumber of correct answer: %d\nWinning percentage: %0.2f%%"), mainGameEngine->getCorrectAns(), ave);
        ending = new wxMessageDialog(this, finalMessage,_("Game Over"), wxOK, wxDefaultPosition);
        ending->ShowModal();
        Hide();
        mainGameEngine->reset();
        getNextQuestion();
        current_round = 1;
    }
    current_round++;
    enableBtns();
    getNextQuestion();
    incrementRoundAndDisplay();
}

void triviaGameFrame::Onchoice_a_btnClick(wxCommandEvent& event)
{
    is_it_correct = mainGameEngine->checkValue(1, random_question_index);
    if(is_it_correct){
        choice_a_btn->SetLabel("correct Choice!");
        choice_a_btn->SetBackgroundColour(*wxGREEN);
        mainGameEngine->incrementScore();
    }
    else{
        choice_a_btn->SetLabel("Wrong choice!");
        mainGameEngine->incrementLoss();
    }
    choice_b_btn->Disable();
    choice_c_btn->Disable();
    choice_d_btn->Disable();
}



void triviaGameFrame::Onchoice_b_btnClick(wxCommandEvent& event)
{
    is_it_correct = mainGameEngine->checkValue(2, random_question_index);
    if(is_it_correct){
        choice_b_btn->SetLabel("correct Choice!");
        choice_b_btn->SetBackgroundColour(*wxGREEN);
        mainGameEngine->incrementScore();
    }
    else{
        choice_b_btn->SetLabel("Wrong choice!");
        mainGameEngine->incrementLoss();
    }
    choice_a_btn->Disable();
    choice_c_btn->Disable();
    choice_d_btn->Disable();
}

void triviaGameFrame::Onchoice_c_btnClick(wxCommandEvent& event)
{
    is_it_correct = mainGameEngine->checkValue(3, random_question_index);
    if(is_it_correct){
        choice_c_btn->SetLabel("correct Choice!");
        choice_c_btn->SetBackgroundColour(*wxGREEN);
        mainGameEngine->incrementScore();
    }
    else{
        choice_c_btn->SetLabel("Wrong choice!");
        mainGameEngine->incrementLoss();
    }
    choice_b_btn->Disable();
    choice_a_btn->Disable();
    choice_d_btn->Disable();
}

void triviaGameFrame::Onchoice_d_btnClick(wxCommandEvent& event)
{
    is_it_correct = mainGameEngine->checkValue(4, random_question_index);
    if(is_it_correct){
        choice_d_btn->SetLabel("correct Choice!");
        choice_d_btn->SetBackgroundColour(*wxGREEN);
        mainGameEngine->incrementScore();
    }
    else{
        choice_d_btn->SetLabel("Wrong choice!");
        mainGameEngine->incrementLoss();
    }
    choice_b_btn->Disable();
    choice_c_btn->Disable();
    choice_a_btn->Disable();
}


void triviaGameFrame::enableBtns(){
    choice_a_btn->Enable();
    choice_b_btn->Enable();
    choice_c_btn->Enable();
    choice_d_btn->Enable();
}

