#ifndef MAINMENUPAGE_H
#define MAINMENUPAGE_H

//(*Headers(MainMenuPage)
#include <wx/msgdlg.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/statbmp.h>
//*)
#include "triviaGameMain.h"
#include "optionPage.h"

class MainMenuPage: public wxFrame
{
	public:

		MainMenuPage(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~MainMenuPage();
		triviaGameFrame *gameScreen;
		optionPage *gameOption;

		//(*Declarations(MainMenuPage)
		wxMenu* Menu1;
		wxStatusBar* menuStatusBar;
		wxMenu* Menu3;
		wxButton* startNewGameBtn;
		wxButton* quitBtn;
		wxMenuItem* MenuQuit;
		wxMenuItem* aboutMenu;
		wxMessageDialog* aboutDialog;
		wxMenuBar* MenuBar1;
		wxStaticBitmap* StaticBitmap1;
		wxPanel* menuPanel;
		wxButton* optionFrameBtn;
		//*)

	protected:

		//(*Identifiers(MainMenuPage)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_STATICBITMAP1;
		static const long ID_PANEL1;
		static const long ID_STATUSBAR1;
		static const long ID_MENUITEM1;
		static const long ID_MENUITEM2;
		static const long ID_MESSAGEDIALOG1;
		//*)

	private:
		//(*Handlers(MainMenuPage)
		    void OnQuit(wxCommandEvent& event);
		void OnaboutMenuSelected(wxCommandEvent& event);
		void OnstartNewGameBtnClick(wxCommandEvent& event);
		void OnoptionFrameBtnClick(wxCommandEvent& event);
		void OnquitBtnClick(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
