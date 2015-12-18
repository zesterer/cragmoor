#ifndef CRAGMOOR_GAME_GENERATION_PERLIN_H
#define CRAGMOOR_GAME_GENERATION_PERLIN_H

//----LIBRARY----
#include "glm/glm.hpp"

//----LOCAL----
#include "common/types.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace Generation
		{
			class Perlin
			{
				private:
				public:
					static float mix(float a, float b, float x);
					
					static float getRandom(glm::vec4 pos, bool discrete = false);

					static float getNoise(glm::vec4 pos, float octave, bool discrete = false);

					static float getPerlin(glm::vec4 pos, float initial, float octaves, float skip, bool discrete = false);

					static glm::vec2 getPerlinVec2(glm::vec4 pos, float initial, float octaves, float skip, bool discrete = false);
					static glm::vec3 getPerlinVec3(glm::vec4 pos, float initial, float octaves, float skip, bool discrete = false);
			};
		}
	}
}

#endif
