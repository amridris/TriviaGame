#include "optionPage.h"

//(*InternalHeaders(optionPage)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//(*IdInit(optionPage)
const long optionPage::ID_STATICTEXT1 = wxNewId();
const long optionPage::ID_STATICTEXT2 = wxNewId();
const long optionPage::ID_STATICTEXT3 = wxNewId();
const long optionPage::ID_SPINBUTTON1 = wxNewId();
const long optionPage::ID_CHOICE1 = wxNewId();
const long optionPage::ID_TEXTCTRL1 = wxNewId();
const long optionPage::ID_STATICBITMAP1 = wxNewId();
const long optionPage::ID_BUTTON1 = wxNewId();
const long optionPage::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(optionPage,wxFrame)
	//(*EventTable(optionPage)
	//*)
END_EVENT_TABLE()

optionPage::optionPage(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(optionPage)
	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(400,448));
	optionPanel = new wxPanel(this, ID_PANEL1, wxPoint(304,248), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	StaticText1 = new wxStaticText(optionPanel, ID_STATICTEXT1, _("Number of Rounds:"), wxPoint(8,232), wxSize(136,24), 0, _T("ID_STATICTEXT1"));
	StaticText2 = new wxStaticText(optionPanel, ID_STATICTEXT2, _("Difficult Level:"), wxPoint(8,296), wxSize(136,16), 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(optionPanel, ID_STATICTEXT3, _("Name:"), wxPoint(8,160), wxSize(136,24), 0, _T("ID_STATICTEXT3"));
	roundSpinButton = new wxSpinButton(optionPanel, ID_SPINBUTTON1, wxPoint(168,224), wxSize(144,40), wxSP_VERTICAL|wxSP_ARROW_KEYS, _T("ID_SPINBUTTON1"));
	roundSpinButton->SetValue(5);
	roundSpinButton->SetRange(5, 100);
	difficultyLevelSet = new wxChoice(optionPanel, ID_CHOICE1, wxPoint(168,288), wxSize(144,32), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	difficultyLevelSet->SetSelection( difficultyLevelSet->Append(_("Easy")) );
	difficultyLevelSet->Append(_("Medium"));
	difficultyLevelSet->Append(_("Hard"));
	TextCtrl1 = new wxTextCtrl(optionPanel, ID_TEXTCTRL1, _("Your\'re name here"), wxPoint(168,152), wxSize(144,32), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	StaticBitmap1 = new wxStaticBitmap(optionPanel, ID_STATICBITMAP1, wxBitmap(wxImage(_T("/home/aamer/CodeBlocksProjects/TriviaGame/triviaGame/assests/options.jpg")).Rescale(wxSize(400,144).GetWidth(),wxSize(400,144).GetHeight())), wxPoint(0,0), wxSize(400,144), wxSIMPLE_BORDER, _T("ID_STATICBITMAP1"));
	saveOptionBtn = new wxButton(optionPanel, ID_BUTTON1, _("Save Options"), wxPoint(136,368), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&optionPage::OnsaveOptionBtnClick);
	//*)
}

optionPage::~optionPage()
{
	//(*Destroy(optionPage)
	//*)
}


void optionPage::OnsaveOptionBtnClick(wxCommandEvent& event)
{
    userName = TextCtrl1->GetValue();
    rounds_value = roundSpinButton->GetValue();
    difficultyLevel = difficultyLevelSet->GetSelection();
    Hide();
}
