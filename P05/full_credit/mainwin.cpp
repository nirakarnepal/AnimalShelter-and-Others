#include "mainwin.h"

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    // Set up a vertical box to hold the main window elements
    set_default_size(600, 800);
    set_title("Sweet");
  
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
    add(*vbox);


    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK,0);
 

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->add(*toolbar);

    //now we add buttons for add sweet, list sweet, place order, list orders 

    //for New store
    Gtk::ToolButton *new_store_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_store_button->set_tooltip_markup("This will clear everything in the store");
    new_store_button->signal_clicked().connect([this]{this->on_new_store_click();});
    toolbar->append(*new_store_button); 

    // for adding sweet
    Gtk::ToolButton *add_sweet_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    //Gtk::Image *addImage = Gtk::manage(new Gtk::Image{"add_chocolate.png"});
    //add_sweet_button = Gtk::manage(new Gtk::Image{*addImage});
    add_sweet_button->set_tooltip_markup("Add sweets,Name of sweet and Price to sell reqiuired.");
    add_sweet_button->signal_clicked().connect([this]{this->on_add_sweet_click();});
    toolbar->append(*add_sweet_button);

    // for listing sweets added
    Gtk::ToolButton *list_sweets_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    //Gtk::Image *sweetImage = Gtk::manage(new Gtk::Image{"add_chocolate.png"});
    //list_sweets_button = Gtk::manage(new Gtk::Image{*sweetImage});
    list_sweets_button->set_tooltip_markup("List the Added sweets");
    list_sweets_button->signal_clicked().connect([this]{this->on_list_sweets_click();});
    toolbar->append(*list_sweets_button);


    //to place the order
    Gtk::ToolButton *place_order_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    //Gtk::Image *orderImage = Gtk::manage(new Gtk::Image{"order.png"});
    //place_order_button = Gtk::manage(new Gtk::Image{*orderImage});
    place_order_button->set_tooltip_markup("Place your order");
    place_order_button->signal_clicked().connect([this]{this->on_place_order_click();});
    toolbar->append(*place_order_button);
    

    // ///////////////////////
    // D A T A   D I S P L A Y
    // Provide a text entry box to show the sweets and orders



    // ///////////////////////////////////    
    // S T A T U S   B A R   D I S P L A Y
    // Provide a status bar for transient messages


    // Make the vertical box and everything in it visible

}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////



// /////////////////
// U T I L I T I E S
// /////////////////



