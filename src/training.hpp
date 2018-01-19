#pragma once

#include <algorithm>
#include <functional>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

#include "debug.hpp"

extern const std::string mobyDick;
extern const size_t sizeMobyDick;

unsigned int calculateScore( const size_t numNodes, uint8_t*& nodes, std::function<uint8_t( uint8_t )> predicter );
void train( const size_t numNodes, uint8_t*& nodes, uint8_t* weights, std::function<uint8_t( uint8_t )> predicter, bool forceChange = false );
void applyMask( const size_t weightsSize, uint8_t* weights, const uint8_t mask );
void saveWeights( const std::string& name, const size_t numNodes, const uint8_t* const weights );
std::string getMobyDick();
