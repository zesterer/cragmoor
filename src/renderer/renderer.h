#ifndef CRAGMOOR_RENDERER_RENDERER_H
#define CRAGMOOR_RENDERER_RENDERER_H

//----LIBRARY----
#include "SDL2/SDL_image.h"

//----LOCAL----
#include "game/game.h"
#include "asciiboard.h"

namespace Cragmoor
{
	namespace Renderer
	{
		class Renderer
		{
			private:
				long time = 0;
				Game::Game* game;
				Window::Window* window;
				
				ASCIIBoard board;
			public:
				Renderer(Game::Game* game, Window::Window* window);
				
				void tick();
				void renderGame();
		};
	}
}

#endif
