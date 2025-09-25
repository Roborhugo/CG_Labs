#include "interpolation.hpp"

glm::vec3
interpolation::evalLERP(glm::vec3 const& p0, glm::vec3 const& p1, float const x)
{
	// 2.4.2
	// As per Lec 3 - 30
	glm::vec3 p_t = glm::vec2(1.0f, x) * glm::mat2x2(1.0f, -1.0f, 0.0f, 1.0f) * glm::mat3x2(p0.x, p1.x, p0.y, p1.y, p0.z, p1.z);

	return p_t;
}

glm::vec3
interpolation::evalCatmullRom(glm::vec3 const& p0, glm::vec3 const& p1,
                              glm::vec3 const& p2, glm::vec3 const& p3,
                              float const t, float const x)
{
	//2.4.2
	// As per Lec 3 - 46
	glm::vec3 pt = glm::vec4(1, x, pow(x, 2), pow(x, 3))
		* glm::mat4x4(0, -t, 2 * t, -t,	// c1
			1, 0, t - 3, 2 - t,			// c2
			0, t, 3 - 2 * t, t - 2,		// c3
			0, 0, -t, t)				// c4
		* glm::mat3x4(p0.x, p1.x, p2.x, p3.x,	// c1
			p0.y, p1.y, p2.y, p3.y,				// c2
			p0.z, p1.z, p2.z, p3.z);			// c3

	return pt;
}
