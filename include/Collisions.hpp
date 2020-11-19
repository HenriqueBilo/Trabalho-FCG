/* 
    Funcoes de colisao entre objetos 3d usando coordenadas homogêneas

    Referencia: https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection 
*/
#ifndef COLLISIONS_HPP
#define COLLISIONS_HPP

#include <iostream>
#include "AABB.hpp"
#include "Sphere.hpp"
#include <glm/vec4.hpp>


bool Box2BoxCollision(AABB a, AABB b);
bool Box2SphereCollision(AABB box, Sphere sphere);
bool Sphere2SphereCollision(Sphere a, Sphere b);
bool Point2BoxCollision(glm::vec4 point, AABB box);

#endif