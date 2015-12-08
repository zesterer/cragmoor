#ifndef CRAGMOOR_RENDERER_COLOUR_H
#define CRAGMOOR_RENDERER_COLOUR_H

//----STANDARD----
#include "string"

//----LOCAL----
#include "common/types.h"

namespace Cragmoor
{
	struct Colour
	{
		byte r = 0;
		byte g = 0;
		byte b = 0;
		
		Colour()
		{
			this->r = 0;
			this->g = 0;
			this->b = 0;
		}
		
		Colour(int r, int g, int b)
		{
			this->r = std::max(0, std::min(r, 255));
			this->g = std::max(0, std::min(g, 255));
			this->b = std::max(0, std::min(b, 255));
		}
		
		Colour(int c)
		{
			this->r = (c >> 16) % 256;
			this->g = (c >> 8) % 256;
			this->b = (c >> 0) % 256;
		}
		
		void to8Bit()
		{
			this->r &= 0xe0;
			this->g &= 0xe0;
			this->b &= 0xc0;
		}
		
		byte getR() {return this->r;}
		byte getG() {return this->g;}
		byte getB() {return this->b;}
	};
	
	struct Pixel : Colour
	{
		byte a = 255;
		
		Pixel(int r, int g, int b, int a) : Colour(r, g, b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}
		
		byte getA() {return this->a;}
		
		Colour getColour()
		{
			return Colour(this->r, this->g, this->b);
		}
	};
}

#endif
