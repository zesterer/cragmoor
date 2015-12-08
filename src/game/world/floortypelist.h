#ifndef CRAGMOOR_GAME_WORLD_FLOORTYPELIST_H
#define CRAGMOOR_GAME_WORLD_FLOORTYPELIST_H

//----STANDARD----
#include "vector"
#include "string"

//----LOCAL----
#include "common/types.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace World
		{
			struct FloorType
			{
				byte character = ' ';
				byte foreground = 15;
				byte background = 0;
				std::string name = "void";
				
				FloorType(byte character, byte foreground, byte background, std::string name)
				{
					this->character = character;
					this->foreground = foreground;
					this->background = background;
					this->name = name;
				}
			};
			
			class FloorTypeList
			{
				private:
					std::vector<FloorType> types;
				public:
					FloorTypeList();
					FloorType* getType(doublebyte id);
			};
		}
	}
}

#endif
