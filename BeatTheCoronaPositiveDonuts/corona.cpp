#include "graphics.h"
#include "corona.h"
void Corona::update()
{
	y += speed * graphics::getDeltaTime(); 
}
void Corona::draw()
{
	graphics::Brush br; 
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSET_PATH) + "corona.png"; 
	graphics::drawRect(x, y, 50, 50, br); 
	if (debug) {  // debug mode 
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
void Corona::init()
{
	speed = 0.12f; 
}
Corona::Corona(const Game& mygame)
	:GameObject(mygame)
{
	init(); 
}
void Corona::setx(float w)
{
	x = w; 
}
void Corona::sety(float w)
{
	y = w; 
}
float Corona::gety()
{
    return y;
}
void Corona::setspeed(float w)
{
	speed = w; 
}
Disk Corona::getCollisionHull() const
{
	Disk d;  
	d.cx = x; 
	d.cy = y;  
	d.radius = 16.0f; 
	return d; 
}
Rect Corona::getCollisionRect() const
{
	return Rect();
}