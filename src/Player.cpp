#include "Player.hpp"

// Constructors
Player::Player(){ 
    this->position = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    this->sphere_collider = Sphere();
    this->movement_speed = 0.0f;
}

Player::Player(glm::vec4 pos, float radius, float speed){
    this->position = pos;
    this->sphere_collider = Sphere(pos,radius);
    this->movement_speed = speed;
}

// Other methods
void Player::move(glm::vec4 direction){
    glm::vec4 next_pos = position + movement_speed * direction;
    this->position = next_pos;
}