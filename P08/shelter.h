#ifndef __SHELTER_H
#define __SHELTER_H

#include "animal.h"

class Shelter{
  public:
    //void add(Order& order);
    int num_orders();
    const Order& order(int number);

    //void add(Sweet& sweet);
    int num_sweets();
    const Sweet& sweet(int number);
  private:
    std::string _name;
    std::vector<Animal*> _available;
};
#endif
