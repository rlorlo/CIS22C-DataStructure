#include "wx/wx.h"
#include "wx/button.h"
#include "wx/textctrl.h"

class BasicDrawPane : public wxPanel
{ 
public:
   	
public:
	BasicDrawPane(wxStaticBitmap* parent);
    void paintEvent(wxPaintEvent & evt);
    void renderTrue(wxDC& dc);
	void renderFalse(wxDC& dc);

	DECLARE_EVENT_TABLE()
};

