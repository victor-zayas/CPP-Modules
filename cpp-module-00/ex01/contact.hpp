
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class   Contact {
private:
    std::string _name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

public:
    Contact();
    Contact(const Contact &copy);
    Contact &operator=(const Contact &other);
    ~Contact();

    void setName(std::string name);
    void setLastName(std::string last_name);
    void setNickname(std::string nickname);
    void setPhoneNumber(std::string phone_number);
    void setDarkSecret(std::string dark_secret);
    std::string getName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhoneNumber();
    std::string getDarkSecret();
};

#endif
