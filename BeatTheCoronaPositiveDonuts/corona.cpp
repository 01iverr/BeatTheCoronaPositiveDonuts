#include "graphics.h"
#include "corona.h"
void Corona::update()
{
	y += speed * graphics::getDeltaTime(); // ry8mizei to y se synarthsh toy speed kai toy xronoy 
}
void Corona::draw()
{
	graphics::Brush br; // dhmiourgei antikeimeno typou brush gia na zwgrafisei antikeimena 
	br.outline_opacity = 0.0f; //gia na einai aorath h eikona gyrw gyrw 
	br.texture = std::string(ASSET_PATH) + "corona.png"; //fortwnei thn korona 
	graphics::drawRect(x, y, 50, 50, br);  //kalei thn drawrect  kai to zwgrafizei ekei poy toy leme 
	if (debug) {  // debug mode 
		br.outline_opacity = 1.0f; //gia na mhn einai aorath h eikona gyrw gyrw 
		br.texture = "";
		//xrwma ~prasino 
		br.fill_color[0] = 0.3f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 0.3f;
		br.fill_opacity = 0.3f; //axnofainetai
		Disk hull = getCollisionHull();  //kalei thn get collusiionhull 
		graphics::drawDisk(hull.cx, hull.cy, hull.radius, br);  // kaloyme thn synarthsh ayth kai zwgrafizetai o kyklos
	}
}
void Corona::init()
{
	speed = 0.12f; // 8etoyme to speed 
}
Corona::Corona(const Game& mygame)
	:GameObject(mygame)
{
	init(); // kaloume thn init 
}
void Corona::setx(float w)
{
	x = w; //uetoyme to x 
}
void Corona::sety(float w)
{
	y = w; //uetoyme to y
}
float Corona::gety()
{
    return y; // epistrefoyme to y 
}
void Corona::setspeed(float w)
{
	speed = w; // uetoyme to speed 
}
Disk Corona::getCollisionHull() const
{
	Disk d; // dhmiourgoyme  disk d 
	d.cx = x; //cx=x
	d.cy = y; // cy=y 
	d.radius = 16.0f; //aktina 
	return d; // epistrefei to d 
}
Rect Corona::getCollisionRect() const
{
	return Rect(); //epistrefei ena "adeio" antikeimeno  (kenos kataskeyasths )
}