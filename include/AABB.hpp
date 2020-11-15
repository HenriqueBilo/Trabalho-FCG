// Axis-aligned Bounding Box Class

#ifndef AABB_HPP
#define AABB_HPP

#include <iostream>
#include <glm/vec4.hpp>

class AABB
{
public:
	glm::vec4 min;
	glm::vec4 max;

	// Constructor
	AABB();
    AABB(glm::vec4 c, float w, float h, float d)
	{
		min = c - glm::vec4(w/2.0f,h/2.0f,d/2.0f,0.0f);
		max = c + glm::vec4(w/2.0f,h/2.0f,d/2.0f,0.0f);
	}
};

#endif