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
			
			this->tileset.loadFromBMP("tileset.bmp");
		}
		
		void Renderer::tick()
		{
			this->window->lockSurface(true);
			
			for (short i = 0; i < 640; i ++)
				for (short j = 0; j < 480; j ++)
					this->window->setPixel(i, j, Pixel(255, 0, 0, 255));
			
			this->window->lockSurface(false);
		}
	}
}
