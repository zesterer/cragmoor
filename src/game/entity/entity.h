#ifndef CRAGMOOR_GAME_ENTITY_ENTITY_H
#define CRAGMOOR_GAME_ENTITY_ENTITY_H

//----LOCAL----
#include "common/types.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace Entity
		{
			class Entity
			{
				private:
					Position pos;
					byte character;
					byte colour;
				public:
					Entity();
					
					virtual Position getPosition() { return this->pos; }
					virtual byte getCharacter() { return this->character; }
					virtual byte getColour() { return this->colour; }
					
					virtual void setPosition(Position pos) { this->pos = pos; }
					virtual void setCharacter(byte character) { this->character = character; }
					virtual void setColour(byte colour) { this->colour = colour; }
			};
		}
	}
}

#endif
