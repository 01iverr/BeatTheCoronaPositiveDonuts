#pragma once
#include "gameobject.h"
#include "config.h"
class Player : public GameObject, public Collidable 
{  
	float speed = 5.0f; 
	float pos_x = CANVAS_WIDTH / 2;  
public:
	Player(const class Game& mygame); 
	void update() override;  
	void draw()   override;  
	void init()   override;  
	float getx(); 
	Rect getCollisionRect() const override; 
	Disk getCollisionHull() const override;  
};
