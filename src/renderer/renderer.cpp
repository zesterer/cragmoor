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
			
			this->tileset.setWindow(this->window);
			this->tileset.loadFromBMP("../data/tileset.png");
			this->tile_size = tileset.getWidth() / 16;
		}
		
		void Renderer::tick()
		{
			this->renderGame();
			
			this->drawSymbolRect('#', 0, 0, 640 / this->tile_size, 13, {180, 175, 125}, {120, 100, 70});
			this->drawSymbolRect(' ', 1, 1, 640 / this->tile_size - 2, 11, {180, 175, 125}, {120, 100, 70});
			
			std::string str = "Welcome, young traveller, to the kingdom of Cragmoor. Although the wind may blow and the rain may pour, you must venture onwards. A little to the north there exists a small hamlet by which you may obtain provisions and a bed for the night. Alas, I must leave you now, but I wish you luck and bid thee farewell.";
			
			for (int i = 0; i < (int)str.size(); i ++)
			{
				char c = str[i];
				this->drawSymbol(c, i % (640 / this->tile_size - 4) + 2, i / (640 / this->tile_size - 4) + 2, {180, 175, 125}, {120, 100, 70});
			}
		}
		
		void Renderer::drawSymbol(byte symbol, short x, short y, Colour foreground, Colour background)
		{
			SDL_Rect src = {(symbol % 16) * this->tile_size, (symbol / 16) * this->tile_size, this->tile_size, this->tile_size};
			SDL_Rect tgt = {x * this->tile_size, y * this->tile_size, this->tile_size, this->tile_size};
			this->window->renderRectangle(tgt, background);
			this->tileset.setColour(foreground);
			this->tileset.draw(src, tgt);
		}
		
		void Renderer::drawSymbolRect(byte symbol, short x, short y, short w, short h, Colour foreground, Colour background)
		{
			for (short i = 0; i < w; i ++)
			{
				for (short j = 0; j < h; j ++)
				{
					this->drawSymbol(symbol, x + i, y + j, foreground, background);
				}
			}
		}
		
		void Renderer::renderGame()
		{
			for (int i = 0; i < 640 / this->tile_size; i ++)
			{
				for (int j = 0; j < 480 / this->tile_size; j ++)
				{
					byte v = (this->game->getWorld()->getCell(i, j)->height / 32) * 32;
					this->drawSymbol(240, i, j, {0, std::min(255, std::max(0, v + 40)), 0}, {0, v, 0});
				}
			}
		}
	}
}
