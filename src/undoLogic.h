#ifndef UNDO_H
#define UNDO_H



#include <vector>
#include <queue>
#include <iostream>

#include "raylib.h"

void clearAll_function( std::queue<std::vector<std::vector<std::pair<float,float>>>> &queue_buffer/*std::vector<std::vector<std::pair<float,float>>> buffer*/){
   if(!queue_buffer.empty()){
      auto front_buffer = queue_buffer.front();
      for(const auto&row : front_buffer ){
            for(size_t i = 0 ; i<row.size();i++){
                DrawCircle(row[i].first,row[i].second,8,BLACK);
      }

}
   queue_buffer.pop();
   }
}




#endif
