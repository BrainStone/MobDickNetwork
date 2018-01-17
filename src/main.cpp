#include "main.hpp"

int main() {
	std::cout << "Training:\t" << s << std::endl;
	std::cout << "Count:\t\t" << calculateScore( []( char in ) { return '\0'; } ) << std::endl;

	std::cout << "t = 0:\t\t" << calculateScore( S ) << std::endl;

	for ( size_t i = 0; i < 10; ++i ) {
		train( s, W, S );
		saveWeights( "16", s, W );
		std::cout << "t = " << i << ":\t\t" << calculateScore( S ) << std::endl;
	}
}
