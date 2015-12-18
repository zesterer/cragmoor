//----STANDARD----
#include "stdlib.h"

//----LOCAL----
#include "entity.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace Entity
		{
			Entity::Entity()
			{
				//Constructor
			}
			
			void Entity::tick(World::World* world)
			{
				if (rand() % 30 == 0)
					this->dir = Position(rand() % 3 - 1, rand() % 3 - 1);
				
				if (this->time % 1 == 0)
					this->move(this->dir.x, this->dir.y);
				
				//Limit position
				this->position %= Position(world->getWidth(), world->getHeight());
			}
			
			void Entity::postTick()
			{
				this->position += this->velocity;
				this->velocity = Position(0, 0);
				
				this->time ++;
			}
			
			void Entity::move(int x, int y)
			{
				this->velocity.x += x;
				this->velocity.y += y;
			}
		}
	}
}
