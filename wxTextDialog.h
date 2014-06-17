#include "wx/wx.h"
#include "wx/button.h"
#include "wx/textctrl.h"

enum
{
    ID_TextDialog = 7000,
	wxID_EXIT2 = 7001
};

class wxTextDialog: public wxDialog
{
public:
	wxTextCtrl* textCtrl;
	
public:
    wxTextDialog(string text2print);
	//~wxTextDialog();
	void OnExitTextDialog(wxCommandEvent& event);	
};

wxTextDialog::wxTextDialog(string text2print) 
	:wxDialog(NULL, wxID_ANY, wxT("Print Text Dialog"), wxDefaultPosition, wxSize(900, 700))
{
	wxTextCtrl* txt = new wxTextCtrl(this, ID_TextDialog, wxEmptyString, wxDefaultPosition, wxSize(894, 630), wxTE_MULTILINE|wxHSCROLL);
	wxButton* bPrintTree = new wxButton(this, wxID_EXIT2, wxT("OK"), wxPoint(460, 640), wxDefaultSize);
	Connect(wxID_EXIT2, wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(wxTextDialog::OnExitTextDialog) );

	txt->AppendText(text2print);
}

void wxTextDialog::OnExitTextDialog(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
	Destroy();
}