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
			public:
				Renderer(Game::Game* game, Window::Window* window);
				
				void tick();
		};
	}
}
