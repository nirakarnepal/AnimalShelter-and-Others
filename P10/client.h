#ifndef __CLIENT_H
#define __CLIENT_H

#include <ostream>



class Client {
  public:
    Client(std::string name, std::string phone, std::string email);
    //virtual ~Client();

    virtual std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& ost, const Client& client);
  private:
    std::string _name;
    std::string _phone;
    std::string _email;
};

#endif
