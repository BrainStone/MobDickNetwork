#pragma once

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>
#include "termcolor.hpp"

void hexDumpMemory( const void* bytes, const size_t numBytes, std::ostream& stream = std::cout );
void hexDumpMemory( const uint8_t* bytes, const size_t numBytes, std::ostream& stream = std::cout );
void hexDumpMemory( const std::vector<uint8_t>& bytes, std::ostream& stream = std::cout );
