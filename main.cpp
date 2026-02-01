#include <wx/wx.h>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <vector>
#include "MyBezierDialog.h"
#include "Coordinate.h"


class DrawingPane : public wxPanel {
public:
    DrawingPane(wxFrame* parent);
    void ControlPointSet(Coordinate p0, Coordinate p1, Coordinate p2, Coordinate p4);
    Coordinate curveCenter;
    bool draggingCenter = false;
    Coordinate dragOffset;

    //void SetZoom(double scale);
private:
    void OnPaint(wxPaintEvent& event);
    void DrawGrid(wxGraphicsContext* gc);
    void RedrawCurve();
    void OnKeyDown(wxKeyEvent& event);
    void OnMouseDown(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnMouseUp(wxMouseEvent& event);
    std::vector<Coordinate> controlPoints;
    std::vector<Coordinate> curveCoordinates;
    int draggedPointIndex = -1;
    double pixpercoord = 10.0;
    double curveZoom = 1.0;
    DECLARE_EVENT_TABLE()
};

wxBEGIN_EVENT_TABLE(DrawingPane, wxPanel)
EVT_PAINT(DrawingPane::OnPaint)
EVT_LEFT_DOWN(DrawingPane::OnMouseDown)
EVT_LEFT_UP(DrawingPane::OnMouseUp)
EVT_MOTION(DrawingPane::OnMouseMove)
EVT_KEY_DOWN(DrawingPane::OnKeyDown)
wxEND_EVENT_TABLE()


class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnCoordinates(wxCommandEvent& event);
private:
    DrawingPane* pane;
    DECLARE_EVENT_TABLE()
};

DECLARE_APP(MyApp)

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame(wxT("Bezier Curve Editor"));
    frame->Show(true);
    return true;
}

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
EVT_MENU(1001, MyFrame::OnCoordinates)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent&) {
    wxString msg;
    msg.Printf(wxT("Bezier Curve Editor\n\n"
        "To change a curve, click and drag any of the four control points.\n"
        "To create a curve, select the input tab and click Enter Coordinates.\n"
        "To move the curve, click and hold the Drag Point."),
        wxVERSION_STRING);
    wxMessageBox(msg, wxT("About"),
        wxOK | wxICON_INFORMATION, this);
    //wxMessageBox("Interactive Bezier Curve Editor\nUse mouse to drag control points.", "About", wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event) {
    Close();
}

#include "mondrian.xpm"

MyFrame::MyFrame(const wxString& title) 
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(816, 682)) {
    SetIcon(wxIcon(mondrian_xpm));
    wxMenu* fileMenu = new wxMenu;
    wxMenu* helpMenu = new wxMenu;
    wxMenu* inputMenu = new wxMenu;
    wxMenu* zoomMenu = new wxMenu;
    helpMenu->Append(wxID_ABOUT, wxT("& About...\tF1"),
        wxT("Show about dialog"));
    fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"),
        wxT("Quit this program"));
    inputMenu->Append(1001, wxT("Enter Control Points\tCtrl+E"), 
        wxT("Enter (x,y) control points"));
    zoomMenu->Append(wxID_ANY, wxT("Reset Scale = (Ctrl+0)"),
        wxT("Reset the scale level of the curve to default"));
    zoomMenu->Append(wxID_ANY, wxT("Scale Up 10% = (Ctrl++)"),
        wxT("Scale up on the curve"));
    zoomMenu->Append(wxID_ANY, wxT("Scale Down 10% = (Ctrl+-)"),
        wxT("Scale down on the curve"));
    wxMenuBar* menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, wxT("&File"));
    menuBar->Append(helpMenu, wxT("&Help"));
    menuBar->Append(inputMenu, wxT("&Input"));
    menuBar->Append(zoomMenu, wxT("&Scale"));
    SetMenuBar(menuBar);
    CreateStatusBar(2);
    SetStatusText(wxT("Welcome To The Bezier Curve Editor"));
    pane = new DrawingPane(this);
}

