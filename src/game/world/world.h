#ifndef CRAGMOOR_GAME_WORLD_H
#define CRAGMOOR_GAME_WORLD_H

//----STANDARD----
#include "vector"

//----LOCAL----
#include "common/types.h"
#include "floortypelist.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace World
		{
			struct Cell
			{
				byte floor_height = 128;
				byte block_height = 0;
				
				doublebyte block_type = 0;
				doublebyte floor_type = 0;
				
				byte data = 0;
			};
			
			class World
			{
				private:
					std::vector<Cell> cells;
					int width = 1024;
					int height = 1024;
					octbyte seed = 142857;
				public:
					FloorTypeList floor_types;
					
					World();
					void clear();
					void generate();
					
					Cell* getCell(short i, short j);
			};
		}
	}
}

#endif
