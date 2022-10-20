#include "enemies.h"
#include "graphics.h"
#include "game.h"

void Enemies::update()
{
	x -= speed * graphics::getDeltaTime() ;  
}
void Enemies::draw()
{
	graphics::Brush br; 
	br.outline_opacity = 0.0f; 
	if (lives == 2) {  
		br.texture = std::string(ASSET_PATH) + "donut.png"; 
		
	}
	else if(lives==1){
		br.texture = std::string(ASSET_PATH) + "deaddonuts.png";  
	}
	else {
		br.texture = std::string(ASSET_PATH) + "deaddead.png"; 

	}
	
	graphics::drawRect(x, y, 100, 100, br); 
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
void Enemies::init()
{
	speed = 0.09999f;  
}
Enemies::Enemies(const Game& mygame) 
	:GameObject(mygame)
{
	init(); 
}
void Enemies::setx(float w)
{
	x = CANVAS_WIDTH + w; 
}
void Enemies::sety(float w)
{
	y = w; 
}
float Enemies::getx()
{
	return x;  
}
float Enemies::gety()
{
	return y;  
}
void Enemies::setspeed(float w)
{
	speed = w;  
}
void Enemies::declives()
{
	lives -= 1; 
}
int Enemies::getlives()
{
	return lives; 
}
Rect Enemies::getCollisionRect() const
{
	return Rect();
}
Disk Enemies::getCollisionHull() const
{
	Disk d; 
	d.cx = x; 
	d.cy = y; 
	d.radius = 50.0f; 
	return d; 
}
