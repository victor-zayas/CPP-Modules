
#include"phonebook.hpp"

int	main(void) {
	PhoneBook myGuide;
	int	i = 0;
	std::string	select;

	while (1)
	{
		std::cout << "Select and action: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> select;

		if (select == "ADD") {
			myGuide.createContact(i);
		}
		else if (select == "SEARCH") {
			myGuide.searchContact(i);
		}
		else if (select == "EXIT") {
			exit(0);
		}
		else {
			std::cout << "Invalid command" << std::endl;
		}
	}
}
