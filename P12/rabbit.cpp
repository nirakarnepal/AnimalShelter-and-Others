#include "rabbit.h"
#include <map>

// Constructor / Destructor - note how delegation to base class works!
Rabbit::Rabbit(Rabbit_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Rabbit::~Rabbit() { }

// File I/O
Rabbit::Rabbit(std::istream& ist) : Animal(ist) {
    std::string s;
    getline(ist, s);
    for(Rabbit_breed breed : rabbit_breeds) 
        if(s == ::to_string(breed)) {_breed = breed; break;}
}
void Rabbit::save(std::ostream& ost) {
    ost << "Rabbit\n";
    Animal::save(ost);
    ost << breed() << '\n';
}

// Overrides for pure virtual methods
std::string Rabbit::family() const {return "rabbit";}
std::string Rabbit::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!
std::string to_string(const Rabbit_breed& breed) {
    std::map<Rabbit_breed,std::string> rabbits_map {
        { Rabbit_breed::CALIFORNIA_WHITE,  "California White"}, 
        { Rabbit_breed::VIENNA_WHITE,  "Vienna White"},
        { Rabbit_breed::CHINCHILLA,  "Chinchilla"}, 
        { Rabbit_breed::GIANT_CHINCHILLA,  "Giant Chinchilla"}, 
        { Rabbit_breed::FLEMISH_CHINCHILLA,  "Flemish Chinchilla"}, 
        { Rabbit_breed::REX,  "Rex"}, 
        { Rabbit_breed::LIONHEAD,  "Lionhead"}, 
        { Rabbit_breed::SILVER_FOX,  "Silver Fox"}, 
        { Rabbit_breed::NEW_ZEALAND,  "New Zealand"}, 
        { Rabbit_breed::LOP,  "Lop"}, 
        { Rabbit_breed::POLISH,  "Polish"}, 
        { Rabbit_breed::HARLEQUIN,  "Harlequin"},
    };
    try {
        return rabbits_map.at(breed);
    } catch (std::exception& e) {
        return "Unknown";
    }
}

// Streaming I/O
std::ostream& operator<<(std::ostream& ost, const Rabbit_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
