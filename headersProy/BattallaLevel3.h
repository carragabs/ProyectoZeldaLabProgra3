
#include <iostream>
#include <string>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <Windows.h>
#include "animN3.h"

using namespace std;

struct preguntasBattle {
	int correcta;
	string pregunta, respuesta1, respuesta2, respuesta3, respuesta4;
}F[8];

int BatallaContable;

class BattallaLevel3 {

public:

	void definirPreguntas() {

		F[0].pregunta = " Para algunos de los siguientes filosofos, el criterio de verdad es la evidencia sensible:";
		F[0].respuesta1 = "1)Emperistas";
		F[0].respuesta2 = "2)criticistas";
		F[0].respuesta3 = "3)Racionalistas";
		F[0].respuesta4 = "4)dogmaticos";
		F[0].correcta = 1;

		F[1].pregunta = "Corriente filosofica que en general tiende a negar la posibilidad de la metafisica y sostiene el conocimiento de fenomenos.";
		F[1].respuesta1 = "1) Racionalistas";
		F[1].respuesta2 = "2) Empiristas";
		F[1].respuesta3 = "3)Escolasticos";
		F[1].respuesta4 = "4)Escepticos";
		F[1].correcta = 2;

		F[2].pregunta = "Para unos de los siguientes filosofos, la experiencia como única fuente del conocimiento";
		F[2].respuesta1 = "1)Epistemologos";
		F[2].respuesta2 = "2)Racionalistas";
		F[2].respuesta3 = "3)Empiristas";
		F[2].respuesta4 = "4)Escepticos";
		F[2].correcta = 3;

		F[3].pregunta = " Filosofos para quienes la unica fuente del conocimiento es la razon. ";
		F[3].respuesta1 = "1)Epistemologos";
		F[3].respuesta2 = "2)Racionalistas";
		F[3].respuesta3 = "3)Empiristas";
		F[3].respuesta4 = "4)Escepticos";
		F[3].correcta = 2;

		F[4].pregunta = "De los siguientes filosofos selecciones el que no se considera Racionalista: ";
		F[4].respuesta1 = "1)David Hume";
		F[4].respuesta2 = "2)John Locke";
		F[4].respuesta3 = "3)Nicolas Malebranch";
		F[4].respuesta4 = "4)Francis Bacon";
		F[4].correcta = 3;

		F[5].pregunta = "Filosofos que postulan las ideas innatas en el sujeto";
		F[5].respuesta1 = "1)Idealistas";
		F[5].respuesta2 = "2)Racionalistas";
		F[5].respuesta3 = "3)Empiristas";
		F[5].respuesta4 = "4)Innatistas";
		F[5].correcta = 2;

		F[6].pregunta = "Es la doctrina que establece que todos nuestros conocimientos provienen de la razon";
		F[6].respuesta1 = "1)Empirismo";
		F[6].respuesta2 = "2)Criticismo";
		F[6].respuesta3 = "3)Racinalismo.";
		F[6].respuesta4 = "4)Epistemologia";
		F[6].correcta = 3;

		F[7].pregunta = " Uno de los siguientes filosofos, postula las ideas innatas en el sujeto:";
		F[7].respuesta1 = "1)George Berkeley";
		F[7].respuesta2 = "2)David Hume";
		F[7].respuesta3 = "3)Leibniz";
		F[7].respuesta4 = "4)Hipatia";
		F[7].correcta = 1;

	}



