#include "MyFrame.h"
#include "wxTextDialog.h"

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    isDrawStar = false;
	
	wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_OpenFile, "&Open File with Starts", "Loads stars from file");
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
	Connect(ID_OpenFile, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame::OnOpenFile) );

	wxBitmap image;
	image.LoadFile(wxT("image.jpg"), wxBITMAP_TYPE_JPEG);
	wxPanel* backPanel = new wxPanel(this, wxID_ANY);
	panel = new wxStaticBitmap(backPanel, wxID_ANY, image);

	txtFileName = new wxTextCtrl(panel, wxID_ANY, "1.txt",wxPoint(20,20), wxDefaultSize);

	wxButton* bPrintTree = new wxButton(panel, ID_bPrintTree, wxT("Print Tree"), wxPoint(50, 300), wxDefaultSize);
	Connect(ID_bPrintTree, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonPrintTree) );
	wxButton* bList = new wxButton(panel, ID_bList, wxT("List"), wxPoint(50, 350), wxDefaultSize);
	Connect(ID_bList, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonList) );

	wxButton* bDrawStar = new wxButton(panel, ID_bDrawStar, wxT("Draw Star"), wxPoint(20, 100), wxDefaultSize);
	Connect(ID_bDrawStar, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame::OnButtonDrawStar) );
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

void MyFrame::OnOpenFile(wxCommandEvent& event)
{
	string fileName = txtFileName->GetLineText(0);
	if (myFunc.OpenFile(myDB, fileName) == "File opened successfully \n") myStatusBar->SetStatusText("File opened successfully");
	else myStatusBar->SetStatusText("File was NOT opened");
}

void MyFrame::OnButtonPrintTree(wxCommandEvent& event)
{
	wxTextDialog* txtDialog = new wxTextDialog(myFunc.PrintTree(myDB));
	txtDialog->Show(true);
}

void MyFrame::OnButtonList(wxCommandEvent& event)
{
	wxTextDialog* txtDialog = new wxTextDialog(myFunc.List(myDB, "b"));
	txtDialog->Show(true);
}

void MyFrame::OnButtonDrawStar(wxCommandEvent& event)
{
	if (isDrawStar) delete drawPane;
	isDrawStar = true;
	drawPane = new BasicDrawPane(panel);
}