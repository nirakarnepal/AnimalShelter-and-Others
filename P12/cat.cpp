#include "cat.h"

// Constructor / Destructor - note how delegation to base class works!
Cat::Cat(Cat_breed breed, std::string name, Gender gender, int age)
    : Animal(name, gender, age), _breed{breed} { }
Cat::~Cat() { }

// File I/O
Cat::Cat(std::istream& ist) : Animal(ist) {
    std::string s;
    getline(ist, s);
    for(auto& [_breed, breed_name] : cats_map)
        if(s == breed_name) break;
}
void Cat::save(std::ostream& ost) {
    ost << "Cat\n";
    Animal::save(ost);
    ost << breed() << '\n';
}
// Overrides for pure virtual methods
std::string Cat::family() const {return "cat";}
std::string Cat::breed() const {return ::to_string(_breed);}

// Convert breed to string and stream - use a std::map for other derived classes!
const std::map<Cat_breed, std::string> cats_map = {
    {Cat_breed::MIX                , "Mix"               },
    {Cat_breed::SIAMESE            , "Siamese"           }, 
    {Cat_breed::PERSIAN            , "Persian"           }, 
    {Cat_breed::MAINE_COON         , "Maine Coon"        }, 
    {Cat_breed::RAGDOLL            , "Ragdoll"           }, 
    {Cat_breed::BENGAL             , "Bengal"            }, 
    {Cat_breed::ABYSSINIAN         , "Abyssinian"        }, 
    {Cat_breed::BIRMAN             , "Birman"            }, 
    {Cat_breed::ORIENTAL_SHORTHAIR , "Oriental Shorthair"}, 
    {Cat_breed::DEVON_REX          , "Devon Rex"         }, 
    {Cat_breed::AMERICAN_SHORTHAIR , "American Shorthair"}, 
    {Cat_breed::HIMALAYAN          , "Himalayan"         }, 
};
std::string to_string(const Cat_breed& breed) {
    try {
        return cats_map.at(breed);
    } catch (std::exception& e) {
        return "Unknown";
    }
}

// Streaming I/O
std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed) {
    ost << ::to_string(breed);
    return ost;
}
