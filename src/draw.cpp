#include "raylib.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include "undoLogic.h"
#include "colorSelector.h"



int main(void) {
    // Initialize the window

   std::queue<std::vector<std::vector<std::pair<float,float>>>> queue_buffer;


    InitWindow(800,800,"PLOT");
    SetTargetFPS(60); // Set frame rate to 60 FPS

      std::vector<std::vector<std::pair<float,float>>> buffer;
       Color color = BLUE ; 
       initial_color_func();
    // Main game loop
    while (!WindowShouldClose()) {



        BeginDrawing();
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT) ){
               // ClearBackground(RAYWHITE);

           Vector2 thisPos  = GetMousePosition();
            DrawCircle(thisPos.x,thisPos.y,3,color);
            std::vector<std::pair<float,float>> buffer_internal;
                  
            buffer_internal.push_back(std::make_pair(thisPos.x,thisPos.y));
            buffer.push_back(buffer_internal);
                  //stack_buffer.push(buffer_internal);
                  if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                         if(select_col(GetMousePosition()) == true ){
                          thisPos.y = 100.0;
                          color = setcolor(thisPos);
                                   }
                
                  }
               

                
       
        }else if(IsKeyPressed(KEY_A)){
            Vector2 thisPos  = GetMousePosition();
            
            if((int(thisPos.y)/100)  != 0){
                       std::cout << thisPos.x<<"hhhhhhh" << thisPos.y;  
                       clearAll_function(queue_buffer);
            }
          
       }else if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            queue_buffer.push(buffer);
            buffer.clear();
       }

        

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close the window and OpenGL context

    return 0;
}
