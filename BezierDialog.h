///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/dialog.h>

#include "BezierDialog.h"

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class BezierDialog
///////////////////////////////////////////////////////////////////////////////
class BezierDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticTextX0;
		wxTextCtrl* m_textCtrlX0;
		wxStaticText* m_staticTextY0;
		wxTextCtrl* m_textCtrlY0;
		wxStaticText* m_staticTextX1;
		wxTextCtrl* m_textCtrlX1;
		wxStaticText* m_staticTextY1;
		wxTextCtrl* m_textCtrlY1;
		wxStaticText* m_staticTextX2;
		wxTextCtrl* m_textCtrlX2;
		wxStaticText* m_staticTextY2;
		wxTextCtrl* m_textCtrlY2;
		wxStaticText* m_staticTextX3;
		wxTextCtrl* m_textCtrlX3;
		wxStaticText* m_staticTextY3;
		wxTextCtrl* m_textCtrlY3;
		wxButton* m_button1;
		wxButton* m_button2Cancel;

	public:

		BezierDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Enter Control Points"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~BezierDialog();

};