void MyFrame::OnCoordinates(wxCommandEvent& event) {
    MyBezierDialog dlg(this, pane->GetClientSize().GetHeight());
    if (dlg.ShowModal() == wxID_OK) {
        Coordinate p0, p1, p2, p3;
        if (dlg.ControlPointsGetter(p0, p1, p2, p3)) {
            pane->ControlPointSet(p0, p1, p2, p3);
        }
    }
}



DrawingPane::DrawingPane(wxFrame* parent)
    : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(816, 682)) {
    SetBackgroundStyle(wxBG_STYLE_PAINT);
    SetFocus();
    SetFocusFromKbd();

    controlPoints.push_back({ 100, 500 });
    controlPoints.push_back({ 300, 100 });
    controlPoints.push_back({ 500, 100 });
    controlPoints.push_back({ 700, 500 });
    RedrawCurve();
}

void DrawingPane::ControlPointSet(Coordinate p0, Coordinate p1, Coordinate p2, Coordinate p3) {
    controlPoints = { p0, p1, p2, p3 };
    RedrawCurve();
}

void DrawingPane::RedrawCurve() {
    curveCoordinates.clear();
    for (int i = 0; i <= 100; i++) {
        double t = i / static_cast<double>(100);
        double n = 1 - t;
        double x = n*n*n * controlPoints[0].x +
            3 * n*n * t * controlPoints[1].x +
            3 * n * t * t * controlPoints[2].x +
            t*t*t * controlPoints[3].x;
        double y = n*n*n * controlPoints[0].y +
            3 * n*n * t * controlPoints[1].y +
            3 * n * t*t * controlPoints[2].y +
            t*t*t * controlPoints[3].y;
        curveCoordinates.push_back({ x,y });
    }
    curveCenter.x = (controlPoints[0].x + controlPoints[3].x) / 2;
    curveCenter.y = (controlPoints[0].y + controlPoints[3].y) / 2;

    Refresh();
}

void DrawingPane::OnPaint(wxPaintEvent& event) {
    wxAutoBufferedPaintDC dc(this);
    dc.Clear();

    wxGraphicsContext* gc = wxGraphicsContext::Create(dc);
    if (!gc) return;

    DrawGrid(gc);

    gc->SetPen(wxPen(wxColour(0, 0, 0), 2));
    if (!curveCoordinates.empty()) {
        for (size_t i = 1; i < curveCoordinates.size(); i++) {
            gc->StrokeLine(curveCoordinates[i - 1].x*curveZoom, curveCoordinates[i - 1].y*curveZoom, curveCoordinates[i].x*curveZoom, curveCoordinates[i].y*curveZoom);
        }
    }

    gc->SetBrush(*wxBLACK_BRUSH);
    gc->SetPen(*wxTRANSPARENT_PEN);
    wxSize size = GetClientSize();
    int h = size.GetHeight();

    for (size_t i = 0; i < controlPoints.size(); ++i) {
        Coordinate p = controlPoints[i];
        double px = p.x * curveZoom;
        double py = p.y * curveZoom;
        gc->DrawEllipse(px-7, py-7, 16, 16);
        double coordX = p.x / pixpercoord;
        double coordY = (h - p.y) / pixpercoord;
        wxString label = wxString::Format("(x,y%zu)(%.1f, %.1f)", i, coordX, coordY);
        gc->DrawText(label, px + 6, py + 6);
        //gc->DrawText(wxString::Format("(%.1f, %.1f)", coordX, coordY), p.x + 6, p.y + 6);
    }

    if (controlPoints.size() == 4) {
        gc->SetPen(wxPen(wxColor(0, 0, 225), 1, wxPENSTYLE_SOLID));
        gc->StrokeLine(controlPoints[0].x*curveZoom, controlPoints[0].y*curveZoom, controlPoints[1].x*curveZoom, controlPoints[1].y*curveZoom);
        gc->StrokeLine(controlPoints[2].x*curveZoom, controlPoints[2].y*curveZoom, controlPoints[3].x*curveZoom, controlPoints[3].y*curveZoom);
    }

    double cx = curveCenter.x * curveZoom;
    double cy = curveCenter.y * curveZoom;
    gc->SetBrush(*wxBLUE_BRUSH);
    gc->DrawEllipse(cx - 6, cy - 6, 12, 12);
    gc->DrawText("Drag Point", cx + 8, cy - 8);

    delete gc;
}

