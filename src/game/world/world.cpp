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
						
						float h = Generation::Perlin::getPerlin(glm::vec4(x, y, 0, 1 * this->seed), -10.0f, 5.0f, 1.0f) * 0.75f;
						float river = 1.0f - std::abs(Generation::Perlin::getPerlin(glm::vec4(x, y, 0, 2 * this->seed), -8.0f, 3.0f, 1.0f, false));
						h -= std::pow(river + 0.15f, 6.0f) * 0.4f;
						
						current.floor_height = (byte)std::min(255.0f, std::max(0.0f, (h + 1.0f) * 128.0f));
						
						current.floor_type = ((rand() % 5) / 4) % 2;
						if (current.floor_height > 200)
							current.floor_type = 1 + (rand() % 2) * 8;
						if (current.floor_height > 230)
							current.floor_type = 9 + rand() % 2;
						if (current.floor_height > 250)
							current.floor_type = 10;
						if (current.floor_height < 170)
							current.floor_type = ((rand() % 7) / 6 + 1 + rand() % 2) % 3;
						if (current.floor_height < 80)
						{
							if (river > 0.8)
								current.floor_type = 2 + ((rand() % 7) / 6 + 1) % 2;
							else
								current.floor_type = 11 + (rand() % 4) / 3;
						}
						if (current.floor_height < 60)
							current.floor_type = 5 + rand() % 2;
						if (river > 0.95f && current.floor_height >= 60 && current.floor_height <= 170)
							current.floor_type = 7 + rand() % 2;
						//if (current.floor_height < 160 && current.floor_height > 150)
							//current.floor_type = 4;
						
						this->cells.push_back(current);
					}
				}
				
				printf("Generated the world.\n");
			}
			
			void World::tick()
			{
				//Tick
			}
			
			Cell* World::getCell(short x, short y)
			{
				return &this->cells[this->height * (x % this->width) + (y % this->height)];
			}
		}
	}
}
