#include "client.h"
#include <iostream>
#include <iomanip>

// Constructor / Destructor
Client::Client(std::string name, std::string phone, std::string email)
    : _name{name}, _phone{phone}, _email{email} { }
Client::~Client() {} // for(Animal* a : _adopted) delete a;}

// File I/O
Client::Client(std::istream& ist) {
    std::getline(ist, _name);
    std::getline(ist, _phone);
    std::getline(ist, _email);
    int animals;
    ist >> animals; ist.ignore(65535, '\n');
    while(animals--) _adopted.push_back(Animal::make_animal(ist)); 
}
void Client::save(std::ostream& ost) {
    ost << _name << '\n' << _phone << '\n' << _email << '\n';
    ost << _adopted.size() << '\n';
    for (Animal* a : _adopted) a->save(ost);
}

// Streaming I/O
std::ostream& operator<<(std::ostream& ost, const Client& client) {
    ost << client._name  << " ("
        << client._phone << " ,"
        << client._email << " )";
    return ost;
}

// Iteration
void Client::adopt(Animal& animal) {_adopted.push_back(&animal);}
int Client::num_adopted() {return _adopted.size();}
const Animal& Client::animal(int index) {return *(_adopted[index]);}

