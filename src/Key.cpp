#include "Key.hpp"

Key::Key(){
    center = glm::vec4(0.0f,0.0f,0.0f,1.0f);
    sphere_collider = Sphere();
}

Key::Key(glm::vec4 pos){
    //center = pos;

    // correcao para o ponto ficar no centro do objeto, ao inves de na parte de baixo
    //center.y += heigth/2.0f;

    /*perpendicular = is_perpendicular;
    // quando a parede esta perpendicular ao eixo x, devemos trocar largura por profundidade
    if (perpendicular){
        sphere_collider = AABB(center, depth, heigth, width);
    }
    else {
        sphere_collider = AABB(center, width, heigth, depth);
    }*/
}
