#ifndef CRAGMOOR_RENDERER_RENDERER_H
#define CRAGMOOR_RENDERER_RENDERER_H

//----LIBRARY----
#include "SDL2/SDL_image.h"

//----LOCAL----
#include "game/game.h"
#include "outputwindow.h"

namespace Cragmoor
{
	namespace Renderer
	{
		class Renderer
		{
			private:
				long time = 0;
				Game::Game* game;
				
				bool should_close = false;
				
				OutputWindow* window;
			public:
				Renderer(Game::Game* game);
				~Renderer();
				
				void tick();
				void renderGame();
				
				bool shouldClose();
				
				void drawRectangle(short x, short y, short w, short h, OutputCell cell = OutputCell(' ', 255, 255));
		};
	}
}

#endif
