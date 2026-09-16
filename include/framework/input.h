#pragma once
#include <raylib.h>
#include "math/basic.h"
namespace input{
    inline bool is_key_pressed(int key){
        return IsKeyPressed(key);
    }

    inline bool is_key_released(int key){
        return IsKeyReleased(key);
    }

    inline bool is_key_repeated(int key){
        return IsKeyDown(key);
    }
    
    inline bool is_mouse_button_pressed(int button){
        return IsMouseButtonPressed(button);
    }

    inline bool is_mouse_button_released(int button){
        return IsMouseButtonReleased(button);
    }

    inline bool is_mouse_button_repeated(int button){
        return IsMouseButtonDown(button);
    }

    inline glm::vec2 mouse_position(){
        Vector2 pos = GetMousePosition();
        return math::to_glm(pos);
    }

    inline glm::vec2 mouse_delta(){
        Vector2 delta = GetMouseDelta();
        return math::to_glm(delta);
    }

    inline float mouse_wheel_delta(){
        return GetMouseWheelMove();
    }
}