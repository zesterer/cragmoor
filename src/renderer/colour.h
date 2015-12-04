#ifndef CRAGMOOR_RENDERER_COLOUR_H
#define CRAGMOOR_RENDERER_COLOUR_H

namespace Cragmoor
{
	typedef unsigned char byte;
	
	struct Colour
	{
		byte r = 0;
		byte g = 0;
		byte b = 0;
		
		Colour(int r, int g, int b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
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
