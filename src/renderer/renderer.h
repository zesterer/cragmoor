#ifndef CRAGMOOR_RENDERER_RENDERER_H
#define CRAGMOOR_RENDERER_RENDERER_H

//----LIBRARY----
#include "SDL2/SDL_image.h"

//----LOCAL----
#include "game/game.h"
#include "window/window.h"
#include "window/texture.h"

namespace Cragmoor
{
	namespace Renderer
	{
		class Renderer
		{
			private:
				Game::Game* game;
				Window::Window* window;
				
				Window::Texture tileset;
				
				short tile_size = 16;
			public:
				Renderer(Game::Game* game, Window::Window* window);
				
				void tick();
				void renderGame();
				
				void drawSymbol(byte symbol, short x, short y, Colour foreground = Colour(255, 255, 255), Colour background = Colour(0, 0, 0));
				void drawSymbolRect(byte symbol, short x, short y, short w, short h, Colour foreground = Colour(255, 255, 255), Colour background = Colour(0, 0, 0));
		};
	}
}

#endif
