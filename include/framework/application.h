#pragma once

#include <string>
#include <glm/glm.hpp>
#include <raylib.h>
#include "window.h"
#include "camera2d.h"

class Application{
    public:
        Application(int width,int height,std::string name)
        :window_(width,height,name)
        {}

        virtual ~Application() = default;

        void run(){
            on_attach();
            while(!window_.should_close()){
                float dt = GetFrameTime();
                camera_.update(dt);
                on_update(dt);

                BeginDrawing();
                camera_.begin();
                    ClearBackground(RAYWHITE);
                    on_render();
                camera_.end();
                EndDrawing();
            }
            on_detach();
        }

        virtual void on_update(float dt){
           
        }

        virtual void on_render(){
            
        }

        virtual void on_attach(){

        }

        virtual void on_detach(){

        }

    private:
        Window window_;
        Camera2d camera_{glm::vec2(0.0f),1.0f};
};