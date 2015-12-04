//----STANDARD----
#include "string"

//----LIBRARY----
#include "SDL/SDL_image.h"

namespace Cragmoor
{
	namespace Window
	{
		class Texture
		{
			private:
				SDL_Surface* texture = nullptr;
			public:
				Texture();
				Texture(std::string filename);
				void loadFromBMP(std::string filename);
		};
	}
}
