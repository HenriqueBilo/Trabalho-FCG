// Wall Object Class

#ifndef WALL_HPP
#define WALL_HPP

#include <iostream>
#include <glm/vec4.hpp>
#include "AABB.hpp"

class Wall
{
public:
    glm::vec4 center;
    glm:: vec4 tamanho;
    AABB box_collider;
    bool perpendicular;

    // Constructor
    Wall();
    Wall(glm::vec4 pos, float width, float heigth, float depth, bool is_perpendicular);
    Wall(glm::vec4 pos, float width, float heigth, float depth, bool is_perpendicular, glm::vec4 tamanhoParede);

};

#endif
