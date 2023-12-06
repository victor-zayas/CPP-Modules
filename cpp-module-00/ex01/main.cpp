
#include"phonebook.hpp"

int	main(int argc, char **argv) {
	(void)argv;
	PhoneBook myGuide;
	std::string	select;
    int i = 0;

	if (argc != 1)
		return (std::cout << "ERROR" << std::endl, 1);
	while (1) {
		std::cout << "Select and action: ADD, SEARCH, EXIT" << std::endl;
        std::getline(std::cin, select);
        if (select == "ADD") {
			myGuide.createContact(i);
		}
		else if (select == "SEARCH") {
            myGuide.searchContact();
		}
		else if (select == "EXIT") {
			exit(0);
		}
	}
}
