#include "main.hpp"

int main() {
	std::cout << w << std::endl << W << std::endl;
	std::cout << "Training:\t" << s << std::endl;
	std::cout << "Count:\t\t" << sizeMobyDick - 1 << std::endl;

	std::cout << "t = 0:\t\t" << calculateScore( s, w, S ) << std::endl;

	for ( size_t i = 0; i < 10; ++i ) {
		train( s, w, W, S );
		saveWeights( std::to_string(s), s, W );
		std::cout << "t = " << i + 1 << ":\t\t" << calculateScore( s, w, S ) << std::endl;
	}
}
