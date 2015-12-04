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
		}
		
		void Renderer::tick()
		{
			this->window->lockSurface(true);
			
			//SDL_Rect src = {0, 0, 256, 256};
			//SDL_Rect tgt = {0, 0, 256, 256};
			//this->tileset.draw(src, tgt);
			
			std::string str = "Hello, World! Just testing the text. This is looking quite good. As you can see, it even overlaps onto the next line! How awesome is that? I'm quite pleased with it ({haha} but it isn't perfect yet!).";
			
			for (int i = 0; i < (int)str.size(); i ++)
			{
				char c = str[i];
				this->drawSymbol(c, i % (640 / 16), i / (640 / 16), {255, 100, 255}, {0, 150, 0});
			}
			
			this->window->lockSurface(false);
		}
		
		void Renderer::drawSymbol(byte symbol, short x, short y, Colour foreground, Colour background)
		{
			SDL_Rect src = {(symbol % 16) * 16, (symbol / 16) * 16, 16, 16};
			SDL_Rect tgt = {x * 16, y * 16, 16, 16};
			this->window->renderRectangle(tgt, background);
			this->tileset.setColour(foreground);
			this->tileset.draw(src, tgt);
		}
	}
}
