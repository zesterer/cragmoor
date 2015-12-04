//----LIBRARY----
#include "SDL2/SDL.h"

//----LOCAL----
#include "renderer/colour.h"

namespace Cragmoor
{
	namespace Window
	{
		class Window
		{
			private:
				SDL_Window* window = nullptr;
				SDL_Surface* surface = nullptr;
				
				bool should_close = false;
			public:
				Window();
				
				void blank();
				void fetchEvents();
				bool shouldClose();
				void update();
				
				void lockSurface(bool lock);
				
				void setPixel(short x, short y, Pixel pixel);
		};
	}
}
