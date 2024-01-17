
#include"Contact.hpp"

Contact::Contact(): _name(""), _last_name(""), _nickname(""), _phone_number(""), _darkest_secret("") {}

Contact::Contact(const Contact &copy) {
    _name = copy._name;
    _last_name = copy._last_name;
    _nickname = copy._nickname;
    _phone_number = copy._phone_number;
    _darkest_secret = copy._darkest_secret;
}

Contact &Contact::operator=(const Contact &other) {
    if (this != &other) {
        _name = other._name;
        _last_name = other._last_name;
        _nickname = other._nickname;
        _phone_number = other._phone_number;
        _darkest_secret = other._darkest_secret;
    }
    return *this;
}

Contact::~Contact() {}

void Contact::setName(std::string name) {
	_name = name;
}

void Contact::setLastName(std::string last_name) {
	_last_name = last_name;
}

void Contact::setNickname(std::string nickname) {
	_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phone_number) {
	_phone_number = phone_number;
}

void Contact::setDarkSecret(std::string dark_secret) {
	_darkest_secret = dark_secret;
}

std::string Contact::getName() {
	return _name;
}

std::string Contact::getLastName() {
	return _last_name;
}

std::string Contact::getNickName() {
	return _nickname;
}

std::string Contact::getPhoneNumber() {
	return _phone_number;
}

std::string Contact::getDarkSecret() {
	return _darkest_secret;
}
