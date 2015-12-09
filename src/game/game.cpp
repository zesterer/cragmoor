//----LOCAL----
#include "game.h"

namespace Cragmoor
{
	namespace Game
	{
		Game::Game()
		{
			//Constructor
			for (int i = 0; i < 4096; i ++)
			{
				this->entities.push_back(new Entity::Entity());
				this->entities[this->entities.size() - 1]->setCharacter(1 + rand() % 2);
				this->entities[this->entities.size() - 1]->setColour(1 + rand() % 6);
				this->entities[this->entities.size() - 1]->setPosition(Position(rand() % 1024, rand() % 1024));
			}
		}
		
		void Game::tick()
		{
			this->world.tick();
			
			for (unsigned int i = 0; i < this->getEntityCount(); i ++)
			{
				this->getEntity(i)->tick();
			}
		}
		
		World::World* Game::getWorld()
		{
			return &this->world;
		}
	}
}