	int juegoGrafico(ALLEGRO_DISPLAY* displayMain , ALLEGRO_EVENT_QUEUE* Mis_eventos, int vida) {

		definirPreguntas();

		ALLEGRO_EVENT evento;
		bool game = true;
		int contRondas = 0;

		cout << F[BatallaContable].pregunta << endl;
		cout << F[BatallaContable].respuesta1 << endl;
		cout << F[BatallaContable].respuesta2 << endl;
		cout << F[BatallaContable].respuesta3 << endl;
		cout << F[BatallaContable].respuesta4 << endl;

		ALLEGRO_FONT* Triforce = al_load_font("Fonts/ReturnofGanon.ttf", 20, 0);
		ALLEGRO_FONT* Triforce1 = al_load_font("Fonts/ReturnofGanon.ttf", 40, 0);
		ALLEGRO_BITMAP* test = al_load_bitmap("Imagenes/batallaLevel3.png");

		animacionN3 miAnimN3(displayMain);
		
		miAnimN3.paso = 3;
		miAnimN3.rot = 1;
		miAnimN3.x = 50; miAnimN3.y = 360;

		miAnimN3.batMapa = al_load_bitmap("Imagenes/batallaLevel3.png");
		miAnimN3.link = al_load_bitmap("Imagenes/linkred.png");
		miAnimN3.enemigo = al_load_bitmap("Imagenes/4Senemies.png");
		al_convert_mask_to_alpha(miAnimN3.enemigo, al_map_rgb(0, 128, 255));
		int x = -1, y = -1;
		//int vida = 100;

		int botones[] = { 0 };
		if (vida != 0) {
			while (game)
			{
				if (BatallaContable > 7) {
					game = false;
					al_rest(3);
				}
				if (vida < 0)
				{
					cout << "GAME OVER!" << endl;
					game = false;
				}

				int resp = F[BatallaContable].correcta;
				al_draw_bitmap((test), 0, 0, 0);

				al_draw_filled_rectangle(10, 20, 200, 30, al_map_rgb(255, 0, 0));
				al_draw_filled_rectangle(11, 20, vida, 30, al_map_rgb(0, 255, 0));

				//al_draw_bitmap(miAnimN3.batMapa, 0, 0, 0);
				//al_draw_scaled_bitmap(miAnimN3.link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
				//al_convert_mask_to_alpha(miAnimN3.enemigo, al_map_rgb(0, 128, 255));
				//al_draw_scaled_bitmap(miAnimN3.enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);
				//al_flip_display();

				int ancho = 768;
				int alto = 576;

				ALLEGRO_EVENT Evento;
				al_wait_for_event(Mis_eventos, &Evento);


				al_draw_text(Triforce, al_map_rgb(25, 25, 255), 1, 50, NULL, F[BatallaContable].pregunta.c_str());
				al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 60, 155, NULL, F[BatallaContable].respuesta1.c_str());
				al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 60, 210, NULL, F[BatallaContable].respuesta2.c_str());
				al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 500, 155, NULL, F[BatallaContable].respuesta3.c_str());
				al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 500, 210, NULL, F[BatallaContable].respuesta4.c_str());


				al_draw_scaled_bitmap(miAnimN3.link, 206, 1985, 35, 31, 50, 360, 150, 140, 1);
				al_draw_scaled_bitmap(miAnimN3.enemigo, 13, 271, 27, 35, 600, 320, 150, 180, 1);

				al_flip_display();

				//	al_clear_to_color(al_map_rgb(0, 0, 0));

				if (botones[0] == 0)
					al_draw_filled_rectangle(400, 100, 400, 100, al_map_rgb(255, 255, 255));
				else if (botones[0] == 1)
					al_draw_filled_rectangle(300, 200, 300, 100, al_map_rgb(255, 255, 255));
				else if (botones[0] == 2)
					al_draw_filled_rectangle(300, 200, 300, 100, al_map_rgb(255, 255, 255));
				else if (botones[0] == 3)
					al_draw_filled_rectangle(300, 200, 300, 100, al_map_rgb(255, 255, 255));
				else
					al_draw_filled_rectangle(200, 100, 200, 100, al_map_rgb(255, 255, 255));

				if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
				{
					//x,y,x,y

					x = Evento.mouse.x;
					y = Evento.mouse.y;

					if (x >= 60 && x <= 300 && y >= 100 && y <= 200) {
						botones[0] = 0;
						if (Evento.mouse.button & 1) {
							int boton = 1;

							if (boton == resp) { //RESP CORRECTA
								BatallaContable++;
								/*miAnimN3.drawWalkLink();
								miAnimN3.drawAtkLink(600 - 50, 360);
								miAnimN3.drawDmgEnmy();
								miAnimN3.drawWalkLinkRev();
								al_rest(1);*/
								cout << boton << endl;

							}
							else { //RESP INCORRECTA
								BatallaContable++;
								vida = vida - 25;
								/*miAnimN3.drawWalkEnmy();
								miAnimN3.drawAtkEnmy(50 + 30, 360);
								miAnimN3.drawDmgLink();
								miAnimN3.drawWalkEnmyRev();
								al_rest(1);*/
								cout << boton << endl;
							}
						}
					}
					else if (x >= 60 && x <= 300 && y >= 210 && y <= 290) {
						botones[0] = 1;
						if (Evento.mouse.button & 1) {
							int boton2 = 2;
							if (boton2 == resp) {
								BatallaContable++;
								cout << boton2 << endl;
								/*miAnimN3.drawWalkLink();
								miAnimN3.drawAtkLink(600 - 50, 360);
								miAnimN3.drawDmgEnmy();
								miAnimN3.drawWalkLinkRev();
								al_rest(1);*/
							}
							else {
								BatallaContable++;
								vida = vida - 25;
								/*miAnimN3.drawWalkEnmy();
								miAnimN3.drawAtkEnmy(50 + 30, 360);
								miAnimN3.drawDmgLink();
								miAnimN3.drawWalkEnmyRev();*/
								cout << boton2 << endl;

							}
						}
					}

					else if (x >= 500 && x <= 700 && y >= 100 && y <= 200) {
						botones[0] = 2;
						if (Evento.mouse.button & 1) {
							int boton3 = 3;
							if (boton3 == resp) {
								BatallaContable++;
								cout << boton3<<endl;

							}
							else {
								BatallaContable++;
								vida = vida - 25;
								cout << boton3 << endl;

							}
						}
					}


					else {
						if (x >= 500 && x <= 700 && y >= 210 && y <= 290) {
							botones[0] = 3;
							int boton4 = 4;

							if (Evento.mouse.button & 1)
								if (boton4 == resp) {
									BatallaContable++;
									cout << boton4 << endl;


								}
								else {
									BatallaContable++;
									vida = vida - 25;
									cout << boton4 << endl;
								}
						}
						else {
							botones[0] = 0;
						}

					}


				}

				al_flip_display();

			}

		}
		else {

			// esperamos a que ocurra un evento
			al_wait_for_event(Mis_eventos, &evento);

			// se ha cerrado la ventana
			if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			{
				game = false;
			}

			// se ha pulsado ESC
			if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
			{
				if (evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				{
					game = false;
				}
			}

		}
		return 0;

	}
};





