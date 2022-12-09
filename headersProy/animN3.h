#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "SpritesheetRow.h"

using namespace std;

class animacionN3
{
public:
	ALLEGRO_DISPLAY* display;
	SpritesheetRow miSR;
	ALLEGRO_BITMAP* batMapa;
	ALLEGRO_BITMAP* link;
	ALLEGRO_BITMAP* enemigo;
	double x, y;
	int rot;
	int paso;
	int dir;

	animacionN3(ALLEGRO_DISPLAY* displayMain)
	{
		display = displayMain;

	}
	void crearAnimaciones();
	void drawAtkLink(double dxAtk, double dyAtk);
	void drawWalkLink();
	void drawWalkLinkRev();
	void drawWalkEnmy();
	void drawWalkEnmyRev();
	void drawAtkEnmy(int dxAtk, int dyAtk);
	void drawDmgLink();
	void drawDeathLink();
	void drawVictoryLink();
	void drawDmgEnmy();
	void drawDeathEnmy();
	void drawEmpate();
	void drawAtkEnmyEmpate(int dxAtk, int dyAtk);

private:

};

void animacionN3::drawAtkLink(double dxAtk, double dyAtk)
{
	varsFrameFlag varslinkAtk[27];
	varslinkAtk[0] = { link,88, 1912, 28, 36,dxAtk, dyAtk, 150, 200, 0.1, 1 };
	varslinkAtk[1] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varslinkAtk[2] = { enemigo,13,271, 27, 35, 600, 320, 150, 180, 0 , 1 };

	varslinkAtk[3] = { link,130, 1912 ,28, 36,dxAtk, dyAtk, 150, 200, 0.1, 1 };
	varslinkAtk[4] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varslinkAtk[5] = { enemigo,13,271, 27, 35, 600, 320, 150, 180, 0 , 1 };

	varslinkAtk[6] = { link, 165, 1912 , 35, 36,dxAtk, dyAtk, 150, 200, 0.1, 1 };
	varslinkAtk[7] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varslinkAtk[8] = { enemigo,13,271, 27, 35, 600, 320, 150, 180, 0 , 1 };

	varslinkAtk[9] = { link, 205, 1912 , 35, 36,dxAtk, dyAtk, 150, 200, 0.1, 1 };
	varslinkAtk[10] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varslinkAtk[11] = { enemigo,13,271, 27, 35, 600, 320, 150, 180, 0 , 1 };

	varslinkAtk[12] = { link,245, 1912 , 40, 36,dxAtk, dyAtk, 150, 200, 0.1, 1 };
	varslinkAtk[13] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varslinkAtk[14] = { enemigo,13,271, 27, 35, 600, 320, 150, 180, 0 , 1 };

	varslinkAtk[15] = { link,285, 1912 , 40, 36,dxAtk, dyAtk, 150, 200, 0.1, 1 };
	varslinkAtk[16] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varslinkAtk[17] = { enemigo,13,271, 27, 35, 600, 320, 150, 180, 0 , 1 };

	varslinkAtk[18] = { link,330, 1912 , 30, 36,dxAtk, dyAtk, 150, 200, 0.1, 1 };
	varslinkAtk[19] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varslinkAtk[20] = { enemigo,13,271, 27, 35, 600, 320, 150, 180, 0 , 1 };

	varslinkAtk[21] = { link,90, 1949 , 25, 36,dxAtk, dyAtk, 150, 200, 0.1, 1 };
	varslinkAtk[22] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varslinkAtk[23] = { enemigo,13,271, 27, 35, 600, 320, 150, 180, 0 , 1 };

	varslinkAtk[24] = { link,130, 1949 , 25, 36,dxAtk, dyAtk, 150, 200, 0.1, 1 };
	varslinkAtk[25] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varslinkAtk[26] = { enemigo,13,271, 27, 35, 600, 320, 150, 180, 0 , 1 };

	al_draw_bitmap(batMapa, 0, 0, 0);
	al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);
	miSR.drawSpritesheetRowFlag(27, display, varslinkAtk);
	al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
	al_flip_display();

	return;
}

void animacionN3::drawWalkLink()
{
	x = 50;
	rot = 1;
	while (true) {

		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(link, paso * 30, 1530, 30, 23, x,
			y, 150, 140, rot);
		al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);
		al_flip_display();
		al_rest(0.1);

		x += 30;
		paso++;

		if (x > 600 - 150)
			break;

		if (paso > 9) paso = 3;
	}
}

void animacionN3::drawWalkLinkRev()
{
	x = 600-150;
	rot = 0;
	while (true) {

		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(link, paso * 30, 1530, 30, 23, x,
			y, 150, 140, rot);
		al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);
		al_flip_display();
		al_rest(0.1);

		x -= 30;
		paso++;

		if (x < 50)
			break;

		if (paso > 9) paso = 3;
	}
	al_draw_bitmap(batMapa, 0, 0, 0);
	al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
	al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);
	al_flip_display();
}

