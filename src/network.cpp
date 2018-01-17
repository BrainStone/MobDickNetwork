// Not part of actual solution!
#include "network.hpp"

const size_t s = 128;
//char w[s];
char* w = new char[s];
#include "W"
char S( char i ) {
	char n[s];

	w[0] = i;
	for ( size_t j = 1; j < s; ++j ) {
		for ( size_t k = 0; k < s; ++k ) {
			n[j] += w[k] * W[s*j + k];
		}
	}

	w = n;

	return w[s - 1] & 127;
}
