// Wall Object Class

#ifndef WALL_HPP
#define WALL_HPP

#include <iostream>
#include <glm/vec4.hpp>
#include "AABB.hpp"

class Wall
{
public:
    glm::vec4 position;
    AABB box_collider;

    // Constructor
    Wall(glm::vec4 pos, float width, float heigth, float depth, bool is_perpendicular)
    {
        position = pos;

        if (is_perpendicular){
            box_collider = AABB(pos, width, heigth, depth);
        }
        else {
            box_collider = AABB(pos, depth, heigth, width);
        }
    }

};

#endif