//----standard----
#include "pthread.h"
#include "chrono"
#include "thread"
#include "iostream"

//----LIBRARY----
#include "ncursesw/curses.h"

//----LOCAL----
#include "curseswindow.h"

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
			setlocale(LC_ALL, "");
			initscr();
			cbreak();
			noecho();
			keypad(stdscr, TRUE);
			curs_set(0);
			
			this->supports_colour = has_colors();
			
			if (this->supports_colour)
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
			
			this->char_palette[0] =  " @@VvA^.Oo0/|pAX";
			this->char_palette[1] =  "><k!#$_k^v><Lx^v";
			this->char_palette[2] =  " !\"#$%&'()*+,-./";
			this->char_palette[3] =  "0123456789:;<=>?";
			
			this->char_palette[4] =  "@ABCDEFGHIJKLMNO";
			this->char_palette[5] =  "PQRSTUVWXYZ[\\]^_";
			this->char_palette[6] =  "`abcdefghijklmno";
			this->char_palette[7] =  "pqrstuvwxyz{|}~^";
			
			this->char_palette[8] =  "CueaaaaceeeiiiAA";
			this->char_palette[9] =  "E&%ooouuyuu0£0xf";
			this->char_palette[10] = "aiounNaei0_%%i<>";
			this->char_palette[11] = "###|+++\\\\+|\\///\\";
			
			this->char_palette[12] = "\\+++-+++\\/+++-++";
			this->char_palette[13] = "+++\\\\//++//#_||-";
			this->char_palette[14] = "aBrnEbUYO0nd8%£n";
			this->char_palette[15] = "=+><(J%~o..Jn2.O";
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
			
			refresh();
			
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			
			this->swapper = (swapper + 1) % 2;
			
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
			
			if (this->supports_colour)
			{
				byte colourid = foreground * 16 + background;
				init_pair(colourid, foreground, background);
				attron(COLOR_PAIR(colourid));
			}
			
			printw("%c", this->char_palette[symbol / 16][symbol % 16]);
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
