
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include "escena.h"
#include "Header.h"

class minijuego3 {


	struct charco
	{
		double x, y;
		int colisionArriba;

	};
	Header teste;
	void definirPreguntas();
	ALLEGRO_EVENT_QUEUE* event_queue;
	void jugar();

	void damage();

	int contador = 0;
	int vida = 100;


	struct datos {
		int FPS;
		ALLEGRO_EVENT_QUEUE* Mis_eventos;
		ALLEGRO_COLOR fondo;
		ALLEGRO_BITMAP* img;
	} sistema;

	bool crearColisionesCharco(charco  charcoActual, double charcoActualW, double charcoActualH,
		int& x, int& y, double protaW, double protaH, int vida, int contador)
	{
		if (x  < charcoActual.x + charcoActualW && x >(charcoActual.x + charcoActualW) - 8
			&& (y < charcoActual.y + charcoActualH + 2) && (y + protaH > charcoActual.y))
		{
			// cout << "COLLISION TRUE!" << endl;
			x = (charcoActual.x + charcoActualW);
		}
		if (x + protaW > charcoActual.x && x + protaW < charcoActual.x + 8
			&& (y < charcoActual.y + charcoActualH + 2) && (y + protaH > charcoActual.y))
		{
			// cout << "COLLISION TRUE!" << endl;
			x = (charcoActual.x - protaW);
		}

		if (y < charcoActual.y + charcoActualH && y >(charcoActual.y + charcoActualH) - 8
			&& (x < charcoActual.x + charcoActualW) && (x + protaW > charcoActual.x))
		{
			//Si y esta en la pos abajo del tesoro O si se da la colision ABAJO
			//cout << "COLLISION TRUE!" << endl;
			y = (charcoActual.y + charcoActualH);
		}
		if (y + protaH > charcoActual.y && (y + protaH < charcoActual.y + (charcoActualH / 2))
			&& (x < charcoActual.x + charcoActualW) && (x + protaW > charcoActual.x))
		{
			if (charcoActual.x == 65 && charcoActual.y == 85) {
				if (charcoActual.colisionArriba == P[contador].correcta) {
					cout << "COLLISION TRUE y Respuesta verdadera!" << vida << endl;

					jugar();

					return true;

				}
				else {
					damage();
					return false;
				}

			}

			if (charcoActual.x == 272 && charcoActual.y == 85) {
				if (charcoActual.colisionArriba == P[contador].correcta) {
					cout << "COLLISION TRUE y Respuesta verdadera!" << vida << endl;
					jugar();

					return true;

				}
				else {
					damage();
					return false;
				}

			}

			if (charcoActual.x == 480 && charcoActual.y == 85) {
				if (charcoActual.colisionArriba == P[contador].correcta) {
					cout << "COLLISION TRUE y Respuesta verdadera!" << vida << endl;
					jugar();

					return true;

				}
				else {
					damage();
					return false;
				}

			}
			if (charcoActual.x == 656 && charcoActual.y == 85) {
				if (charcoActual.colisionArriba == P[contador].correcta) {
					cout << "COLLISION TRUE y Respuesta verdadera!" << vida << endl;
					jugar();

					return true;

				}
				else {
					damage();
					return false;
				}

			}
			cout << "COLLISION TRUE!" << endl;
			//y = (charcoActual.y - (protaH));
			return false;
		}


		return false;
	}

	void dibuja(ALLEGRO_COLOR fondo, int vida, int contador)
	{

		al_clear_to_color(fondo);


		escena.pinta(jugador.getCamX(), jugador.getCamY());
		jugador.pinta();
		escena.pinta(jugador.getCamX(), jugador.getCamY(), true);
		// al_draw_textf(font, al_map_rgb(60, 60, 60), 50, 330, 0, "%d, %d", px,py);
		// muestra por pantalla

		al_flip_display();


	}

