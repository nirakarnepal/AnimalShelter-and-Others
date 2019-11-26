#include "mainwin.h"
#include "dog.h"
#include "cat.h"
#include "rabbit.h"
#include <sstream>
#include "client.h"
#include <iostream>
#include <string.h>

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

        //           L I S T
    // Append List to the CLient menu
    Gtk::MenuItem *menuitem_listclient = Gtk::manage(new Gtk::MenuItem("_List", true));
    menuitem_listclient->signal_activate().connect([this] {this->on_list_clients_click();});
    clientmenu->append(*menuitem_listclient);

        //     Adoption 
    // Create an client menu and add to the menu bar
    Gtk::MenuItem *menuitem_adopt = Gtk::manage(new Gtk::MenuItem("_Adoption", true));
    menubar->append(*menuitem_adopt);
    Gtk::Menu *adoptmenu = Gtk::manage(new Gtk::Menu());
    menuitem_adopt->set_submenu(*adoptmenu);

    //           N E W  Adopt
    // Append New to the Adoption menu
    Gtk::MenuItem *menuitem_newadopt = Gtk::manage(new Gtk::MenuItem("_Adopt", true));
    menuitem_newadopt->signal_activate().connect([this] {this->on_adopt_animal_click();});
    adoptmenu->append(*menuitem_newadopt);

        //           L I S T
    // Append List to the Adoption menu
    Gtk::MenuItem *menuitem_listadopt = Gtk::manage(new Gtk::MenuItem("_List", true));
    //menuitem_listadopt->signal_activate().connect([this] {this->on_list_adopted_click();});
    adoptmenu->append(*menuitem_listadopt);

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    toolbar->override_background_color(Gdk::RGBA{"gray"});
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);

    //to Add Animals
    Gtk::Image* imageAnimal = Gtk::manage(new Gtk::Image{"Animal.png"});
    Gtk::ToolButton *add_animal_button = Gtk::manage(new Gtk::ToolButton(*imageAnimal));
    add_animal_button->set_tooltip_markup("Add a New Animal");
    add_animal_button->signal_clicked().connect([this] {this->on_new_animal_click();});
    toolbar->append(*add_animal_button);


   ///list Animal button
    Gtk::ToolButton *list_animal_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::FILE));
    //Gtk::Image *orderImage = Gtk::manage(new Gtk::Image{"order.png"});
    //list_animal_button = Gtk::manage(new Gtk::Image{*orderImage});
    list_animal_button->set_tooltip_markup("List All Animal Data");
    list_animal_button->signal_clicked().connect([this] {this->on_list_animals_click();});
    toolbar->append(*list_animal_button);

    //to Add Client
    Gtk::Image* imageClient = Gtk::manage(new Gtk::Image{"Client.png"});
    Gtk::ToolButton *add_client_button = Gtk::manage(new Gtk::ToolButton(*imageClient));
    add_client_button->set_tooltip_markup("Add a New CLient");
    add_client_button->signal_clicked().connect([this] {this->on_new_client_click();});
    toolbar->append(*add_client_button);

    //to List Client
    Gtk::Image* imageCList = Gtk::manage(new Gtk::Image{"CList.png"});
    Gtk::ToolButton *add_clist_button = Gtk::manage(new Gtk::ToolButton(*imageCList));
    add_clist_button->set_tooltip_markup("List All Clients");
    add_clist_button->signal_clicked().connect([this] {this->on_list_clients_click();});
    toolbar->append(*add_clist_button);
    
        //to Adopt animal
    Gtk::Image* imageAdopt = Gtk::manage(new Gtk::Image{"Adopt.png"});
    Gtk::ToolButton *add_adopt_button = Gtk::manage(new Gtk::ToolButton(*imageAdopt));
    add_adopt_button->set_tooltip_markup("Adopt Animal");
    add_adopt_button->signal_clicked().connect([this] {this->on_adopt_animal_click();});
    toolbar->append(*add_adopt_button);


