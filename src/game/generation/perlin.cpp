//----LOCAL----
#include "perlin.h"

namespace Cragmoor
{
	namespace Game
	{
		namespace Generation
		{
			float Perlin::getRandom(glm::vec4 pos)
		{
			float val = glm::fract(glm::sin(glm::dot(pos, glm::vec4(3.1415, 12.9898, 78.233, 5.327)))* 43758.5453);
			return val;
		}

		float Perlin::getNoise(glm::vec4 pos, float octave)
		{
			pos *= glm::pow(2.0, octave);
			glm::vec3 mpos = glm::mod(glm::vec3(pos.x, pos.y, pos.z), 1.0f);
			pos = glm::floor(pos);

			float c000 = Perlin::getRandom(pos + glm::vec4(0.0, 0.0, 0.0, 0.0));
			float c100 = Perlin::getRandom(pos + glm::vec4(1.0, 0.0, 0.0, 0.0));
			float c010 = Perlin::getRandom(pos + glm::vec4(0.0, 1.0, 0.0, 0.0));
			float c110 = Perlin::getRandom(pos + glm::vec4(1.0, 1.0, 0.0, 0.0));

			float c001 = Perlin::getRandom(pos + glm::vec4(0.0, 0.0, 1.0, 0.0));
			float c101 = Perlin::getRandom(pos + glm::vec4(1.0, 0.0, 1.0, 0.0));
			float c011 = Perlin::getRandom(pos + glm::vec4(0.0, 1.0, 1.0, 0.0));
			float c111 = Perlin::getRandom(pos + glm::vec4(1.0, 1.0, 1.0, 0.0));

			float eX00 = glm::mix(c000, c100, mpos.x);
			float eX10 = glm::mix(c010, c110, mpos.x);
			float eX01 = glm::mix(c001, c101, mpos.x);
			float eX11 = glm::mix(c011, c111, mpos.x);

			float fXX0 = glm::mix(eX00, eX10, mpos.y);
			float fXX1 = glm::mix(eX01, eX11, mpos.y);

			float value = glm::mix(fXX0, fXX1, mpos.z);

			return 2.0 * (value - 0.5);
		}

		float Perlin::getPerlin(glm::vec4 pos, float initial, float octaves, float skip)
		{
			float val = 0.0;

			for (float x = initial; x < initial + octaves; x += skip)
				val += Perlin::getNoise(pos, x + 2.0) / glm::pow(2.0, x - initial);

			return val;
		}

		glm::vec2 Perlin::getPerlinVec2(glm::vec4 pos, float initial, float octaves, float skip)
		{
			glm::vec2 noise;

			noise.x = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 0.0), initial, octaves, skip);
			noise.y = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 1.0), initial, octaves, skip);

			return noise;
		}

		glm::vec3 Perlin::getPerlinVec3(glm::vec4 pos, float initial, float octaves, float skip)
		{
			glm::vec3 noise;

			noise.x = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 0.0), initial, octaves, skip);
			noise.y = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 1.0), initial, octaves, skip);
			noise.z = Perlin::getPerlin(pos + glm::vec4(0.0, 0.0, 0.0, 2.0), initial, octaves, skip);

			return noise;
		}
		}
	}
}