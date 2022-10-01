#pragma once
#include "player.h"
#include "enemies.h"
#include "oranges.h"
#include "corona.h"
#include<string>
class Game //create class Game 
{	//idiwtikes metablhtes  
	float time2; // elegxei an metajy twn click poy pyroboloun exoyn perasei ta 30msec
	Player* player = nullptr; //dhmiourgei antikeimeno typou  paikth
	bool player_initialized = false; // boolean metablhth poy elegxei an exei dhmioyrghuei o paikthw hdh 
	//(gia na mhn dhmiourgei apeira antikeimena kaue fora p kaleitai h update)
	bool s = false; // metablhth poy afora to 3o background
	bool d = false; // metablhth poy afora to 1o background 
	//o syndiasmos twn parapanv dyo afora to 2o background 
	bool b = true; // h metablhth pou xrhsimopoioume stis entoles  gia ta dyo keimena pou ueloume na 
	//anabosbhnoun sta do while gia na stamathsoyn an o paikths allajei "selida"
	Enemies * enemy[25] ;  //dhmiourgei antikeimeno typou  enemies
	bool enemy_initialized[25]; // boolean metablhth poy elegxei an exei dhmioyrghuei
	//o ex8ros hdh (gia na mhn dhmiourgei apeira antikeimena kaue fora p kaleitai h update)
	float time; //o xronos poy pathse to h na allaksei back 
	bool corona_initialized[25]; // pinakas me boolean metablhtes poy elegxei an exei dhmioyrghuei
	Corona * coronas [25]; //pinakas me tis sfaires twn ex8rwn 
	int randomnumber; // "tyxaios" ariumos poy orizei poios 8a pyrobolhsei 
	int coronalive; // poses sfaires einai zwntanes twn ex8rwn ekeinh thn stigmh 
	bool a = false; // stamathsan oi ex8roi  n mpainoyn 
	bool l = false; // gia na mpei prvth fora tiw sfaires
	Oranges* orangebullets[100];  //dhmiourgei antikeimeno typou  orange
	bool orange_initialized[100]; // boolean metablhth poy elegxei an exei dhmioyrghuei
	void spawnEnemy(); // bgainei o ex8ros 
	void spawnCorona(); //bgainei h sfaira tou ex8roy 
	void spawnOrange();   //bgainei h sfaira toy portokalioy
	bool checkCollision(int h); // elegxei thn sygkroush metaksy tvn kyklwn 
	bool checkCollision2(int i ,int h); // elegxei thn sygkroush metaksy toy kyklou  kai tou or8ogwniou 
	bool w = false; // win background
	bool f = false; // defeat background 
	bool started = true; // deixnei an exei ksekinhsei h moysikh nikhs kai httas
	std::string username=""; // to username tou paikth mas 
	int maxx; // to mhkos tvn xarakthrwn toy username 
	bool enter; //gia na treksei thn taksinomhsh met a score  
	bool enter_pr; //an pathse enter
	bool maxl; //an graftoyn 10 xarakthrew gia na stamata na grafei alla kai gia na elegxoume an to telow thw lejhs pathsei na sbhsei grammata
	bool q; // gia na mhn mporoyme na patame pollew forew enter kai na pernaei to score tou idioy synexeia 
	bool firstletter; // epeidh prepei na pathsei to e na paei sto back me ta jighscore to sbhnoyme gia na mhn perastei 
	int totaldeaddonuts=0; //ta donuts poy skotwnei se ka8e pista 
	int totaloranges = 0; //sfaires poy exei xrhsimopoihsei o paikths mas 
	float text_x; // oi sfaires poy exei rijei o paikths poy emfanizontai sta dejia ( se ti 8esh 8a mpoun )
	int randomback; // random number to choose the background 
	bool m = false;  //dhlwnei an mphkame sto ((!s && d)||m) dhladh oti hdh exeipath8ei to h enw briskomaste sto 2o background 
	float deathtime[25]; //pinakas poy krataei poia wra pe8ane to ekastote donut
	std::string plnames[5]; // o pinakas me ta onomata tvn highscore
	int plscores[5]; //o pinakas me ta highscores
	int score; // to score toy ekastote paikth otan diabazei to arxeio 
	bool last = true; // gia na mpei mia fora sto if (w && graphics::getKeyState(graphics::SCANCODE_E)&&last)
	int totaltotaldead=0; // oi 24ades me ta nekra donuts
	std::string temp; // gia na apo8hkeytei prwsorina to onoma enow paikth sthn taksinomhsh poy ginetai 
	std::string plname; // to onoma poy paikth toy diabazei ekeinh thn wra 
	int plscore; // to score toy paikth toy diabazei ekeinh thn wra 
	int numlines; //grammes toy arxioy
	bool pausemode = false;
public: //public metablhtes
	void update(); //dhlwnei thn update
	void draw(); //dhlwnei thn draw
	void init(); //dhlwnei thn init
	Game(); // dhlwnoume ena kataskeyasth
	~Game(); // dhlwnoume enan "katastrofea"
	std::string readfile(); // dhlvnoume thn me8odo poy 8a diabasei to arxeio 
	void writefile();	// dhlvnoume thn me8odo poy 8a grapsei  sto arxeio
};