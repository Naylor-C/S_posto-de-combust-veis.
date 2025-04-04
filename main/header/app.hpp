

// Declare the application class
class MyApp : public wxApp
{
public:
    // Called on application startup
    virtual bool OnInit();
};


// Declare our main frame class
class Frame : public wxFrame
{
public:
    // Constructor
    MyFrame(const wxString &title);
    // Event handlers

    void OnQuit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

private:
    // This class handles events
    DECLARE_EVENT_TABLE()
};



bool MyApp::OnInit()
{
    // Create the main application window
    Frame *F = new Frame(wxT(“Sistema of Posto of Combustiveis”));
    // Show it
    F->Show(true);
    // Start the event loop
    return true;
}

// Give wxWidgets the means to create a MyApp object
IMPLEMENT_APP(MyApp)

// Implements MyApp& wxGetApp()
DECLARE_APP(MyApp)


// Event table for MyFrame
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, Frame::OnAbout)
EVT_MENU(wxID_EXIT, Frame::OnQuit)
END_EVENT_TABLE()


//Events 

void Frame::OnAbout(wxCommandEvent& event)
{
wxString msg;
msg.Printf(wxT(“Hello and welcome to %s”),
wxVERSION_STRING);
wxMessageBox(msg, wxT(“About Minimal”),
wxOK | wxICON_INFORMATION, this);
}


void Frame::OnQuit(wxCommandEvent& event)
{
// Destroy the frame
Close();
}