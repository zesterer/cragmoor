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
				Position view_focus = Position(0, 0);
				
				World::World world;
				std::vector<Entity::Entity*> entities;
			public:
				Game();
				
				void tick();
				
				World::World* getWorld();
				Position getViewFocus() { return this->view_focus; }
				void setViewFocus(Position view_focus) { this->view_focus = view_focus; }
				
				Entity::Entity* getEntity(int id) { return this->entities[id]; }
				int getEntityCount() { return (int)this->entities.size(); }
		};
	}
}

#endif
