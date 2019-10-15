#include "mainwin.h"

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    // Set up a vertical box to hold the main window elements
    set_default_size(600, 800);
    set_title("Mav's Ultra Sweet Shop");
  
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);


    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK,0);

    /// Creating a file menu and adding Quit and New store.
     Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    /// since file menu is done now we add Quit under files
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
 
 /// now we add new store option under file menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
   // menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);


    /// here we create add sweets and list sweets menu under sweets menu
    Gtk::MenuItem *menuitem_sweets = Gtk::manage(new Gtk::MenuItem("_Sweets", true));
    menubar->append(*menuitem_sweets);
    Gtk::Menu *sweetsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_sweets->set_submenu(*sweetsmenu);
   /// adding add under sweets menu
    Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("Add", true));
  //  menuitem_add->signal_activate().connect([this] {this->on_add_sweet_click();});
    sweetsmenu->append(*menuitem_add);
     /// adding list under sweet menu
     Gtk::MenuItem *menuitem_list= Gtk::manage(new Gtk::MenuItem("List", true));
   // menuitem_list->signal_activate().connect([this] {this->on_list_sweets_click();});
    sweetsmenu->append(*menuitem_list);

     // adding Order menu
     Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menubar->append(*menuitem_orders);
    Gtk::Menu *ordersmenu = Gtk::manage(new Gtk::Menu());
    menuitem_orders->set_submenu(*ordersmenu);
    /// adding Place under Orderss menu
    Gtk::MenuItem *menuitem_place = Gtk::manage(new Gtk::MenuItem("Place", true));
   // menuitem_place->signal_activate().connect([this] {this->on_place_order_click();});
    ordersmenu->append(*menuitem_place);
     /// adding list under sweet menu
     Gtk::MenuItem *menuitem_olist= Gtk::manage(new Gtk::MenuItem("List", true));
    //menuitem_olist->signal_activate().connect([this] {this->on_list_order_click();});
    ordersmenu->append(*menuitem_olist);

     /// adding help menu in the menu bar
     Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);


     /// adding About menu under help

     Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);


    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //now we add buttons for add sweet, list sweet, place order, list orders 


   //for New store
    Gtk::ToolButton *new_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_store_button->set_tooltip_markup("This will clear everything in the store");
    //new_store_button->signal_clicked().connect([this] {this->on_new_store_click();});
    toolbar->append(*new_store_button); 

 

    // for adding sweet
   Gtk::ToolButton *add_sweet_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    //Gtk::Image *addImage = Gtk::manage(new Gtk::Image{"add_chocolate.png"});
    //add_sweet_button = Gtk::manage(new Gtk::Image{*addImage});
    add_sweet_button->set_tooltip_markup("Add sweets,Name of sweet and Price to sell reqiuired.");
    //add_sweet_button->signal_clicked().connect([this] {this->on_add_sweet_click();});
    toolbar->append(*add_sweet_button);

    // for listing sweets added
    Gtk::ToolButton *list_sweets_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::APPLY));
    //Gtk::Image *sweetImage = Gtk::manage(new Gtk::Image{"add_chocolate.png"});
    //list_sweets_button = Gtk::manage(new Gtk::Image{*sweetImage});
    list_sweets_button->set_tooltip_markup("List the Added sweets");
    //list_sweets_button->signal_clicked().connect([this] {this->on_list_sweets_click();});
    toolbar->append(*list_sweets_button);


    //to place the order
    Gtk::ToolButton *place_order_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::FILE));
    //Gtk::Image *orderImage = Gtk::manage(new Gtk::Image{"order.png"});
    //place_order_button = Gtk::manage(new Gtk::Image{*orderImage});
    place_order_button->set_tooltip_markup("Place your order");
    //place_order_button->signal_clicked().connect([this] {this->on_place_order_click();});
    toolbar->append(*place_order_button);


   ///list orders button
    Gtk::ToolButton *list_orders_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::HARDDISK));
    //Gtk::Image *orderImage = Gtk::manage(new Gtk::Image{"order.png"});
    //place_order_button = Gtk::manage(new Gtk::Image{*orderImage});
    list_orders_button->set_tooltip_markup("List your orders");
    //list_orders_button->signal_clicked().connect([this] {this->on_list_order_click();});
    toolbar->append(*list_orders_button);
    


//////////////for Quit button

    Gtk::ToolButton *quit_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::QUIT));
    quit_button->set_tooltip_markup("This will exit the program");
    quit_button->signal_clicked().connect([this] {this->on_quit_click();});
    toolbar->append(*quit_button);

    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders

    data = Gtk::manage(new Gtk::Label());
    vbox->add(*data);

    msg = Gtk::manage(new Gtk::Label());
    vbox->add(*msg);
     
    // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages


    // Make the vertical box and everything in it visible
    vbox->show_all();

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    hide();
}

/*
void Mainwin::on_new_store_click()
{
   clear();
   
}
*/
/*
string candy;
void Mainwin::on_add_sweet_click();
{
    EntryDialog edialog{*this, "please enter name of candy?"};
    edialog.set_text("Nothing to report...");

    EntryDialog edialog{*this, "please enter the price"};
    edialog.set_text("Nothing to report...");

    edialog.run();

}

void Mainwin::on_list_sweets_click();
{

}


void Mainwin::on_place_order_click();
{


}


void Mainwin::on_list_order_click();
{

}

*/
void Mainwin::on_about_click()
{
             Glib::ustring s = R"(
<span size='24000' weight='bold'>Mav's Ultra Sweet Shop</span>
<span size='large'>Copyright 2019, George F. Rice</span>
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see www.gnu.org/licenses/ .)";

    Gtk::MessageDialog dlg(*this, s, true, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.run();
}
// /////////////////
// U T I L I T I E S
// /////////////////



