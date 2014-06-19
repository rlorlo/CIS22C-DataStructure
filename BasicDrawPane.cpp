#include "BasicDrawPane.h"


BEGIN_EVENT_TABLE(BasicDrawPane, wxPanel)
	EVT_PAINT(BasicDrawPane::paintEvent)
END_EVENT_TABLE()

BasicDrawPane::BasicDrawPane(wxStaticBitmap* parent, wxPoint& p, wxSize& s, Menu* myFunc)
	: wxPanel(parent, wxID_ANY, p, s)
{
	menu = myFunc;
}

void BasicDrawPane::paintEvent(wxPaintEvent & evt)
{
	wxClientDC dc(this);
	renderTrue(dc);
}

void BasicDrawPane::renderTrue(wxDC& dc)
{
	dc.Clear();
	// draw a circle
	if (menu->number != 0)
	{
	dc.SetBrush(*wxGREEN_BRUSH); // green filling
    dc.SetPen( wxPen( wxColor(255,0,0), 3 ) ); // 5-pixels-thick red outline
    dc.DrawCircle( wxPoint(menu->pArray[0].x, menu->pArray[0].y), 10 /* radius */ );

	dc.SetBrush(*wxBLUE_BRUSH);
	dc.SetPen( wxPen( wxColor(255,255,0), 3 ) );
	for (int i = 1; i < menu->number; i++)
	{
		dc.DrawCircle( wxPoint(menu->pArray[i].x,menu->pArray[i].y), 5 /* radius */ );
	}
	}
}