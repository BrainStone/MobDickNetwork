#pragma once

#include <algorithm>
#include <functional>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>

unsigned int calculateScore( std::function<char( char )> predicter );
void train( const size_t numNodes, char* weights, std::function<char( char )> predicter );
std::string getMobyDick();