	void juego(ALLEGRO_COLOR fondo, ALLEGRO_EVENT_QUEUE* Mis_eventos)
	{
	
		ALLEGRO_FONT* Triforce = al_load_font("Fonts/TNR.ttf", 23, 0);
		// nuevi

		font = al_load_ttf_font("neuropol.ttf", 64, 0);
		ALLEGRO_EVENT evento;
		bool test = true;
		bool repetir = true;
		bool dibujar = true;
		jugador.inicia();
		escena.carga();


		while (repetir)
		{





			// Pinta si es dibuja y esta vacia la lista de eventos
			if (dibujar && al_event_queue_is_empty(Mis_eventos))
			{


				dibuja(fondo, vida, contador);

				int charcoWidth = 95;
				int charcoHeight = 59;
				charco charco1 = { 65,85,1 };
				charco charco2 = { 272,85,2 };
				charco charco3 = { 480,85,3 };
				charco charco4 = { 656,85,4 };




				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 1, 30, NULL, P[contador].pregunta.c_str());
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 100, 250, NULL, P[contador].respuesta1.c_str());
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 100, 300, NULL, P[contador].respuesta2.c_str());
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 500, 250, NULL, P[contador].respuesta3.c_str());
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 500, 300, NULL, P[contador].respuesta4.c_str());


				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 105, 85, NULL, "A");
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 312, 85, NULL, "B");
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 520, 85, NULL, "C");
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 696, 85, NULL, "D");


				crearColisionesCharco(charco1, charcoWidth, charcoHeight,
					jugador.x, jugador.y, jugador.tamx, jugador.tamy, vida, contador);
				crearColisionesCharco(charco2, charcoWidth, charcoHeight,
					jugador.x, jugador.y, jugador.tamx, jugador.tamy, vida, contador);
				crearColisionesCharco(charco3, charcoWidth, charcoHeight,
					jugador.x, jugador.y, jugador.tamx, jugador.tamy, vida, contador);
				crearColisionesCharco(charco4, charcoWidth, charcoHeight,
					jugador.x, jugador.y, jugador.tamx, jugador.tamy, vida, contador);
				teste.LifeBar(vida);
				al_flip_display();
				al_draw_filled_rectangle(10, 20, vida, 10, al_map_rgb(0, 255, 0));


				dibujar = false;

			}

			// esperamos a que ocurra un evento
			al_wait_for_event(Mis_eventos, &evento);

			// se ha cerrado la ventana
			if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				repetir = false;
			}

			// se ha pulsado ESC
			if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				{
					repetir = false;
				}
			}





			// pasa un tiempo determinado
			if (evento.type == ALLEGRO_EVENT_TIMER)
			{
				dibujar = true;
				jugador.actualiza(evento);


			}
			if (contador >= 5) {


				repetir = false;
			}


			al_destroy_font(font);



		}

		al_clear_to_color(al_map_rgb(255, 255, 255));
		al_flip_display();


		al_rest(1);


		cout << "THE END";

	}


	void jugar()
	{

		ALLEGRO_EVENT Evento;

		contador++;
		vida = vida + 10;


		jugador.inicia();

		//juego(sistema.fondo, sistema.Mis_eventos, vida, contador);



	}

	void damage() {



		ALLEGRO_EVENT Evento;

		contador++;

		jugador.inicia();

		//juego(sistema.fondo, sistema.Mis_eventos, vida, contador);




	}



	void definirPreguntas() {

		P[0].pregunta = "Uno de los siguientes personajes fue el encargado de pintar la capilla Sixtina:";
		P[0].respuesta1 = "1)Donatello";
		P[0].respuesta2 = "2)Miguel Angel";
		P[0].respuesta3 = "3)Leonardo Da Vinci";
		P[0].respuesta4 = "4)Francis Bacon";
		P[0].correcta = 2;

		P[1].pregunta = "Genio del renacimiento que esculpio el Moises, el David y la Pieta";
		P[1].respuesta1 = "1) Miguel Angel Buonarroti";
		P[1].respuesta2 = "2) Rafael Sanzio";
		P[1].respuesta3 = "3)Leonardo Da Vinci";
		P[1].respuesta4 = "4)Galileo Galiley";
		P[1].correcta = 1;

		P[2].pregunta = "Durante el renacimiento el estilo artistico que impregno el arte, la filosofia, la pintura escritura fue el:";
		P[2].respuesta1 = "1)Romantisimo";
		P[2].respuesta2 = "2)Gotico";
		P[2].respuesta3 = "3)El barroco.";
		P[2].respuesta4 = "4)Clasismo";
		P[2].correcta = 3;

		P[3].pregunta = "Durante el renacimiento surge una nueva vision del hombre, que se vio reflejada en el arte, en la politica y en las ciencias sociales y humanas, a lo que se denomina";
		P[3].respuesta1 = "1)Humanismo";
		P[3].respuesta2 = "2)Teocentrismo";
		P[3].respuesta3 = "3)Antropocentrismo";
		P[3].respuesta4 = "4)Paradigma antropologico";
		P[3].correcta = 1;

		P[4].pregunta = "Cuatro genios del renacimiento (Leonardo, Donatello, Rafael y Michelangelo) han sido llevados a la pantalla en los comics de:";
		P[4].respuesta1 = "1)Tortugas Ninja";
		P[4].respuesta2 = "2)Los cuatro Fantasticos";
		P[4].respuesta3 = "3)Los antagonistas de Attack on Titan";
		P[4].respuesta4 = "4)Los 4 Requesones";
		P[4].correcta = 1;

	}




};

/*int main(void)
{
	definirPreguntas();
	// inicializamos las librerías utilizadas
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	al_install_keyboard();
	ALLEGRO_DISPLAY* display = al_create_display(800, 450);

	//ALLEGRO_DISPLAY* display = al_create_display(800, 450);
	ALLEGRO_TIMER* timer = NULL;

	al_set_window_title(display, "Zelda");

	sistema.img = al_load_bitmap("escenario.png");
	sistema.fondo = al_map_rgb(255, 0, 0);
	sistema.FPS = 30;
	timer = al_create_timer(1.0 / sistema.FPS);

	// creo lista de eventos
	sistema.Mis_eventos = al_create_event_queue();

	// asigno eventos a la lista de eventos
	al_register_event_source(sistema.Mis_eventos, al_get_keyboard_event_source());
	al_register_event_source(sistema.Mis_eventos, al_get_display_event_source(display));
	al_register_event_source(sistema.Mis_eventos, al_get_timer_event_source(timer));
	al_start_timer(timer);

	juego(sistema.fondo, sistema.Mis_eventos);

	// al_unlock_bitmap(choque);

}
*/