//----LOCAL----
#include "texture.h"
#include "window.h"

namespace Cragmoor
{
	namespace Window
	{
		Texture::Texture()
		{
			//Constructor
		}
		
		Texture::Texture(Window* window)
		{
			this->window = window;
		}
		
		Texture::Texture(std::string filename, Window* window)
		{
			this->window = window;
			this->loadFromBMP(filename);
		}
		
		Texture::~Texture()
		{
			SDL_DestroyTexture(this->texture);
		}
		
		void Texture::loadFromBMP(std::string filename)
		{
			this->texture = IMG_LoadTexture(this->window->getInternalRenderer(), filename.c_str());
			
			if (this->texture == nullptr)
				printf(("Failed to load '" + filename + "': " + SDL_GetError() + "\n").c_str());
			else
				printf(("Loaded '" + filename + "'\n").c_str());
			
			SDL_QueryTexture(this->texture, NULL, NULL, &this->width, &this->height);
			
			//SDL_SetTextureBlendMode(this->texture, SDL_BLENDMODE_BLEND);
		}
		
		void Texture::draw(SDL_Rect source, SDL_Rect target)
		{
			this->window->renderTexture(this, source, target);
		}
		
		SDL_Texture* Texture::getInternal()
		{
			return this->texture;
		}
		
		void Texture::setWindow(Window* window)
		{
			this->window = window;
		}
		
		void Texture::setColour(Colour colour)
		{
			SDL_SetTextureColorMod(this->texture, colour.r, colour.g, colour.b);
		}
		
		int Texture::getWidth()
		{
			return this->width;
		}
		
		int Texture::getHeight()
		{
			return this->height;
		}
	}
}
