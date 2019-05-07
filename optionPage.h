#ifndef OPTIONPAGE_H
#define OPTIONPAGE_H

//(*Headers(optionPage)
#include <wx/spinbutt.h>
#include <wx/button.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
//*)

class optionPage: public wxFrame
{
	public:

		optionPage(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~optionPage();
		std::string userName;
		std::string difficultyLevel;
		int         rounds_value;

		//(*Declarations(optionPage)
		wxPanel* optionPanel;
		wxSpinButton* roundSpinButton;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxButton* saveOptionBtn;
		wxTextCtrl* TextCtrl1;
		wxChoice* difficultyLevelSet;
		wxStaticText* StaticText2;
		wxStaticBitmap* StaticBitmap1;
		//*)

	protected:

		//(*Identifiers(optionPage)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_SPINBUTTON1;
		static const long ID_CHOICE1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICBITMAP1;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(optionPage)
		void OnsaveOptionBtnClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
