#include "Array.hpp"

int	main()
{
	try 
	{
		Array<int> A(6);
		std::cout << "A: " << A << "\n";
		std::cout << "Change index 2 value in A\n";
		A[2] = 42;
		std::cout << "A: " << A << "\n";
		std::cout << "Copy array A to array B\n";
		Array<int> B(A);
		std::cout << "B: " << B << "\n";
		std::cout << "change index 0 value in B\n";
		B[0] = -42;
		std::cout << "A: " << A << "\n";
		std::cout << "B: " << B << "\n";
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
