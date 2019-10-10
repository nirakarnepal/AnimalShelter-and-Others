#include <gtkmm.h>

class Mainwin : public Gtk::Window {
  public:
    Mainwin();
    virtual ~Mainwin();
  protected:
    void on_label_click();
    void on_entry_activate();
    void on_button_click();
    void on_comboboxtext_activate();

  private:
    // These are the widgets demonstrated in order
    Gtk::Entry* entry;
    Gtk::ComboBoxText* comboboxtext;
    Gtk::Button* button;
    Gtk::ToggleButton* togglebutton;
    

    Gtk::Button* dialog_button;
    void dialog();
};
