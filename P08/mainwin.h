#ifndef MAINWIN_H
#define MAINWIN_H

#include<gtkmm.h>
#include "shelter.h"

class Mainwin: public Gtk::Window {
    public:
        Mainwin()
	Mainwin(Shelter&shelter);
	virtual ~Mainwin();

    private:
	Shelter*_shelter;
        Gtk::Label* data;
        Gtk::Label* msg;

    protected:
	void on_quit_click();
	void on _new_animal_clickl();
	void on_list_animal_click();
};
#endif
