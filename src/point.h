#include <wx/wx.h>
#include <gmpxx.h>

class Point: public wxWindow {
public:
	Point(wxWindow *parent);

	wxWindow *myparent;

	mpz_class getX();
	mpz_class getY();

private:
	wxBoxSizer *row;
	wxTextCtrl *x;
	wxTextCtrl *y;
	wxButton *deleteButton;
};
