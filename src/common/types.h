#ifndef CRAGMOOR_COMMON_TYPES_H
#define CRAGMOOR_COMMON_TYPES_H

namespace Cragmoor
{
	typedef unsigned char byte;
	typedef unsigned short doublebyte;
	typedef unsigned int quadbyte;
	typedef unsigned long octbyte;
	
	struct Position
	{
		int x;
		int y;
		
		Position() {};
		
		Position(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	};
}

#endif
