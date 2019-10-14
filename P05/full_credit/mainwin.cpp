#include "mainwin.h"

Mainwin::Mainwin() : Mainwin{*(new Store)} { }
Mainwin::Mainwin(Store& store) : _store{&store} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    // Set up a vertical box to hold the main window elements


    // ///////
    // M E N U
    // Add and configure a menu bar as the top item in the vertical box
 

    // /////////////
    // T O O L B A R
    // Add a toolbar to the vertical box just below the menu (bonus level)



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



