/*
Write a Fraction class that has a constructor that takes a numerator and a denominator.
If the user passes in a denominator of 0, throw an exception of type std::runtime_error (included in the stdexcept header).
In your main program, ask the user to enter two integers. If the Fraction is valid, print the fraction. 
If the Fraction is invalid, catch a std::exception, and tell the user that they entered an invalid fraction.

Here’s what one run of the program should output:

Enter the numerator: 5
Enter the denominator: 0
Invalid denominator

*/

#include <iostream>
#include <stdexcept>

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

public:
	Fraction(int num, int denom) : m_numerator{ num }, m_denominator{ denom } 
	{
			if (denom == 0)
				throw std::runtime_error("Invalid denominator");
	}

	double getFraction() { return static_cast<double>(m_numerator) / m_denominator; }
};

int main()
{
	try {
		int num{ 0 }, denom{ 0 };
		std::cout << "Enter the numerator: ";
		std::cin >> num;
		std::cout << "Enter the denominator: ";
		std::cin >> denom;

		std::cout << "The Fraction is equal to: " << Fraction(num, denom).getFraction() << '\n';
	}
	catch (std::runtime_error err) {
		std::cout << err.what() << '\n';
	}

	return 0;
}