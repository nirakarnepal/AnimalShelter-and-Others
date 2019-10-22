#include "mainwin.h"
#include "entrydialog.h"
#include <sstream>

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : 
    _store{&store},
    entry{Gtk::manage(new Gtk::Entry{})},
    comboboxtext{Gtk::manage(new Gtk::ComboBoxText{true})},
    label{Gtk::manage(new Gtk::Label{"This Label Views Added Sweets"})} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    // Set up a vertical box to hold the main window elements
    set_default_size(600, 800);
    set_title("Ultra Sweet Shop");
  
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);


    // ///////////
    // M E N U ///
    /////////////
    // Add and configure a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK,0);

//////////////////// F I L E   M E N U //////////////////////////////////////////

    /// Creating a file menu and adding Quit and New store.
     Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

   // N E W   S T O R E
 /// now we add new store option under file menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New Store", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_store_click();});
    filemenu->append(*menuitem_new);

    // Q U I T
    /// since file menu is done now we add Quit under files
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

//////////////////// S W E E T S   M E N U  ///////////////////////////////////

    /// here we create add sweets and list sweets menu under sweets menu
    Gtk::MenuItem *menuitem_sweets = Gtk::manage(new Gtk::MenuItem("_Sweets", true));
    menubar->append(*menuitem_sweets);
    Gtk::Menu *sweetsmenu = Gtk::manage(new Gtk::Menu());
    menuitem_sweets->set_submenu(*sweetsmenu);
    // A D D   S W E E T S
    /// adding add under sweets menu
    Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("Add", true));
    menuitem_add->signal_activate().connect([this] {this->on_add_sweet_click();});
    sweetsmenu->append(*menuitem_add);
    /// L I S T   S W E E T S 
    /// adding list under sweet menu
    Gtk::MenuItem *menuitem_list= Gtk::manage(new Gtk::MenuItem("List", true));
    menuitem_list->signal_activate().connect([this] {this->on_list_sweets_click();});
    sweetsmenu->append(*menuitem_list);

/////////////////////////////// O R D E R   M E N U //////////////////////////////////

     // adding Order menu
     Gtk::MenuItem *menuitem_orders = Gtk::manage(new Gtk::MenuItem("_Orders", true));
    menubar->append(*menuitem_orders);
    Gtk::Menu *ordersmenu = Gtk::manage(new Gtk::Menu());
    menuitem_orders->set_submenu(*ordersmenu);
    
    /// P L A C E    O R D E R
    /// adding Place under Orderss menu
    Gtk::MenuItem *menuitem_place = Gtk::manage(new Gtk::MenuItem("Place", true));
    //menuitem_place->signal_activate().connect([this] {this->on_place_order_click();});
    ordersmenu->append(*menuitem_place);
     
     /// L I S T   O R D E R S
     /// adding list under sweet menu
     Gtk::MenuItem *menuitem_olist= Gtk::manage(new Gtk::MenuItem("List", true));
    //menuitem_olist->signal_activate().connect([this] {this->on_list_order_click();});
    ordersmenu->append(*menuitem_olist);


////////////////////////// H E L P     M E N U////////////////////////////////////
     /// adding help menu in the menu bar
     Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

     /// A B O U T
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
    new_store_button->signal_clicked().connect([this] {this->on_new_store_click();});
    toolbar->append(*new_store_button); 

 

    // for adding sweet
   Gtk::ToolButton *add_sweet_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::ADD));
    //Gtk::Image *addImage = Gtk::manage(new Gtk::Image{"add_chocolate.png"});
    //add_sweet_button = Gtk::manage(new Gtk::Image{*addImage});
    add_sweet_button->set_tooltip_markup("Add sweets,Name of sweet and Price to sell reqiuired.");
    add_sweet_button->signal_clicked().connect([this] {this->on_add_sweet_click();});
    toolbar->append(*add_sweet_button);

    // for listing sweets added
    Gtk::ToolButton *list_sweets_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::APPLY));
    //Gtk::Image *sweetImage = Gtk::manage(new Gtk::Image{"add_chocolate.png"});
    //list_sweets_button = Gtk::manage(new Gtk::Image{*sweetImage});
    list_sweets_button->set_tooltip_markup("List the Added sweets");
    list_sweets_button->signal_clicked().connect([this] {this->on_list_sweets_click();});
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
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);
    


     
    // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    
    vbox->add(*msg);

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


