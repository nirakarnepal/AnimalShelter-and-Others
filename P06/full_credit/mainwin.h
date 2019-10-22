  #ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
#include "store.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        Mainwin(Store& store);
        virtual ~Mainwin();
         
         

    private:
        Store *_store;
        Gtk::MenuItem* menuitem_add_sweets;
        Gtk::MenuItem* menuitem_list_sweets;
        Gtk::MenuItem* menuitem_place_order;
        Gtk::MenuItem* menuitem_list_orders;

        Gtk::ToolButton* add_sweet_button;
        Gtk::ToolButton* list_sweets_button;
        Gtk::ToolButton* place_order_button;
        Gtk::ToolButton* list_orders_button;

        Gtk::Label* data;
        Gtk::Label* msg;
        void reset_sensitivity();

        Gtk::Entry* entry;
        Gtk::ComboBoxText* comboboxtext;
        Gtk::Label* label;

    protected:
        void on_new_store_click();
        void on_add_sweet_click();
        void on_list_sweets_click();
        void on_place_order_click();
        void on_list_order_click();
        void on_about_click();
        void on_quit_click();
        void on_entry_activate();
        void on_comboboxtext_activate();
        
    // Lots more Mainwin members are needed!
    // (You ARE permitted to change the above as well if you like.)
};
#endif

