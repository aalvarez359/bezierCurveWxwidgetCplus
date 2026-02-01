///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "BezierDialog.h"
#include "Coordinate.h"

///////////////////////////////////////////////////////////////////////////

BezierDialog::BezierDialog( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextX0 = new wxStaticText( this, wxID_ANY, _("x0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextX0->Wrap( -1 );
	bSizer5->Add( m_staticTextX0, 0, wxALL, 5 );

	m_textCtrlX0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_textCtrlX0, 0, wxALL, 5 );

	m_staticTextY0 = new wxStaticText( this, wxID_ANY, _("y0"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextY0->Wrap( -1 );
	bSizer5->Add( m_staticTextY0, 0, wxALL, 5 );

	m_textCtrlY0 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_textCtrlY0, 0, wxALL, 5 );


	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextX1 = new wxStaticText( this, wxID_ANY, _("x1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextX1->Wrap( -1 );
	bSizer6->Add( m_staticTextX1, 0, wxALL, 5 );

	m_textCtrlX1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_textCtrlX1, 0, wxALL, 5 );

	m_staticTextY1 = new wxStaticText( this, wxID_ANY, _("y1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextY1->Wrap( -1 );
	bSizer6->Add( m_staticTextY1, 0, wxALL, 5 );

	m_textCtrlY1 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_textCtrlY1, 0, wxALL, 5 );


	bSizer4->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextX2 = new wxStaticText( this, wxID_ANY, _("x2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextX2->Wrap( -1 );
	bSizer8->Add( m_staticTextX2, 0, wxALL, 5 );

	m_textCtrlX2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_textCtrlX2, 0, wxALL, 5 );

	m_staticTextY2 = new wxStaticText( this, wxID_ANY, _("y2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextY2->Wrap( -1 );
	bSizer8->Add( m_staticTextY2, 0, wxALL, 5 );

	m_textCtrlY2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_textCtrlY2, 0, wxALL, 5 );


	bSizer4->Add( bSizer8, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextX3 = new wxStaticText( this, wxID_ANY, _("x3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextX3->Wrap( -1 );
	bSizer9->Add( m_staticTextX3, 0, wxALL, 5 );

	m_textCtrlX3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_textCtrlX3, 0, wxALL, 5 );

	m_staticTextY3 = new wxStaticText( this, wxID_ANY, _("y3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextY3->Wrap( -1 );
	bSizer9->Add( m_staticTextY3, 0, wxALL, 5 );

	m_textCtrlY3 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_textCtrlY3, 0, wxALL, 5 );


	bSizer4->Add( bSizer9, 1, wxEXPAND, 5 );

	m_button1 = new wxButton( this, wxID_ANY, _("OK"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button1, 0, wxALL, 5 );

	m_button2Cancel = new wxButton( this, wxID_ANY, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_button2Cancel, 0, wxALL, 5 );


	this->SetSizer( bSizer4 );
	this->Layout();
	bSizer4->Fit( this );

	this->Centre( wxBOTH );
}

BezierDialog::~BezierDialog()
{
}
