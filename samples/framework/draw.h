#pragma once
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <glm/glm.hpp>
#include "math/basic.h"


namespace graphic {    
    namespace Colors{
        inline const glm::vec4 green{128.0f / 255.0f, 230.0f / 255.0f, 128.0f / 255.0f, 185.0f / 255.0f};
        inline const glm::vec4 red  {230.0f / 255.0f, 179.0f / 255.0f, 179.0f / 255.0f, 185.0f / 255.0f};
        inline const glm::vec4 grey {153.0f / 255.0f, 153.0f / 255.0f, 153.0f / 255.0f, 185.0f / 255.0f};
        inline const glm::vec4 blue {128.0f / 255.0f, 179.0f / 255.0f, 230.0f / 255.0f, 185.0f / 255.0f};
        inline const glm::vec4 black{0.0f, 0.0f, 0.0f, 1.0f};
    }

    inline Color to_raylib(const glm::vec4& color){
        auto channel = [](float value){
            return (unsigned char)std::clamp(value * 255.0f, 0.0f, 255.0f);
        };
        return (Color){channel(color.r), channel(color.g), channel(color.b), channel(color.a)};
    }

    inline void draw_text(glm::vec2 position, const std::string& text, int font_size, const glm::vec4& color){
        DrawText(text.c_str(), (int)position.x, (int)position.y, font_size, to_raylib(color));
    }

    inline int circle_segments(float radius, float error = 0.25f){
        if (radius <= 0.0f) return 36;
        float th = acosf(2.0f * powf(1.0f - error / radius, 2.0f) - 1.0f);
        int segments = (int)ceilf((2.0f * PI) / th);
        return std::clamp(segments, 36, 256);
    }

    inline void draw_circle(glm::vec2 position, float radius, const glm::vec4& color, const glm::vec4& line_color = Colors::black){
        Vector2 center = math::to_raylib(position);
        int segments = circle_segments(radius);
        DrawCircleSector(center, radius, 0.0f, 360.0f, segments, to_raylib(color));
        DrawRing(center, std::max(radius - 1.0f, 0.0f), radius, 0.0f, 360.0f, segments, to_raylib(line_color));
    } 

    inline void draw_point(glm::vec2 position, const glm::vec4& color){
        draw_circle(position, 3, color);
    }

    inline void draw_line(glm::vec2 start, glm::vec2 end, float thick, const glm::vec4& color){
        DrawLineEx(math::to_raylib(start), math::to_raylib(end), thick, to_raylib(color));
    }

    inline void draw_polygon(const std::vector<glm::vec2>& points, const glm::vec4& color, const glm::vec4& line_color = Colors::black){
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

    inline void draw_rectangle(glm::vec2 position, glm::vec2 size, const glm::vec4& color, const glm::vec4& line_color = Colors::black){
        DrawRectangleV(math::to_raylib(position), math::to_raylib(size), to_raylib(color));
        DrawRectangleLinesEx((Rectangle){position.x, position.y, size.x, size.y}, 1.0f, to_raylib(line_color));
    }
}
