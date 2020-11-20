// Key Object Class

#ifndef KEY_HPP
#define KEY_HPP

#include <iostream>
#include <glm/vec4.hpp>
#include "Sphere.hpp"

class Key
{
public:
    glm::vec4 center;
    Sphere sphere_collider;
    bool collected;

    // Constructor
    Key();
    Key(glm::vec4 pos);
};

#endif
