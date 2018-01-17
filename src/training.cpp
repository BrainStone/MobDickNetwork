#include "training.hpp"

int main() {
	std::cout << calculateScore( []( char in ) { return in; } ) << std::endl;   // Assumes next letter is the same
	std::cout << calculateScore( []( char in ) { return '\0'; } ) << std::endl; // Assumes next letter is \0. (Which it never is. Shoudl return the size)
}

unsigned int calculateScore( std::function<char( char )> predicter ) {
	static const std::string mobyDick = getMobyDick();
	static const size_t size = mobyDick.size();

	unsigned int score = 0;

	for ( size_t i = 0; i < (size - 1); ++i ) {
		if ( predicter( mobyDick[i] ) != mobyDick[i + 1] ) {
			++score;
		}
	}

	return score;
}

std::string getMobyDick() {
	// Open the Moby Dick file. 
	std::ifstream fileMobyDick( "resources/whale2.txt" );

	// Read the entire file
	std::string strMobyDick( (std::istreambuf_iterator<char>( fileMobyDick )), std::istreambuf_iterator<char>() );

	// Make sure there are no line breaks in the string
	std::remove_if( strMobyDick.begin(), strMobyDick.end(), []( char in ) { return in == '\r'; } );

	return strMobyDick;
}
