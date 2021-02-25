#include <wx/wx.h>
#include <wx/spinctrl.h>
#include "pointlist.h"

class fMain: public wxFrame {
public:
	fMain();

private:
	wxBoxSizer *row;
	wxBoxSizer *leftpanel;
	PointList *points;

	wxButton *button;
	wxSpinCtrl *k;

	wxTextCtrl *output;

	void clickCalculate(wxCommandEvent &event);
	void scrollSpinner(wxSpinEvent &event);

	wxDECLARE_EVENT_TABLE();
};
