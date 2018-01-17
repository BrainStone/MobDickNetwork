#include "main.hpp"

int main() {
	std::cout << calculateScore( []( char in ) { return in; } ) << std::endl;   // Assumes next letter is the same
	std::cout << calculateScore( []( char in ) { return '\0'; } ) << std::endl; // Assumes next letter is \0. (Which it never is. Shoudl return the size)

	char W[128 * 128];
	char X[256 * 256];
	char Y[512 * 512];

	saveWeights( "W", 128, W );
	saveWeights( "X", 256, X );
	saveWeights( "Y", 512, Y );
}
