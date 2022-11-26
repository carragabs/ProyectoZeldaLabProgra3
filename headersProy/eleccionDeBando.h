#pragma once
#include <iostream>
using namespace std;

struct coordenadas {
	int xRect; int yRect; bool colisionAbajo;
};

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

public:
	eleccionDeBando(ALLEGRO_DISPLAY* pantallaMain)
	{
		pantalla = pantallaMain;
	}
	void crearEleccionBando();
private:

};

bool eleccionDeBando::crearColisionesLider(coordenadas  objeto,double objetoW, double objetoH,
	double protaW, double protaH)
{
	if (y * desplaza < objeto.yRect + objetoH && y * desplaza >(objeto.yRect + objetoH) - 8
		&& (x * desplaza < objeto.xRect + objetoW) && (x * desplaza + protaW > objeto.xRect) )
	{
		//Si y esta en la pos abajo del tesoro O si se da la colision ABAJO
		//cout << "COLLISION TRUE!" << endl;
		y = (objeto.yRect + objetoH) / desplaza;
		return true;
	}
	if (y * desplaza + protaH > objeto.yRect && (y * desplaza + protaH < objeto.yRect + 8)
		&& (x * desplaza < objeto.xRect + objetoW) && (x * desplaza + protaW > objeto.xRect))
	{
		// cout << "COLLISION TRUE!" << endl;
		y = (objeto.yRect - (protaH)) / desplaza;
	}

	if (x * desplaza < objeto.xRect + objetoW && x * desplaza >(objeto.xRect + objetoW) - 8
		&& (y * desplaza < objeto.yRect + objetoH) && (y * desplaza + protaH > objeto.yRect))
	{
		// cout << "COLLISION TRUE!" << endl;
		x = (objeto.xRect + objetoW) / desplaza;
	}
	if (x * desplaza + protaW > objeto.xRect && x * desplaza + protaW < objeto.xRect + 8
		&& (y * desplaza < objeto.yRect + objetoH) && (y * desplaza + protaH > objeto.yRect))
	{
		// cout << "COLLISION TRUE!" << endl;
		x = (objeto.xRect - protaW) / desplaza;
	}
	return false;
}

