#version 330 core

// Atributos de vértice recebidos como entrada ("in") pelo Vertex Shader.
// Veja a função BuildTrianglesAndAddToVirtualScene() em "main.cpp".
layout (location = 0) in vec4 model_coefficients;
layout (location = 1) in vec4 normal_coefficients;
layout (location = 2) in vec2 texture_coefficients;

// Matrizes computadas no código C++ e enviadas para a GPU
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// Parâmetros da axis-aligned bounding box (AABB) do modelo
uniform vec4 bbox_min;
uniform vec4 bbox_max;

#define COW 4

uniform int object_id;

out vec4 position_world;
out vec4 position_model;
out vec4 normal;
out vec2 texcoords;
out vec3 color_cow;

uniform sampler2D TextureImage3;

// Constantes
#define M_PI   3.14159265358979323846
#define M_PI_2 1.57079632679489661923

void main()
{
    gl_Position = projection * view * model * model_coefficients;
    position_world = model * model_coefficients;
    position_model = model_coefficients;
    normal = inverse(transpose(model)) * normal_coefficients;
    normal.w = 0.0;
    texcoords = texture_coefficients;

    if (object_id == COW){
         // Coordenadas de textura U e V
        float U = 0.0;
        float V = 0.0;

        vec4 bbox_center = (bbox_min + bbox_max) / 2.0;

        vec4 formula_p_linha = bbox_center + normalize(position_model - bbox_center);
        vec4 p_textura = formula_p_linha - bbox_center;

        //Obtemos os ângulos
        float teta = atan(p_textura.x, p_textura.z);
        float phi = asin(p_textura.y);

        U = (teta + M_PI) / (2*M_PI);
        V = (phi + M_PI_2) / M_PI;

        vec4 origin = vec4(0.0, 0.0, 0.0, 1.0);
        vec4 camera_position = inverse(view) * origin;

        vec4 p = position_world;
        vec4 n = normalize(normal);
        vec4 v = normalize(camera_position - p);
        vec4 l = v;
        vec4 h = normalize(v + l);

        vec3 Kd =  texture(TextureImage3, vec2(U,V)).rgb;
        vec3 Ks = vec3(1.0, 0.5, 0.35);
        vec3 Ka = vec3(0.0, 0.0, 0.0);
        float q = 20.0;

        vec3 I = vec3(1.0, 1.0, 1.0);
        vec3 Ia = vec3(0.2, 0.2, 0.2);
        vec3 lambert_diffuse_term = Kd*I*max(0, dot(n, l));
        vec3 ambient_term = Ka*Ia;
        vec3 phong_specular_term  = Ks * I * pow(max(0, dot(n, h)), q);

        color_cow = lambert_diffuse_term + ambient_term + phong_specular_term;
        color_cow = pow(color_cow, vec3(1.0,1.0,1.0)/2.2);
    }
}
