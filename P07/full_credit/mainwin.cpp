#include "mainwin.h"
#include <cmath>

Mainwin::Mainwin()


  : //button{Gtk::manage(new Gtk::Button{"Click this button!"})},
    entry{Gtk::manage(new Gtk::Entry{})},
    comboboxtext{Gtk::manage(new Gtk::ComboBoxText{true})},
    label{Gtk::manage(new Gtk::Label{"This Label displays the vlaue of above operations"})}

{
    set_title("Nirakar Nepal 4");
    Gtk::VBox *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox); // This is where we add the vbox

    vbox->pack_start(*entry);
    entry->set_text("Enter your number (0-100)");
    entry->signal_activate().connect([this]{this->on_comboboxtext_activate();});



   // vbox->pack_start(*button);
    //button->set_tooltip_markup("Cosine");
    //button->signal_clicked().connect([this] {this->on_button_click();});


    vbox->pack_start(*comboboxtext);
    comboboxtext->append("Square root");
    comboboxtext->append("Natural logarithm (base e)");
    comboboxtext->append("Trigonometric cosine");
    comboboxtext->set_active(1);
    comboboxtext->signal_changed().connect([this]{this->on_comboboxtext_activate();});


    vbox->pack_start(*label);


    vbox->show_all();
}

Mainwin::~Mainwin() { }


//void Mainwin::on_button_click() {
//   Gtk::MessageDialog{*this, "Ouch!"}.run();
//}

void Mainwin::on_entry_activate() {
    Gtk::MessageDialog{*this, entry->get_text()}.run();
}

void Mainwin::on_comboboxtext_activate() {
   // std::string s = entry->get_text();//"Row " + std::to_string(comboboxtext->get_active_row_number())
        //+ ": " + comboboxtext->get_active_text();
    double a = atof(entry->get_text().c_str());
    if(comboboxtext->get_active_row_number()==0)
      {

         a = pow(a,0.5);

       }
     else if(comboboxtext->get_active_row_number()==1)

      {
           a = log(a);
       }
      else if(comboboxtext->get_active_row_number()==2)

      {
           a = cos(a);
       }


    label->set_text(std::to_string(a));
}




