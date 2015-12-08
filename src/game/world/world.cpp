//----STANDARD----
#include "stdio.h"
#include "string"
#include "stdlib.h"

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
				
				std::srand(this->seed);
				
				for (doublebyte x = 0; x < this->width; x ++)
				{
					for (doublebyte y = 0; y < this->height; y ++)
					{
						Cell current = Cell();
						
						current.floor_height = (byte)std::min(255.0f, std::max(0.0f, (Generation::Perlin::getPerlin(glm::vec4(x, y, 0, 0), -6.5f, 4.0f, 1.0f) + 1.0f) * 128.0f));
						
						current.floor_type = ((rand() % 5) / 4) % 2;
						if (current.floor_height < 170)
							current.floor_type = ((rand() % 7) / 6 + 1 + rand() % 2) % 3;
						if (current.floor_height < 80)
							current.floor_type = 2 + ((rand() % 7) / 6 + 1) % 2;
						if (current.floor_height < 60)
							current.floor_type = 5 + (rand()) % 4;
						//if (current.floor_height < 160 && current.floor_height > 150)
							//current.floor_type = 4;
						
						this->cells.push_back(current);
					}
				}
				
				printf("Generated the world.\n");
			}
			
			Cell* World::getCell(short x, short y)
			{
				return &this->cells[this->height * (x % this->width) + (y % this->height)];
			}
		}
	}
}
