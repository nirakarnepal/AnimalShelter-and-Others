#ifndef __CLIENT_H
#define __CLIENT_H

#include <ostream>
#include <vector>
#include "animal.h"
#include <string>

class Client {
  public:
    Client(std::string name, std::string phone, std::string email);
    //virtual ~Client();

    //virtual std::string to_string() const;
    const Animal& animal(int index);
    int num_adopted();
    void adopt(Animal& animal);
    
    friend std::ostream& operator<<(std::ostream& ost, const Client& client);

    void save(std::ostream& ost);
    void load(std::istream& ist);
  private:
    
    std::string _name;
    std::string _phone;
    std::string _email;
    std::vector<Animal*> _adopted;
};

#endif
