#pragma once
#include <glm/glm.hpp>
#include <raylib.h>
namespace math{
    inline glm::vec2 to_glm(Vector2 vec2){
        return glm::vec2(vec2.x,vec2.y);
    }

    inline glm::vec3 to_glm(Vector3 vec3){
        return glm::vec3(vec3.x,vec3.y,vec3.z);
    }
    
    inline Vector2 to_raylib(glm::vec2 vec2){
        return Vector2{vec2.x,vec2.y};
    }
}
