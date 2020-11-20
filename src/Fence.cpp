#include "Fence.hpp"

Fence::Fence(){
    center = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    box_collider = AABB();
    perpendicular = false;
}

Fence::Fence(glm::vec4 pos, float width, float heigth, float depth, bool is_perpendicular){
    center = pos;

    // correcao para o ponto ficar no centro do objeto, ao inves de na parte de baixo
    center.y += heigth/2.0f;

    perpendicular = is_perpendicular;
    // quando a parede esta perpendicular ao eixo x, devemos trocar largura por profundidade
    if (perpendicular){
        box_collider = AABB(center, depth, heigth, width);
    }
    else {
        box_collider = AABB(center, width, heigth, depth);
    }
}
