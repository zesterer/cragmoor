//----LOCAL----
#include "graphicalwindow.h"

namespace Cragmoor
{
	namespace Renderer
	{
		GraphicalWindow::GraphicalWindow()
		{
			//Constructor
		}
		
		GraphicalWindow::~GraphicalWindow()
		{
			//Destructor
		}
		
		void GraphicalWindow::initiate()
		{
			this->tileset.setWindow(&this->window);
			this->tileset.loadFromBMP("../data/tileset-10.png");
			
			this->tile_w = tileset.getWidth() / 16;
			this->tile_h = tileset.getHeight() / 16;
			this->cell_w = this->pixel_w * this->tile_w;
			this->cell_h = this->pixel_w * this->tile_h;
			
			this->width = this->window.getWidth() / this->cell_w;
			this->height = this->window.getHeight() / this->cell_h;
			
			this->setup();
		}
		
		void GraphicalWindow::setup()
		{
			this->cells[0].clear();
			this->cells[1].clear();
			this->cells[0].reserve(this->width * this->height);
			this->cells[1].reserve(this->width * this->height);
			
			for (short i = 0; i < this->width; i ++)
			{
				for (short j = 0; j < this->height; j ++)
				{
					this->cells[0].emplace_back(' ', 0, 0);
					this->cells[1].emplace_back(' ', 0, 0);
				}
			}
			
			/* Create the colour palette */
			//Dark colours
			this->palette[0] = Colour(30, 30, 30);
			this->palette[1] = Colour(170, 30, 30);
			this->palette[2] = Colour(30, 120, 30);
			this->palette[3] = Colour(170, 110, 30);
			this->palette[4] = Colour(30, 30, 170);
			this->palette[5] = Colour(170, 30, 170);
			this->palette[6] = Colour(30, 170, 170);
			this->palette[7] = Colour(170, 170, 170);
			
			//Light colours
			this->palette[8] = Colour(85, 85, 85);
			this->palette[9] = Colour(210, 85, 85);
			this->palette[10] = Colour(85, 210, 85);
			this->palette[11] = Colour(230, 230, 50);
			this->palette[12] = Colour(85, 85, 210);
			this->palette[13] = Colour(210, 85, 210);
			this->palette[14] = Colour(85, 210, 210);
			this->palette[15] = Colour(255, 255, 255);
		}
		
		bool GraphicalWindow::tick()
		{
			for (short i = 0; i < this->width; i ++)
			{
				for (short j = 0; j < this->height; j ++)
				{
					OutputCell* cell = &this->cells[(this->swapper + 0) % 2][this->height* (i % this->width) + (j % this->height)];
					OutputCell* old = &this->cells[(this->swapper + 1) % 2][this->height* (i % this->width) + (j % this->height)];
					
					if (*cell != *old)
					{
						//Draw the cell because it has changed.
						this->blitSymbol(cell->character, i, j, this->palette[cell->foreground % 16], this->palette[cell->background % 16]);
					}
				}
			}
			
			this->window.update();
			
			SDL_Delay(100);
			
			this->swapper = (swapper + 1) % 2;
			
			return this->window.shouldClose();
		}
		
		OutputCell* GraphicalWindow::getCell(short x, short y)
		{
			return &this->cells[(this->swapper) % 2][this->height* (x % this->width) + (y % this->height)];
		}
		
		short GraphicalWindow::getWidth()
		{
			return this->width;
		}
		
		short GraphicalWindow::getHeight()
		{
			return this->height;
		}
		
		void GraphicalWindow::blitSymbol(byte symbol, short x, short y, Colour foreground, Colour background)
		{
			SDL_Rect src = {(symbol % 16) * this->tile_w, (symbol / 16) * this->tile_h, this->tile_w, this->tile_h};
			SDL_Rect tgt = {x * this->cell_w, y * this->cell_h, this->cell_w, this->cell_h};
			
			this->window.renderRectangle(tgt, background);
			this->tileset.setColour(foreground);
			this->tileset.draw(src, tgt);
		}
		
		void GraphicalWindow::setCellChar(short x, short y, byte character)
		{
			OutputCell* cell = this->getCell(x, y);
			cell->character = character;
		}
		
		void GraphicalWindow::setCellForeground(short x, short y, byte foreground)
		{
			OutputCell* cell = this->getCell(x, y);
			cell->foreground = foreground;
		}
		
		void GraphicalWindow::setCellBackground(short x, short y, byte background)
		{
			OutputCell* cell = this->getCell(x, y);
			cell->background = background;
		}
		
		void GraphicalWindow::setCell(short x, short y, OutputCell cell)
		{
			OutputCell* old = this->getCell(x, y);
			old->character = cell.character;
			old->foreground = cell.foreground;
			old->background = cell.background;
		}
	}
}
