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
			
			void Entity::tick()
			{
				this->move(rand() % 3 - 1, rand() % 3 - 1);
			}
			
			void Entity::move(int x, int y)
			{
				this->pos.x += x;
				this->pos.y += y;
			}
		}
	}
}