//////////////for Quit button

    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("Exit the program");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    toolbar->append(*quit_button);

    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the remaining data
    Gtk::Image *disp =Gtk::manage(new Gtk::Image{"adoption.png"});
    //disp->set("adoption.jpeg");
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    Gtk::ScrolledWindow* scroller = Gtk::manage(new Gtk::ScrolledWindow);
    scroller->add(*data);
    vbox->pack_start(*scroller, Gtk::PACK_EXPAND_WIDGET, 0);
    vbox->pack_start(*disp); 
     

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

    Gtk::Dialog mdialog{"Chose your animal", *this};

    Gtk::HBox b_animal; 
    Gtk::Label l_animal ("Animals:");
    l_animal.set_width_chars(15);
    b_animal.pack_start(l_animal, Gtk::PACK_SHRINK);
    mdialog.get_vbox()->pack_start(b_animal, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText b_gen;
    //b_gen.set_max_length(50);
    b_animal.pack_start(b_gen, Gtk::PACK_SHRINK);
    mdialog.get_vbox()->pack_start(b_animal, Gtk::PACK_SHRINK);
    b_gen.append("DOG");
    b_gen.append("CAT");
    b_gen.append("RABBIT");
    b_gen.set_active(1);


//    mdialog.add_button("DOG", 1);
//    mdialog.add_button("CAT", 2);
//    mdialog.add_button("RABBIT", 3);

    mdialog.add_button("Done", 0);
    mdialog.add_button("Add", 1);
    mdialog.show_all();
     //mdialog.set_default_response(1);
   if (mdialog.run() != 1 ) return;
    
    int row = b_gen.get_active_row_number();
    if(row == 0  ){
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
  if(row == 1){
     Gtk::Dialog dialog{"Cat Information", *this};

     Gtk::Grid grid;

     Gtk::Label l_name{"Name"};
     Gtk::Entry e_name;
     grid.attach(l_name, 0, 0, 1, 1);
     grid.attach(e_name, 1, 0, 2, 1);

     Gtk::Label l_breed{"Breed"};
     Gtk::ComboBoxText c_breed;
     for(auto b : cat_breeds) c_breed.append(to_string(b));
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

     dialog.add_button("Add Cat", 1);
     dialog.add_button("Cancel", 0);

     dialog.show_all();

     while(dialog.run()) {
         if(e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
         Animal* animal = new Cat{cat_breeds[c_breed.get_active_row_number()], 
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
     if(row == 2){
     Gtk::Dialog dialog{"Rabbit Information", *this};

     Gtk::Grid grid;

     Gtk::Label l_name{"Name"};
     Gtk::Entry e_name;
     grid.attach(l_name, 0, 0, 1, 1);
     grid.attach(e_name, 1, 0, 2, 1);

     Gtk::Label l_breed{"Breed"};
     Gtk::ComboBoxText c_breed;
     for(auto b : rabbit_breeds) c_breed.append(to_string(b));
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

     dialog.add_button("Add Rabbit", 1);
     dialog.add_button("Cancel", 0);

     dialog.show_all();

     while(dialog.run()) {
         if(e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
         Animal* animal = new Rabbit{rabbit_breeds[c_breed.get_active_row_number()], 
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
     
}
void Mainwin::on_list_animals_click() {
    std::ostringstream oss;

    if(shelter->num_clients() < 1 && shelter->num_animals() < 1  )
     {
      data->set_text("NO ANIMAL AVAILABLE !!");
      return;
      }
    for(int i=0; i<shelter->num_animals(); ++i)
        oss << shelter->animal(i) << '\n'; 
    data->set_text(oss.str());
    status("");
}      // List all animals


void Mainwin::on_list_clients_click() {
    std::ostringstream oss;
    if(shelter->num_clients() < 1 )
     {
      data->set_text("NO CLIENT AVAILABLE !!");
      return;
     }
    for(int i=0; i<shelter->num_clients(); ++i)
        oss << shelter->client(i) << '\n'; 
    data->set_text(oss.str());
    status("");
} 

void Mainwin::on_adopt_animal_click(){
    if(shelter->num_animals() < 1 || shelter->num_clients() < 1 )
     {
      Gtk::MessageDialog{*this, "No Animal or Client available !!! Press OK to continue"}.run();
      return;
      }
     
    Gtk::Dialog dialog{"Adopt Animal", *this};
    Gtk::Grid grid;

    Gtk::Label a_name{"Available Animals:   "};
    Gtk::Label c_name{"Our CLients:"};
    grid.attach(a_name, 0, 0, 1, 1);
    grid.attach(c_name, 1, 0, 2, 1);
    

  
    Gtk::ComboBoxText c_cname;
    for(int i=0; i<shelter->num_clients(); ++i)
       {
	  std::ostringstream oss;
          oss << shelter->client(i);
          c_cname.append(oss.str());
       } 
    c_cname.set_active(0);
    grid.attach(c_cname, 1, 1, 2, 1);
    int c_active = c_cname.get_active_row_number() ;
   
    Gtk::ComboBoxText c_aname;
    for(int i=0; i<shelter->num_animals(); ++i)
       {
         std::ostringstream oss;
         oss << shelter->animal(i);
         c_aname.append(oss.str());  
       }

    c_aname.set_active(0);
    grid.attach(c_aname, 0, 1, 1, 1);
    int active = c_aname.get_active_row_number(); 

    dialog.get_content_area()->add(grid);
 
    dialog.add_button("Adopt", 1);
    dialog.add_button("Cancel", 0);


    dialog.show_all();
    if(dialog.run())
     {
       shelter->adopt(shelter->client(c_active),shelter->animal(active)); 
       
//       data->set_text(shelter->animal(active) + " has been adopted by " + shelter->client(c_active));
        return;
     }
     
}

void Mainwin::on_new_client_click() {

     

    Gtk::Dialog dialog{"client info", *this};

    Gtk::Grid grid;

    Gtk::Label l_name{"Name"};
    Gtk::Entry e_name;
    grid.attach(l_name, 0, 0, 1, 1);
    grid.attach(e_name, 1, 0, 2, 1);

    Gtk::Label l_number{"Phone:"};
    Gtk::Entry e_phone;
    e_phone.set_text("999-999-9999");
    grid.attach(l_number, 0, 1, 1, 1);
    grid.attach(e_phone, 1, 1, 2, 1);

    Gtk::Label l_email{"email:"};
    Gtk::Entry e_email;
    e_email.set_text("name@example.com");
    grid.attach(l_email, 0, 2, 1, 1);
    grid.attach(e_email, 1, 2, 2, 1);

    dialog.get_content_area()->add(grid);

    dialog.add_button("Add Client", 1);
    dialog.add_button("Cancel", 0);

    dialog.show_all();

    while(dialog.run()) {
        if(e_name.get_text().size() == 0) {e_name.set_text("*required*"); continue;}
          msg->set_text(e_name.get_text() + " has been added");
	  data->set_text("ADDED CLIENT\nName: "+ e_name.get_text());
//        shelter->add_client(*client);
//        std::ostringstream oss;
//        oss << "Added " << *client;
//        status(oss.str());
          shelter->add_client(*(new Client{e_name.get_text(), e_phone.get_text(), e_email.get_text()}));
        break;
     }
}


// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::status(std::string s) {
    msg->set_text(s);
}
