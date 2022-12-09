#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "escena.h"
using namespace std;

struct coordenadas {
	int xRect; int yRect; bool colisionAbajo;
};

ALLEGRO_LOCKED_REGION* lock1;
ALLEGRO_BITMAP* choque1;

class eleccionDeBando
{
	ALLEGRO_DISPLAY* pantalla;
	double x, y;
	int  desplaza;
	int paso;
	int dir;
	bool salir;
	bool crearColisionesLider(coordenadas  objeto, double objetoW, double objetoH,
		double protaW, double protaH);
	void crearColisionesSoldados(coordenadas objeto, double objetoW, double objetoH,
		double protaW, double protaH);




public:
	eleccionDeBando(ALLEGRO_DISPLAY* pantallaMain)
	{
		pantalla = pantallaMain;
	}
	void crearEleccionBando();
private:
	void bloquea1();
	void desbloquea1();

};


void bloquea1()
{
	lock1 = al_lock_bitmap(choque1, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);
}

// libera memoria
void desbloquea1()
{
	al_unlock_bitmap(choque1);
}

// comprueba si esta bloqueado
bool esRojo1(int x, int y)
{
	unsigned char r, g, b;
	ALLEGRO_COLOR colorMira;
	colorMira = al_get_pixel(choque1, x, y);
	al_unmap_rgb(colorMira, &r, &g, &b);

	return (r == 255 && g == 0 && b == 0);
}

bool eleccionDeBando::crearColisionesLider(coordenadas  objeto, double objetoW, double objetoH,
	double protaW, double protaH)
{
	if (y < objeto.yRect + objetoH && y >(objeto.yRect + objetoH) - 8
		&& (x < objeto.xRect + objetoW) && (x + protaW > objeto.xRect))
	{
		//Si y esta en la pos abajo del tesoro O si se da la colision ABAJO
		//cout << "COLLISION TRUE!" << endl;
		y = (objeto.yRect + objetoH);
		return true;
	}
	if (y + protaH > objeto.yRect && (y + protaH < objeto.yRect + 8)
		&& (x < objeto.xRect + objetoW) && (x + protaW > objeto.xRect))
	{
		// cout << "COLLISION TRUE!" << endl;
		y = (objeto.yRect - (protaH));
	}

	if (x < objeto.xRect + objetoW && x >(objeto.xRect + objetoW) - 8
		&& (y < objeto.yRect + objetoH) && (y + protaH > objeto.yRect))
	{
		// cout << "COLLISION TRUE!" << endl;
		x = (objeto.xRect + objetoW);
	}
	if (x + protaW > objeto.xRect && x + protaW < objeto.xRect + 8
		&& (y < objeto.yRect + objetoH) && (y + protaH > objeto.yRect))
	{
		// cout << "COLLISION TRUE!" << endl;
		x = (objeto.xRect - protaW);
	}
	return false;
}

void eleccionDeBando::crearColisionesSoldados(coordenadas objeto, double objetoW, double objetoH,
	double protaW, double protaH)
{
	if (y < objeto.yRect + objetoH && y >(objeto.yRect + objetoH) - 8
		&& (x < objeto.xRect + objetoW) && (x + protaW > objeto.xRect))
	{
		//cout << "COLLISION TRUE!" << endl;
		y = (objeto.yRect + objetoH);
	}
	if (y + protaH > objeto.yRect && (y + protaH < objeto.yRect + 8)
		&& (x < objeto.xRect + objetoW) && (x + protaW > objeto.xRect))
	{
		// cout << "COLLISION TRUE!" << endl;
		y = (objeto.yRect - (protaH));
	}

	if (x < objeto.xRect + objetoW && x >(objeto.xRect + objetoW) - 8
		&& (y < objeto.yRect + objetoH) && (y + protaH > objeto.yRect))
	{
		// cout << "COLLISION TRUE!" << endl;
		x = (objeto.xRect + objetoW);
	}
	if (x + protaW > objeto.xRect && x + protaW < objeto.xRect + 8
		&& (y < objeto.yRect + objetoH) && (y + protaH > objeto.yRect))
	{
		// cout << "COLLISION TRUE!" << endl;
		x = (objeto.xRect - protaW);
	}

}

bool colisiona1(int x, int y)
{
	bloquea1();
	bool valor = false;
	for (int i = 1; i < 32 - 1; i++)
	{
		for (int j = 35 / 2; j < 35; j++)
		{
			int vx = x + i;
			int vy = y + j;
			if (esRojo1(vx, vy))
			{
				valor = true;
			}
		}
	}
	desbloquea1();
	return valor;
}



