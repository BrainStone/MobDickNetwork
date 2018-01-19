#include "training.hpp"

const std::string mobyDick = getMobyDick();
const size_t sizeMobyDick = mobyDick.size();

unsigned int calculateScore( const size_t numNodes, uint8_t*& nodes, std::function<uint8_t( uint8_t )> predicter ) {
	std::fill_n( nodes, numNodes, 0 );
	
	unsigned int score = 0;

	for ( size_t i = 0; i < (sizeMobyDick - 1); ) {
		if ( predicter( mobyDick[i] ) != mobyDick[++i] ) {
			++score;
		}
	}

	return score;
}

void train( const size_t numNodes, uint8_t*& nodes, uint8_t* weights, std::function<uint8_t( uint8_t )> predicter ) {
	const size_t weightsSize = numNodes * numNodes;
	short weight;
	unsigned int score;
	unsigned int bestScore;
	uint8_t bestWeight;

	for ( size_t i = numNodes; i < weightsSize; ++i ) {
		bestScore = std::numeric_limits<unsigned int>::max();
		bestWeight = std::numeric_limits<uint8_t>::min();

		for ( weight = ((short)bestWeight); weight <= ((short)std::numeric_limits<uint8_t>::max()); ++weight ) {
			weights[i] = ((uint8_t)weight);
			score = calculateScore( numNodes, nodes, predicter );

			if ( score < bestScore ) {
				bestScore = score;
				bestWeight = ((uint8_t)weight);
			}
		}

		weights[i] = bestWeight;

		std::cout << "\t\tTraining Step " << (i - numNodes) + 1 << " of " << weightsSize - numNodes << " complete... (" << bestScore << ')' << std::endl;
        hexDumpMemory(weights, weightsSize);
	}
}

// This method generates a file that assigns a string literal to a variable called name
void saveWeights( const std::string& name, const size_t numNodes, const uint8_t* const weights ) {
	std::ofstream weightFile( "weights/" + name );

	weightFile << "char* T=R\"delim(";
	weightFile.write( (char*) weights, numNodes * numNodes );
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
