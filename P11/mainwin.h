#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "shelter.h"
#include <fstream>

const std::string APP_TITLE{"Mavs Animal Shelter Software"};
const std::string APP_NAME{"edu.uta.cse1325.mass.v0_1_0"};
const std::string VERSION{"0.1.0"};
const std::string EXT = "ctp";

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_quit_click();              // Exit the application
        void on_new_animal_click();        // Create a new animal
        void on_list_animals_click();      // List all animals
	void on_open_click();              // Open file
	void on_save_click();              // Savefile
        void on_new_client_click();        // Add new client
	void on_list_clients_click();      // List available client
        void on_adopt_animal_click();      // Adopt animal
	void on_list_adopted_click();      // List adopted animal
	void status(std::string s);        // Set the status message
    private:
        Shelter *shelter;                  // Current animal shelter
        Gtk::Label *data;                  // Display of sticks on game board
        Gtk::Label *msg;                   // Status message display
};
#endif 

