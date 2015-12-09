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
		
		bool isInRectangle(int x, int y, int w, int h)
		{
			return this->x >= x && this->y >= y && this->x - w < x && this->y - h < y;
		}
		
		Position& operator+(const Position& pos)
		{
			this->x += pos.x;
			this->y += pos.y;
			return *this;
		}
		
		Position& operator-(const Position& pos)
		{
			this->x -= pos.x;
			this->y -= pos.y;
			return *this;
		}
		Position& operator-()
		{
			this->x *= -1;
			this->y *= -1;
			return *this;
		}
	};
}

#endif
