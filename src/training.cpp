#include "training.hpp"

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

void train( const size_t numNodes, char* weights, std::function<char( char )> predicter ) {
	const size_t weightsSize = numNodes * numNodes;
	short weight;
	unsigned int score;
	unsigned int bestScore;
	char bestWeight;

	for ( size_t i = 0; i < weightsSize; ++i ) {
		bestScore = std::numeric_limits<unsigned int>::max();
		bestWeight = std::numeric_limits<char>::min();

		for ( weight = ((short)bestWeight); weight < ((short)std::numeric_limits<char>::max()); ++weight ) {
			weights[i] = ((char)weight);
			score = calculateScore( predicter );

			if ( score < bestScore ) {
				bestScore = score;
				bestWeight = ((char)weight);
			}
		}

		weights[i] = bestWeight;

		std::cout << "Training Step " << i + 1 << " of " << weightsSize << " complete..." << std::endl;
	}
}

// This method generates a file that assigns a string literal to a variable called name
void saveWeights( const std::string& name, const size_t numNodes, const char const* weights ) {
	std::ofstream weightFile( "weights/" + name );

	weightFile << "char* T=R\"delim(";
	weightFile.write( weights, numNodes * numNodes );
	weightFile << ")delim\";";
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
