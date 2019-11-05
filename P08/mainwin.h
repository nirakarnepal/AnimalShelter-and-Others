#ifndef MAINWIN_H
#define MAINWIN_H

#include <gtkmm.h>
//#include "store.h"

class Mainwin: public Gtk::Window {
    public:
        Mainwin();
	virtual ~Mainwin();

    private:
	//Store*_store;
        Gtk::Label* data;
        Gtk::Label* msg;

    protected:
	void on_quit_click();
	void on_new_animal_click();
	void on_list_animal_click();
};
#endif
