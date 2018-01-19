// Not part of actual solution!
#include "network.hpp"

#include <cstring>

const int s = 4;
#include "W"
uint8_t* v = new uint8_t[s];
uint8_t* w = new uint8_t[s];
uint8_t* W = (uint8_t *) memcpy( new uint8_t[s*s], T, s*s );
uint8_t S( uint8_t i ) {
	int j, k, l;

	w[0] = i;
	for ( j = 1; j < s; ++j ) {
		l = s*j;
		for ( k = 0; k < s; ++k ) {
			v[j] += w[k] * W[l + k];
		}
	}

	uint8_t *t = w;
	w = v;
	v = t;

	return w[s - 1] & 127;
}
