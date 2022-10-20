#pragma once 
#include "gameobject.h"
#include "config.h"
class Enemies : public GameObject, public Collidable // create class enemies poy einai apogonos ths klashs GameObject
{s
	float speed = 0.0f;   // orizei th  float metablhth tou speed
	float x ;  // orizei th  float metablhth tou x 
	float y; // orizei th  float metablhth tou y 
	int lives = 2; //gia na allazei to donut kai na exei kai ena efe sto telos 
public: 
	void update() override; //dhlwnei thn update kai oti "8a grapsei apo panw" apthn update tou gameobject 
	void draw() override; //dhlwnei thn draw kai oti "8a grapsei apo panw" apthn draw tou gameobject 
	void init() override; //dhlwnei thn init kai oti "8a grapsei apo panw" apthn init tou gameobject 
	Enemies(const class Game& mygame);  //constructor orizoyme pws dhmioyrgoyntai ta antikeimena 
	void setx(float w); // orizei  to x tou kaue donut
	void sety(float w); // orizei  to y tou kaue donut
	float getx(); //epistrefei to x tou donut
	float gety(); //epistrefei to ypsos tou donut
	void setspeed(float w); //orizei thn taxythta toy donut 
	void declives(); //meiwnei tis zwes toy donut 
	int getlives(); // epistrefei to poses zwes exei to donut 
	Rect getCollisionRect() const override; //den to xrhsimopoioume apla to bazoyme giati yparxei sto game object
	Disk getCollisionHull() const override; //orizei to kyklo sygkroyshs
};
