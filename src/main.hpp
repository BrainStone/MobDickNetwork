#pragma once

#include <cstdlib>
#include <string>

#include "debug.hpp"
#include "network.hpp"
#include "training.hpp"

int main(int argc, char* argv[]);
void randomizeWeights( const size_t weightsSize, uint8_t* weights, const uint8_t seed = 0 );
