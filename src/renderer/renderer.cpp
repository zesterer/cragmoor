//----LOCAL----
#include "renderer.h"
#include "graphicalwindow.h"
#include "curseswindow.h"

namespace Cragmoor
{
	namespace Renderer
	{
		Renderer::Renderer(Game::Game* game)
		{
			this->game = game;
			this->window = window;
			
			if (0)
				this->window = new CursesWindow();
			else
				this->window = new GraphicalWindow();
			
			this->window->initiate();
		}
		
		Renderer::~Renderer()
		{
			delete this->window;
		}
		
		void Renderer::tick()
		{
			this->renderGame();
			
			this->drawRectangle(2, 2, this->window->getWidth() - 4, 10, OutputCell(' ', 11, 3));
			this->drawBorder(2, 2, this->window->getWidth() - 4, 10, 11);
			
			std::string str = "Welcome, young traveller, to the kingdom of Cragmoor.\n\nAlthough the wind may blow and the rain may pour, you must venture onwards. A little to the north there exists a small hamlet by which you may obtain provisions and a bed for the night. Alas, I must leave you now, but I wish you luck and bid thee farewell.";
			
			this->drawText(3, 3, this->window->getWidth() - 6, 10, str, 11);
			
			/*for (int i = 0; i < (int)str.size(); i ++)
			{
				char c = str[i];
				this->window->setCell(i % (this->window->getWidth() - 6) + 3, i / (this->window->getWidth() - 6) + 3, OutputCell(c, 11, 3));
			}*/
			
			this->should_close |= this->window->tick();
			
			this->time ++;
		}
		
		void Renderer::renderGame()
		{
			for (int i = 0; i < this->window->getWidth(); i ++)
			{
				for (int j = 0; j < this->window->getHeight(); j ++)
				{
					int x = i + this->time;
					int y = j - this->time / 6;
					
					Game::World::Cell* cell = this->game->getWorld()->getCell(x, y);
					Game::World::FloorType* floortype = this->game->getWorld()->floor_types.getType(cell->floor_type);
					
					//this->window->setCell(i, j, OutputCell(floortype->character, 2 + 8 * ((h / 128 + ((y ^ x ^ h) % 6) / 5) % 2), 0));
					this->window->setCell(i, j, OutputCell(floortype->character, floortype->foreground, floortype->background));
				}
			}
			
			this->window->setCellChar(9 + this->time / 4, 20 + this->time / 6, 2);
			this->window->setCellForeground(9 + this->time / 4, 20 + this->time / 6, 219);
			
			this->window->setCellChar(60 + this->time / 3, 29 + this->time / 8, 2);
			this->window->setCellForeground(60 + this->time / 3, 29 + this->time / 8, 5);
			
			this->window->setCellChar(30 + this->time / 11, 60 + this->time / 3, 1);
			this->window->setCellForeground(30 + this->time / 11, 60 + this->time / 3, 3);
		}
		
		bool Renderer::shouldClose()
		{
			return this->should_close;
		}
		
		void Renderer::drawRectangle(short x, short y, short w, short h, OutputCell cell)
		{
			for (short i = 0; i < w; i ++)
			{
				for (short j = 0; j < h; j ++)
				{
					this->window->setCell(x + i, y + j, cell);
				}
			}
		}
		
		/* TODO - Could probably do with cleaning up */
		void Renderer::drawText(short x, short y, short w, short h, std::string text, byte colour)
		{
			std::vector<std::string>lines;
			lines.emplace_back();
			
			if (w < 1)
				w = 1;
			
			for (unsigned int i = 0; i < text.size(); i ++)
			{
				bool skip_char = false;
				unsigned int str_id = lines.size() - 1;
				
				if (lines[str_id].size() >= w)
				{
					lines.emplace_back();
					
					unsigned int last = lines[str_id].size() - 1;
					while (lines[str_id][last] != ' ' && last > 0)
						last --;
					
					if (last > 0)
					{
						lines[str_id + 1] += lines[str_id].substr(last + 1, lines[str_id].size() - last - 1);
						lines[str_id] = lines[str_id].substr(0, last);
					}
					
					str_id = lines.size() - 1;
				}
				
				{
					if (text[i] == '\n')
					{
						lines.emplace_back();
						skip_char = true;
					}
					
					if (!skip_char)
						lines[str_id] += text[i];
				}
			}
			
			for (unsigned int j = 0; j < lines.size(); j ++)
			{
				this->drawString(x, y + j, lines[j], colour);
			}
		}
		
		void Renderer::drawString(short x, short y, std::string text, byte colour)
		{
			for (unsigned int i = 0; i < text.size(); i ++)
			{
				this->window->setCellChar(x + i, y, text[i]);
					this->window->setCellForeground(x + i, y, colour);
			}
		}
		
		void Renderer::drawBorder(short x, short y, short w, short h, byte colour)
		{
			this->window->setCellChar(x, y, 12 * 16 + 9);
			this->window->setCellChar(x + w - 1, y, 11 * 16 + 11);
			this->window->setCellChar(x, y + h - 1, 12 * 16 + 8);
			this->window->setCellChar(x + w - 1, y + h - 1, 11 * 16 + 12);
			
			for (short i = 0; i < w - 2; i ++)
			{
				this->window->setCellChar(x + i + 1, y, 12 * 16 + 13);
				this->window->setCellForeground(x + i + 1, y, colour);
				
				this->window->setCellChar(x + i + 1, y + h - 1, 12 * 16 + 13);
				this->window->setCellForeground(x + i + 1, y + h - 1, colour);
			}
			
			for (short j = 0; j < h - 2; j ++)
			{
				this->window->setCellChar(x, y + j + 1, 11 * 16 + 10);
				this->window->setCellForeground(x, y + j + 1, colour);
				
				this->window->setCellChar(x + w - 1, y + j + 1, 11 * 16 + 10);
				this->window->setCellForeground(x + w - 1, y + j + 1, colour);
			}
		}
	}
}
