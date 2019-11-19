#include "client.h"
#include <iostream>

// Constructors / Destructors
Client::Client(std::string name, std::string phone, std::string email)
    : _name{name}, _phone{phone}, _email{email} { }

//Client::~Client() { }


// Convert clientand its derived classes to a string and stream representation
std::string Client::to_string() const {
    return "Client Name: " + _name + " has been added.";
}
std::ostream& operator<<(std::ostream& ost, const Client& client) {
    ost << client._name    << " ("
        << client._phone << ", "
        << client._email << ')';
    return ost;
}
void Client::adopt(Animal& animal) {
    _adopted.push_back(&animal);
}

int Client::num_adopted() {return _adopted.size();}
//Animal& Client::animal(int index) {return _adopted[index];}




