
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class   Contact{
private:
    std::string _name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

public:
    Contact() : _name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {}

    Contact(const Contact &copy) {
        _name = copy._name;
        _last_name = copy._last_name;
        _nickname = copy._nickname;
        _phone_number = copy._phone_number;
        _darkest_secret = copy._darkest_secret;
    }

    Contact &operator=(const Contact &other) {
        if (this != &other) {
        _name = other._name;
        _last_name = other._last_name;
        _nickname = other._nickname;
        _phone_number = other._phone_number;
        _darkest_secret = other._darkest_secret;
        }
        return *this;
    }

    ~Contact(){}

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