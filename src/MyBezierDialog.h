#pragma once
#include "BezierDialog.h"
#include "Coordinate.h"


class MyBezierDialog : public BezierDialog {
public:
    MyBezierDialog(wxWindow* parent, int panelHeight);

    bool ControlPointsGetter(Coordinate& p0, Coordinate& p1, Coordinate& p2, Coordinate& p3);
private:
    Coordinate pt0, pt1, pt2, pt3;
    void OnOK(wxCommandEvent& event);
    void OnCancel(wxCommandEvent& event);
    int panelHeight;
};
