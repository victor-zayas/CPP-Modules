
#include"phonebook.hpp"

void	PhoneBook::createContact(void) {

	int i = 0;

	if (i == 8)
		i = 0;
	if (i < 8) {
		std::string name, lastName, nickName, phoneNumber, darkSecret;
		std::cout << "Please enter the following information" << "\n";
		std::cout << "Name: ";
		std::cin >> name;
		PhoneBook::contacts[i].setName(name);
		std::cout << "Last name: ";
		std::cin >> lastName;
		PhoneBook::contacts[i].setLastName(lastName);
		std::cout << "Nickname: " ;
		std::cin >> nickName;
		PhoneBook::contacts[i].setNickname(nickName);
		std::cout << "Phone number: ";
		std::cin >> phoneNumber;
		PhoneBook::contacts[i].setPhoneNumber(phoneNumber);
		std::cout << "A dark secret: ";
		std::cin.ignore();
		std::getline(std::cin, darkSecret);
		PhoneBook::contacts[i].setDarkSecret(darkSecret);
		std::cout << "Contact created" << std::endl;
		i++;
	}
}

void	PhoneBook::searchContact(void) {

	if (contacts[0].getName().length() == 0) {
		std::cout << "Phonbook is empty" << std::endl;
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
	do {
		std::cout << "Enter the index of the contact" << std::endl;
		std::cin >> select;
		if (select.length() > 1 || !isnumber(select[0]))
			std::cout << "Not valid index" << std::endl;
		else {
			int id = stoi(select);
			std::cout << "> FIRST NAME : " << contacts[id].getName() << std::endl;
			std::cout << "> LAST NAME : " << contacts[id].getLastName() << std::endl;
			std::cout << "> NICKNAME : " << contacts[id].getNickName() << std::endl;
			std::cout << "> PHONE NUMBER : " << contacts[id].getPhoneNumber() << std::endl;
			std::cout << "> DARK SECRET : " << contacts[id].getDarkSecret() << std::endl;
		}
	}
	while (select.length() > 1 || !isnumber(select[0]));
}
