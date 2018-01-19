#include "main.hpp"

int main(int argc, char* argv[]) {
    if(argc > 1) {
        int seed;
        
        try {
            seed = std::stoi(argv[0]);
        } catch(...) {
            // Ignore all errors
            seed = 0;
        }
        
        randomizeWeights(s * s, W, seed);
    }
    
	hexDumpMemory(W, s*s);
	std::cout << "Training:\t" << s << std::endl;
	std::cout << "Count:\t\t" << sizeMobyDick - 1 << std::endl;

	std::cout << "t = 0:\t\t" << calculateScore( s, w, S ) << std::endl;

	for ( size_t i = 0; i < 10; ++i ) {
		train( s, w, W, S );
		saveWeights( std::to_string(s), s, W );
		std::cout << "t = " << i + 1 << ":\t\t" << calculateScore( s, w, S ) << std::endl;
	}
}

void randomizeWeights( const size_t weightsSize, uint8_t* weights, const uint8_t seed ) {
    srand(seed);
    
    for(size_t i = 0; i < weightsSize; ++i) {
        weights[i] = (uint8_t) rand();
    }
}
