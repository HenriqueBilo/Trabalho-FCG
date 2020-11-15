#include "Sphere.hpp"

Sphere::Sphere()
{
    center = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    radius = 1.0f;
}

Sphere::Sphere( glm::vec4 c, float r )
{
    center = c;
    radius = r;
}