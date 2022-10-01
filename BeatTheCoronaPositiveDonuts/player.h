#pragma once
#include "gameobject.h"
#include "config.h"
class Player : public GameObject, public Collidable //// create class player poy einai apogonos ths klashs GameObject
{    // idiwtikes metablhtes 
	float speed = 5.0f; // taxythta poy ua exei o paikths
	float pos_x = CANVAS_WIDTH / 2;  //dhlwnoume h metablhth pos_x na nai sthn mesh toy kamba dhladh otan
	//emfanisoume to mixer na paei sthn arxh katw sthn mesh (to na emfanizetai katw exei oristei allou)
public:
	//public metablhtes 
	Player(const class Game& mygame); //constructor orizoyme pws dhmioyrgoyntai ta antikeimena 
	void update() override;   //dhlwnei thn update kai oti "8a grapsei apo panw" apthn update tou gameobject 
	void draw()   override;  //dhlwnei thn draw kai oti "8a grapsei apo panw" apthn draw tou gameobject 
	void init()   override;  //dhlwnei thn init kai oti "8a grapsei apo panw" apthn init tou gameobject 
	float getx(); //epistrefei to x toy paikth
	Rect getCollisionRect() const override; // orizei to oruogwnio sygkroyshs
	Disk getCollisionHull() const override;  //den to xrhsimopoioume apla to bazoyme giati yparxei sto game object
};