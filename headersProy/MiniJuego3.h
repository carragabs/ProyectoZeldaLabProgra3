
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>
#include "headersProy/escena.h"
#include "headersProy/Header.h"

//int contador = 0;

class minijuego3 {
public:
	int contador = 0;
	int vidaM3 = 50;

	struct charco
	{
		double x, y;
		int colisionArriba;

	};
	Header teste;
	//void M3definirPreguntas();
	ALLEGRO_EVENT_QUEUE* event_queue;
	//void M3jugar();

	//void M3damage();




	/*struct datos {
		int FPS;
		ALLEGRO_EVENT_QUEUE* Mis_eventos;
		ALLEGRO_COLOR fondo;
		ALLEGRO_BITMAP* img;
	} sistema; */

	bool crearColisionesCharco(charco  charcoActual, double charcoActualW, double charcoActualH,
		int& x, int& y, double protaW, double protaH, int vidaM3, int contador)
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
				if (charcoActual.colisionArriba == Q[contador].correcta) {
					cout << "COLLISION TRUE y Respuesta verdadera!" << vidaM3 << endl;

					M3jugar();

					return true;

				}
				else {
					M3damage();
					return false;
				}

			}

			if (charcoActual.x == 272 && charcoActual.y == 85) {
				if (charcoActual.colisionArriba == Q[contador].correcta) {
					cout << "COLLISION TRUE y Respuesta verdadera!" << vidaM3 << endl;
					M3jugar();

					return true;

				}
				else {
					M3damage();
					return false;
				}

			}

			if (charcoActual.x == 480 && charcoActual.y == 85) {
				if (charcoActual.colisionArriba == Q[contador].correcta) {
					cout << "COLLISION TRUE y Respuesta verdadera!" << vidaM3 << endl;
					M3jugar();

					return true;

				}
				else {
					M3damage();
					return false;
				}

			}
			if (charcoActual.x == 656 && charcoActual.y == 85) {
				if (charcoActual.colisionArriba ==	Q[contador].correcta) {
					cout << "COLLISION TRUE y Respuesta verdadera!" << vidaM3 << endl;
					M3jugar();

					return true;

				}
				else {
					M3damage();
					return false;
				}

			}
			cout << "COLLISION TRUE!" << endl;
			//y = (charcoActual.y - (protaH));
			return false;
		}


		return false;
	}

	void dibuja(int vidaM3, int contador)
	{

		//al_clear_to_color(fondo);


		escena.pinta(jugador.getCamX(), jugador.getCamY());
		jugador.pinta();
		escena.pinta(jugador.getCamX(), jugador.getCamY(), true);
		// al_draw_textf(font, al_map_rgb(60, 60, 60), 50, 330, 0, "%d, %d", px,py);
		// muestra por pantalla

		al_flip_display();


	}

	void juego(ALLEGRO_EVENT_QUEUE* Mis_eventos)
	{
		M3definirPreguntas();
		ALLEGRO_FONT* Triforce = al_load_font("Fonts/ReturnofGanon.ttf", 23, 0);
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
			//cout << "VIDAAAAAAAAA:" << vidaM3 << endl;




			// Pinta si es dibuja y esta vacia la lista de eventos
			if (dibujar && al_event_queue_is_empty(Mis_eventos))
			{


				dibuja(vidaM3, contador);

				int charcoWidth = 95;
				int charcoHeight = 59;
				charco charco1 = { 65,85,1 };
				charco charco2 = { 272,85,2 };
				charco charco3 = { 480,85,3 };
				charco charco4 = { 656,85,4 };




				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 1, 30, NULL, Q[contador].pregunta.c_str());
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 100, 250, NULL, Q[contador].respuesta1.c_str());
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 100, 300, NULL, Q[contador].respuesta2.c_str());
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 500, 250, NULL, Q[contador].respuesta3.c_str());
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 500, 300, NULL, Q[contador].respuesta4.c_str());


				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 105, 85, NULL, "A");
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 312, 85, NULL, "B");
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 520, 85, NULL, "C");
				al_draw_text(Triforce, al_map_rgb(255, 255, 255), 696, 85, NULL, "D");


				crearColisionesCharco(charco1, charcoWidth, charcoHeight,
					jugador.x, jugador.y, jugador.tamx, jugador.tamy, vidaM3, contador);
				crearColisionesCharco(charco2, charcoWidth, charcoHeight,
					jugador.x, jugador.y, jugador.tamx, jugador.tamy, vidaM3, contador);
				crearColisionesCharco(charco3, charcoWidth, charcoHeight,
					jugador.x, jugador.y, jugador.tamx, jugador.tamy, vidaM3, contador);
				crearColisionesCharco(charco4, charcoWidth, charcoHeight,
					jugador.x, jugador.y, jugador.tamx, jugador.tamy, vidaM3, contador);
				teste.LifeBar(vidaM3);
			
				al_flip_display();
			//	al_draw_filled_rectangle(10, 20, vidaM3, 10, al_map_rgb(0, 255, 0));


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


	void M3jugar()
	{

		ALLEGRO_EVENT Evento;

		contador++;
		vidaM3 = vidaM3 + 10;
		al_draw_filled_rectangle(10, 20, 200, 30, al_map_rgb(255, 0, 0));
		al_draw_filled_rectangle(10, 20, vidaM3, 30, al_map_rgb(0, 255, 0));
		al_flip_display();

	jugador.inicia();

		//juego(sistema.fondo, sistema.Mis_eventos, vidaM3, contador);



	}

	void M3damage() {



		ALLEGRO_EVENT Evento;

		contador++;
		al_draw_filled_rectangle(10, 20, 200, 30, al_map_rgb(255, 0, 0));
		al_draw_filled_rectangle(10, 20, vidaM3, 30, al_map_rgb(0, 255, 0));
		al_flip_display();
		jugador.inicia();

		//juego(sistema.fondo, sistema.Mis_eventos, vidaM3, contador);




	}



	void M3definirPreguntas() {

		Q[0].pregunta = "Uno de los siguientes personajes fue el encargado de pintar la capilla Sixtina:";
		Q[0].respuesta1 = "1)Donatello";
		Q[0].respuesta2 = "2)Miguel Angel";
		Q[0].respuesta3 = "3)Leonardo Da Vinci";
		Q[0].respuesta4 = "4)Francis Bacon";
		Q[0].correcta = 2;

		Q[1].pregunta = "Genio del renacimiento que esculpio el Moises, el David y la Pieta";
		Q[1].respuesta1 = "1) Miguel Angel Buonarroti";
		Q[1].respuesta2 = "2) Rafael Sanzio";
		Q[1].respuesta3 = "3)Leonardo Da Vinci";
		Q[1].respuesta4 = "4)Galileo Galiley";
		Q[1].correcta = 1;

		Q[2].pregunta = "Durante el renacimiento el estilo artistico que impregno el arte, la filosofia, la pintura escritura fue el:";
		Q[2].respuesta1 = "1)Romantisimo";
		Q[2].respuesta2 = "2)Gotico";
		Q[2].respuesta3 = "3)El barroco.";
		Q[2].respuesta4 = "4)Clasismo";
		Q[2].correcta = 3;

		Q[3].pregunta = "Durante el renacimiento surge una nueva vision del hombre, que se vio reflejada en el arte, en la politica y en las ciencias sociales y humanas, a lo que se denomina";
		Q[3].respuesta1 = "1)Humanismo";
		Q[3].respuesta2 = "2)Teocentrismo";
		Q[3].respuesta3 = "3)Antropocentrismo";
		Q[3].respuesta4 = "4)Paradigma antropologico";
		Q[3].correcta = 1;

		Q[4].pregunta = "Cuatro genios del renacimiento (Leonardo, Donatello, Rafael y Michelangelo) han sido llevados a la pantalla en los comics de:";
		Q[4].respuesta1 = "1)Tortugas Ninja";
		Q[4].respuesta2 = "2)Los cuatro Fantasticos";
		Q[4].respuesta3 = "3)Los antagonistas de Attack on Titan";
		Q[4].respuesta4 = "4)Los 4 Requesones";
		Q[4].correcta = 1;

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