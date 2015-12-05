//----STANDARD----
#include "stdio.h"
#include "string"

//----LOCAL----
#include "world.h"
#include "generation/perlin.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace World
		{
			World::World()
			{
				//Create the world
				this->generate();
			}
			
			void World::clear()
			{
				this->cells.clear();
			}
			
			void World::generate()
			{
				this->clear();
				this->cells.reserve(this->width * this->height);
				
				for (doublebyte x = 0; x < this->width; x ++)
				{
					for (doublebyte y = 0; y < this->height; y ++)
					{
						Cell current = Cell();
						
						current.height = (byte)std::min(255.0f, std::max(0.0f, (Generation::Perlin::getPerlin(glm::vec4(x, y, 0, 0), -6.5f, 3.0f, 1.0f) + 1.0f) * 128.0f));
						
						this->cells.push_back(current);
					}
				}
				
				printf("Generated the world.\n");
			}
			
			Cell* World::getCell(short x, short y)
			{
				return &this->cells[this->height * x + y];
			}
		}
	}
}
