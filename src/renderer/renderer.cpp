//----LOCAL----
#include "renderer.h"

namespace Cragmoor
{
	namespace Renderer
	{
		Renderer::Renderer(Game::Game* game, Window::Window* window)
		{
			this->game = game;
			this->window = window;
			
			this->board.setWindow(this->window);
			this->board.initiate();
		}
		
		void Renderer::tick()
		{
			this->renderGame();
			
			this->board.setRect('#', 0, 0, this->board.getWidth(), 12, Colour(0xb79e4b), Colour(0x6d552f));
			this->board.setRect(' ', 1, 1, this->board.getWidth() - 2, 10, Colour(0xb79e4b), Colour(0x6d552f));
			
			std::string str = "Welcome, young traveller, to the kingdom of Cragmoor. Although the wind may blow and the rain may pour, you must venture onwards. A little to the north there exists a small hamlet by which you may obtain provisions and a bed for the night. Alas, I must leave you now, but I wish you luck and bid thee farewell.";
			
			for (int i = 0; i < (int)str.size(); i ++)
			{
				char c = str[i];
				this->board.setChar(c, i % (this->board.getWidth() - 2) + 1, i / (this->board.getWidth() - 2) + 1, Colour(0xb79e4b));
			}
			
			this->board.tick();
			this->time ++;
		}
		
		void Renderer::renderGame()
		{
			char grass[4] = {'`', '"','.', ';'};
			
			for (int i = 0; i < this->board.getWidth(); i ++)
			{
				for (int j = 0; j < this->board.getHeight(); j ++)
				{
					byte v = (this->game->getWorld()->getCell(i + this->time / 2, j)->height / 64) * 64;
					this->board.setCell(grass[this->game->getWorld()->getCell(i + this->time / 2, j)->height % 4], i, j, Colour(20, v, 20), Colour(20, v + 40, 20));
				}
			}
			
			this->board.setChar('@', 9 + this->time, 20 + this->time / 4, Colour(0x804020));
		}
	}
}
