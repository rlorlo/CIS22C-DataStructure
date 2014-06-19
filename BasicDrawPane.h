#include "wx/wx.h"
#include "wx/button.h"
#include "wx/textctrl.h"
#include "Menu.h"

class BasicDrawPane : public wxPanel
{ 
private:
   	/*StarPoint* points2draw;
	int number;*/
	Menu* menu;
public:
	BasicDrawPane(wxStaticBitmap* parent, wxPoint& p, wxSize& s, Menu* myFunc);
	void paintEvent(wxPaintEvent & evt);
    void renderTrue(wxDC& dc);

	DECLARE_EVENT_TABLE()
};

