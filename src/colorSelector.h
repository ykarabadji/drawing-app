#ifndef COLOR
#define COLOR 

#include <iostream>
#include <map>
#include <array>
#include <cmath>
#include "raylib.h"

// Define position struct
typedef struct pos {
    float x;
    float y;

    // For std::map ordering
    bool operator<(const pos& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
} pos;

// Global color map and color database
std::map<pos, std::array<int, 4>> color_map;

std::array<std::array<int, 4>, 8> color_db = {{
    {{255, 0, 0, 255}},     // Red
    {{0, 255, 0, 255}},     // Green
    {{0, 0, 255, 255}},     // Blue
    {{255, 255, 0, 255}},   // Yellow
    {{255, 0, 255, 255}},   // Magenta
    {{0, 255, 255, 255}},   // Cyan
    {{255, 165, 0, 255}},   // Orange
    {{128, 0, 128, 255}}    // Purple
}};

// Fill the map with 8 positions and their colors
void initial_color_func() {
    for (int i = 0; i < 800; i += 100) {
        
        pos p = { static_cast<float>(i), 0.0f }; // ✅ Top bar
        color_map[p] = color_db[i / 100];
        Color color = {(unsigned char)color_db[i/100][0],(unsigned char)color_db[i/100][1],(unsigned char)color_db[i/100][2],(unsigned char)color_db[i/100][3]};
        DrawRectangle(i,0,100,100,color);// rectangle to know each the position of each color;
        // nice work for today bro next day we'll continue ;

    }
}


// Check if a mouse position is inside the color bar area
bool select_col(Vector2 getmousepos) {
    return (getmousepos.y >= 0 && getmousepos.y < 100); // Matches y = 100 bar height
}

// Convert pos → Color (if exists)
Color setcolor(Vector2 getmousepos) {
    
    pos p = { std::floor(getmousepos.x / 100) * 100.0f, 0.0f }; // ✅ Snap to top bar
// Snap to color cell

    auto it = color_map.find(p);
    if (it != color_map.end()) {
        std::array<int, 4> arr = it->second;
        return Color{ (unsigned char)arr[0], (unsigned char)arr[1], (unsigned char)arr[2], (unsigned char)arr[3] };
    }

    // Default color if not found
    return WHITE;
}

#endif
