#include <wx/wx.h>
#include "window.h"

class ShamirGui: public wxApp {
private:
	fMain *main_frame;

public:
	bool OnInit() {
		main_frame = new fMain;
		main_frame->Show();
		return true;
	}
};

wxIMPLEMENT_APP(ShamirGui);
