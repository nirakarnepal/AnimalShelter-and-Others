#include "shelter.h"
#include <algorithm>

Shelter::Shelter(std::string name) : _name{name} { }
Shelter::~Shelter() {for(Animal* a : _available) delete a;}
std::string Shelter::name() {return _name;}
Shelter::Shelter(std::istream& ist) {
    std::getline(ist, _name);

    int num;
    ist >> num; ist.ignore(65535, '\n');
    while(num--) _available.push_back(Animal::make_animal(ist));

    ist >> num; ist.ignore(65535, '\n');
    while(num--) _clients.push_back(Client{ist});
}
void Shelter::save(std::ostream& ost) {
    ost << _name << '\n';
    ost << _available.size() << '\n';
    for (Animal* a : _available) a->save(ost);
    ost << _clients.size() << '\n';
    for (Client c : _clients) c.save(ost);
}

void Shelter::add_animal(Animal& animal) {
    _available.push_back(&animal);
}
int Shelter::num_animals() {return _available.size();}
Animal& Shelter::animal(int index) {return *(_available[index]);}

void Shelter::add_client(Client& client) {_clients.push_back(client);}
int Shelter::num_clients() {return _clients.size();}
Client& Shelter::client(int index) {return _clients[index];}

void Shelter::adopt(Client& client, Animal& animal) {
    client.adopt(animal);
    _available.erase(std::remove(_available.begin(), _available.end(), &animal), _available.end());
}
