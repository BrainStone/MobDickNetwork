// Not part of actual solution!
#include "network.hpp"

#include <cstdint>
#include <cstring>

const int s = 8;
uint8_t* v = new uint8_t[s];
uint8_t* w = new uint8_t[s];
uint8_t* W = (uint8_t *) memcpy( new uint8_t[s*s],
#include "W"
, s*s );
const uint8_t* const chars = (uint8_t *) R"xxx( etaonsihrldumcwgf,ypbvk.-
;|"'ATS!HBWEqNCPx?OLjRFMDGzYQJU():KV1028573*4Z69X_$&[] etaonsihrldumcwgf,ypbvk.-
;|"'ATS!HBWEqNCPx?OL)xxx";
uint8_t S( uint8_t i ) {
	int j, k, l;

	w[0] = i;
	for ( j = 1; j < s; ++j ) {
		l = s*j;
        v[j] = W[j];
		for ( k = 0; k < s; ++k ) {
			v[j] += w[k] * W[l + k];
		}
	}

	uint8_t *t = w;
	w = v;
	v = t;

	return chars[w[s - 1] & 127];
}
