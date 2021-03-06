#ifndef CRAGMOOR_RENDERER_RENDERER_H
#define CRAGMOOR_RENDERER_RENDERER_H

//----LIBRARY----
#include "SDL2/SDL_image.h"

//----LOCAL----
#include "game/game.h"
#include "outputwindow.h"
#include "generic/dialog.h"

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
				
				std::vector<Generic::Dialog*> dialogs;
			public:
				Renderer(Game::Game* game);
				~Renderer();
				
				void tick();
				void renderGame();
				
				bool shouldClose();
				
				OutputWindow* getWindow() { return this->window; };
				
				void drawRectangle(short x, short y, short w, short h, OutputCell cell = OutputCell(' ', 255, 255));
				void drawBorder(short x, short y, short w, short h, byte colour = 255);
				void drawString(short x, short y, std::string text, byte colour);
				void drawText(short x, short y, short w, short h, std::string text, byte colour);
		};
	}
}

#endif
