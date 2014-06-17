#include "wx/wx.h"
#include "wx/button.h"
#include "wx/textctrl.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include "menu.h"
#include "DataBase.h"

#include "BasicDrawPane.h"

enum
{
    ID_OpenFile = wxID_HIGHEST + 1,
	ID_bPrintTree = wxID_HIGHEST + 2,
	ID_bList = wxID_HIGHEST + 3,
	ID_bDrawStar = wxID_HIGHEST + 10
};

class MyFrame: public wxFrame
{
public:
	//constrols
	wxStatusBar* myStatusBar;
	wxStaticBitmap* panel;		//background panel
	BasicDrawPane* drawPane;	//star draw panel
	bool isDrawStar;			//star draw bool
	wxTextCtrl* txtFileName;	//file name text box

	//here is the program
	Menu myFunc;
	DataBase myDB;

public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	void OnOpenFile(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
	
	void OnButtonPrintTree(wxCommandEvent& event);
	void OnButtonDrawStar(wxCommandEvent& event);
	void OnButtonList(wxCommandEvent& event);
};
