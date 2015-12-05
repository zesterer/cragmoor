//----LOCAL----
#include "game.h"

namespace Cragmoor
{
	namespace Game
	{
		Game::Game()
		{
			//Constructor
		}
		
		World::World* Game::getWorld()
		{
			return &this->world;
		}
	}
}
