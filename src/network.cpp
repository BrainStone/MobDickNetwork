// Not part of actual solution!
#include "network.hpp"

#include <cstring>

const int s = 4;
#include "W"
char* v = new char[s];
char* w = new char[s];
char* W = (char *) memcpy( new char[s*s], T, s*s );
char S( char i ) {
	int j, k, l;

	w[0] = i;
	for ( j = 1; j < s; ++j ) {
		l = s*j;
		for ( k = 0; k < s; ++k ) {
			v[j] += w[k] * W[l + k];
		}
	}

	char *t = w;
	w = v;
	v = t;

	return w[s - 1] & 127;
}