void eleccionDeBando::crearEleccionBando()
{
	al_set_window_title(pantalla, "Eleccion de Bando");
	
	ALLEGRO_BITMAP* prota = al_load_bitmap("Imagenes/Alm1.png");
	ALLEGRO_BITMAP* warpOff = al_load_bitmap("Imagenes/warpOff.png");
	ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/castleOutside.jpg");
	ALLEGRO_BITMAP* manBlue = al_load_bitmap("Imagenes/oldManBlue.png");
	ALLEGRO_BITMAP* manRed = al_load_bitmap("Imagenes/oldManRed.png");

	double protaW = 32.5;
	double protaH = 35;
	
	coordenadas coordBlue = { 206, 82 , false};
	double blueW = 25;
	double blueH = 25;
	coordenadas coordRed = { 553, 80 , false };
	double redW = 25;
	double redH = 25;

	ALLEGRO_EVENT_QUEUE* Mis_eventos;


	ALLEGRO_EVENT evento;

	ALLEGRO_TIMER* timer;


	Mis_eventos = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	// asigno eventos a la lista de eventos

	al_register_event_source(Mis_eventos, al_get_timer_event_source(timer));

	al_register_event_source(Mis_eventos, al_get_keyboard_event_source());

	al_register_event_source(Mis_eventos, al_get_display_event_source(pantalla));


	ALLEGRO_KEYBOARD_STATE teclado;

	// inicializar vbles

	desplaza = 4;
	x = 380 / 4;

	y = 360 / 4;


	paso = 0;

	dir = 0;


	salir = false;
	coordenadas coordElegido;

	Transition transBando;
	transBando.drawTransitionReversa(pantalla, fondo, 962, 962, prota, paso, dir, x, y, desplaza);
	al_start_timer(timer);

	while (!salir)
	{
		coordBlue.colisionAbajo = false;
		coordRed.colisionAbajo = false;
		al_clear_to_color(al_map_rgb(120, 90, 90));
		al_draw_scaled_bitmap(fondo, 0, 0, 962, 962, 0, 0, 800, 600, 0);
		al_draw_scaled_bitmap(warpOff, 1, 9, 15, 15, 380, 360, 30, 30, 0);
		al_draw_bitmap_region(prota, paso * 32.5, dir * 35, 32.5, 35, x * desplaza, y * desplaza, 0);
		al_draw_scaled_bitmap(manBlue, 0,0,17,21,206,82,25,25,0);
		al_draw_scaled_bitmap(manRed,0,0,1280,1733,553,80,25,25,0);

		al_flip_display();

		al_wait_for_event(Mis_eventos, &evento);

		al_get_keyboard_state(&teclado);

		if (al_key_down(&teclado, ALLEGRO_KEY_UP))

		{

			y--;

			cout << "y: " << y * desplaza << endl;
			cout << "x: " << x * desplaza << endl;

			dir = 4;

			paso++;

		}

		if (al_key_down(&teclado, ALLEGRO_KEY_DOWN))

		{

			y++;

			cout << "y: " << y * desplaza << endl;
			cout << "x: " << x * desplaza << endl;

			dir = 3;

			paso++;

		}

		if (al_key_down(&teclado, ALLEGRO_KEY_LEFT))

		{

			x--;

			cout << "x: " << x * desplaza << endl;
			cout << "y: " << y * desplaza << endl;

			dir = 1;

			paso++;

		}

		if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT))

		{

			x++;

			cout << "x: " << x * desplaza << endl;
			cout << "y: " << y * desplaza << endl;


			dir = 2;

			paso++;

		}
		if (paso > 3) paso = 0;

		coordBlue.colisionAbajo = crearColisionesLider(coordBlue,blueW,blueH,protaW,protaH);
		coordRed.colisionAbajo = crearColisionesLider(coordRed, redW, redH, protaW, protaH);
		//cout << "col abajo blue" << coordBlue.colisionAbajo << endl;
		if (al_key_down(&teclado, ALLEGRO_KEY_SPACE))
		{
			if (coordBlue.colisionAbajo || coordRed.colisionAbajo)
			{
				al_draw_scaled_bitmap(fondo, 0, 0, 962, 962, 0, 0, 800, 600, 0);
				al_draw_scaled_bitmap(warpOff, 1, 9, 15, 15, 380, 360, 30, 30, 0);
				al_draw_scaled_bitmap(manBlue, 0, 0, 17, 21, 206, 82, 25, 25, 0);
				al_draw_scaled_bitmap(manRed, 0, 0, 1280, 1733, 553, 80, 25, 25, 0);
				ALLEGRO_FONT* textboxFont = al_load_font("Fonts/ReturnofGanon.ttf", 40, 0);
				//ALLEGRO_BITMAP* boxoutline = al_load_bitmap("alttpTextbox.png");
				//al_draw_scaled_bitmap(boxoutline,0,0,378,122, 250, 272,300,22,0);
				//al_flip_display();


				if (coordBlue.colisionAbajo)
				{

					coordElegido = coordBlue;
					ALLEGRO_BITMAP* linkBlue = al_load_bitmap("Imagenes/linkblue.png");
					al_draw_text(textboxFont, al_map_rgb(0,0,255), 250, 272, NULL, "Bienvenido a los EMPIRITAS !");
					al_draw_scaled_bitmap(linkBlue, 92, 2282, 28, 31, x*desplaza , y*desplaza , 32.5, 35, 0);
					al_flip_display();
					al_rest(5);
					break;
					
				}
				coordRed = coordRed;
				ALLEGRO_BITMAP* linkRed = al_load_bitmap("Imagenes/linkred.png");
				al_draw_text(textboxFont, al_map_rgb(255, 0, 0), 250, 272, NULL, "Bienvenido a los RACIONALISTAS !");
				al_draw_scaled_bitmap(linkRed, 92, 2282, 28, 31, x * desplaza, y * desplaza, 32.5, 35, 0);
				al_flip_display();
				al_rest(5);
				break;

			}
		}

	}

}