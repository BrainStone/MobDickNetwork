#include "debug.hpp"

void hexDumpMemory( const void* bytes, const size_t numBytes, std::ostream& stream ) {
	hexDumpMemory( (uint8_t*)bytes, numBytes, stream );
}

void hexDumpMemory( const uint8_t* bytes, const size_t numBytes, std::ostream& stream ) {
	hexDumpMemory( std::vector<uint8_t>( bytes, bytes + numBytes ), stream );
}

void hexDumpMemory( const std::vector<uint8_t>& bytes, std::ostream& stream ) {
	char buff[17];
	size_t i = 0;

	stream << std::hex;

	// Process every byte in the data.
	for ( i = 0; i < bytes.size(); i++ ) {
		// Multiple of 16 means new line (with line offset).

		if ( (i % 16) == 0 ) {
			// Just don't print ASCII for the zeroth line.
			if ( i != 0 ) {
				stream << "  " << buff << std::endl;
			}

			// Output the offset.
			std::cout << termcolor::blue;
			stream << "  " << std::setw( 4 ) << std::setfill( '0' ) << static_cast<unsigned int>(i);
			std::cout << termcolor::reset;
		}

		// Now the hex code for the specific character.
		std::cout << termcolor::green;
		stream << " " << std::setw( 2 ) << std::setfill( '0' ) << static_cast<unsigned int>(bytes[i]);
		std::cout << termcolor::reset;

		// And store a printable ASCII character for later.
		if ( (bytes[i] < 0x20) || (bytes[i] > 0x7e) ) {
			buff[i % 16] = '.';
		} else {
			buff[i % 16] = bytes[i];
		}
		buff[(i % 16) + 1] = '\0';
	}

	stream << std::dec;

	// Pad out last line if not exactly 16 characters.
	while ( (i % 16) != 0 ) {
		stream << "   ";
		i++;
	}

	// And print the final ASCII bit.
	stream << "  " << buff << std::endl;
}
