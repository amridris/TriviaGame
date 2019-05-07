#include "MainMenuPage.h"

//(*InternalHeaders(MainMenuPage)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(MainMenuPage)
const long MainMenuPage::ID_BUTTON1 = wxNewId();
const long MainMenuPage::ID_BUTTON2 = wxNewId();
const long MainMenuPage::ID_BUTTON3 = wxNewId();
const long MainMenuPage::ID_STATICBITMAP1 = wxNewId();
const long MainMenuPage::ID_PANEL1 = wxNewId();
const long MainMenuPage::ID_STATUSBAR1 = wxNewId();
const long MainMenuPage::ID_MENUITEM1 = wxNewId();
const long MainMenuPage::ID_MENUITEM2 = wxNewId();
const long MainMenuPage::ID_MESSAGEDIALOG1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(MainMenuPage,wxFrame)
	//(*EventTable(MainMenuPage)
	//*)
END_EVENT_TABLE()

MainMenuPage::MainMenuPage(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(MainMenuPage)
	Create(parent, id, _("Trivia Menu"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(400,470));
	menuPanel = new wxPanel(this, ID_PANEL1, wxPoint(200,240), wxSize(320,470), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	startNewGameBtn = new wxButton(menuPanel, ID_BUTTON1, _("Start New Game"), wxPoint(128,208), wxSize(144,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
	optionFrameBtn = new wxButton(menuPanel, ID_BUTTON2, _("Options"), wxPoint(128,296), wxSize(144,32), 0, wxDefaultValidator, _T("ID_BUTTON2"));
	quitBtn = new wxButton(menuPanel, ID_BUTTON3, _("Quit"), wxPoint(128,384), wxSize(144,32), 0, wxDefaultValidator, _T("ID_BUTTON3"));
	StaticBitmap1 = new wxStaticBitmap(menuPanel, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/aamer/CodeBlocksProjects/TriviaGame/triviaGame/assests/triviaImg.jpg")).Rescale(wxSize(384,144).GetWidth(),wxSize(384,144).GetHeight())), wxPoint(8,8), wxSize(384,144), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	menuStatusBar = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -10 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	menuStatusBar->SetFieldsCount(1,__wxStatusBarWidths_1);
	menuStatusBar->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(menuStatusBar);
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuQuit = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit"), _("Quit application"), wxITEM_NORMAL);
	Menu1->Append(MenuQuit);
	MenuBar1->Append(Menu1, _("File"));
	Menu3 = new wxMenu();
	aboutMenu = new wxMenuItem(Menu3, ID_MENUITEM2, _("About"), _("Application Information"), wxITEM_NORMAL);
	Menu3->Append(aboutMenu);
	MenuBar1->Append(Menu3, _("Help"));
	SetMenuBar(MenuBar1);
	aboutDialog = new wxMessageDialog(this, _("Trivia Game created for CMPE 135 class Demo\nCreators: Aamer Idris"), _("Message"), wxOK, wxDefaultPosition);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainMenuPage::OnstartNewGameBtnClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainMenuPage::OnoptionFrameBtnClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainMenuPage::OnquitBtnClick);
	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainMenuPage::OnQuit);
	Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&MainMenuPage::OnaboutMenuSelected);
	//*)
	gameScreen = new triviaGameFrame(0);
	gameOption = new optionPage(0);
	startNewGameBtn->Disable();

}

MainMenuPage::~MainMenuPage()
{
	//(*Destroy(MainMenuPage)
	//*)
    delete gameScreen;
    delete gameOption;
    delete this;
}

void MainMenuPage::OnQuit(wxCommandEvent& event){

    delete gameScreen;
    delete gameOption;
    delete this;
}

void MainMenuPage::OnaboutMenuSelected(wxCommandEvent& event)
{
    aboutDialog->ShowModal();
}

void MainMenuPage::OnstartNewGameBtnClick(wxCommandEvent& event)
{
    gameScreen->userName = gameOption->userName;
    gameScreen->difficultyLevel = gameOption->difficultyLevel;
    gameScreen->rounds_value = gameOption->rounds_value;
    gameScreen->Show();
    startNewGameBtn->Disable();
}

void MainMenuPage::OnoptionFrameBtnClick(wxCommandEvent& event)
{
    gameOption->Show();
    gameOption->Center();
    startNewGameBtn->Enable();
}

void MainMenuPage::OnquitBtnClick(wxCommandEvent& event)
{
    delete gameScreen;
    delete gameOption;
    delete this;
}
