//----LOCAL----
#include "asciiboard.h"

namespace Cragmoor
{
	namespace Renderer
	{
		ASCIIBoard::ASCIIBoard()
		{
			//Constructor
		}
		
		void ASCIIBoard::initiate()
		{
			this->tileset.setWindow(this->window);
			this->tileset.loadFromBMP("../data/tileset.png");
			this->tile_w = tileset.getWidth() / 16;
			this->tile_h = tileset.getHeight() / 16;
			
			this->width = this->window->getWidth() / this->tile_w;
			this->height = this->window->getHeight() / this->tile_h;
			
			this->setup();
		}
		
		void ASCIIBoard::setWindow(Window::Window* window)
		{
			this->window = window;
		}
		
		void ASCIIBoard::setup()
		{
			this->ascii_cells[0].clear();
			this->ascii_cells[1].clear();
			this->ascii_cells[0].reserve(this->width * this->height);
			this->ascii_cells[1].reserve(this->width * this->height);
			
			for (short i = 0; i < this->width; i ++)
			{
				for (short j = 0; j < this->height; j ++)
				{
					this->ascii_cells[0].emplace_back(' ', 255, 0);
					this->ascii_cells[1].emplace_back(' ', 255, 0);
				}
			}
		}
		
		ASCIICell* ASCIIBoard::getCell(short x, short y, byte buffer)
		{
			return &this->ascii_cells[(this->swapper + buffer) % 2][this->height* (x % this->width) + (y % this->height)];
		}
		
		short ASCIIBoard::getTileWidth()
		{
			return this->tile_w;
		}
		
		short ASCIIBoard::getTileHeight()
		{
			return this->tile_h;
		}
		
		void ASCIIBoard::blitSymbol(byte symbol, short x, short y, Colour foreground, Colour background)
		{
			SDL_Rect src = {(symbol % 16) * this->tile_w, (symbol / 16) * this->tile_h, this->tile_w, this->tile_h};
			SDL_Rect tgt = {x * this->tile_w, y * this->tile_h, this->tile_w, this->tile_h};
			this->window->renderRectangle(tgt, background);
			this->tileset.setColour(foreground);
			this->tileset.draw(src, tgt);
		}
		
		void ASCIIBoard::tick()
		{
			for (short i = 0; i < this->width; i ++)
			{
				for (short j = 0; j < this->height; j ++)
				{
					ASCIICell* cell = this->getCell(i, j);
					
					if (*cell != *this->getCell(i, j, 1))
					{
						//Draw the cell because it has changed.
						this->blitSymbol(cell->character, i, j, cell->foreground, cell->background);
						//printf("DREW!\n");
					}
					
					cell->character = ' ';
					cell->foreground = Colour(0xffffff);
					cell->background = Colour(0x0);
				}
			}
			
			this->swapper = (swapper + 1) % 2;
		}
		
		void ASCIIBoard::setChar(byte character, short x, short y, Colour foreground)
		{
			ASCIICell* cell = this->getCell(x, y);
			cell->character = character;
			cell->foreground = foreground;
		}
		
		void ASCIIBoard::setBack(short x, short y, Colour background)
		{
			ASCIICell* cell = this->getCell(x, y);
			cell->background = background;
		}
		
		void ASCIIBoard::setCell(byte character, short x, short y, Colour foreground, Colour background)
		{
			ASCIICell* cell = this->getCell(x, y);
			cell->character = character;
			cell->foreground = foreground;
			cell->background = background;
		}
		
		void ASCIIBoard::setRect(byte character, short x, short y, short w, short h, Colour foreground, Colour background)
		{
			for (short i = 0; i < w; i ++)
			{
				for (short j = 0; j < h; j ++)
				{
					this->setCell(character, x + i, y + j, foreground, background);
				}
			}
		}
		
		int ASCIIBoard::getWidth()
		{
			return this->width;
		}
		
		int ASCIIBoard::getHeight()
		{
			return this->height;
		}
	}
}
