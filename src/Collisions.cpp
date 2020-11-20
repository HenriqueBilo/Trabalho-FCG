#include "Collisions.hpp"
#include <cmath>

bool Box2BoxCollision(AABB a, AABB b){
    return
        (a.min.x <= b.max.x && a.max.x >= b.min.x) &&
        (a.min.y <= b.max.y && a.max.y >= b.min.y) &&
        (a.min.z <= b.max.z && a.max.z >= b.min.z);
}
bool Box2SphereCollision(AABB box, Sphere sphere){
    float x = std::max(box.min.x, std::min(sphere.center.x, box.max.x));
    float y = std::max(box.min.y, std::min(sphere.center.y, box.max.y));
    float z = std::max(box.min.z, std::min(sphere.center.z, box.max.z));

    float distance = std::sqrt(
                            (x - sphere.center.x) * (x - sphere.center.x)
                            +
                            (y - sphere.center.y) * (y - sphere.center.y)
                            +
                            (z - sphere.center.z) * (z - sphere.center.z)
    ); 

    return distance < sphere.radius;
}

bool Sphere2SphereCollision(Sphere a, Sphere b){
    float distance = std::sqrt(
                            (b.center.x - a.center.x) * (b.center.x - a.center.x)
                            +
                            (b.center.y - a.center.y) * (b.center.y - a.center.y)
                            +
                            (b.center.z - a.center.z) * (b.center.z - a.center.z)
    ); 

    return distance < (a.radius + b.radius);
}

bool Point2BoxCollision(glm::vec4 point, AABB box){
    return
        (point.x <= box.max.x && point.x >= box.min.x) &&
        (point.y <= box.max.y && point.y >= box.min.y) &&
        (point.z <= box.max.z && point.z >= box.min.z);
}