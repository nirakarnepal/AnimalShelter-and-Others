#include "shelter.h"
#include <algorithm>

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

void Shelter::adopt(Client& client, Animal& animal) {
    client.adopt(animal);
    auto index = std::find(_available.begin(), _available.end(), &animal);
    if (index != _available.end()) _available.erase(index);
    // OR use the "erase remove" idiom, which removes ALL elements matching animal
    // _available.erase(std::remove(_available.begin(), _available.end(), &animal), _available.end());

}

std::string Shelter::get_filename() {return filename;}
void Shelter::set_filename(std::string filename) {this->filename = filename;}

void Shelter::save(std::ostream& ost) {
    
    for(int i=0; i<num_clients(); ++i)
        ost << client(i) << '\n'; 
    
    for(int i=0; i<num_animals(); ++i)
        ost << animal(i) << '\n';
   
//  for (Graph_lib::Animal* a : animals) {
//      ost << typeid(*s).name() << ' '; // Write the name of the actual type
//      a->save(ost);
//      ost << std::endl;  // one line per shape (this is ignored when loading)
//  }
//  dirty = false;
}

