
#include"phonebook.hpp"

int	main(int argc, char **argv) {
	(void)argv;
	PhoneBook myGuide;
	int	i = 0;
	std::string	select;

	if (argc != 1)
		return (std::cout << "ERROR" << std::endl, 1);

	do {
		std::cout << "Select and action: ADD, SEARCH, EXIT" << std::endl;
		std::cin >> select;
		if (select == "ADD") {
			myGuide.createContact();
			std::cout << "Press enter\n";
		}
		else if (select == "SEARCH") {
			myGuide.searchContact();
			std::cout << "Press enter\n";
		}
		else if (select == "EXIT") {
			exit(0);
		}
		else {
			std::cout << "Invalid command" << std::endl;
		}
	}
	while (std::getline(std::cin, select));
}
