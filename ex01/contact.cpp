
#include"contact.hpp"

Contact::Contact(std::string name, std::string last_name, std::string nickname, std::string phone_number, std::string dark_secret) {
	_name = name;
	_last_name = last_name;
	_nickname = nickname;
    _phone_number = phone_number;
	_darkest_secret = dark_secret;
}

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
