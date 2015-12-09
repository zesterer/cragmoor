//----LOCAL----
#include "floortypelist.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace World
		{
			FloorTypeList::FloorTypeList()
			{
				this->types.push_back({'.', 10, 0, "Meadow Grass"});
				this->types.push_back({247, 2, 0, "Brome Grass"});
				this->types.push_back({'~', 10, 0, "Rye Grass"});
				this->types.push_back({'*', 2, 8, "Marsh Grass"});
				this->types.push_back({176, 11, 0, "Sandy Loam"});
				this->types.push_back({'~', 12, 0, "Shallow Salt Water"});
				this->types.push_back({'~', 4, 0, "Deep Salt Water"});
				this->types.push_back({'~', 6, 0, "Shallow Fresh Water"});
				this->types.push_back({'~', 14, 0, "Deep Fresh Water"});
			}
			
			FloorType FloorTypeList::getType(doublebyte id)
			{
				return this->types[id % this->types.size()];
			}
		}
	}
}