void eleccionDeBando::crearEleccionBando()
{
	al_set_window_title(pantalla, "Eleccion de Bando");

	choque1 = al_load_bitmap("Imagenes/MapaBandoROJO2.png");

	ALLEGRO_BITMAP* prota = al_load_bitmap("Imagenes/SheetZelda2.png");
	ALLEGRO_BITMAP* warpOff = al_load_bitmap("Imagenes/warpOff.png");
	ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/MapaNuevoBando.png");
	ALLEGRO_BITMAP* manWhite = al_load_bitmap("Imagenes/oldManWhite.png");
	ALLEGRO_BITMAP* manRed = al_load_bitmap("Imagenes/oldManRed.png");
	ALLEGRO_BITMAP* knightWhite = al_load_bitmap("Imagenes/knightWhite.png");
	ALLEGRO_BITMAP* knightRed = al_load_bitmap("Imagenes/knightRed.png");

	double protaW = 32;
	double protaH = 35;

	coordenadas coordWhite = { 206, 82 , false };
	double WhiteW = 25;
	double WhiteH = 25;
	coordenadas coordRed = { 553, 80 , false };
	double redW = 25;
	double redH = 25;

	coordenadas coordWhiteKL = { 150,70,NULL };
	coordenadas coordWhiteKR = { 257,70,NULL };
	double WhiteK_W = 30;
	double WhiteK_H = 30;

	coordenadas coordRedKL = { 503,70,NULL };
	coordenadas coordRedKR = { 611,70,NULL };
	double redK_W = 30;
	double redK_H = 30;

	ALLEGRO_EVENT_QUEUE* Mis_eventos;


	ALLEGRO_EVENT evento;

	ALLEGRO_TIMER* timer;


	Mis_eventos = al_create_event_queue();
	timer = al_create_timer(1.0 / 30);

	// asigno eventos a la lista de eventos

	al_register_event_source(Mis_eventos, al_get_timer_event_source(timer));

	al_register_event_source(Mis_eventos, al_get_keyboard_event_source());

	al_register_event_source(Mis_eventos, al_get_display_event_source(pantalla));


	ALLEGRO_KEYBOARD_STATE teclado;

	// inicializar vbles

	desplaza = 4;
	x = 380;

	y = 360;
	double ax, ay;

	paso = 0;

	dir = 0;
	int rot = 0;


	salir = false;
	coordenadas coordElegido;

	Transition transBando;
	transBando.drawTransitionReversa(pantalla, fondo, 960, 960, prota, paso, dir, x, y);
	transBando.destroyTrans();

	al_start_timer(timer);

	while (!salir)
	{
		ax = x;
		ay = y;
		coordWhite.colisionAbajo = false;
		coordRed.colisionAbajo = false;
		al_clear_to_color(al_map_rgb(120, 90, 90));
		al_draw_scaled_bitmap(fondo, 0, 0, 960, 960, 0, 0, 800, 600, 0);
		al_draw_scaled_bitmap(warpOff, 1, 9, 15, 15, 385, 360, 30, 30, 0);
		al_draw_bitmap_region(prota, paso * 32, dir * 35, 32, 35, x, y, rot);
		al_draw_scaled_bitmap(manWhite, 0, 0, 17, 21, 206, 82, 25, 25, 0);
		al_draw_scaled_bitmap(knightWhite, 0, 0, 64, 70, coordWhiteKL.xRect, coordWhiteKL.yRect, 30, 30, 0);
		al_draw_scaled_bitmap(knightWhite, 0, 0, 64, 70, coordWhiteKR.xRect, coordWhiteKR.yRect, 30, 30, 0);
		al_draw_scaled_bitmap(knightRed, 0, 0, 64, 70, coordRedKL.xRect, coordRedKL.yRect, 30, 30, 0);
		al_draw_scaled_bitmap(knightRed, 0, 0, 64, 70, coordRedKR.xRect, coordRedKR.yRect, 30, 30, 0);
		al_draw_scaled_bitmap(manRed, 0, 0, 1280, 1733, 553, 80, 25, 25, 0);

		al_flip_display();

		al_wait_for_event(Mis_eventos, &evento);

		al_get_keyboard_state(&teclado);

		if (al_key_down(&teclado, ALLEGRO_KEY_UP))

		{

			y -= desplaza;

			cout << "y: " << y << endl;
			cout << "x: " << x << endl;

			dir = 2;
			rot = 0;

			paso++;

		}

		if (al_key_down(&teclado, ALLEGRO_KEY_DOWN))

		{

			y += desplaza;

			cout << "y: " << y << endl;
			cout << "x: " << x << endl;
			rot = 0;

			dir = 0;

			paso++;

		}

		if (al_key_down(&teclado, ALLEGRO_KEY_LEFT))

		{

			x -= desplaza;

			cout << "x: " << x << endl;
			cout << "y: " << y << endl;

			rot = 0;
			dir = 1;

			paso++;

		}

		if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT))

		{

			x += desplaza;

			cout << "x: " << x << endl;
			cout << "y: " << y << endl;


			dir = 1;
			rot = 1;
			paso++;

		}

		if ((x != ax || y != ay) && colisiona1(x, y))
		{
			cout << "ES ROJO" << endl;
			x = ax;
			y = ay;
		}

		if (x < 0) x = 0;

		if (x > 800 - 32) x = 800 - 32;

		if (y < 0) y = 0;

		if (y > 600 - 35) y = 600 - 35;

		if (paso > 9) paso = 0;


		coordWhite.colisionAbajo = crearColisionesLider(coordWhite, WhiteW, WhiteH, protaW, protaH);
		coordRed.colisionAbajo = crearColisionesLider(coordRed, redW, redH, protaW, protaH);
		crearColisionesSoldados(coordWhiteKL, WhiteK_W, WhiteK_H, protaW, protaH);
		crearColisionesSoldados(coordWhiteKR, WhiteK_W, WhiteK_H, protaW, protaH);
		crearColisionesSoldados(coordRedKL, redK_W, redK_H, protaW, protaH);
		crearColisionesSoldados(coordRedKR, redK_W, redK_H, protaW, protaH);

		if (al_key_down(&teclado, ALLEGRO_KEY_SPACE))
		{
			if (coordWhite.colisionAbajo || coordRed.colisionAbajo)
			{
				al_draw_scaled_bitmap(fondo, 0, 0, 960, 960, 0, 0, 800, 600, 0);
				al_draw_scaled_bitmap(warpOff, 1, 9, 15, 15, 380, 360, 30, 30, 0);
				al_draw_scaled_bitmap(manWhite, 0, 0, 17, 21, 206, 82, 25, 25, 0);
				al_draw_scaled_bitmap(manRed, 0, 0, 1280, 1733, 553, 80, 25, 25, 0);
				al_draw_scaled_bitmap(knightWhite, 0, 0, 64, 70, coordWhiteKL.xRect, coordWhiteKL.yRect, 30, 30, 0);
				al_draw_scaled_bitmap(knightWhite, 0, 0, 64, 70, coordWhiteKR.xRect, coordWhiteKR.yRect, 30, 30, 0);
				al_draw_scaled_bitmap(knightRed, 0, 0, 64, 70, coordRedKL.xRect, coordRedKL.yRect, 30, 30, 0);
				al_draw_scaled_bitmap(knightRed, 0, 0, 64, 70, coordRedKR.xRect, coordRedKR.yRect, 30, 30, 0);
				ALLEGRO_FONT* textboxFont = al_load_font("Fonts/ReturnofGanon.ttf", 40, 0);

				if (coordWhite.colisionAbajo)
				{
					al_draw_filled_rectangle(248, 270, 680, 320, al_map_rgba(0, 0, 0, 200));
					coordElegido = coordWhite;
					ALLEGRO_BITMAP* linkWhite = al_load_bitmap("Imagenes/linkwhite.png");
					al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 250, 272, NULL, "Bienvenido a los RACIONALISTAS !");
					al_draw_scaled_bitmap(linkWhite, 92, 2282, 28, 31, x, y, 32.5, 35, 0);
					al_flip_display();
					al_rest(5);
					break;

				}
				al_draw_filled_rectangle(248, 270, 630, 320, al_map_rgba(0, 0, 0, 200));
				coordRed = coordRed;
				ALLEGRO_BITMAP* linkRed = al_load_bitmap("Imagenes/linkred.png");
				al_draw_text(textboxFont, al_map_rgb(255, 0, 0), 250, 272, NULL, "Bienvenido a los EMPIRISTAS !");
				al_draw_scaled_bitmap(linkRed, 92, 2282, 28, 31, x, y, 32.5, 35, 0);
				al_flip_display();
				al_rest(5);
				break;

			}
		}

	}
	al_clear_to_color(al_map_rgb(0,0,0));
	al_flip_display();
	al_rest(1);
	al_destroy_bitmap(choque1);

}
