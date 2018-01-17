#include "main.hpp"

int main() {
	std::cout << calculateScore( []( char in ) { return in; } ) << std::endl;   // Assumes next letter is the same
	std::cout << calculateScore( []( char in ) { return '\0'; } ) << std::endl; // Assumes next letter is \0. (Which it never is. Shoudl return the size)
}
