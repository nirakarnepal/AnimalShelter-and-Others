#include "mainwin.h"
#include "entrydialog.h"
#include <sstream>
#include <string>

Mainwin::Mainwin()  
{

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
    menuanimal_quit->signal_activate().connect([this] {this->on_quit_click();});
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
    menuanimal_new->signal_activate().connect([this] {this->on_new_animal_click();});
    animalsmenu->append(*menuanimal_new);
    /// L I S T   S W E E T S 
    /// adding list under sweet menu
    Gtk::MenuItem *menuanimal_list= Gtk::manage(new Gtk::MenuItem("List Animals", true));
    //menuanimal_list->signal_activate().connect([this] {this->on_new_animal_clickl();});
    animalsmenu->append(*menuanimal_list);



    vbox->show_all();

}

Mainwin::~Mainwin() { }


void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_new_animal_click() 
{

    Gtk::Dialog *dialog = new Gtk::Dialog("Add animal", *this);
    int age;
   
    std::string gender;
    int result;
    std::string name;
    
  ///framework
   
    Gtk::HBox b_name; 
    Gtk::Label l_name ("Name:");
    l_name.set_width_chars(15);
    b_name.pack_start(l_name, Gtk::PACK_SHRINK);
/// ready to enter value.
    Gtk::Entry e_name;
    e_name.set_max_length(50);
    b_name.pack_start(e_name, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_name, Gtk::PACK_SHRINK);


    Gtk::HBox b_age; 
    Gtk::Label l_age ("Age:");
    l_age.set_width_chars(15);
    b_age.pack_start(l_age, Gtk::PACK_SHRINK);
/// ready to enter value.
    Gtk::Entry e_age;
    e_age.set_max_length(50);
    b_age.pack_start(e_age, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_age, Gtk::PACK_SHRINK);

  
    Gtk::HBox b_gender; 
    Gtk::Label l_gender ("Gender:");
    l_gender.set_width_chars(15);
    b_gender.pack_start(l_gender, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_gender, Gtk::PACK_SHRINK);

    Gtk::ComboBoxText b_gen;
    //b_gen.set_max_length(50);
    b_gender.pack_start(b_gen, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_gender, Gtk::PACK_SHRINK);
    b_gen.append("male");
    b_gen.append("female");
    b_gen.set_active(1);

//    dialog->get_vbox()->pack_start(b_gen);
//    b_gen.append("male");
//    b_gen.append("female");
//    b_gen.set_active(1);
   
    
    //// Bottons to cancel and add Animal.
    dialog->add_button("Cancel",0);
    dialog->add_button("Add",1);
    
    
    dialog->show_all(); 
    dialog->run();
//    
//    
//    
//    
//   bool fail = true;
//    while (fail)
//    {
//       
//       result = dialog->run();
//       if(result ==1) 
//       {
//         sweet = b_sweets.get_active_row_number();
//         quantity = std::stoi(e_quantity.get_text());
//         order.add(quantity,_store->sweet(sweet));
//         msg->set_text("Sweets added in the order");
//         fail = true;
//         
//       }
//       
//       if (result == 0)
//        {
//          if(order.size()==0)
//           {
//             msg->set_text("Order Cancled!!");
//             delete dialog;
//             
//             fail= false;
//           }
//        } 

//        if (result == 2 && order.size()>0)
//        {
//          _store->add(order);
//          msg->set_text("Your Order has been placed");
//          data->set_text("Order has been placed");
//          delete dialog;
//          
//          fail = false;
//        } 
//         
//        
//    }
      
}
