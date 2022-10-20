#include "game.h"
#include "graphics.h"
#include "config.h"
#include "enemies.h"
#include "oranges.h"
#include <algorithm>
#include <string>
#include <stdlib.h>  
#include <fstream>
#include <iostream>
void Game::update() 
{
	if (graphics::getKeyState(graphics::SCANCODE_GRAVE)&&s ) {
		if (pausemode) {
			pausemode = false;
		}
		else {
			pausemode = true;
		}
	}
		if (!player_initialized && s) 
		{
			player = new Player(*this); 
			player_initialized = true;
		}
		if (!d) { 
			if (graphics::getKeyState(graphics::SCANCODE_G)) {
				d = true; 
				graphics::playMusic(std::string(ASSET_PATH) + "FragOut.mp3", 0.2f, true, 2000);
			}
		}
		if ((!s && d) || m) 
		{
			randomback = rand() % 60 + 1; 
			if ((graphics::getKeyState(graphics::SCANCODE_H)) || m) {
				graphics::playMusic(std::string(ASSET_PATH) + "redemption2.ogg", 0.1f, true, 5000);
				s = true; 
				time = graphics::getGlobalTime();
				m = false; 	
			}
		}
		if (!pausemode) {
		graphics::MouseState mouse; 
		graphics::getMouseState(mouse); 
		if (mouse.button_left_pressed && a && (graphics::getGlobalTime() > time2 + 30 || !l))  
		{
			spawnOrange(); 
			time2 = graphics::getGlobalTime(); 
			l = true; 
		}
		if (a) { 
			spawnCorona(); 
		}
		if (player) {
			player->update();
		}
		spawnEnemy();
		for (int j = 1; j < 25; j++) {
			if (enemy[j]) {
				enemy[j]->update(); 
			}
			if (coronas[j]) { 
				coronas[j]->update(); 
				if (coronas[j]->gety() > CANVAS_HEIGHT - 30.0f) {  
					delete coronas[j]; 
					coronalive -= 1; 
					coronas[j] = nullptr;  
					corona_initialized[j] = false;  
				}
			}
		}
		for (int j = 0; j < 100; j++) {
			if (orangebullets[j]) {
				orangebullets[j]->update();
				if (orangebullets[j]->gety() < 0) { 
					delete orangebullets[j]; 
					orangebullets[j] = nullptr;  
					orange_initialized[j] = false;
				}
			}
		}
		for (int h = 1; h < 25; h++) {
			if (checkCollision(h)) {  
				delete player; 
				player = nullptr; 
				f = true; 
			}
		}
		for (int h = 0; h < 100; h++) {
			for (int j = 1; j < 25; j++) {
				if (deathtime[j] && enemy[j]) { 
					if (graphics::getGlobalTime() > deathtime[j] + 1500.0f) {  
						if (enemy[j]->getlives() == 0 || enemy[j]->getlives() < 0) {  
							delete enemy[j];
							enemy[j] = nullptr;  
							totaldeaddonuts += 1;  
						}
					}
				}
				if (checkCollision2(j, h)) { 
					enemy[j]->declives(); 
					if (enemy[j]->getlives() == 0) { 
						deathtime[j] = graphics::getGlobalTime();  
						graphics::playSound(std::string(ASSET_PATH) + "Bomb.mp3", 0.1f, false);
					}
					delete orangebullets[h];  
					orangebullets[h] = nullptr;
				}
			}
		}
		if (totaldeaddonuts % 24 == 0 && totaldeaddonuts != 0 && !w) { 
			w = true;  
			totaltotaldead += 1;  
		}
		if (f && started) { 
			graphics::playMusic(std::string(ASSET_PATH) + "sadviolinmgl.mp3", 0.5f, true); 
			started = false; 
		}
		if (w && started && !f) {
			delete player; 
			player = nullptr;
			graphics::playMusic(std::string(ASSET_PATH) + "champions.mp3", 0.3f, true); 
			started = false; 
			score = (totaltotaldead * 24 * 50) - (totaloranges * 5); 
		}
		if (w && graphics::getKeyState(graphics::SCANCODE_E) && last) { 
			last = false; 
			q = false; 
			totaloranges = 0; 
			totaltotaldead = 0;
			graphics::playMusic(std::string(ASSET_PATH) + "SonicLiberation.mp3", 0.2f, true); 
		}
		if ((w || f) && graphics::getKeyState(graphics::SCANCODE_R) && q) { 
			totaldeaddonuts = 0; 
			if (f) {
				totaloranges = 0;
				totaltotaldead = 0;
			}
			w = false; 
			f = false;
			init(); 
			player_initialized = false; 
			a = false; 
			s = true; 
			m = true; 
			started = true; 
		}
		if (last == false) { 
			if (score > plscores[4]) {
				if (!enter && !enter_pr && !maxl) { 
					if (firstletter) {
						username.erase(std::prev(username.end()));
						maxx -= 1;
						firstletter = false;
					}
					if (graphics::getKeyState(graphics::SCANCODE_A)) {
						username += "A";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_B)) {
						username += "B";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_C)) {
						username += "C";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_D)) {
						username += "D";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_E)) {
						username += "E";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_F)) {
						username += "F";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_G)) {
						username += "G";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_H)) {
						username += "H";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_I)) {
						username += "I";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_K)) {
						username += "K";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_L)) {
						username += "L";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_M)) {
						username += "M";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_N)) {
						username += "N";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_O)) {
						username += "O";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_P)) {
						username += "P";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_Q)) {
						username += "Q";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_R)) {
						username += "R";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_S)) {
						username += "S";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_T)) {
						username += "T";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_J)) {
						username += "J";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_U)) {
						username += "U";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_V)) {
						username += "V";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_W)) {
						username += "W";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_X)) {
						username += "X";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_Y)) {
						username += "Y";
						maxx += 1;
					}
					if (graphics::getKeyState(graphics::SCANCODE_Z)) {
						username += "Z";
						maxx += 1;
					}
					if (maxx >= 10) { 
						maxl = true;
					}
				}
				if (graphics::getKeyState(graphics::SCANCODE_RETURN) && !enter_pr) {
					enter = true;
					q = true;
				}
				if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE)) {
					if (maxx > 0) { 
						username.erase(std::prev(username.end())); 
						if (maxx == 10) { 
							maxl = false;
							q = false;
						}
						maxx -= 1;	
					}
				}
				if (enter) {  
					plnames[4] = username; 
					plscores[4] = score; 
					std::sort(plscores, plscores + 5, std::greater<int>());  
					for (int i = 0; i < 4; i++) {
						if (plscores[i] == score) { 
							temp = plnames[i];  
							plnames[i] = plnames[4]; 

							for (int j = 4; j > i + 1; j--) { 
								plnames[j] = plnames[j - 1];

							}
							plnames[i + 1] = temp; 
						}
					}
					enter = false;
					enter_pr = true;
					writefile();	
				}
			}
			else { 
				enter_pr = true;
				q = true;
			}
		}
	}
}
void Game::draw() 
{
	graphics::Brush br; 
	br.outline_opacity = 0.0f; 
	if (!d) {
		br.fill_color[0] = 0.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br); 
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
		br.texture = std::string(ASSET_PATH) + "child_mask.png"; 
		graphics::drawRect(150, CANVAS_HEIGHT - 150, 492, 512, br);                   
		graphics::setFont(std::string(ASSET_PATH) + "Saucer BB.ttf"); 
		br.fill_color[0] = 0.6f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.8f;
		graphics::drawText(33, 50, 50, "  BEAT THE CORONA POSITIVE DONUTS", br); 
		br.fill_color[0] = 0.9f;
		br.fill_color[1] = 0.9f;
		br.fill_color[2] = 0.9f;
		graphics::drawText(250, 150, 60, "  DONUTS HAVE CORONA ", br); 
		graphics::drawText(300, 220, 70, "  KILL THE DONUTS  ", br); 
		br.fill_color[0] = 0.6f;
		br.fill_color[1] = 0.3f;
		br.fill_color[2] = 0.8f;
		graphics::drawText(240, 350, 45, " WELCOME TO THE DONUTS HELL...", br);
		graphics::drawText(280, 400, 45, " YOU ARE AN AMAZING BLENDER", br);
		graphics::drawText(300, 445, 32, " FAST THROW APPLES TO KILL THE DONUTS", br); 
		graphics::drawText(290, 480, 25, "DONUTS WORTH 50 POINTS BUT EVERY APPLE COSTS YOU 5 ...", br);		
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 0.0f;
		br.fill_color[2] = 0.0f;
		graphics::drawText(420, 550, 60, " BE CAREFUL!!!", br); 
		graphics::drawText(425, 600, 40, " AVOID CORONA BULLETS!", br); 
		graphics::drawText(430, 650, 40, " YOU WILL BE KILLED ....", br);  
		do { 
			if (graphics::getKeyState(graphics::SCANCODE_G)) {
				b = false; 
			}
			if ((int)graphics::getGlobalTime() % 2 == 0) {
				br.fill_color[0] = 0.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 1.0f;
			}
			else {
				br.fill_color[0] = 0.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 0.0f;
			}
			graphics::drawText(920, 710, 20, "PRESS G TO CONTINUE", br);
		} while (!b); 
	}
	if (d && !s) {
		br.texture = std::string(ASSET_PATH) + "corona_sign.png";
		graphics::drawRect(900, 470, 700, 500, br);
		br.texture = std::string(ASSET_PATH) + "lefy.png";
		graphics::drawRect(390, 100, 300, 200, br);
		br.texture = std::string(ASSET_PATH) + "right.png";
		graphics::drawRect(790, 100, 390, 225, br);
		graphics::drawText(250, 500, 80, "SHOOT", br);
		br.texture = std::string(ASSET_PATH) + "click.png";
		graphics::drawRect(100, 450, 150, 300, br);
		graphics::drawText(9, 640, 20, "PRESS THE GRAVE TO REST IN GAME  ", br);
		graphics::drawText(250,670, 20, "(left from the number 1) ", br);
		b = true; 
		do {
			if (graphics::getKeyState(graphics::SCANCODE_H)) {
				b = false; 
			}
			if ((int)graphics::getGlobalTime() % 12 == 0) {
				br.fill_color[0] = 0.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 0.0f;
			}
			else {
				br.fill_color[0] = 0.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 1.0f;
			}
			graphics::drawText(10, 710, 20, "PRESS H TO START", br); 
		} while (!b); 
	}
	if (s) {  
		if (randomback % 3 == 0) {
			br.texture = std::string(ASSET_PATH) + "background.png"; 
		}
		else if (randomback % 3 == 1) {
			br.texture = std::string(ASSET_PATH) + "hell.png"; 
		}
		else {
			br.texture = std::string(ASSET_PATH) + "backgroundelse.png"; 
		}
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);  
		br.texture = "";
		if (totaloranges < 10) {
			text_x = 1160.0f;
		}
		else if (totaloranges < 100) {
			text_x = 1130.0f;
		}
		else if (totaloranges < 1000) {
			text_x = 1090.0f;
		}
		else {
			text_x = 1000.0f;
		}
		if (last&&!pausemode) {  
			graphics::drawText(text_x, 400, 40, std::to_string(totaloranges), br);
		}
	}
	if (player) {
		player->draw(); 
	}
	for (int j = 1; j < 25; j++) {
		if (enemy[j]) {
			enemy[j]->draw(); 
		}
	}
	for (int j = 1; j < 25; j++) {
		if (coronas[j]) {
			coronas[j]->draw(); 
		}
	}
	for (int j = 0; j < 100; j++) {
		if (orangebullets[j]) {
			orangebullets[j]->draw();
		}
	}
	if (f) { 
		br.texture = "";
		br.fill_color[0] = 0.2f;
		br.fill_color[1] = 0.2f;
		br.fill_color[2] = 0.2f;
		br.fill_opacity = 0.8f;
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;
		br.fill_opacity = 1.0f;
		br.texture = std::string(ASSET_PATH) + "go.png";
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, 750, 530, br);
		b = true;
		do { 
			if (graphics::getKeyState(graphics::SCANCODE_R)) {
				b = false; 
			}
			if ((int)graphics::getGlobalTime() % 12 == 0) {
				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 1.0f;
				br.fill_color[2] = 1.0f;
			}
			else {
				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 0.0f;
				br.fill_color[2] = 0.0f;
			}
			graphics::drawText(10, 710, 30, "PRESS R TO TRY AGAIN", br);
		} while (!b);  
	}
	if (w && !f) {
		br.texture = std::string(ASSET_PATH) + "victory.png"; 
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
		if (last) {
			graphics::drawText(10, 500, 30, "PRESS R TO GO TO THE NEXT LEVEL ", br);
			graphics::drawText(25, 680, 30, "PRESS E TO STOP AND GO TO THE HIGHSCORES", br);
		}
		if (last == false) {
			br.texture = std::string(ASSET_PATH) + "highscore.png";  
			graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
			br.fill_color[0] = 0.02f;
			br.fill_color[1] = 0.06f;
			br.fill_color[2] = 0.07f;
			graphics::drawText(400, 100, 90, "HIGHSCORES", br);
			for (int j = 0; j < 5; j++) {
				br.fill_color[0] = 0.9f;
				br.fill_color[1] = 0.7f;
				br.fill_color[2] = 0.55f;
				graphics::drawText(100, 425 + 50 * j, 40, plnames[j], br);
				graphics::drawText(550, 425 + 50 * j, 40, std::to_string(plscores[j]), br);
			}	

			if (score < plscores[4]) { 
				br.fill_color[0] = 0.02f;
				br.fill_color[1] = 0.06f;
				br.fill_color[2] = 0.07f;
				graphics::drawText(400, 200, 40, "Your score were too low", br);
				graphics::drawText(400, 300, 30, " Your score was:  " + std::to_string(score), br);
				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 1.0f;
				br.fill_color[2] = 1.0f;
				graphics::drawText(700, 680, 30, "PRESS R TO PLAY AGAIN", br);
			}
			else { 
				br.fill_color[0] = 0.02f;
				br.fill_color[1] = 0.06f;
				br.fill_color[2] = 0.07f;
				graphics::drawText(300, 200, 50, "WELL  DONE ", br);
				graphics::drawText(10, 260, 50, " WRITE YOUR NICKNAME: ", br);
				graphics::drawText(250, 310, 30, " Your score is:  " + std::to_string(score), br);
				graphics::drawText(750, 260, 50, username, br);
				if (enter_pr) { 
					br.fill_color[0] = 1.0f;
					br.fill_color[1] = 1.0f;
					br.fill_color[2] = 1.0f;
					graphics::drawText(700, 680, 30, "PRESS R TO PLAY AGAIN", br);
				}
			}
		}
	}
	if (pausemode&&s) {
		br.texture = std::string(ASSET_PATH) + "1.png"; 
		graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);  
	}
}
void Game::init() //h init 
{
	enter_pr = false; 
	maxl = false;
	username = "";
	firstletter = true;
	q = true;
	last = true;
	enter = false;
	maxx = 0;
	if (s != true) {
		graphics::playMusic(std::string(ASSET_PATH) + "Investigations (Kevin MacLeod) - Gaming Background Music (HD).mp3", 0.5f );
	}
	for (int j = 1; j < 25; j++) {
		enemy_initialized[j] = false;
		enemy[j]=nullptr;
		coronas[j] = nullptr;
		corona_initialized[j] = false;
	}
	for (int j = 0; j < 100; j++) {
		orangebullets[j] = nullptr;
		orange_initialized[j] = false;
	}
	coronalive = 0;
	time2 = 0;
	readfile();  
}
Game::Game()
{
}
Game::~Game()  
{
	if (player)
	{
		delete player; 
	}
	for (int j = 0; j < 100; j++) {
		if (orangebullets[j]) 
		{
			delete orangebullets[j]; 
		}
	}
	for (int j=1; j<25; j++)
		if (enemy[j]){
		delete enemy[j]; 
		delete coronas[j]; 
	}
}
void Game::spawnEnemy()
{
	if ( s&& graphics::getGlobalTime()>time+1000)  
	{
		for (int j = 1; j < 25; j++) {
			if (!enemy_initialized[j]) {
				enemy[ j] = new Enemies(*this);
				enemy_initialized[j] = true; 
				if (j < 10) { 
					enemy[j]->setx(j * 130.0f);
					enemy[j]->sety(80.0f);
				}
				else if (9<j &&j <=17) {
					enemy[j]->setx((j - 9) * 130.0f+65.0f);
					enemy[j]->sety(190.0f);
				}
				else   {
					enemy[j]->setx((j - 17) * 130.0f +130.0f  );
					enemy[j]->sety(297.0f);
				}
			}
		}
		if(enemy[1]){ 
			if (enemy[1]->getx() < 80.0f) 
			{
				for (int j = 1; j < 25; j++) {
					if (enemy[j]) { 
						enemy[j]->setspeed(0.0f); 
						a = true; 
					}
				}
			}
		}
	}
}
void Game::spawnCorona()
{												
		randomnumber = rand() % 24 + 1; 
		if ((coronalive < 7) &&(( randomnumber <= 1 || randomnumber >= 9) || (randomnumber > 1 && randomnumber < 9 && enemy[16 + randomnumber] == nullptr))) {
			if (!corona_initialized[randomnumber]) { 
				if (enemy[randomnumber]) { 
					if (enemy[randomnumber]->getlives() > 0) { 
						coronas[randomnumber] = new Corona(*this); 
						coronas[randomnumber]->setx(enemy[randomnumber]->getx());  
						coronas[randomnumber]->sety(enemy[randomnumber]->gety() + 56); 
						corona_initialized[randomnumber] = true; 
						coronalive += 1; 
					}
				}
			}
		}
	}
