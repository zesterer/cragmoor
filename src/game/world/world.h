#ifndef CRAGMOOR_GAME_WORLD_H
#define CRAGMOOR_GAME_WORLD_H

//----STANDARD----
#include "vector"

//----LOCAL----
#include "common/types.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace World
		{
			struct Cell
			{
				byte height = 128;
				doublebyte material = 0;
				byte data = 0; //0(1) = filled
				quadbyte object_id = 0;
			};
			
			class World
			{
				private:
					std::vector<Cell> cells;
					int width = 512;
					int height = 512;
					octbyte seed = 142857;
				public:
					World();
					void clear();
					void generate();
					
					Cell* getCell(short i, short j);
			};
		}
	}
}

#endif
