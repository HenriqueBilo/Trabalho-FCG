#include "Player.hpp"
#include "Collisions.hpp"
#include <iostream>

// Constructors
Player::Player(){ 
    position = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    sphere_collider = Sphere();
    movement_speed = 0.0f;
}

Player::Player(glm::vec4 pos, float radius, float speed){
    position = pos;
    sphere_collider = Sphere(pos,radius);
    movement_speed = speed;
}

// Other methods
void Player::move(glm::vec4 direction, std::vector<AABB> box_colliders){
    glm::vec4 next_pos = position + movement_speed * direction;
    sphere_collider.center = next_pos;
    
    bool collision = false;

    for (auto box : box_colliders) {
         if ( Box2SphereCollision(box,sphere_collider) ){
             collision = true;
             //std::cout << "Player colidiu com bbox min(" << box.min.x << ", " << box.min.y << ", " << box.min.z << ") max(" << box.max.x << ", " << box.max.y << ", " << box.max.z << ")" << std::endl;
             break;
         }
        //std::cout << "Iterando sobre AABBs";
    }

    if (collision){
        sphere_collider.center = position;

    }
    else {
        position = next_pos;
    }
}