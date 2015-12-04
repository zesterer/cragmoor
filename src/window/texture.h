#ifndef CRAGMOOR_WINDOW_TEXTURE_H
#define CRAGMOOR_WINDOW_TEXTURE_H

//----STANDARD----
#include "string"

//----LIBRARY----
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

//----LOCAL----
#include "renderer/colour.h"

namespace Cragmoor
{
	namespace Window
	{
		class Window;
		
		class Texture
		{
			private:
				SDL_Texture* texture = nullptr;
				Window* window;
				int width;
				int height;
			public:
				Texture();
				virtual ~Texture();
				Texture(Window* window);
				Texture(std::string filename, Window* window);
				void setWindow(Window* window);
				void loadFromBMP(std::string filename);
				void draw(SDL_Rect source, SDL_Rect target);
				SDL_Texture* getInternal();
				void setColour(Colour colour);
		};
	}
}

#endif
