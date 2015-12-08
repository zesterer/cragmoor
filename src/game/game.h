#ifndef CRAGMOOR_GAME_GAME_H
#define CRAGMOOR_GAME_GAME_H

//----LOCAL----
#include "world/world.h"
#include "entity/entity.h"

namespace Cragmoor
{
	namespace Game
	{
		class Game
		{
			private:
				World::World world;
				std::vector<Entity::Entity*> entities;
			public:
				Game();
				
				World::World* getWorld();
		};
	}
}

#endif
