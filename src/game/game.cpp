//----LOCAL----
#include "game.h"

namespace Cragmoor
{
	namespace Game
	{
		Game::Game()
		{
			//Constructor
			this->entities.push_back(new Entity::Entity());
			this->entities[0]->setCharacter(2);
			this->entities[0]->setColour(1);
			this->entities[0]->setPosition(Position(32, 32));
		}
		
		World::World* Game::getWorld()
		{
			return &this->world;
		}
	}
}
