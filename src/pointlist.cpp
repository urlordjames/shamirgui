#include "pointlist.h"

PointList::PointList(wxWindow *parent, int k): wxScrolledWindow(parent, wxID_ANY) {
	column = new wxBoxSizer(wxVERTICAL);
	SetSizer(column);

	setK(k);

	SetScrollRate(0, 5);
}

void PointList::setK(int k) {
	for (int i = 0; i < points.size(); i++) {
		points.at(i)->Destroy();
	}

	points.clear();

	for (int i = 0; i < k; i++) {
		Point *p = new Point(this);
		points.push_back(p);
		column->Add(p, 1, wxEXPAND, 10);
	}

	FitInside();
}

std::vector<mpz_class> PointList::getX() {
	std::vector<mpz_class> x;

	for (int i = 0; i < points.size(); i++) {
		x.push_back(points.at(i)->getX());
	}

	return x;
}

std::vector<mpz_class> PointList::getY() {
	std::vector<mpz_class> y;

	for (int i = 0; i < points.size(); i++) {
		y.push_back(points.at(i)->getY());
	}

	return y;
}
