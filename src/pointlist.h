#include <vector>
#include <wx/wx.h>
#include <gmpxx.h>
#include "point.h"

class PointList: public wxScrolledWindow {
public:
	PointList(wxWindow *parent, int k);

	void setK(int k);

	std::vector<mpz_class> getX();
	std::vector<mpz_class> getY();

private:
	wxBoxSizer *column;
	std::vector<Point*> points;
};
