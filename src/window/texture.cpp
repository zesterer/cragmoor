//----LOCAL----
#include "texture.h"

namespace Cragmoor
{
	namespace Window
	{
		Texture::Texture()
		{
			//Constructor
		}
		
		Texture::Texture(std::string filename)
		{
			this->loadFromBMP(filename);
		}
		
		void Texture::loadFromBMP(std::string filename)
		{
			this->texture = SDL_LoadBMP(filename.c_str());
		}
	}
}
