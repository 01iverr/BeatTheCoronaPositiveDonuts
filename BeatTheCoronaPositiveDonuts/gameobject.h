#pragma once
#include "util.h"
class Collidable {
public:
	virtual Disk getCollisionHull() const = 0; //dhmiourgei mia virtual me8odo ths klasshs collidable
	virtual Rect getCollisionRect() const = 0; //dhmiourgei mia virtual me8odo ths klasshs collidable
};
class GameObject  //create class GameObject gia polymorfismo twn ypoloipwn klasewn einai mia ""afhrhmenh klash""!!!!
{ //idiwtikes metablhtes
	const class Game & game; // orizoyme oti yparxei klassh Game kai oti 8a brei ayth th metablhth game 
public:  // public metablhtes
	GameObject(const class Game & mygame); //constructor orizoyme pws dhmioyrgoyntai ta antikeimena 
	virtual void update() = 0; // dhmiourgei mia virtual me8odo update  dn 8a oristei pote kai opoia klash thn klhrwnomei prepei ekeinh na thn orisei 
	virtual void draw() = 0; // dhmiourgei mia virtual me8odo draw dn 8a oristei pote kai opoia klash thn klhrwnomei prepei ekeinh na thn orisei 
	virtual void init() = 0; //dhmiourgei mia virtual me8odo init  dn 8a oristei pote kai opoia klash thn klhrwnomei prepei ekeinh na thn orisei 
    // ola auta me skopo gia na mporoume na xrhsimopoihsoume to idio onoma metablhtwn kai na "antidrane" diaforetika se kaue antikeimeno 
	bool debug = !true; // an 8eloyme na emfanisoume ta sxhmata toy collision 
};