void Mainwin::on_new_store_click()
{
   _store = new Store;
   data->set_text("ADD SWEETS");
   msg->set_text("New store created");
   
}



void Mainwin::on_add_sweet_click()
{
    std::string name ="";
    double price = -1;
    
    EntryDialog dialog{*this, "Name of new sweet?"};
    dialog.run();
    name = dialog.get_text();
    if(name.size()==0)
    {
      msg->set_text("New Sweet Not Added");
      return;
    }
    EntryDialog edialog{*this, "Price of sweet?"};
    edialog.run();
    price = std::stod(edialog.get_text());
    msg->set_text("Sweet Added");
   
    
    

    Sweet sweet{name,price};
    _store->add(sweet);
    //on_list_sweets_click();
    data->set_text("Sweet Added, click list sweet to view.");
    msg->set_text(sweet.name() + " has been added");

   
}


void Mainwin::on_list_sweets_click()
{
    if(_store->num_sweets()==0)
    {
      data->set_text("No Sweet Added, Please add sweet.");
      return;

    }
    std:: string s = "";
    for(int i = 0; i<_store->num_sweets(); ++i)
    {
      s = s + _store->sweet(i).name() + "$ " + std::to_string(_store->sweet(i).price()) + "\n" ;
      data->set_text( s);

    }
}

/*
void Mainwin::on_place_order_click()
{
    Gtk::Dialog *dialog = new Gtk::Dialog("Place your Order", *this);
    double quantity;
    Order order;
    int sweet = 0;

    
  ///framework
   
    Gtk::HBox b_quantity; 
    Gtk::Label l_name ("Quantity:");
    l_name.set_width_chars(15);
    b_quantity.pack_start(l_name, Gtk::PACK_SHRINK);

/// ready to enter value.

    Gtk::Entry e_quantity;
    e_quantity.set_max_length(50);
    b_quantity.pack_start(e_quantity, Gtk::PACK_SHRINK);
    dialog->get_vbox()->pack_start(b_quantity, Gtk::PACK_SHRINK);

/// loading options

    Gtk::ComboBoxText b_sweets;
    for(int i = 0; i<)   

//// Bottons to cancel and place orders.
    dialog->add_button("Cancel",0);
    dialog->add_button("Add",1)
    dialog->add_button("Order",2);
    
    dialog->show_all(); 
    
    int result;
    bool fail = true;
   
    while (fail)
    {
       fail = false;
       result = dialog->run();
       if(result !=1)
       {
         msg->set_text("Order Cancelled");
         delete dialog;
         return;
       }
         quantity = std::stod(e_quantity.get_text());
        

    }
      if (quantity > 0 )
      {  
        
         order->add(quantity, _store->sweet(sweet));
      }
      _store->add(order);
}
/*
void Mainwin::on_list_order_click()
{
    int order;
    if(_store->num_orders()==0)
    {
      data->set_text("No order placed, Please place order.");
      return;

    }
    std:: string s = "";
    for(int i = 0; i<_store->num_orders(); i++)
    {
      s = s + _store->order(i).quanitiy() + " " + _store->order(i).sweet() + "\n";

    }
 

}

*/
void Mainwin::on_about_click()
{
             Glib::ustring s = R"(
<span size='24000' weight='bold'>Ultra Sweet Shop</span>
<span size='large'>Copyright 2019, Nirakar Nepal</span>
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



