
#include"phonebook.hpp"

int	main(void) {
	PhoneBook myCalendar;
	int	i = 0;
	int	search = 0;
	std::string	select;

	while (1)
	{
		std::cout << "Select and action: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> select;

		if (select == "ADD") {
			if (i < 8) {
				//Console messagge
				std::cout << "Insert: Name, last name, nickname, phone number, a dark secret" << std::endl;

				// Prompt received
				std::string name, lastName, nickName, phoneNumber, darkSecret;
				std::cin >> name >> lastName >> nickName >> phoneNumber >> darkSecret;

				// ADD CONTACT
				myCalendar.contacts[i] = Contact(name, lastName, nickName, phoneNumber, darkSecret);
				i++;
			}
			else {
				// Console messagge
				std::cout << "Insert: Name, last name, nickname, phone number, a dark secret" << std::endl;

				// Prompt received
				std::string name, lastName, nickName, phoneNumber, darkSecret;
				std::cin >> name >> lastName >> nickName >> phoneNumber >> darkSecret;

				// Replace the 9th contact for the first one
				myCalendar.contacts[0] = Contact(name, lastName, nickName, phoneNumber, darkSecret);
			}
		}
		else if (select == "SEARCH") {
			if (i > 0) {
				// Select index contact
				std::cout << "Enter the index of the contact (0 to 7):" << std::endl;
				std::cin >> search;

				if (search >= 0 && search < i) {
					// Show contact index
					std::cout << "Name: " << myCalendar.contacts[search].getName() << std::endl;
					std::cout << "Last name: " << myCalendar.contacts[search].getLastName() << std::endl;
					std::cout << "Nickname: " << myCalendar.contacts[search].getNickName() << std::endl;
					std::cout << "Phone_number: " << myCalendar.contacts[search].getPhoneNumber() << std::endl;
					std::cout << "Dark secret: " << myCalendar.contacts[search].getDarkSecret() << std::endl;
				}
				else
					std::cout << "Invalid contact" << std::endl;
			}
			else
				std::cout << "There is no contacts" << std::endl;
		}
		else if (select == "EXIT") {
			exit(0);
		}
		else
			std::cout << "Invalid command" << std::endl;
	}
}
