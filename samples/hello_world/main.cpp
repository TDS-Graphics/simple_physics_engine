#include <glm/glm.hpp>
#include <iostream>
#include <vector>
#include "framework/input.h"
#include "framework/draw.h"
#include "framework/application.h"
#include "imgui.h"
#include "rlImGui.h"

class PhysicsApp : public Application {
public:
    PhysicsApp(int width, int height, std::string name)
        : Application(width, height, name) {}

    void on_attach() override {
        std::cout << "PhysicsApp attached" << std::endl;
    }

    void on_detach() override {
        std::cout << "PhysicsApp detached, ran for " << elapsed_ << "s" << std::endl;
    }

    void on_update(float dt) override {
        elapsed_ += dt;
        if (input::is_key_pressed(KEY_SPACE))
            std::cout << "space pressed at t=" << elapsed_ << "s" << std::endl;
    }

    void on_render() override {
        graphic::draw_text(glm::vec2(100, 50), "Hello World", 20, graphic::Colors::black);
        graphic::draw_circle(circle_pos_, circle_radius_, circle_color_);
        graphic::draw_point(glm::vec2(100, 100), graphic::Colors::red);
        graphic::draw_point(glm::vec2(100, 120), graphic::Colors::red);
        graphic::draw_point(glm::vec2(100, 140), graphic::Colors::red);

        graphic::draw_point(glm::vec2(200, 300), graphic::Colors::green);
        graphic::draw_point(glm::vec2(400, 300), graphic::Colors::green);
        graphic::draw_line(glm::vec2(200, 300), glm::vec2(400, 300), 2, graphic::Colors::grey);

        graphic::draw_rectangle(glm::vec2(300, 100), glm::vec2(120, 80), graphic::Colors::green);

        std::vector<glm::vec2> polygon = {
            glm::vec2(500, 300), glm::vec2(560, 260), glm::vec2(620, 300),
            glm::vec2(600, 360), glm::vec2(520, 360)
        };
        graphic::draw_polygon(polygon, graphic::Colors::red, graphic::Colors::black);
    }

    void on_imgui() override {
        rlImGuiBegin();

        ImGui::Begin("Render Params");

        if (ImGui::CollapsingHeader("Circle", ImGuiTreeNodeFlags_DefaultOpen)) {
            ImGui::DragFloat2("Center", &circle_pos_.x, 1.0f);
            ImGui::SliderFloat("Radius", &circle_radius_, 1.0f, 300.0f);
            ImGui::ColorEdit4("Color##circle", &circle_color_.x, ImGuiColorEditFlags_AlphaBar);
        }

        ImGui::Separator();
        ImGui::Checkbox("Show ImGui Demo", &show_demo_);

        ImGui::End();

        if (show_demo_)
            ImGui::ShowDemoWindow();

        rlImGuiEnd();
    }

private:
    float elapsed_ = 0.0f;

    glm::vec2 circle_pos_{100.0f, 100.0f};
    float circle_radius_ = 100.0f;
    glm::vec4 circle_color_ = graphic::Colors::blue;

    bool show_demo_ = false;
};

int main(int argc,char** argv){

    float aspect_ratio = argc>1 ? atof(argv[1]) : 0.5f;
    const int window_width = (int)1920 * aspect_ratio;
    const int window_height = (int)1080 * aspect_ratio;

    PhysicsApp app{window_width, window_height, "test"};
    app.run();

    return 0;
}
