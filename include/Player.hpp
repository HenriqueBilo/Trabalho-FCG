// Player Object Class

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Sphere.hpp"
#include "AABB.hpp"
#include <glm/vec4.hpp>
#include <vector>
#include <iostream>

class Player
{
public:
    //Attributes
    glm::vec4 position;
    Sphere sphere_collider;
    float movement_speed;

    // Constructors
    Player();
    Player(glm::vec4 pos, float radius, float speed);
    
    // Other methods
    void move(glm::vec4 direction, std::vector<AABB> box_colliders);
};

#endif