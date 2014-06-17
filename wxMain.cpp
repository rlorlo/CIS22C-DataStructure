// Name: minimal.cpp
// Purpose: Stars Team Project
// Author: Tatiana Karminskaya
#include "wxMain.h"

wxIMPLEMENT_APP(wxMain);

bool wxMain::OnInit()
{
	wxInitAllImageHandlers();
	MyFrame *frame = new MyFrame("Stars", wxPoint(100, 100), wxSize(1000, 700));
	frame->Show(true);
	return true;

}

