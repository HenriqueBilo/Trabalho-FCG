// Fence Object Class

#ifndef FENCE_HPP
#define FENCE_HPP

#include <iostream>
#include <glm/vec4.hpp>
#include "AABB.hpp"

class Fence
{
public:
    glm::vec4 center;
    AABB box_collider;
    bool perpendicular;

    // Constructor
    Fence();
    Fence(glm::vec4 pos, float width, float heigth, float depth, bool is_perpendicular);
};

#endif
