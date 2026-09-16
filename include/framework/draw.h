#pragma once
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include "math/basic.h"


namespace graphic {    
    enum class Colors{
        green,
        red,
        grey,
        blue,
        black
    }; 

    inline Color to_raylib(Colors color){
        switch(color){
            case Colors::green:
                return (Color){128, 230, 128, 185};
            case Colors::red:
                return (Color){230, 179, 179, 185};
            case Colors::grey:
                return (Color){153, 153, 153, 185};
            case Colors::blue:
                return (Color){128, 179, 230, 185};
            case Colors::black:
                return (Color){0, 0, 0, 255};
        }
    }
    inline void draw_text(glm::vec2 position, const std::string& text, int font_size, Colors color){
        DrawText(text.c_str(), (int)position.x, (int)position.y, font_size, to_raylib(color));
    }

    inline int circle_segments(float radius, float error = 0.25f){
        if (radius <= 0.0f) return 36;
        float th = acosf(2.0f * powf(1.0f - error / radius, 2.0f) - 1.0f);
        int segments = (int)ceilf((2.0f * PI) / th);
        return std::clamp(segments, 36, 256);
    }

    inline void draw_circle(glm::vec2 position, float radius, graphic::Colors color, graphic::Colors line_color = graphic::Colors::black){
        Vector2 center = math::to_raylib(position);
        int segments = circle_segments(radius);
        DrawCircleSector(center, radius, 0.0f, 360.0f, segments, to_raylib(color));
        DrawRing(center, std::max(radius - 1.0f, 0.0f), radius, 0.0f, 360.0f, segments, to_raylib(line_color));
    } 

    inline void draw_point(glm::vec2 position,graphic::Colors color){
        draw_circle(position, 3, color);
    }

    inline void draw_line(glm::vec2 start,glm::vec2 end,float thick,graphic::Colors color){
        DrawLineEx(math::to_raylib(start),math::to_raylib(end), thick, to_raylib(color));
    }

    inline void draw_polygon(const std::vector<glm::vec2>& points, graphic::Colors color, graphic::Colors line_color = graphic::Colors::black){
        int n = (int)points.size();
        if (n < 3) return;

        float area = 0.0f;
        for (int i = 0; i < n; ++i){
            const glm::vec2& a = points[i];
            const glm::vec2& b = points[(i + 1) % n];
            area += a.x * b.y - b.x * a.y;
        }

        std::vector<Vector2> raylib_points;
        raylib_points.reserve(n + 1);
        for (int i = 0; i < n; ++i)
            raylib_points.push_back(math::to_raylib(area > 0.0f ? points[n - 1 - i] : points[i]));
        raylib_points.push_back(raylib_points.front());    // close the outline

        DrawTriangleFan(raylib_points.data(), n, to_raylib(color));
        DrawLineStrip(raylib_points.data(), n + 1, to_raylib(line_color));
    }

    inline void draw_rectangle(glm::vec2 position, glm::vec2 size, graphic::Colors color, graphic::Colors line_color = graphic::Colors::black){
        DrawRectangleV(math::to_raylib(position), math::to_raylib(size), to_raylib(color));
        DrawRectangleLinesEx((Rectangle){position.x, position.y, size.x, size.y}, 1.0f, to_raylib(line_color));
    }
}
