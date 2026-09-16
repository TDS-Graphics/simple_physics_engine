#include <glm/glm.hpp>
#include "framework/window.h"
#include <raylib.h>
#include "framework/graphics/draw.h"
int main(int argc,char** argv){

    float aspect_ratio = argc>1 ? atof(argv[1]) : 0.5f;
    const int window_width = (int)1920 * aspect_ratio;
    const int window_height = (int)1080 * aspect_ratio;
    
    Window window{window_width,window_height,"test"};
    
    while(!window.should_close()){
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            graphic::draw_circle(glm::vec2(100,100), 100,BLUE);
            graphic::draw_point(glm::vec2(100,100), RED);
            graphic::draw_point(glm::vec2(100,120), RED);
            graphic::draw_point(glm::vec2(100,140), RED);


            graphic::draw_point(glm::vec2(200,300), GREEN);
            graphic::draw_point(glm::vec2(400,300), GREEN);
            graphic::draw_line(glm::vec2(200,300), glm::vec2(400,300),2,BLACK);

        EndDrawing();
    }

    return 0;
}
