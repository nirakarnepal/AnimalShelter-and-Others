#ifndef __CAT_H
#define __CAT_H

#include "animal.h"
#include <map>

enum class Cat_breed {
    ABYSSINIAN,
    AMERICAN_SHORTHAIR,
    BENGAL,
    BIRMAN,
    DEVON_REX,
    HIMALAYAN,
    MAINE_COON,
    MIX,
    ORIENTAL_SHORTHAIR, 
    PERSIAN,
    RAGDOLL,
    SIAMESE,
};
constexpr Cat_breed cat_breeds[] = {
    Cat_breed::ABYSSINIAN,
    Cat_breed::AMERICAN_SHORTHAIR,
    Cat_breed::BENGAL,
    Cat_breed::BIRMAN,
    Cat_breed::DEVON_REX,
    Cat_breed::HIMALAYAN,
    Cat_breed::MAINE_COON,
    Cat_breed::MIX,
    Cat_breed::ORIENTAL_SHORTHAIR, 
    Cat_breed::PERSIAN,
    Cat_breed::RAGDOLL,
    Cat_breed::SIAMESE,
};
// Cat implements to_string with a global map, which makes cat_breeds[] above redundant,
// since you can iterate over all cat breeds using this:
//    for (auto& [breed, s] : cats_map)
//  instead of this:
//    for (Cat_breed breed : cat_breeds)
// This eliminates cat_breeds (and 1 of your 3 redundant breeds lists) entirely.
extern const std::map<Cat_breed, std::string> cats_map;
std::string to_string(const Cat_breed& breed);
std::ostream& operator<<(std::ostream& ost, const Cat_breed& breed);

class Cat : public Animal {
  public:
    Cat(Cat_breed breed, std::string name, Gender gender, int age);
    Cat(std::istream& ist);
    void save(std::ostream& ost) override;
    virtual ~Cat();
    virtual std::string family() const override;
    virtual std::string breed() const override;
  private:
    Cat_breed _breed;
};

#endif
