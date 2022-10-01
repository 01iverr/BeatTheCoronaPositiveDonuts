#include "enemies.h"
#include "graphics.h"
#include "game.h"

void Enemies::update()
{
	x -= speed * graphics::getDeltaTime() ;  // ry8mizei to x se synarthsh toy speed kai toy xronoy 
}
void Enemies::draw()
{
	graphics::Brush br; // dhmiourgei antikeimeno typou brush gia na zwgrafisei antikeimena 
	br.outline_opacity = 0.0f; //gia na einai aorath h eikona gyrw gyrw 
	if (lives == 2) { // an to donut den exei xtyphuei pote 
		br.texture = std::string(ASSET_PATH) + "donut.png"; // fortwnei thn prvth eikona toy oloklhroy donut 
		
	}
	else if(lives==1){
		br.texture = std::string(ASSET_PATH) + "deaddonuts.png"; // fortvnei to misofagvmeno donut 
	}
	else {
		br.texture = std::string(ASSET_PATH) + "deaddead.png"; // fortwnei to efe ;

	}
	
	graphics::drawRect(x, y, 100, 100, br); //kalei thn drawrect  kai to zwgrafizei ekei poy toy leme 
	if (debug) { // debug mode 
		br.outline_opacity = 1.0f; //gia na mhn einai aorath h eikona gyrw gyrw 
		br.texture = "";
		//xrwma ~ prasino 
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f; //axnofainetai 
		Disk hull = getCollisionHull(); //kalei thn get collusiionhull 
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br); // kaloyme thn synarthsh ayth kai zwgrafizetai o kyklos
	}
}
void Enemies::init()//enemies starting position
{
	speed = 0.09999f; //8etoume to speed 
}
Enemies::Enemies(const Game& mygame) 
	:GameObject(mygame)
{
	init(); //kaloyme thn init 
}
void Enemies::setx(float w)
{
	x = CANVAS_WIDTH + w; // uetoyme to x 
}
void Enemies::sety(float w)
{
	y = w; //8etoume to y
}
float Enemies::getx()
{
	return x; //epistrefetai to x 
}
float Enemies::gety()
{
	return y; // epistrefetai to y 
}
void Enemies::setspeed(float w)
{
	speed = w; // uetoyme to speed 
}
void Enemies::declives()
{
	lives -= 1; // meiwnontai oi zwes kata mia 
}
int Enemies::getlives()
{
	return lives; // epistrefei posew zwes exei 
}
Rect Enemies::getCollisionRect() const
{
	return Rect(); //epistrefei ena "adeio" antikeimeno  (kenos kataskeyasths )
}
Disk Enemies::getCollisionHull() const
{
	Disk d; //dhmioyrgeitai disk d 
	d.cx = x;  //cx=x 
	d.cy = y; // cy =y
	d.radius = 50.0f; //aktina 
	return d; // epistrefetai to antikeimeno d 
}
