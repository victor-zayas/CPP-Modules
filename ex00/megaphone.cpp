
#include<iostream>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            for (size_t j = 0; j < std::strlen(argv[i]); j++)
                std::cout << (char)std::toupper(argv[i][j]);
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}
