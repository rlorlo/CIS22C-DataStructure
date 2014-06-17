#include "BasicDrawPane.h"

BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
	EVT_PAINT(BasicDrawPane::paintEvent)
END_EVENT_TABLE()

BasicDrawPane::BasicDrawPane(wxStaticBitmap* parent)
	: wxPanel(parent, wxID_ANY, wxPoint(300, 40), wxSize(300, 300))
{}

void BasicDrawPane::paintEvent(wxPaintEvent & evt)
{
	wxClientDC dc(this);
	renderTrue(dc);
}

void BasicDrawPane::renderTrue(wxDC& dc)
{
	dc.Clear();
	// draw a circle
    dc.SetBrush(*wxGREEN_BRUSH); // green filling
    dc.SetPen( wxPen( wxColor(255,0,0), 5 ) ); // 5-pixels-thick red outline
    dc.DrawCircle( wxPoint(150,150), 50 /* radius */ );
}