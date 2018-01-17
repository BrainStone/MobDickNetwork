// Not part of actual solution!
#include "network.hpp"

#include <cstring>

const size_t s = 4;
#include "W"
char* w = new char[s];
char* W = (char *) memcpy( new char[s*s], T, s*s );
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
