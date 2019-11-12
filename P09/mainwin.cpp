#include "mainwin.h"
#include "dog.h"
#include <sstream>

Mainwin::Mainwin() : shelter{new Shelter{"Mavs Animal Shelter"}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(800, 600);
    set_title(APP_TITLE);

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // ///////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    //     A N I M A L
    // Create an Animal menu and add to the menu bar
    Gtk::MenuItem *menuitem_animal = Gtk::manage(new Gtk::MenuItem("_Animal", true));
    menubar->append(*menuitem_animal);
    Gtk::Menu *animalmenu = Gtk::manage(new Gtk::Menu());
    menuitem_animal->set_submenu(*animalmenu);

    //           N E W
    // Append New to the Animal menu
    Gtk::MenuItem *menuitem_newanimal = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newanimal->signal_activate().connect([this] {this->on_new_animal_click();});
    animalmenu->append(*menuitem_newanimal);

    //           L I S T
    // Append List to the Animal menu
    Gtk::MenuItem *menuitem_listanimal = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listanimal->signal_activate().connect([this] {this->on_list_animals_click();});
    animalmenu->append(*menuitem_listanimal);

    //     C L I E N T 
    // Create an client menu and add to the menu bar
    Gtk::MenuItem *menuitem_client = Gtk::manage(new Gtk::MenuItem("_Client", true));
    menubar->append(*menuitem_client);
    Gtk::Menu *clientmenu = Gtk::manage(new Gtk::Menu());
    menuitem_client->set_submenu(*clientmenu);

    //           N E W  C L I E N T
    // Append New to the client menu
    Gtk::MenuItem *menuitem_newclient = Gtk::manage(new Gtk::MenuItem("_New", true));
    menuitem_newclient->signal_activate().connect([this] {this->on_new_client_click();});
    clientmenu->append(*menuitem_newclient);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    toolbar->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    //to Add Animals
    Gtk::ToolButton *add_animal_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    //Gtk::Image *orderImage = Gtk::manage(new Gtk::Image{"order.png"});
    //place_order_button = Gtk::manage(new Gtk::Image{*orderImage});
    add_animal_button->set_tooltip_markup("Add a New Animal");
    add_animal_button->signal_clicked().connect([this] {this->on_new_animal_click();});
    toolbar->append(*add_animal_button);


   ///list Animal button
    Gtk::ToolButton *list_animal_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::HARDDISK));
    //Gtk::Image *orderImage = Gtk::manage(new Gtk::Image{"order.png"});
    //list_animal_button = Gtk::manage(new Gtk::Image{*orderImage});
    list_animal_button->set_tooltip_markup("List All Animal Data");
    list_animal_button->signal_clicked().connect([this] {this->on_list_animals_click();});
    toolbar->append(*list_animal_button);
    


//////////////for Quit button

    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit the program");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    toolbar->append(*quit_button);

    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining data
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->pack_start(*data, Gtk::PACK_EXPAND_WIDGET, 0);

    // ///////////////////////////////////
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for program messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    msg->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);

    // Make the box and everything in it visible
    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_new_animal_click() {

    Gtk::Dialog dialog{"Dog Information", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_breed{"Breed"};
    Gtk::ComboBoxText c_breed;
    for(auto b : dog_breeds) c_breed.append(to_string(b));
    c_breed.set_active(0);
    grid.attach(l_breed, 0, 1, 1, 1);
    grid.attach(c_breed, 1, 1, 2, 1);

    Gtk::Label l_gender{"Gender"};
    Gtk::ComboBoxText c_gender;
    c_gender.append("Female");
    c_gender.append("Male");
    c_gender.set_active(0);
    grid.attach(l_gender, 0, 2, 1, 1);
    grid.attach(c_gender, 1, 2, 2, 1);

    Gtk::Label l_age{"Age"};
    Gtk::SpinButton s_age;
    s_age.set_range(0,99);
    s_age.set_increments(1,5);
    s_age.set_value(5);
    grid.attach(l_age, 0, 3, 1, 1);
    grid.attach(s_age, 1, 3, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add Dog", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
        if(e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
        Animal* animal = new Dog{dog_breeds[c_breed.get_active_row_number()], 
                                 e_name.get_text(),
                                 (c_gender.get_active_row_number() ? Gender::MALE : Gender::FEMALE),
                                 static_cast<int>(s_age.get_value())};
        shelter->add_animal(*animal);
        std::ostringstream oss;
        oss << "Added " << *animal;
        status(oss.str());
        break;
    }
}

void Mainwin::on_list_animals_click() {
    std::ostringstream oss;
    for(int i=0; i<shelter->num_animals(); ++i)
        oss << shelter->animal(i) << '\n'; 
    data->set_text(oss.str());
    status("");
}      // List all animals


void Mainwin::on_new_client_click() {

    Gtk::Dialog dialog{"client info", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_number{"Phone:"};
    Gtk::Entry e_number;
    e_number.set_text("999-999-9999");
    grid.attach(l_number, 0, 1, 1, 1);
    grid.attach(e_number, 1, 1, 2, 1);

    Gtk::Label l_email{"email:"};
    Gtk::Entry e_email;
    e_email.set_text("name@example.com");
    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);


//    Gtk::Label l_gender{"Gender"};
//    Gtk::ComboBoxText c_gender;
//    c_gender.append("Female");
//    c_gender.append("Male");
//    c_gender.set_active(0);
//    grid.attach(l_gender, 0, 2, 1, 1);
//    grid.attach(c_gender, 1, 2, 2, 1);

//    Gtk::Label l_age{"Age"};
//    Gtk::SpinButton s_age;
//    s_age.set_range(0,99);
//    s_age.set_increments(1,5);
//    s_age.set_value(5);
//    grid.attach(l_age, 0, 3, 1, 1);
//    grid.attach(s_age, 1, 3, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add Client", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
        if(e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
          msg->set_text(e_name.get_text() + " has been added");
//        shelter->add_animal(*animal);
//        std::ostringstream oss;
//        oss << "Added " << *animal;
//        status(oss.str());
          break;
     }
}


// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::status(std::string s) {
    msg->set_text(s);
}
