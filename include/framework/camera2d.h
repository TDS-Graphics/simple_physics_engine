#pragma once

#include <algorithm>
#include <cmath>
#include <raylib.h>
#include <glm/glm.hpp>
#include "input.h"
#include "math/basic.h"

class Camera2d {
public:
    explicit Camera2d(glm::vec2 target = glm::vec2(0.0f), float zoom = 1.0f) {
        camera_.offset = Vector2{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
        camera_.target = math::to_raylib(target);
        camera_.rotation = 0.0f;
        camera_.zoom = zoom;
    }

    void update(float dt) {
        float wheel = input::mouse_wheel_delta();
        if (wheel != 0.0f)
            zoom_at(input::mouse_position(), std::pow(1.1f, wheel));

        if (input::is_mouse_button_repeated(MOUSE_BUTTON_RIGHT))
            pan(input::mouse_delta());

        glm::vec2 dir(0.0f);
        if (input::is_key_repeated(KEY_W) || input::is_key_repeated(KEY_UP))    dir.y -= 1.0f;
        if (input::is_key_repeated(KEY_S) || input::is_key_repeated(KEY_DOWN))  dir.y += 1.0f;
        if (input::is_key_repeated(KEY_A) || input::is_key_repeated(KEY_LEFT))  dir.x -= 1.0f;
        if (input::is_key_repeated(KEY_D) || input::is_key_repeated(KEY_RIGHT)) dir.x += 1.0f;
        if (dir.x != 0.0f || dir.y != 0.0f)
            move(glm::normalize(dir) * (move_speed_ * dt));
    }

    void set_target(glm::vec2 target) { camera_.target = math::to_raylib(target); }
    glm::vec2 target() const { return math::to_glm(camera_.target); }

    void set_offset(glm::vec2 offset) { camera_.offset = math::to_raylib(offset); }
    glm::vec2 offset() const { return math::to_glm(camera_.offset); }

    void set_rotation(float degrees) { camera_.rotation = degrees; }
    float rotation() const { return camera_.rotation; }

    void set_zoom(float zoom) { camera_.zoom = std::clamp(zoom, min_zoom_, max_zoom_); }
    float zoom() const { return camera_.zoom; }

    void set_move_speed(float speed) { move_speed_ = speed; }

    void move(glm::vec2 delta) {
        camera_.target.x += delta.x;
        camera_.target.y += delta.y;
    }

    void pan(glm::vec2 screen_delta) {
        move(-screen_delta / camera_.zoom);
    }

    void zoom_by(float factor) {
        set_zoom(camera_.zoom * factor);
    }

    void zoom_at(glm::vec2 screen_pos, float factor) {
        glm::vec2 before = screen_to_world(screen_pos);
        set_zoom(camera_.zoom * factor);
        glm::vec2 after = screen_to_world(screen_pos);
        move(before - after);
    }

    glm::vec2 world_to_screen(glm::vec2 position) const {
        return math::to_glm(GetWorldToScreen2D(math::to_raylib(position), camera_));
    }

    glm::vec2 screen_to_world(glm::vec2 position) const {
        return math::to_glm(GetScreenToWorld2D(math::to_raylib(position), camera_));
    }

    void begin() const { BeginMode2D(camera_); }
    void end() const { EndMode2D(); }

private:
    ::Camera2D camera_;
    float move_speed_ = 400.0f;
    float min_zoom_ = 0.1f;
    float max_zoom_ = 10.0f;
};
