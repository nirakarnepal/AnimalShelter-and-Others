#ifndef __SHELTER_H
#define __SHELTER_H

#include "animal.h"
#include "client.h"
#include <vector>

class Shelter {
  public:
    Shelter(std::string name);
    ~Shelter();
    std::string name();
    Shelter(std::istream& ist);
    void save(std::ostream& ost);

    void add_animal(Animal& animal);
    int num_animals();
    Animal& animal(int index); 

    void add_client(Client& client);
    int num_clients();
    Client& client(int index);

    void adopt(Client& client, Animal& animal);
  private:
    std::string _name;
    std::vector<Animal*> _available;
    std::vector<Client>  _clients;
};

#endif

