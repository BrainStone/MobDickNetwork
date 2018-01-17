#pragma once

#include <algorithm>
#include <functional>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

extern const std::string mobyDick;
extern const size_t sizeMobyDick;

unsigned int calculateScore( const size_t numNodes, char* nodes, std::function<char( char )> predicter );
void train( const size_t numNodes, char* nodes, char* weights, std::function<char( char )> predicter );
void saveWeights( const std::string& name, const size_t numNodes, const char* const weights );
std::string getMobyDick();
