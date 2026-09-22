#pragma once

#include <string>
#include <glm/glm.hpp>
#include <raylib.h>
#include <rlImGui.h>
#include "window.h"
#include "camera2d.h"

class Application{
    public:
        Application(int width,int height,std::string name)
        :window_(width,height,name)
        {}

        virtual ~Application() = default;

        void run(){
            rlImGuiSetup(true);
            on_attach();
            last_width_ = GetScreenWidth();
            last_height_ = GetScreenHeight();
            while(!window_.should_close()){
                float dt = GetFrameTime();
                handle_resize();
                camera_.update(dt);
                on_update(dt);

                BeginDrawing();
                camera_.begin();
                    ClearBackground(RAYWHITE);
                    on_render();
                camera_.end();
                on_imgui();
                EndDrawing();
            }
            on_detach();
            rlImGuiShutdown();
        }

        virtual void on_update(float dt){
           
        }

        virtual void on_render(){
            
        }

        virtual void on_imgui(){

        }

        virtual void on_attach(){

        }

        virtual void on_detach(){

        }

        virtual void on_resize(int width, int height){

        }

    private:
        void handle_resize(){
            int width = GetScreenWidth();
            int height = GetScreenHeight();
            if (width == last_width_ && height == last_height_)
                return;
            last_width_ = width;
            last_height_ = height;
            camera_.set_offset(glm::vec2(width / 2.0f, height / 2.0f));
            on_resize(width, height);
        }

        Window window_;
        Camera2d camera_{glm::vec2(0.0f),1.0f};
        int last_width_ = 0;
        int last_height_ = 0;
};