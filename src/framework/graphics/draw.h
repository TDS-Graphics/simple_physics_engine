#pragma once
#include "../math/basic.h"
namespace graphic {    
    inline void draw_circle(glm::vec2 position,float radius,Color color){
        DrawCircle(position.x,position.y, radius , color);
    } 
    inline void draw_point(glm::vec2 position,Color color){
        draw_circle(position, 5, color);
    }
    inline void draw_line(glm::vec2 start,glm::vec2 end,float thick,Color color){
        DrawLineEx(math::to_raylib(start),math::to_raylib(end), thick, color);
    }
}
