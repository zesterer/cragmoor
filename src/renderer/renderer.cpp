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
			
			//this->window = new CursesWindow();
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
			
			this->drawRectangle(0, 0, this->window->getWidth(), 12, OutputCell('#', 11, 3));
			this->drawRectangle(1, 1, this->window->getWidth() - 2, 10, OutputCell(' ', 11, 3));
			
			std::string str = "Welcome, young traveller, to the kingdom of Cragmoor. Although the wind may blow and the rain may pour, you must venture onwards. A little to the north there exists a small hamlet by which you may obtain provisions and a bed for the night. Alas, I must leave you now, but I wish you luck and bid thee farewell.";
			
			for (int i = 0; i < (int)str.size(); i ++)
			{
				char c = str[i];
				this->window->setCell(i % (this->window->getWidth() - 2) + 1, i / (this->window->getWidth() - 2) + 1, OutputCell(c, 11, 3));
			}
			
			this->should_close |= this->window->tick();
			
			this->time ++;
		}
		
		void Renderer::renderGame()
		{
			char grass[4] = {(char)247, '*','.', ':'};
			
			for (int i = 0; i < this->window->getWidth(); i ++)
			{
				for (int j = 0; j < this->window->getHeight(); j ++)
				{
					byte h = this->game->getWorld()->getCell(i + this->time / 4, j)->height;
					this->window->setCell(i, j, OutputCell(grass[h % 4], 2 + 8 * (h % 2), 2 + 8 * ((h + 1) % 2)));
				}
			}
			
			this->window->setCell(9 + this->time / 2, 20 + this->time / 6, OutputCell(1, 1, 0));
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
	}
}
