#ifndef __CLIENT_H
#define __CLIENT_H

#include <ostream>
#include <vector>
#include "animal.h"

class Client {
  public:
    Client(std::string name, std::string phone, std::string email);
    //virtual ~Client();

    virtual std::string to_string() const;
    const Animal& animal(int index);
    int num_adopted();
    void adopt(Animal& adopt);
    std::string _name;
    friend std::ostream& operator<<(std::ostream& ost, const Client& client);
  private:
    
    std::string _phone;
    std::string _email;
    std::vector<Animal*> _adopted;
};

#endif
