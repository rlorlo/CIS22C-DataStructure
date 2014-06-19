#include "wx/wx.h"
#include "wx/button.h"
#include "wx/textctrl.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include "menu.h"
#include "DataBase.h"
//#include "StarPoint.h"


#include "BasicDrawPane.h"

enum
{
    ID_bOpenFile = wxID_HIGHEST + 1,
	ID_bAdd = wxID_HIGHEST + 2,
	ID_bDelete = wxID_HIGHEST + 3,
	ID_bUndo = wxID_HIGHEST + 4,
	ID_bDisplay = wxID_HIGHEST + 5,
	ID_bList = wxID_HIGHEST + 6,
	ID_bPrintTree = wxID_HIGHEST + 7,
	ID_bPrintTree2 = wxID_HIGHEST + 11,
	ID_bHashedStat = wxID_HIGHEST + 8,
	ID_bDraw = wxID_HIGHEST + 9,
	ID_bSave = wxID_HIGHEST + 10
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
	wxTextCtrl* txtAdd1;			//Add text
	wxTextCtrl* txtAdd2;
	wxTextCtrl* txtAdd3;
	wxTextCtrl* txtAdd4;
	wxTextCtrl* txtAdd5;
	wxTextCtrl* txtAdd6;
	wxTextCtrl* txtAdd7;
	wxTextCtrl* txtAdd8;
	wxTextCtrl* txtAdd9;
	wxTextCtrl* txtDelete;		//delete text
	wxTextCtrl* txtDisplay;		//display text
	wxTextCtrl* txtList;
	wxTextCtrl* txtDraw;

	//here is the program
	Menu myFunc;
	DataBase myDB;

public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
	
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
	
	void OnButtonOpenFile(wxCommandEvent& event);
	void OnButtonAdd(wxCommandEvent& event);
	void OnButtonDelete(wxCommandEvent& event);
	void OnButtonUndo(wxCommandEvent& event);
	void OnButtonDisplay(wxCommandEvent& event);
	void OnButtonList(wxCommandEvent& event);
	void OnButtonPrintTree(wxCommandEvent& event);
	void OnButtonPrintTree2(wxCommandEvent& event);
	void OnButtonHashedStat(wxCommandEvent& event);
	void OnButtonDraw(wxCommandEvent& event);
	void OnButtonSave(wxCommandEvent& event);
	
};
