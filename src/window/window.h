#ifndef CRAGMOOR_WINDOW_WINDOW_H
#define CRAGMOOR_WINDOW_WINDOW_H

//----LIBRARY----
#include "SDL2/SDL.h"

//----LOCAL----
#include "renderer/colour.h"
#include "texture.h"

namespace Cragmoor
{
	namespace Window
	{
		class Window
		{
			private:
				SDL_Window* window = nullptr;
				SDL_Surface* surface = nullptr;
				
				SDL_Renderer* renderer = nullptr;
				
				bool should_close = false;
			public:
				Window();
				virtual ~Window();
				
				void blank();
				void fetchEvents();
				bool shouldClose();
				void update();
				
				void lockSurface(bool lock);
				
				void setPixel(short x, short y, Pixel pixel);
				void renderTexture(Texture* texture, SDL_Rect source, SDL_Rect target);
				void renderRectangle(SDL_Rect rectangle, Colour colour);
				
				SDL_Renderer* getInternalRenderer();
		};
	}
}

#endif
