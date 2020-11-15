#include "Sphere.hpp"

Sphere::Sphere()
{
    this->center = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    this->radius = 1.0f;
}

Sphere::Sphere( glm::vec4 c, float r )
{
    this->center = c;
    this->radius = r;
}