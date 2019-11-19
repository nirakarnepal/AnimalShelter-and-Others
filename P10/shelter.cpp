#include "shelter.h"

Shelter::Shelter(std::string name) : _name{name} { }
std::string Shelter::name() {return _name;}

void Shelter::add_animal(Animal& animal) {
    _available.push_back(&animal);
}
int Shelter::num_animals() {return _available.size();}
Animal& Shelter::animal(int index) {return *(_available[index]);}


void Shelter::add_client(Client& client) {_clients.push_back(client);}
int Shelter::num_clients() {return _clients.size();}
Client& Shelter::client(int index) {return _clients[index];}

void Shelter::adopt(Client& client, Animal& animal){_clients.push_back(client);}
