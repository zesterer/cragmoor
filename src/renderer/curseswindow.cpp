//----LOCAL----
#include "curseswindow.h"
#include "ncurses.h"

namespace Cragmoor
{
	namespace Renderer
	{
		CursesWindow::CursesWindow()
		{
			//Constructor
		}
		
		CursesWindow::~CursesWindow()
		{
			curs_set(1);
			endwin();
		}
		
		void CursesWindow::initiate()
		{
			initscr();
			cbreak();
			noecho();
			keypad(stdscr, TRUE);
			curs_set(0);
			
			move(0, 0);
			if (!has_colors())
				printf("Does not support colours");
			
			start_color();
			
			getmaxyx(stdscr, this->height, this->width);
			
			this->setup();
		}
		
		void CursesWindow::setup()
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
		}
		
		bool CursesWindow::tick()
		{
			for (short i = 0; i < this->width; i ++)
			{
				for (short j = 0; j < this->height; j ++)
				{
					OutputCell* cell = &this->cells[(this->swapper + 0) % 2][this->height * (i % this->width) + (j % this->height)];
					OutputCell* old = &this->cells[(this->swapper + 1) % 2][this->height * (i % this->width) + (j % this->height)];
					
					if (*cell != *old)
					{
						//Draw the cell because it has changed.
						this->blitSymbol(cell->character, i, j, cell->foreground % 16, cell->background % 16);
					}
				}
			}
			
			this->swapper = (swapper + 1) % 2;
			
			refresh();
			
			return false;
		}
		
		OutputCell* CursesWindow::getCell(short x, short y)
		{
			return &this->cells[(this->swapper) % 2][this->height* (x % this->width) + (y % this->height)];
		}
		
		short CursesWindow::getWidth()
		{
			return this->width;
		}
		
		short CursesWindow::getHeight()
		{
			return this->height;
		}
		
		void CursesWindow::blitSymbol(byte symbol, short x, short y, byte foreground, byte background)
		{
			move(y, x);
			
			byte colourid = foreground * 16 + background;
			init_pair(colourid, foreground, background);
			attron(COLOR_PAIR(colourid));
			
			printw("%c", symbol % 128);
			
			
			
			//foreground.to8Bit();
			//background.to8Bit();
			
			//SDL_Rect src = {(symbol % 16) * this->tile_w, (symbol / 16) * this->tile_h, this->tile_w, this->tile_h};
			//SDL_Rect tgt = {x * this->cell_w, y * this->cell_h, this->cell_w, this->cell_h};
			
			//this->window.renderRectangle(tgt, background);
			//this->tileset.setColour(foreground);
			//this->tileset.draw(src, tgt);
		}
		
		void CursesWindow::setCellChar(short x, short y, byte character)
		{
			OutputCell* cell = this->getCell(x, y);
			cell->character = character;
		}
		
		void CursesWindow::setCellForeground(short x, short y, byte foreground)
		{
			OutputCell* cell = this->getCell(x, y);
			cell->foreground = foreground;
		}
		
		void CursesWindow::setCellBackground(short x, short y, byte background)
		{
			OutputCell* cell = this->getCell(x, y);
			cell->background = background;
		}
		
		void CursesWindow::setCell(short x, short y, OutputCell cell)
		{
			OutputCell* old = this->getCell(x, y);
			old->character = cell.character;
			old->foreground = cell.foreground;
			old->background = cell.background;
		}
	}
}
