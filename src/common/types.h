#ifndef CRAGMOOR_COMMON_TYPES_H
#define CRAGMOOR_COMMON_TYPES_H

namespace Cragmoor
{
	typedef unsigned char byte;
	typedef unsigned short doublebyte;
	typedef unsigned int quadbyte;
	typedef unsigned long octbyte;
	
	enum CellColour
	{
		BLACK = 0,
		RED = 1,
		GREEN = 2,
		YELLOW = 3,
		BLUE = 4,
		MAGENTA = 5,
		CYAN = 6,
		GREY = 7,
		DARK_GREY = 8,
		LIGHT_RED = 9,
		LIGHT_GREEN = 10,
		LIGHT_YELLOW = 11,
		LIGHT_BLUE = 12,
		LIGHT_MAGENTA = 13,
		LIGHT_CYAN = 14,
		WHITE = 15
	};
	
	struct Position
	{
		int x;
		int y;
		
		Position(int x = 0, int y = 0)
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
		
		Position& operator+=(const Position& pos)
		{
			return *this + pos;
		}
		
		Position& operator-(const Position& pos)
		{
			this->x -= pos.x;
			this->y -= pos.y;
			return *this;
		}
	  
	  	Position& operator%(const Position& pos)
		{
		  	this->x %= pos.x;
		  	this->y %= pos.y;
			return *this;
		}
	  
		Position& operator%=(const Position& pos)
		{
		  	return *this % pos;
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
