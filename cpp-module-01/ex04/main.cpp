#include <iostream>
#include <fstream>
#include <string>

void replaceLine(const std::string file, const std::string s1, const std::string s2) {
	std::ifstream input(file);

	if (!input.is_open()) {
		std::cerr << "Error: couldn't open file: " << file << std::endl;
		return ;
	}
	std::ofstream output(file + ".replace");
	if (!output.is_open()) {
		std::cerr << "Error: couldn't create file: " << file << std::endl;
		return ;
	}
	std::string line;
	while(std::getline(input, line)) {
		size_t poss = 0;
		while ((poss = line.find(s1, poss)) != std::string::npos) {
			line.replace(poss, s1.length(), s2);
			poss += s2.length();
		}
		output << line << std::endl;
	}
	input.close();
	output.close();
	std::cout << "Replacement completed " << file + ".replace" << std::endl;
}

int	main(int argc, char **argv) {
	std::string file = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <file> <text> <text to replace>" << std::endl;
	}
	else
		replaceLine(file, s1, s2);
}
