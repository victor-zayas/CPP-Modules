
#include"phonebook.hpp"


void	PhoneBook::createContact(int &i) {
	if (i < 8) {
		// Console messagge
		std::cout << "Insert: Name, last name, nickname, phone number, a dark secret" << std::endl;
		// Prompt
		std::string name, lastName, nickName, phoneNumber, darkSecret;
		// Store info
		std::cout << "Name: " << "\n";
		std::cin >> name;
		std::cout << "Last name: " << "\n";
		std::cin >> lastName;
		std::cout << "Nickname: " << "\n";
		std::cin >> nickName;
		std::cout << "Phone number: " << "\n";
		std::cin >> phoneNumber;
		std::cout << "A dark secret: " << "\n";
		std::cin >> darkSecret;

		// ADD CONTACT
		this->contacts[i] = Contact(name, lastName, nickName, phoneNumber, darkSecret);
		i++;
	}
	else {
		// Console messagge
		std::cout << "Insert: Name, last name, nickname, phone number, a dark secret" << std::endl;

		// Prompt received
		std::string name, lastName, nickName, phoneNumber, darkSecret;
		std::cin >> name >> lastName >> nickName >> phoneNumber >> darkSecret;

		// Replace the 9th contact for the first one
		this->contacts[0] = Contact(name, lastName, nickName, phoneNumber, darkSecret);
	}
}

void	PhoneBook::searchContact(int &i) {
	if (i > 0) {
		int	search = 0;

		// Select index contact
		std::cout << "Enter the index of the contact (0 to 7):" << std::endl;
		std::cin >> search;

		if (search >= 0 && search < i) {
			// Show contact index
			std::cout << "Name: " << contacts[search].getName() << std::endl;
			std::cout << "Last name: " << contacts[search].getLastName() << std::endl;
			std::cout << "Nickname: " << contacts[search].getNickName() << std::endl;
			std::cout << "Phone_number: " << contacts[search].getPhoneNumber() << std::endl;
			std::cout << "Dark secret: " << contacts[search].getDarkSecret() << std::endl;
		}
		else
			std::cout << "Invalid contact" << std::endl;
	}
	else
		std::cout << "There is no contacts" << std::endl;
}
