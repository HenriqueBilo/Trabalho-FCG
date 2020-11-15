/* 
    Funcoes de colisao entre objetos 3d usando coordenadas homogêneas

    Referencia: https://developer.mozilla.org/en-US/docs/Games/Techniques/3D_collision_detection 
*/
#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "AABB.hpp"
#include "Sphere.hpp"
#include <glm/vec4.hpp>
#include <cmath>

using namespace std;

bool Box2BoxCollision(AABB a, AABB b){
    return
        (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
        (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
        (a.min.z <= b.max.z && a.max.z >= b.min.z);
}
bool Box2SphereCollision(AABB box, Sphere sphere){
    float x = max(box.min.x, min(sphere.center.x, box.max.x));
    float y = max(box.min.y, min(sphere.center.y, box.max.y));
    float z = max(box.min.z, min(sphere.center.z, box.max.z));

    float distance = sqrt(
                            (x - sphere.center.x)
                            +
                            (y - sphere.center.y)
                            +
                            (z - sphere.center.z)
    ); 

    return distance < sphere.radius;
}

bool Sphere2SphereCollision(Sphere a, Sphere b){
    float distance = sqrt(
                            (b.center.x - a.center.x)
                            +
                            (b.center.y - a.center.y)
                            +
                            (b.center.z - a.center.z)
    ); 

    return distance < (a.radius + b.radius);
}

#endif