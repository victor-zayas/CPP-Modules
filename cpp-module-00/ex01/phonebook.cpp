
#include"phonebook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::PhoneBook(const PhoneBook &copy) {
    for (int i = 0; i < 8; i++) {
        contacts[i] = copy.contacts[i];
    }
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other){
    if (this != &other){
        for (int i = 0; i < 8; i++) {
            contacts[i] = other.contacts[i];
        }
    }
    return *this;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::createContact(int &i) {

	if (i == 8)
		i = 0;
	if (i < 8) {
		std::string name, lastName, nickName, phoneNumber, darkSecret;
		std::cout << "Please enter the following information" << "\n";
		std::cout << "Name: ";
		std::getline(std::cin, name);
		PhoneBook::contacts[i].setName(name);
		std::cout << "Last name: ";
        std::getline(std::cin, lastName);
		PhoneBook::contacts[i].setLastName(lastName);
		std::cout << "Nickname: " ;
        std::getline(std::cin, nickName);
		PhoneBook::contacts[i].setNickname(nickName);
		std::cout << "Phone number: ";
        std::getline(std::cin, phoneNumber);
		int c = 0;
        // add rule to prevent open empty contact
		while (phoneNumber.length() < 9) {
			if (!isnumber(phoneNumber[c])) {
                std::cout << "Error: invalid phone number, try again:";
                std::cin >> phoneNumber;
                c = 0;
            }
            c++;
		}
		PhoneBook::contacts[i].setPhoneNumber(phoneNumber);
		std::cout << "A dark secret: ";
		std::getline(std::cin, darkSecret);
		PhoneBook::contacts[i].setDarkSecret(darkSecret);
		std::cout << "Contact created" << std::endl;
		i++;
	}
}

void	PhoneBook::searchContact(void) {

	if (contacts[0].getName().length() == 0) {
		std::cout << "Phonebook is empty" << std::endl;
		return ;
	}

	std::cout << "|   INDEX  |" << "FIRSTNAME |" << " LASTNAME |" << " NICKNAME |" << std::endl;
	for (int index = 0; index < 8; index++) {
		std::cout << "|" << std::setw(10) << index;
		if (contacts[index].getName().length() < 10)
			std::cout << "|" << std::setw(10) << contacts[index].getName();
		else
			std::cout << "|" << std::setw(10) << contacts[index].getName().substr(0, 9) + ".";
		if (contacts[index].getLastName().length() < 10)
			std::cout << "|" << std::setw(10) << contacts[index].getLastName();
		else
			std::cout << "|" << std::setw(10) << contacts[index].getLastName().substr(0, 9) + ".";
		if (contacts[index].getNickName().length() < 10)
			std::cout << "|" << std::setw(10) << contacts[index].getNickName() << "|" << std::endl;
		else
			std::cout << "|" << std::setw(10) << contacts[index].getNickName().substr(0, 9) + "." << "|" << std::endl;
	}

	std::string select;
    int nb;
    std::cout << "Enter the index of the contact" << std::endl;
    std::cin >> select;
    nb = select[0] - '0';
    if (nb < 0 || nb > 7)
        std::cout << "Not valid index" << std::endl;
    else {
        if (contacts[nb].getName().length() == 0) {
            std::cout << "Empty contact" << std::endl;
            return;
        }
        std::cout << "> FIRST NAME : " << contacts[nb].getName() << std::endl;
        std::cout << "> LAST NAME : " << contacts[nb].getLastName() << std::endl;
        std::cout << "> NICKNAME : " << contacts[nb].getNickName() << std::endl;
        std::cout << "> PHONE NUMBER : " << contacts[nb].getPhoneNumber() << std::endl;
        std::cout << "> DARK SECRET : " << contacts[nb].getDarkSecret() << std::endl;
    }
}
