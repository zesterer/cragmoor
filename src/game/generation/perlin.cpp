//----LOCAL----
#include "perlin.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace Generation
		{
			float Perlin::getRandom(glm::vec4 pos, bool discrete)
			{
				float v = glm::fract(glm::sin(glm::dot(glm::mod(pos, 4321.0f), glm::vec4(3.1415, 12.9898, 78.233, 5.327)) * (4.5453 * pos.w)) * 3337.3);
				
				switch (discrete)
				{
					case true:
						{
							if (v > 0.5f)
								return 1.0f;
							else
								return 0.0f;
						}
						break;
				
					case false:
						return v;
						break;
				}
			}
			
			float Perlin::mix(float a, float b, float x)
			{
				float x2 = (1 - cos(x * 3.141592f)) / 2;
				return (a * (1 - x2) + b * x2);
			}

			float Perlin::getNoise(glm::vec4 pos, float octave, bool discrete)
			{
				pos.w *= 123456.0;
				
				pos *= glm::pow(2.0, octave);
				glm::vec3 mpos = glm::mod(glm::vec3(pos.x, pos.y, pos.z), 1.0f);
				pos = glm::floor(pos);

				float c000 = Perlin::getRandom(pos + glm::vec4(0.0, 0.0, 0.0, 0.0), discrete);
				float c100 = Perlin::getRandom(pos + glm::vec4(1.0, 0.0, 0.0, 0.0), discrete);
				float c010 = Perlin::getRandom(pos + glm::vec4(0.0, 1.0, 0.0, 0.0), discrete);
				float c110 = Perlin::getRandom(pos + glm::vec4(1.0, 1.0, 0.0, 0.0), discrete);

				float c001 = Perlin::getRandom(pos + glm::vec4(0.0, 0.0, 1.0, 0.0), discrete);
				float c101 = Perlin::getRandom(pos + glm::vec4(1.0, 0.0, 1.0, 0.0), discrete);
				float c011 = Perlin::getRandom(pos + glm::vec4(0.0, 1.0, 1.0, 0.0), discrete);
				float c111 = Perlin::getRandom(pos + glm::vec4(1.0, 1.0, 1.0, 0.0), discrete);

				float eX00 = Perlin::mix(c000, c100, mpos.x);
				float eX10 = Perlin::mix(c010, c110, mpos.x);
				float eX01 = Perlin::mix(c001, c101, mpos.x);
				float eX11 = Perlin::mix(c011, c111, mpos.x);

				float fXX0 = Perlin::mix(eX00, eX10, mpos.y);
				float fXX1 = Perlin::mix(eX01, eX11, mpos.y);

				float value = Perlin::mix(fXX0, fXX1, mpos.z);

				return 2.0 * (value - 0.5);
			}

			float Perlin::getPerlin(glm::vec4 pos, float initial, float octaves, float skip, bool discrete)
			{
				float val = 0.0;

				for (float x = initial; x < initial + octaves; x += skip)
					val += Perlin::getNoise(pos, x + 2.0, discrete) / glm::pow(2.0, x - initial);

				return val;
			}

			glm::vec2 Perlin::getPerlinVec2(glm::vec4 pos, float initial, float octaves, float skip, bool discrete)
			{
				glm::vec2 noise;

				noise.x = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 0.0), initial, octaves, skip, discrete);
				noise.y = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 1.0), initial, octaves, skip, discrete);

				return noise;
			}

			glm::vec3 Perlin::getPerlinVec3(glm::vec4 pos, float initial, float octaves, float skip, bool discrete)
			{
				glm::vec3 noise;

				noise.x = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 0.0), initial, octaves, skip, discrete);
				noise.y = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 1.0), initial, octaves, skip, discrete);
				noise.z = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 2.0), initial, octaves, skip, discrete);

				return noise;
			}
		}
	}
}
