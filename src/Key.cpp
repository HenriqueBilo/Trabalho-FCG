#include "Key.hpp"

Key::Key(){
    center = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    sphere_collider = Sphere();
    collected = false;
}

Key::Key(glm::vec4 pos){
    center = pos;
    sphere_collider = Sphere(pos, 1.0f);
    collected = false;
}
