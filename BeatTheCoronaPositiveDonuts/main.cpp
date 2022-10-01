#include "graphics.h"
#include <iostream>
#include "game.h"
#include "config.h"

//etsi to ekane o proffessor NA DOUME TO BINTEO 1 GIA NA GRAPSOUME SXOLIA 
 void update(float ms)
{
     Game* game=reinterpret_cast<Game *>  (graphics::getUserData());
     game->update();
}
 void draw()
 {
     Game* game = reinterpret_cast<Game*>  (graphics::getUserData());
     game->draw();
    
 }
int main()
{
    Game mygame; //orizoume oti h metablhth mygame einai typou game 
    graphics::createWindow(WINDOW_WIDTH, WINDOW_HEIGHT,"                                                                                                                                                       BEAT THE CORONA POSITIVE DONUTS ");
    //h apo panw grammhdhmioyrgei to parauyro kai bazei ton titlo BEAT THE CORONA POSITIVE DONUTS pio sto "kenntro" 
    graphics::setUserData(&mygame); //apo8hkeuoume to game mas sthn metablhth mygame kai to kanei to graphics ayto 
    graphics::setDrawFunction(draw); //orizei poia synarthsh 8a sxediazei to paixnidi 
    graphics::setUpdateFunction(update); // orizei poia synarthsh 8a kanei update to paixnidi 
    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT); // orizei ton kamba (ta noumera yparxun sto arxeio config.h)
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT); // orizetai na diathrountai oi analogies swstes kai na mhn allazoyn me bash to mege8os toy para8urou
    mygame.init(); //kalei thn init sto mygame 
    graphics::startMessageLoop(); //praktika ksekinaei to paixnidi gia na trexei to paixnidi
   return 0; // aparaithto  gia na oristei  h main swsta
}