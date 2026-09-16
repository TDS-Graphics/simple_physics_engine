#pragma once
#include <string>
#include <raylib.h>
class Window{
    public:
        Window(int width,int height,std::string name)
        :width_(width),
        height_(height),
        name_(name)
        {
            InitWindow(width_, height_, name.c_str());
            SetTargetFPS(60);
        }
        
        ~Window(){
            CloseWindow();
        }

        bool should_close(){
            return WindowShouldClose();
        }

        void set_target_fps(int fps){
            SetTargetFPS(fps);
        }


    private:
        int width_;
        int height_;
        std::string name_; 
};