void DrawingPane::DrawGrid(wxGraphicsContext* gc) {
    wxSize size = GetClientSize();
    int w = size.GetWidth();
    int h = size.GetHeight();

    gc->SetPen(wxPen(wxColor(220, 220, 220), 1));
    gc->SetFont(*wxNORMAL_FONT, *wxBLACK);
    int spacing = 50;
    //double pixpercoord = 10.0;

    for (int x = 0; x < w; x += spacing) {
        gc->StrokeLine(x, 0, x, h);
        double xunits = x / pixpercoord;
        gc->DrawText(wxString::Format("%.0f", xunits), x + 2, h-20);
    }

    for (int y = 0; y < h; y += spacing) {
        gc->StrokeLine(0, y, w, y);
        double yunits = (h-y) / pixpercoord;
        gc->DrawText(wxString::Format("%.0f", yunits), 2, y + 2);
    }
}

void DrawingPane::OnMouseDown(wxMouseEvent& event) {
    wxPoint mPt = event.GetPosition();
    double x = mPt.x;
    double y = mPt.y;
    if (!HasCapture())
    {
        for (int i = 0; i < controlPoints.size(); ++i) {
            wxPoint pt(controlPoints[i].x * curveZoom, controlPoints[i].y * curveZoom);
            if (abs(mPt.x - pt.x) <= 8 && abs(mPt.y - pt.y) <= 8) {
                draggedPointIndex = i;
                CaptureMouse();
                break;
            }
        }
    }
    double cx = curveCenter.x * curveZoom;
    double cy = curveCenter.y * curveZoom;

    if (sqrt(pow(x - cx, 2) + pow(y - cy, 2)) < 10) {
        draggingCenter = true;
        dragOffset = { x - cx, y - cy };
        CaptureMouse();
    }
}

void DrawingPane::OnMouseMove(wxMouseEvent& event) {
    if (!event.Dragging() || !event.LeftIsDown())
        return;

    wxPoint pos = event.GetPosition();
    double x = pos.x;
    double y = pos.y;
    if (draggedPointIndex != -1 && event.Dragging() && event.LeftIsDown()) {
        controlPoints[draggedPointIndex].x = event.GetX()/curveZoom;
        controlPoints[draggedPointIndex].y = event.GetY()/curveZoom;
        RedrawCurve();
    }
    else if (draggingCenter) {
        double newCx = (x - dragOffset.x) / curveZoom;
        double newCy = (y - dragOffset.y) / curveZoom;

        double dx = newCx - curveCenter.x;
        double dy = newCy - curveCenter.y;

        for (auto& pt : controlPoints) {
            pt.x += dx;
            pt.y += dy;
        }

        curveCenter.x = newCx;
        curveCenter.y = newCy;

        RedrawCurve();
    }
}

void DrawingPane::OnMouseUp(wxMouseEvent& event) {
    draggedPointIndex = -1;
    draggingCenter = false;

    if (HasCapture()) {
        ReleaseMouse();
    }
}


void DrawingPane::OnKeyDown(wxKeyEvent& event) {
    if (event.ControlDown()) {
        int keyCode = event.GetKeyCode();

        if (keyCode == WXK_ADD || keyCode == '=') {
            curveZoom *= 1.1;
        }
        else if (keyCode == WXK_SUBTRACT || keyCode == '-') {
            curveZoom /= 1.1;
        }
        else if (keyCode == '0') {
            curveZoom = 1.0;
        }

        Refresh();
    }
    else {
        event.Skip();
    }
}


