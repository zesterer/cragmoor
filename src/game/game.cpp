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
			
			this->entity_focus = this->entities[0];
		}
		
		void Game::tick()
		{	
			this->world.tick();
			
			//Tick the entities
			for (unsigned int i = 0; i < this->getEntityCount(); i ++)
			{
				this->getEntity(i)->tick(&this->world);
			}
			
			//PostTick the entities
			for (unsigned int i = 0; i < this->getEntityCount(); i ++)
			{
				this->getEntity(i)->postTick();
			}
			
			//Apply the game state to frontend stuff
			if (this->entity_focus != nullptr)
				this->setViewFocus(this->entity_focus->getPosition());
			this->makeViewFocusSane();
		}
		
		World::World* Game::getWorld()
		{
			return &this->world;
		}
		
		void Game::setViewFocus(Position view_focus)
		{
			this->view_focus = view_focus;
			this->makeViewFocusSane();
		}
		
		void Game::makeViewFocusSane()
		{
			Position focus = this->view_focus;
			focus.x = std::max(0, std::min(this->world.getWidth(), focus.x));
			focus.y = std::max(0, std::min(this->world.getHeight(), focus.y));
			this->view_focus = focus;
		}
	}
}
