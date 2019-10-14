#include <gtkmm.h>
#include "mainwin.h"


int main (int argc, char *argv[]) {
  // Your main function code goes here!
  auto app = Gtk::Application::create(argc, argv, "sweet.test");
  Mainwin win;

}


