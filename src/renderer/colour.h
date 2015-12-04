namespace Cragmoor
{
	typedef unsigned char byte;
	
	struct Colour
	{
		byte r = 0;
		byte g = 0;
		byte b = 0;
		
		byte getR() {return this->r;}
		byte getG() {return this->g;}
		byte getB() {return this->b;}
	};
	
	struct Pixel : Colour
	{
		byte a = 255;
		
		Pixel(int r, int g, int b, int a)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
		
		byte getA() {return this->a;}
	};
}
