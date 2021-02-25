#include "point.h"

Point::Point(wxWindow *parent): wxWindow(parent, wxID_ANY) {
	myparent = parent;

	row = new wxBoxSizer(wxHORIZONTAL);

	x = new wxTextCtrl(this, wxID_ANY, "x", wxDefaultPosition, wxDefaultSize);
	y = new wxTextCtrl(this, wxID_ANY, "y", wxDefaultPosition, wxDefaultSize);

	row->Add(x, wxEXPAND | wxALL, 10);
	row->Add(y, wxEXPAND | wxALL, 10);

	SetSizerAndFit(row);
}

mpz_class Point::getX() {
	return mpz_class(x->GetValue());
}

mpz_class Point::getY() {
	return mpz_class(y->GetValue());
}
