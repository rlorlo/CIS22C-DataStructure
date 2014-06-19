#include "MyFrame.h"
#include "wxTextDialog.h"

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    isDrawStar = false;
	
	wxMenu *menuFile = new wxMenu;
    //menuFile->Append(ID_OpenFile, "&Open File with Starts", "Loads stars from file");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    myStatusBar = CreateStatusBar();
    SetStatusText( "Stars!" );

	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame::OnExit) );
	Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame::OnAbout) );
	//Connect(ID_OpenFile, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame::OnOpenFile) );

	wxBitmap image;
	image.LoadFile(wxT("image.jpg"), wxBITMAP_TYPE_JPEG);
	wxPanel* backPanel = new wxPanel(this, wxID_ANY);
	panel = new wxStaticBitmap(backPanel, wxID_ANY, image);

	wxButton* bOpenFile = new wxButton(panel, ID_bOpenFile, wxT("Open File"), wxPoint(50, 50), wxDefaultSize);
	Connect(ID_bOpenFile, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonOpenFile) );
	txtFileName = new wxTextCtrl(panel, wxID_ANY, "1.txt",wxPoint(160,50), wxDefaultSize);

	wxButton* bAdd = new wxButton(panel, ID_bAdd, wxT("Add"), wxPoint(50, 100), wxDefaultSize);
	Connect(ID_bAdd, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonAdd) );
	txtAdd1 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(160,100), wxDefaultSize);
	txtAdd2 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(300,100), wxSize(40,23));
	txtAdd3 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(350,100), wxSize(40,23));
	txtAdd4 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(400,100), wxSize(40,23));
	txtAdd5 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(450,100), wxSize(40,23));
	txtAdd6 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(500,100), wxSize(40,23));
	txtAdd7 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(550,100), wxSize(40,23));
	txtAdd8 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(600,100), wxSize(40,23));
	txtAdd9 = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(650,100), wxSize(40,23));

	wxButton* bDelete = new wxButton(panel, ID_bDelete, wxT("Delete"), wxPoint(50, 150), wxDefaultSize);
	Connect(ID_bDelete, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonDelete) );
	txtDelete = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(160,150), wxDefaultSize);

	wxButton* bUndo = new wxButton(panel, ID_bUndo, wxT("Undo"), wxPoint(50, 200), wxDefaultSize);
	Connect(ID_bUndo, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonUndo) );

	wxButton* bDisplay = new wxButton(panel, ID_bDisplay, wxT("Display"), wxPoint(50, 250), wxDefaultSize);
	Connect(ID_bDisplay, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonDisplay) );
	txtDisplay = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(160,250), wxDefaultSize);

	wxButton* bList = new wxButton(panel, ID_bList, wxT("List"), wxPoint(50, 300), wxDefaultSize);
	Connect(ID_bList, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonList) );
	txtList = new wxTextCtrl(panel, wxID_ANY, "BST", wxPoint(160,300), wxDefaultSize);

	wxButton* bPrintTree = new wxButton(panel, ID_bPrintTree, wxT("Print Tree"), wxPoint(50, 350), wxDefaultSize);
	Connect(ID_bPrintTree, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonPrintTree) );

	wxButton* bPrintTree2 = new wxButton(panel, ID_bPrintTree2, wxT("Print Tree 2"), wxPoint(50, 400), wxDefaultSize);
	Connect(ID_bPrintTree2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonPrintTree2) );
	
	wxButton* bH = new wxButton(panel, ID_bHashedStat, wxT("H Statistics"), wxPoint(50, 450), wxDefaultSize);
	Connect(ID_bHashedStat, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonHashedStat) );

	wxButton* bDraw = new wxButton(panel, ID_bDraw, wxT("Draw Star"), wxPoint(50, 500), wxDefaultSize);
	Connect(ID_bDraw, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonDraw) );
	txtDraw = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(160,500), wxDefaultSize);

	wxButton* bSave = new wxButton(panel, ID_bSave, wxT("Save"), wxPoint(50, 550), wxDefaultSize);
	Connect(ID_bSave, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonSave) );

	myFunc.number = 0;
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Star Gasers Team\n version 1.0",
                  "About Stars", wxOK | wxICON_INFORMATION );
}

void MyFrame::OnButtonOpenFile(wxCommandEvent& event)
{
	string fileName = txtFileName->GetLineText(0);
	if (myFunc.OpenFile(myDB, fileName) == "File opened successfully \n") myStatusBar->SetStatusText("File opened successfully");
	else myStatusBar->SetStatusText("File was NOT opened");
}

void MyFrame::OnButtonAdd(wxCommandEvent& event)
{

}

void MyFrame::OnButtonDelete(wxCommandEvent& event)
{
	string name = txtDelete->GetLineText(0);
	if (myFunc.Delete(myDB, name)) myStatusBar->SetStatusText("Delete successfull");
	else myStatusBar->SetStatusText("Star was not found");
}
	
void MyFrame::OnButtonUndo(wxCommandEvent& event)
{
	if (myFunc.Undo(myDB)) myStatusBar->SetStatusText("Undo okidoki");
	else myStatusBar->SetStatusText("Undooooooooooooooooooooooo not doooooooooooooo");
}
	
void MyFrame::OnButtonDisplay(wxCommandEvent& event)
{
	string star = txtDisplay->GetLineText(0);
	wxTextDialog* txtDialog = new wxTextDialog(myFunc.Display(myDB, star));
	txtDialog->Show(true);
}
	
void MyFrame::OnButtonList(wxCommandEvent& event)
{
	string what = txtList->GetLineText(0);
	if (what == "HASH") 
	{
		wxTextDialog* txtDialog = new wxTextDialog(myFunc.List(myDB, "h"));
		txtDialog->Show(true);
	}
	else if (what == "BST")
	{
		wxTextDialog* txtDialog = new wxTextDialog(myFunc.List(myDB, "b"));
		txtDialog->Show(true);
	}
	else {}
}

void MyFrame::OnButtonPrintTree(wxCommandEvent& event)
{
	wxTextDialog* txtDialog = new wxTextDialog(myFunc.PrintTree(myDB));
	txtDialog->Show(true);
}

void MyFrame::OnButtonPrintTree2(wxCommandEvent& event)
{
	wxTextDialog* txtDialog = new wxTextDialog(myFunc.PrintTree2(myDB));
	txtDialog->Show(true);
}

void MyFrame::OnButtonHashedStat(wxCommandEvent& event)
{
	wxTextDialog* txtDialog = new wxTextDialog(myFunc.HashStatistic(myDB));
	txtDialog->Show(true);
}

void MyFrame::OnButtonDraw(wxCommandEvent& event)
{
	if (isDrawStar) delete drawPane;
	isDrawStar = true;
	string name = txtDraw->GetLineText(0);
	myFunc.getCon(myDB, name);
	drawPane = new BasicDrawPane(panel, wxPoint(500, 250), wxSize(400, 300), &myFunc);
}

void MyFrame::OnButtonSave(wxCommandEvent& event)
{
	myFunc.Save(myDB);
	myStatusBar->SetStatusText("File was saved");
}