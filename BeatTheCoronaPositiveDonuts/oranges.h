#pragma once 
#include "gameobject.h"
#include "config.h"
class Oranges : public GameObject, public Collidable 
{
	float speed;  
	float x ;
	float y = 100.0f;
public: 
	void update() override; 
	void draw() override;  
	void init() override; 
	Oranges(const class Game& mygame);   
	void setx(float w); 
	float gety();
	Rect getCollisionRect() const override; 
	Disk getCollisionHull() const override; 
};