void Game::spawnOrange() { 
	if (player) { 
		for (int j = 0; j < 100; j++) { 
			if (!orange_initialized[j]) { 
				orangebullets[j] = new Oranges(*this); 
				orangebullets[j]->setx(player->getx()); 
				orange_initialized[j] = true;  
				totaloranges += 1;
				break; 

			}
		}
	}
}
bool Game::checkCollision(int h)
{	
		if (!player || !coronas[h]) { 
			return false;
		}
		if (coronas[h]) {
			Disk d1 = coronas[h]->getCollisionHull();
			Rect p1 = player->getCollisionRect();

			float DeltaX = d1.cx - std::max(p1.cx - p1.width / 2, std::min(d1.cx, p1.cx + p1.width / 2));
			float DeltaY = d1.cy - std::max(p1.cy - p1.height / 2, std::min(d1.cy, p1.cy + p1.height / 2));
			return (DeltaX * DeltaX + DeltaY * DeltaY) < (d1.radius * d1.radius); 
		}
}
bool Game::checkCollision2(int i,int h)
{
	if (orangebullets[h]) { 
		
		if (enemy[i]) { 
			if (enemy[i]->getlives() > 0) {
				Disk d1 = orangebullets[h]->getCollisionHull(); 
				Disk d2 = enemy[i]->getCollisionHull();

				float DeltaX = d1.cx - d2.cx;
				float DeltaY = d1.cy - d2.cy;
				return sqrt(DeltaX * DeltaX + DeltaY * DeltaY) < (d1.radius + d2.radius);  
			}
		}
		else { 
			return false;
		}
	}
	else { 
		return false;
	}
}
std::string Game:: readfile() {  
	std::ifstream file(filename);  
	if (!file) { 
		return "File does not exist";
	}
	std::string line; 
	numlines = 0;  
	while (getline(file, line) && numlines < 5) {
		std::string plname;
		int plscore; 
		file >> plname >> plscore;
		plnames[numlines] = plname;
		plscores[numlines] = plscore;
		numlines++; 
	}
	if (file.fail()) { 
		file.close(); 
		return "Error reading the file"; 
	}
	file.close(); 
	return "Ok";
}
void Game::writefile() { 
	std::ofstream file(filename); 
	file << "" << std::endl; 
	for (int i = 0; i < 5; i++) { 
		if (!file) { 
			std::cerr << "Cannot open file" << std::endl;
			return; 
		}
		file << plnames[i] + " " << plscores[i] << std::endl; 
		if (file.fail()) { 
			std::cerr << "Could not write data" << std::endl;
		}
	}
	file.close(); 
	return; 
}