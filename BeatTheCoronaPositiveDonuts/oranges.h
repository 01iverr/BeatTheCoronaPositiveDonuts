#pragma once 
#include "gameobject.h"
#include "config.h"
class Oranges : public GameObject, public Collidable // create class enemies poy einai apogonos ths klashs GameObject
{//idiwtikes metablhtes
	float speed; //taxythta poy 8a exoyn ta mhla (polles forew onomazontai kai portokalia sto programma) 
	float x ; // orizei th  float metablhth tou x
	float y = 100.0f; // 8etei to ypsos apo to opoio bgainoun ta portokalia
public: // public metablhtes 
	void update() override; //dhlwnei thn update kai oti "8a grapsei apo panw" apthn update tou gameobject 
	void draw() override; //dhlwnei thn draw kai oti "8a grapsei apo panw" apthn draw tou gameobject 
	void init() override; //dhlwnei thn init kai oti "8a grapsei apo panw" apthn init tou gameobject 
	Oranges(const class Game& mygame);  //constructor orizoyme pws dhmioyrgoyntai ta antikeimena 
	void setx(float w); // orizei  to x (to poy brisketai to mixer  ekeinh thn stigmh  )sta mhla
	float gety();//epistrefei to ypsos ths sfairas mhlou
	Rect getCollisionRect() const override;  //den to xrhsimopoioume apla to bazoyme giati yparxei sto game object
	Disk getCollisionHull() const override; //orizei to kyklo sygkroyshs
};
