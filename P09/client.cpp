#include "client.h"

// Constructors / Destructors
Client::Client(std::string name, std::string phone, std::string email)
    : _name{name}, _phone{phone}, _email{email} { }

Client::~Client() { }

// Getters
std::string Client::name() const {return _name;}
std::string Client::phone() const {return _phone;}
std::string Client::email() const {return _email;}

// Convert clientand its derived classes to a string and stream representation
std::string Client::to_string() const {
    return "Client Name: " + _name + " has been added.";
}
std::ostream& operator<<(std::ostream& ost, const Client& client) {
    ost << client.to_string();
    return ost;
}



