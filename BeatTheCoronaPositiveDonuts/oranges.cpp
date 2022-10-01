#include "oranges.h"
#include "graphics.h"
#include "player.h"

void Oranges::update()
{
    y -= speed * graphics::getDeltaTime();   // ry8mizei to y se synarthsh toy speed kai toy xronoy
}
void Oranges::draw()
{
    graphics::Brush br;  // dhmiourgei antikeimeno typou brush gia na zwgrafisei antikeimena 
    br.outline_opacity = 0.0f;   //gia na einai aorath h eikona gyrw gyrw        
    br.texture = std::string(ASSET_PATH) + "apple.png"; //fortwnei to mhlo 
    graphics::drawRect(x, y, 50, 50, br); //kalei thn drawrect  kai to zwgrafizei ekei poy toy leme 
    if (debug) { //debug mode 
        br.outline_opacity = 1.0f; //gia na mhn einai aorath h eikona gyrw gyrw 
        br.texture = "";
        //xrwma ~prasino 
        br.fill_color[0] = 0.3f;
        br.fill_color[1] = 1.0f;
        br.fill_color[2] = 0.3f;
        br.fill_opacity = 0.3f; //axnofainetai 
        Disk hull = getCollisionHull(); //kalei thn get collusiionhull 
        graphics::drawDisk(hull.cx, hull.cy, hull.radius, br); // kaloyme thn synarthsh ayth kai zwgrafizetai o kyklos
    }
}
void Oranges::init()
{
    speed = 0.25f; //8etoume to speed 
    y = CANVAS_HEIGHT - 220; // 8etoyme to y
}
Oranges::Oranges(const Game& mygame)
    :GameObject(mygame)
{
    init(); // kaloume thn init 
}
void Oranges::setx(float w)
{
    x = w; //uetoyme to x 
}
Rect Oranges::getCollisionRect() const
{
    return Rect(); //epistrefei ena "adeio" antikeimeno  (kenos kataskeyasths )
}
Disk Oranges::getCollisionHull() const
{
    Disk d;// dhmioyrgoyme disk d 
    d.cx = x; //cx=x 
    d.cy = y+5; //cy=y+5  
    d.radius = 20.0f; // aktina 
    return d; //epistrefei to d 
}

float Oranges::gety()
{
    return y; //epistrefei to y 
}