#include "../include/Matrix.hpp"

#include <iostream>

using namespace vmath;

//eg. defining own vector types
using vec2_16 = _vec2<int16_t>;
using vecFunny = _vec2<_vec2<_vec2<char>>>;

int main() {
    std::cout << "Hello World!" << std::endl;
    std::cout << " -- "<< std::endl;

    //  eg. normalizing coordinates of a point 
    //  pos is type _vec<float>, window is type _vec<uint32_t>
    vec2 pos(5, 270);
    uvec2 window(1000, 100);
    vec2 posNorm = pos / window;
    posNorm += 10;
    std::cout << "normalized pos" << posNorm << std::endl;
    std::cout << " -- "<< std::endl;

    //  eg. using scalars with vectors
    //  cube is initialized with scalar 10, then incremented again by 10.
    ivec3 cube(10);
    int volume = cube.x * cube.y * cube.z;
    std::cout << "Cube " << cube << " has volume " << volume << std::endl;
    cube += 10;
    volume = cube.x * cube.y * cube.z;
    std::cout << "Cube " << cube << " has volume " << volume << std::endl;
    std::cout << " -- "<< std::endl;

    //  eg. using _vec3<float>'s to calculate simple lighting.
    //  vec4 is used to store color. (RGBA)
    vec3 hitPos(20, 30, 15);
    vec3 normal(0, 1, 0);
    vec3 lightPos(0, 10, -2);
    vec3 lightDir = normalize(hitPos - lightPos);

    vec3 rgb(0.5f, 1.0f, 0.25f);
    rgb *= dot(normal, lightDir);

    vec4 outColor(rgb.x, rgb.y, rgb.z, 1.0f);
    std::cout << "color: " << outColor << std::endl;
    std::cout << " -- "<< std::endl;

    //  eg. using matrices to project a 3D point
    vec4 point(1, 1, -2, 1);
    mat4 model_world = vmath::modelToWorld(vec3(0, 0, 0));
    mat4 world_view = vmath::worldToView(vec3(0, 0, 0), 0, 0);
    mat4 view_proj = vmath::viewToProj<float>(90, 1, 0.1f, 100);

    mat4 total = model_world * world_view * view_proj;
    std::cout << "model " << point * model_world << std::endl;
    std::cout << "view " << world_view << std::endl;
    std::cout << "proj " << view_proj << std::endl;
    std::cout << "total mat4 " << total<< std::endl;
    std::cout << "projected point: " << point * view_proj << std::endl;
    std::cout << " -- "<< std::endl;
}