#ifndef CRAGMOOR_GAME_GAME_H
#define CRAGMOOR_GAME_GAME_H

//----LOCAL----
#include "world/world.h"

namespace Cragmoor
{
	namespace Game
	{
		class Game
		{
			private:
				World::World world;
			public:
				Game();
				
				World::World* getWorld();
		};
	}
}

#endif
