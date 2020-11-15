// Sphere Object Class

#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <iostream>
#include <glm/vec4.hpp>

class Sphere
{
public:
	glm::vec4 center;
	float radius;

	// Constructors
	Sphere();
    Sphere(glm::vec4 c, float r);
};

#endif