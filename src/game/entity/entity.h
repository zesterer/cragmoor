#ifndef CRAGMOOR_GAME_ENTITY_ENTITY_H
#define CRAGMOOR_GAME_ENTITY_ENTITY_H

//----LOCAL----
#include "common/types.h"
#include "world/world.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace Entity
		{
			class Entity
			{
				private:
			  		long time = 0;
			  
					Position position;
					Position velocity;
					
					byte character;
					byte colour;
			  
			  		Position dir;
				public:
					Entity();
					
					virtual void tick(World::World* world);
					virtual void postTick();
					
					virtual void move(int x, int y);
					
					virtual Position getPosition() { return this->position; }
					virtual byte getCharacter() { return this->character; }
					virtual byte getColour() { return this->colour; }
					
					virtual void setPosition(Position position) { this->position = position; }
					virtual void setCharacter(byte character) { this->character = character; }
					virtual void setColour(byte colour) { this->colour = colour; }
			};
		}
	}
}

#endif
