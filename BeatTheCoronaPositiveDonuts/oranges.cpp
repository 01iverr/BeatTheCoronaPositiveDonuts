#include "oranges.h"
#include "graphics.h"
#include "player.h"

void Oranges::update()
{
    y -= speed * graphics::getDeltaTime();   
}
void Oranges::draw()
{
    graphics::Brush br;  
    br.outline_opacity = 0.0f;          
    br.texture = std::string(ASSET_PATH) + "apple.png";
    graphics::drawRect(x, y, 50, 50, br); 
    if (debug) { 
        br.outline_opacity = 1.0f; 
        br.texture = ""; 
        br.fill_color[0] = 0.3f;
        br.fill_color[1] = 1.0f;
        br.fill_color[2] = 0.3f;
        br.fill_opacity = 0.3f; 
        Disk hull = getCollisionHull(); 
        graphics::drawDisk(hull.cx, hull.cy, hull.radius, br); 
    }
}
void Oranges::init()
{
    speed = 0.25f;
    y = CANVAS_HEIGHT - 220; 
}
Oranges::Oranges(const Game& mygame)
    :GameObject(mygame)
{
    init(); 
}
void Oranges::setx(float w)
{
    x = w; 
}
Rect Oranges::getCollisionRect() const
{
    return Rect(); 
}
Disk Oranges::getCollisionHull() const
{
    Disk d;
    d.cx = x; 
    d.cy = y+5;  
    d.radius = 20.0f;
    return d;  
}

float Oranges::gety()
{
    return y; 
}