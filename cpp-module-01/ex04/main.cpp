#include <iostream>
#include <fstream>
#include <string>

void replace(const std::string file, const std::string s1, const std::string s2) {
	std::ifstream input(file);

	if (!input.is_open()) {
		std::cerr << "Error: couldn't open file: " << file << std::endl;
		return ;
	}
    if (input.peek() == std::ifstream::traits_type::eof()) {
        std::cout << "Error: File is empty" << std::endl;
        return ;
    }
    std::string searchLine;
    while (std::getline(input, searchLine)) {
        if (searchLine.find(s1) != std::string::npos) {
            break ;
        }
        else {
            std::cout << "Error: searched string doesn't exist" << std::endl;
            return ;
        }
    }
    input.close();
    input.open(file);
	std::ofstream output(file + ".replace");
	if (!output.is_open()) {
		std::cerr << "Error: couldn't create file: " << file << std::endl;
		return ;
	}
    std::string line;
    while (std::getline(input, line)) {
        std::string::size_type pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            output << line.substr(0, pos) << s2;
            line = line.substr(pos + s1.length());
            pos = line.find(s1);
        }
        output << line << std::endl;
    }
	input.close();
	output.close();
	std::cout << "Replacement completed " << file + ".replace" << std::endl;
}

int	main(int argc, char **argv) {

    if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <file> <text> <text to replace>" << std::endl;
        exit (EXIT_FAILURE);
	}
    std::string file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    replace(file, s1, s2);
}
