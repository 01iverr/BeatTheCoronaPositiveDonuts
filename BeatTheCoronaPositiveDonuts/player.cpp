#include "player.h"
#include "graphics.h"
#include "game.h"
Player::Player(const Game& mygame)
	:GameObject(mygame)
{
}
void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_LEFT)) 
	{
		pos_x -= speed * graphics::getDeltaTime()/10.0f; 
	}
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT)) 
	{
		pos_x += speed * graphics::getDeltaTime()/10.0f;
	}
	if (pos_x < 50) 
	{
		pos_x = 50.0f; 
	}
	if (pos_x > CANVAS_WIDTH - 50)
	{
		pos_x = CANVAS_WIDTH - 50; 
	}	
}
void Player::draw() 
{
	graphics::Brush br;
	br.texture = std::string(ASSET_PATH) + "blender.png"; 
	br.outline_opacity = 0.0f;
	graphics::drawRect(pos_x,CANVAS_HEIGHT-65, 250, 270, br);
	if (debug) {
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		Rect hull = getCollisionRect(); 
		graphics::drawRect(hull.cx, hull.cy, hull.width, hull.height, br);  
	}
}
void Player::init()
{	
}
float Player::getx()
{
	return pos_x; 
}
Disk Player::getCollisionHull() const{
	return Disk(); 
}
Rect Player::getCollisionRect() const
{
	Rect pl; 
	pl.cx = pos_x+5;  
	pl.cy = CANVAS_HEIGHT - 100; 
	pl.width = 250.0f/2-30;  
	pl.height = 189.0f; 
	return pl; 
}
