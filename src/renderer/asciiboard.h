#ifndef CRAGMOOR_RENDERER_ASCIIBOARD_H
#define CRAGMOOR_RENDERER_ASCIIBOARD_H

//----STANDARD----
#include "vector"

//----LOCAL----
#include "common/types.h"
#include "window/window.h"
#include "window/texture.h"

namespace Cragmoor
{
	namespace Renderer
	{
		struct ASCIICell
		{
			byte character = ' ';
			Colour foreground = {255, 255, 255};
			Colour background = {255, 255, 255};
			
			ASCIICell(byte character, Colour foreground, Colour background)
			{
				this->character = character;
				this->foreground = foreground;
				this->background = background;
			}
			
			bool operator!=(const ASCIICell& other)
			{
				bool eq = true;
				eq &= this->character == other.character;
				eq &= this->foreground.r == other.foreground.r;
				eq &= this->foreground.g == other.foreground.g;
				eq &= this->foreground.b == other.foreground.b;
				eq &= this->background.r == other.background.r;
				eq &= this->background.g == other.background.g;
				eq &= this->background.b == other.background.b;
				return !eq;
			}
		};
		
		class ASCIIBoard
		{
			private:
				std::vector<ASCIICell> ascii_cells[2];
				
				byte swapper = 0;
				
				int width = 1;
				int height = 1;
				
				Window::Texture tileset;
				short tile_w = 16;
				short tile_h = 16;
				
				Window::Window* window;
				
				void blitSymbol(byte symbol, short x, short y, Colour foreground = Colour(255, 255, 255), Colour background = Colour(0, 0, 0));
			public:
				ASCIIBoard();
				void initiate();
				
				void setup();
				
				void setWindow(Window::Window* window);
				
				ASCIICell* getCell(short x, short y, byte back_buffer = 0);
				short getTileWidth();
				short getTileHeight();
				void tick();
				
				int getWidth();
				int getHeight();
				
				void setChar(byte character, short x, short y, Colour foreground = Colour(255, 255, 255));
				void setBack(short x, short y, Colour background = Colour(0, 0, 0));
				void setCell(byte character, short x, short y, Colour foreground = Colour(255, 255, 255), Colour background = Colour(0, 0, 0));
				void setRect(byte character, short x, short y, short w, short h, Colour foreground = Colour(255, 255, 255), Colour background = Colour(0, 0, 0));
		};
	}
}

#endif
