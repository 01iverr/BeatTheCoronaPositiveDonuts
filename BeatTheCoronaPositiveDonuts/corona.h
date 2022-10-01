#pragma once
#include "gameobject.h"
#include "config.h"
class Corona : public GameObject, public Collidable // create class corona poy einai apogonos ths klashs GameObject
{//idiwtikes metablhtes
	float speed ;  // orizei th  float metablhth tou speed
	float x ; // orizei th  float metablhth tou x
	float y ;  // orizei th  float metablhth tou y 
public: // public metablhtes 
	int i = 0; // metrhths poy ua bazei allon ex8ro se mona zyga
	void update() override; //dhlwnei thn update kai oti "8a grapsei apo panw" apthn update tou gameobject 
	void draw() override; //dhlwnei thn draw kai oti "8a grapsei apo panw" apthn draw tou gameobject 
	void init() override; //dhlwnei thn init kai oti "8a grapsei apo panw" apthn init tou gameobject 
	Corona(const class Game& mygame); //constructor orizoyme pws dhmioyrgoyntai ta antikeimena 
	void setx(float w); // orizei  to x (to poy brisketai to kaue donut apo to opoio 8a bgoyn )sta bullets
	void sety(float w); // orizei  to y (to poy brisketai to kaue donut apo to opoio 8a bgoyn )sta bullets 
	float gety(); //epistrefei to ypsos ths sfairas 
	void setspeed(float w); // orizei thn taxythta ths sfairas 
	virtual Disk getCollisionHull() const override; //orizei to kyklo sygkroyshs
	virtual Rect getCollisionRect() const override; //den to xrhsimopoioume apla to bazoyme giati yparxei sto game object
};