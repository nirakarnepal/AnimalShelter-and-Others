#include "mainwin.h"
//#include "entrydialog.h"
#include <sstream>
#include <string>

Mainwin::Mainwin() : Mainwin{*(new Shelter)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////


    // Set up a vertical box to hold the main window elements
    set_default_size(600, 800);
    set_title("ANIMAL SHELTER");
  
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);

    // ///////////
    // M E N U ///
    /////////////


    // Add and configure a menu bar as the top item in the vertical box
    
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK,0);

///////////////// F I L E   M E N U //////////////////////

    /// Creating a file menu and adding Quit and New store.
    
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    // Q U I T
    /// since file menu is done now we add Quit under files
    Gtk::MenuItem *menuanimal_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
   // menuanimal_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuanimal_quit);

////////////////// A N I M A L S   M E N U  ///////////////////////////////////

    /// here we create add animals and list animals menu under Animals menu
    Gtk::MenuItem *menuitem_animals = Gtk::manage(new Gtk::MenuItem("_Animals", true));
    menubar->append(*menuitem_animals);
    Gtk::Menu *animalsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animals->set_submenu(*animalsmenu);
    
    // A D D   A N I M A L S
    /// adding add under Animals menu
    Gtk::MenuItem *menuanimal_new = Gtk::manage(new Gtk::MenuItem("Add Animal", true));
    //menuanimal_new->signal_activate().connect([this] {this->on_new_animal_click();});
    animalsmenu->append(*menuanimal_new);
    /// L I S T   S W E E T S 
    /// adding list under sweet menu
    Gtk::MenuItem *menuanimal_list= Gtk::manage(new Gtk::MenuItem("List Animals", true));
    //menuanimal_list->signal_activate().connect([this] {this->on_list_animals_click();});
    animalsmenu->append(*menuanimal_list);



    vbox->show_all

}

Mainwin::~Mainwin() { }
