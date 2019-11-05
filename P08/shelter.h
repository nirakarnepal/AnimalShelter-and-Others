#ifndef __SHELTER_H
#define __SHELTER_H

//#include "animal.h"
#include <string>
#include <vector>

class Shelter{
  public:

    Shelter(std::string _name);
    std::string name();
    void add_animal(Animal& animal);
    int num_animals();
    Animal &animal(int index);

  private:
    std::string _name;
  //  std::vector<Animal*> _available;
};
#endif
