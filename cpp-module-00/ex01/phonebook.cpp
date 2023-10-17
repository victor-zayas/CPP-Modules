
#include"phonebook.hpp"

void	PhoneBook::createContact(int &i) {
	// if contact full, replace the first one
	if (i == 8)
		i = 0;
	if (i < 8) {
		std::string name, lastName, nickName, phoneNumber, darkSecret;
		std::cout << "Please enter the following information" << "\n";
		std::cout << "Name: " << "\n";
		std::cin >> name;
		PhoneBook::contacts[i].setName(name);
		std::cout << "Last name: " << "\n";
		std::cin >> lastName;
		PhoneBook::contacts[i].setLastName(lastName);
		std::cout << "Nickname: " << "\n";
		std::cin >> nickName;
		PhoneBook::contacts[i].setNickname(nickName);
		std::cout << "Phone number: " << "\n";
		std::cin >> phoneNumber;
		PhoneBook::contacts[i].setPhoneNumber(phoneNumber);
		std::cout << "A dark secret: " << "\n";
		std::cin >> darkSecret;
		PhoneBook::contacts[i].setDarkSecret(darkSecret);
		std::cout << "Contact created" << "\n";
		i++;
	}
}

void	PhoneBook::searchContact(int &i) {
	if (i > 0) {
		int	index = 0;

		std::cout << "Enter the index of the contact (0 to 7):" << std::endl;
		std::cin >> index;

		if (index >= 0 && index < i) {
			std::cout << "Contact info" << std::endl;
			std::cout << "Name: " << contacts[index].getName() << std::endl;
			std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
			std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
			std::cout << "Phone_number: " << contacts[index].getPhoneNumber() << std::endl;
			std::cout << "Dark secret: " << contacts[index].getDarkSecret() << std::endl;
		}
		else
			std::cout << "Invalid index" << std::endl;
	}
	else
		std::cout << "Phonbook is empty" << std::endl;
}
