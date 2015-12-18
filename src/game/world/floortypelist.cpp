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
				this->types.push_back({'.', 10, 0, "Meadow Grass"}); //0
				this->types.push_back({'"', 2, 0, "Brome Grass"}); //1
				this->types.push_back({'~', 10, 0, "Rye Grass"}); //2
				this->types.push_back({'*', 2, 8, "Marsh Grass"}); //3
				this->types.push_back({176, 11, 0, "Sandy Loam"}); //4
				this->types.push_back({'~', 12, 0, "Shallow Salt Water"}); //5
				this->types.push_back({247, 4, 0, "Deep Salt Water"}); //6
				this->types.push_back({'~', 6, 0, "Shallow Fresh Water"}); //7
				this->types.push_back({247, 14, 0, "Deep Fresh Water"}); //8
				this->types.push_back({30, CellColour::DARK_GREY, 0, "Craggy Rocks"}); //9
				this->types.push_back({'^', CellColour::GREY, 0, "Gravel Rock"}); //10
				this->types.push_back({':', CellColour::LIGHT_YELLOW, 0, "Fine Sand"}); //11
				this->types.push_back({247, CellColour::YELLOW, 0, "Wet Sand"}); //12
			}
			
			FloorType FloorTypeList::getType(doublebyte id)
			{
				return this->types[id % this->types.size()];
			}
		}
	}
}
