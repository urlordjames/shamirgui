#include "window.h"
#include "shamir.h"
#include <gmpxx.h>

wxBEGIN_EVENT_TABLE(fMain, wxFrame)
	EVT_BUTTON(1, fMain::clickCalculate)
	EVT_SPINCTRL(2, fMain::scrollSpinner)
wxEND_EVENT_TABLE()

fMain::fMain(): wxFrame(NULL, wxID_ANY, "shamir gui") {
	row = new wxBoxSizer(wxHORIZONTAL);

	leftpanel = new wxBoxSizer(wxVERTICAL);

	int initk = 2;
	points = new PointList(this, initk);

	wxBoxSizer *rightpanel = new wxBoxSizer(wxVERTICAL);
	output = new wxTextCtrl(this, wxID_ANY, "output", wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

	row->Add(leftpanel, 1, wxEXPAND | wxALL, 10);
	row->Add(rightpanel, 1, wxEXPAND | wxALL, 10);

	button = new wxButton(this, 1, "calculate", wxDefaultPosition, wxDefaultSize);
	k = new wxSpinCtrl(this, 2, "k", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 2, 15, initk);

	leftpanel->Add(k, 1, wxEXPAND | wxALL, 10);
	
	// DO NOT SET wxALL HERE, IT BREAKS!
	leftpanel->Add(points, 5, wxEXPAND, 10);

	rightpanel->Add(output, 5, wxEXPAND | wxALL, 10);
	rightpanel->Add(button, 1, wxEXPAND | wxALL, 10);

	SetSizerAndFit(row);
}

void fMain::clickCalculate(wxCommandEvent &event) {
	std::vector<mpz_class> x = points->getX();
	std::vector<mpz_class> y = points->getY();
	output->SetValue(calcShamir(x, y));
	event.Skip();
}

void fMain::scrollSpinner(wxSpinEvent &event) {
	points->setK(event.GetInt());
	event.Skip();
}