void animacionN3::drawWalkEnmy()
{
	x = 600;
	rot = 1;
	paso = 0;
	while (true) {

		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(enemigo, 10 + paso * 30, 270, 30, 35, x,
			y-30, 150, 180, rot);
		al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
		al_flip_display();
		al_rest(0.1);

		x -= 30;
		paso++;

		if (x <  50+150)
			break;

		if (paso > 3) paso = 0;
	}
}

void animacionN3::drawWalkEnmyRev()
{
	x = 50+150;
	rot = 0;
	paso = 0;
	while (true) {

		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(enemigo, 10 + paso * 30, 270, 30, 35, x,
			y - 30, 150, 180, rot);
		al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
		al_flip_display();
		al_rest(0.1);

		x += 30;
		paso++;

		if (x > 600)
			break;

		if (paso > 3) paso = 0;
	}
	al_draw_bitmap(batMapa, 0, 0, 0);
	al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
	al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);
	al_flip_display();
}

void animacionN3::drawAtkEnmy(int Dx, int Dy)
{
	varsFrameFlag varsenmyAtk[18];
	varsenmyAtk[0] = { enemigo , 130, 270, 25, 35, Dx+.0 , Dy+.0, 150, 180, 0.1, 1 };
	varsenmyAtk[1] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[2] = { link, 206, 1985, 35, 31, 50, 360, 150, 140, 0 , 1};

	varsenmyAtk[3] = { enemigo , 155, 270, 40, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[4] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[5] = { link, 206, 1985, 35, 31, 50, 360, 150, 140, 0 , 1 };

	varsenmyAtk[6] = { enemigo , 195, 270, 40, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[7] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[8] = { link, 206, 1985, 35, 31, 50, 360, 150, 140, 0 , 1 };

	varsenmyAtk[9] = { enemigo , 240, 270, 45, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[10] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[11] = { link, 206, 1985, 35, 31, 50, 360, 150, 140, 0 , 1 };

	varsenmyAtk[12] = { enemigo , 290, 270, 35, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[13] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[14] = { link, 206, 1985, 35, 31, 50, 360, 150, 140, 0 , 1 };

	varsenmyAtk[15] = { enemigo , 340, 270, 30, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[16] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[17] = { link, 206, 1985, 35, 31, 50, 360, 150, 140, 0 , 1 };

	al_draw_bitmap(batMapa, 0, 0, 0);
	al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
	miSR.drawSpritesheetRowFlag(18, display, varsenmyAtk);

	al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);
	al_flip_display();
	return;
}

void animacionN3::drawAtkEnmyEmpate(int Dx, int Dy)
{

	varsFrameFlag varsenmyAtk[18];
	varsenmyAtk[0] = { enemigo , 130, 270, 25, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[1] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[2] = { link, 206, 1679, 29, 26, 50, 360, 150, 140, 0, 1 };

	varsenmyAtk[3] = { enemigo , 155, 270, 40, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[4] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[5] = { link, 206, 1679, 29, 26, 50, 360, 150, 140, 0, 1 };

	varsenmyAtk[6] = { enemigo , 195, 270, 40, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[7] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[8] = { link, 206, 1679, 29, 26, 50, 360, 150, 140, 0, 1 };

	varsenmyAtk[9] = { enemigo , 240, 270, 45, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[10] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[11] = { link, 206, 1679, 29, 26, 50, 360, 150, 140, 0, 1 };

	varsenmyAtk[12] = { enemigo , 290, 270, 35, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[13] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[14] = { link, 206, 1679, 29, 26, 50, 360, 150, 140, 0, 1 };

	varsenmyAtk[15] = { enemigo , 340, 270, 30, 35, Dx + .0 , Dy + .0, 150, 180, 0.1, 1 };
	varsenmyAtk[16] = { batMapa,0, 0, 800, 600, 0 , 0, 800, 600, 0, 0 };
	varsenmyAtk[17] = { link, 206, 1679, 29, 26, 50, 360, 150, 140, 0, 1 };

	al_draw_bitmap(batMapa, 0, 0, 0);
	al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
	miSR.drawSpritesheetRowFlag(18, display, varsenmyAtk);

	al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 50+70, 360, 150, 180, 1);
	al_flip_display();
	return;
}

void animacionN3::drawDmgLink()
{
	for (size_t i = 0; i < 7; i++)

	{
		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(link, 240, 1648, 25, 27, 50, 360, 150, 140, 1);
		al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 50 + 100, 360, 150, 180, 1);
		al_flip_display();
		al_rest(0.1);

		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(link, 265, 1645, 35, 35, 50, 360, 150, 140, 1);
		al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 50 + 100, 360, 150, 180, 1);
		al_flip_display();
		al_rest(0.1);
	}

}

void animacionN3::drawDeathLink()
{
	//90,2498 width = 30 height = 26 dx = 90+30 dy = 2498 

	x = 50; y = 360;
	rot = 0;

	for (size_t i = 0; i < 5; i++)	
	{

		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(link, 90 + i*30, 2498, 30, 26, x,
			y, 150, 140, rot);
		al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 50 + 100, 360, 150, 180, 1);
		al_flip_display();
		al_rest(0.1);
		
	}

}

void animacionN3::drawVictoryLink()
{
	//120,2315 width = 30 height = 32 dx = 120+30 dy = 2315 
	x = 600-170; y = 360;
	rot = 0;

	al_draw_bitmap(batMapa, 0, 0, 0);
	al_draw_scaled_bitmap(link, 180, 2286, 30, 26, 600-140,
		y, 130, 120, rot);
	//al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);
	al_flip_display();
	al_rest(0.5);

	for (size_t i = 0; i < 8; i++)
	{

		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(link, 120 + i * 30, 2315, 30, 32, x,
			y, 150, 140, rot);
		//al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);
		al_flip_display();
		al_rest(0.1);

	}

}

void animacionN3::drawDmgEnmy()
{
	bool rojo;

	for (size_t i = 0; i < 7; i++)
	{
		rojo = i % 2;

		al_draw_bitmap(batMapa, 0, 0, 0);
		if(!rojo)
			al_draw_scaled_bitmap(enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);

		al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 600-50, 360, 150, 140, 1);
		al_flip_display();
		al_rest(0.1);
	}
}

void animacionN3::drawDeathEnmy()
{
	ALLEGRO_BITMAP* enmyDeath = al_load_bitmap("Imagenes/enemyDeath.png");

	for (size_t i = 0; i < 5; i++)
	{
		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 600 - 50, 360, 150, 140, 1);
		al_draw_scaled_bitmap(enmyDeath,i*25,0,25,27,600,320,150,180,0);
		al_flip_display();
		al_rest(0.1);
	}
	al_draw_scaled_bitmap(enmyDeath, 130, 3, 25, 26, 600, 320, 150, 180, 0);
	al_draw_bitmap(batMapa, 0, 0, 0);
	al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 600 - 50, 360, 150, 140, 1);
	al_flip_display();
	al_rest(0.1);

	al_draw_scaled_bitmap(enmyDeath, 156, 3, 25, 26, 600, 320, 150, 180, 0);
	al_draw_bitmap(batMapa, 0, 0, 0);
	al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 600 - 50, 360, 150, 140, 1);
	al_flip_display();
	al_rest(0.1);

}

void animacionN3::drawEmpate()
{
	drawWalkEnmy();
	al_draw_scaled_bitmap(link,206,1679,29,26, 50, 360, 150, 140, 1);
	al_flip_display();
	drawAtkEnmyEmpate(50 + 70, 360);

}

void animacionN3::crearAnimaciones()
{
	bool salir = false;
	while(!salir)
	{
		paso = 3;
		rot = 1;
		x = 50; y = 360;

		batMapa = al_load_bitmap("Imagenes/Batallabase.png");
		link = al_load_bitmap("Imagenes/linkred.png");
		enemigo = al_load_bitmap("Imagenes/4Senemies.png");

		al_draw_bitmap(batMapa, 0, 0, 0);
		al_draw_scaled_bitmap(link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
		al_convert_mask_to_alpha(enemigo,al_map_rgb(0,128,255));
		al_draw_scaled_bitmap(enemigo,13,271, 27, 35, 600, 320, 150, 180, 1);
		al_flip_display();		
		system("pause");

		//Animaciones

		//LINK
		//ATK LINK
		drawWalkLink();
		drawAtkLink(600-50,360);
		drawDmgEnmy();
		drawWalkLinkRev();
		al_rest(1);

		//VICTORY LINK
		drawWalkLink();
		drawAtkLink(600 - 50, 360);
		drawDmgEnmy();
		drawDeathEnmy();

		drawVictoryLink();
		//AQUI CANCION Hallowed be thy Name de Iron Maiden
		al_rest(10);

		//ENEMIGO
		//ATK ENEMIGO
		drawWalkEnmy();
		drawAtkEnmy(50+30, 360);
		drawDmgLink();
		drawWalkEnmyRev();
		al_rest(1);

		//VICTORY ENMY (DEATH LNIK)
		drawWalkEnmy();
		drawAtkEnmy(50 + 30, 360);
		drawDmgLink();
		drawDeathLink();

		//AQUI CANCION Oh Fortuna de Carmina Burana
		al_rest(10);
		
		//EMPATE
		drawEmpate();
		al_rest(0.5);
		drawWalkEnmyRev();
		al_rest(1);
		salir = true;
	}

}
