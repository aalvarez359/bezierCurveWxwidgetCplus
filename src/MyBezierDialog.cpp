#include "MyBezierDialog.h"
#include "Coordinate.h"

MyBezierDialog::MyBezierDialog(wxWindow* parent, int panelHeight)
    : BezierDialog(parent), panelHeight(panelHeight) {

    m_button1->Bind(wxEVT_BUTTON, &MyBezierDialog::OnOK, this);
    m_button2Cancel->Bind(wxEVT_BUTTON, &MyBezierDialog::OnCancel, this);
}

void MyBezierDialog::OnOK(wxCommandEvent& event) {
    double x0 = wxAtof(m_textCtrlX0->GetValue());
    double y0 = wxAtof(m_textCtrlY0->GetValue());
    double x1 = wxAtof(m_textCtrlX1->GetValue());
    double y1 = wxAtof(m_textCtrlY1->GetValue());
    double x2 = wxAtof(m_textCtrlX2->GetValue());
    double y2 = wxAtof(m_textCtrlY2->GetValue());
    double x3 = wxAtof(m_textCtrlX3->GetValue());
    double y3 = wxAtof(m_textCtrlY3->GetValue());

    double scale = 10.0;
    int height = GetParent()->GetSize().GetHeight();

    pt0 = { x0 * scale, panelHeight - y0 * scale };
    pt1 = { x1 * scale, panelHeight - y1 * scale };
    pt2 = { x2 * scale, panelHeight - y2 * scale };
    pt3 = { x3 * scale, panelHeight - y3 * scale };

    EndModal(wxID_OK);
}

void MyBezierDialog::OnCancel(wxCommandEvent& event) {
    EndModal(wxID_CANCEL);
}

bool MyBezierDialog::ControlPointsGetter(Coordinate& p0, Coordinate& p1, Coordinate& p2, Coordinate& p3) {
    p0 = pt0;
    p1 = pt1;
    p2 = pt2;
    p3 = pt3;
    return true;
}
