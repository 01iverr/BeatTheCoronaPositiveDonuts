#include "player.h"
#include "graphics.h"
#include "game.h"
Player::Player(const Game& mygame)
	:GameObject(mygame)
{
}
void Player::update() //orizei thn synarthsh update gia to Player
{
	if (graphics::getKeyState(graphics::SCANCODE_LEFT)) // kounietai pros ta aristera me to aristero belaki 
	{
		pos_x -= speed * graphics::getDeltaTime()/10.0f; // allazei uesh pros ta aristera kata taxythta(dhladh gia poso exei pathmeno to plhktro)dia toy 10 
	}
	if (graphics::getKeyState(graphics::SCANCODE_RIGHT)) // kounietai pros ta deksia me to deksio belaki 
	{
		pos_x += speed * graphics::getDeltaTime()/10.0f; // allazei uesh pros ta deksia  kata taxythta(dhladh gia poso exei pathmeno to plhktro)dia toy 10 
	}
	if (pos_x < 50) 
	{
		pos_x = 50.0f; //gia na mhn bgainei ektos oriwn apo ta aristera
	}
	if (pos_x > CANVAS_WIDTH - 50)
	{
		pos_x = CANVAS_WIDTH - 50; //gia na mhn bgainei ektos oriwn apo ta deksia 
	}	
}
void Player::draw() //orizei thn synarthsh draw gia to Player
{
	graphics::Brush br; // dhmiourgei antikeimeno typou brush gia na zwgrafisei antikeimena 
	br.texture = std::string(ASSET_PATH) + "blender.png"; //fortwnei to blender
	br.outline_opacity = 0.0f;//to gyrw gyrw einai aorato 
	graphics::drawRect(pos_x,CANVAS_HEIGHT-65, 250, 270, br); // to emfanizei kentrarismeno sto katv mero ths o8onhs (ligo pio katw bebaia kai den feinetai olo to blender giati etsi mas arese kalytera)
	if (debug) {
		br.outline_opacity = 1.0f;
		br.texture = "";
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f;
		Rect hull = getCollisionRect(); //kalei thn get collusiionrect
		graphics::drawRect(hull.cx, hull.cy, hull.width, hull.height, br); // zwgrafizei to tetrsgvno 
	}
}
void Player::init()
{	
}
float Player::getx()
{
	return pos_x; // epistrefei to x 
}
Disk Player::getCollisionHull() const{
	return Disk(); //epistrefei ena "adeio" antikeimeno  (kenos kataskeyasths )
}
Rect Player::getCollisionRect() const
{
	Rect pl; //dhmioyrgeitai rect pl
	pl.cx = pos_x+5;  // kentro x 
	pl.cy = CANVAS_HEIGHT - 100; // kentro y
	pl.width = 250.0f/2-30;  // platos 
	pl.height = 189.0f; // ypsos 
	return pl; // epistrefei to pl 
}