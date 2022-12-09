
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

using namespace std;

struct preguntasBattlePK {
	int correcta;
	string pregunta, respuesta1, respuesta2, respuesta3, respuesta4;
}K[6];

struct posNavi
{
	int x, y;

}PosPistas[6];

int ContadorKant;

class PreguntasKant {

public:

	void definirPreguntasKant() {

		K[0].pregunta = " Seleccione el mandato cuya obligacion viene del miedo al castigo o la busqueda de un premio: ";
		K[0].respuesta1 = "1)Imperativo Hipotetico";
		K[0].respuesta2 = "2)Imperativo categorigo";
		K[0].respuesta3 = "3)Ambos";
		K[0].respuesta4 = "4)Ninguno";
		K[0].correcta = 1;

		K[1].pregunta = "Para Kant, es posible conocer lo que las cosas nos permiten (como lo superficial) a través de nuestros sentidos:";
		K[1].respuesta1 = "1) Conocimiento Noumenico";
		K[1].respuesta2 = "2) Conocimiento Fenomenico";
		K[1].respuesta3 = "3) Conocimiento Empirico";
		K[1].respuesta4 = "4) Conocimiento Racional";
		K[1].correcta = 2;

		K[2].pregunta = " Kant decía que el lema de la ilustración era “Sapere aude”, que significa: ";
		K[2].respuesta1 = "1)Sopesa tus acciones";
		K[2].respuesta2 = "2)Atrevete a saber por ti mismo";
		K[2].respuesta3 = "3)Saber a la fuerza";
		K[2].respuesta4 = "4)Someterse al conocimiento";
		K[2].correcta = 2;

		K[3].pregunta = " Kant (Copérnico cambió el centro del universo),cambia el centro del conocimiento del objeto al sujeto, a esto se le llama : ";
		K[3].respuesta1 = "1)Subjetivismo";
		K[3].respuesta2 = "2)Prejuicio";
		K[3].respuesta3 = "3)giro copernicano";
		K[3].respuesta4 = "4)Suerte";
		K[3].correcta =3;

		K[4].pregunta = "La postura conciliadora de Kant respecto a los empiristas y racionalistas define que los datos experimentales son la fuente del conocimiento racional del sujeto : ";
		K[4].respuesta1 = "1) Racionalismo";
		K[4].respuesta2 = "2) Empirismo";
		K[4].respuesta3 = "3) Criticismo";
		K[4].respuesta4 = "4) Escepticismo";
		K[4].correcta = 3;


		K[5].pregunta = " De las siguientes obras de Emanuel Kant, seleccione aquella que define su epistemología:";
		K[5].respuesta1 = "1)Critica de la razon practica";
		K[5].respuesta2 = "2)Critica de la razon pura";
		K[5].respuesta3 = "3)Critica del juicio.";
		K[5].respuesta4 = "4)Criticafenomenologica";
		K[5].correcta = 2;

	}
	void definirposPistas()
	{
		PosPistas[0] = { 220,150 };
		PosPistas[1] = { 615,220 };
		PosPistas[2] = { 460,180 };
		PosPistas[3] = { 300 , 190 };
		PosPistas[4] = { 460 , 400 };
		PosPistas[5] = { 670 , 415 };

	}

	int juegoGrafico(ALLEGRO_EVENT_QUEUE* Mis_eventos, int vida) {

		definirPreguntasKant();
		definirposPistas();

		ALLEGRO_EVENT evento;
		bool game = true;

		cout << K[ContadorKant].pregunta << endl;
		cout << K[ContadorKant].respuesta1 << endl;
		cout << K[ContadorKant].respuesta2 << endl;
		cout << K[ContadorKant].respuesta3 << endl;
		cout << K[ContadorKant].respuesta4 << endl;

		ALLEGRO_FONT* Triforce = al_load_font("Fonts/ReturnofGanon.ttf", 30, 0);
		ALLEGRO_FONT* Triforce1 = al_load_font("Fonts/ReturnofGanon.ttf", 40, 0);
		ALLEGRO_BITMAP* test = al_load_bitmap("Imagenes/EscenarioKant.png");
		ALLEGRO_BITMAP* navi = al_load_bitmap("Imagenes/navi.png");
		ALLEGRO_BITMAP* kant = al_load_bitmap("Imagenes/kant.jpg");
		ALLEGRO_BITMAP* link = al_load_bitmap("Imagenes/SheetZelda2.png");;


		al_reserve_samples(2);

		ALLEGRO_SAMPLE* song = al_load_sample("Audios/biblio.mp3");
		ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song);
		al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_LOOP);
		al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());

		al_play_sample_instance(instance);

		ALLEGRO_SAMPLE* pista = al_load_sample("Audios/fairy.wav");
		ALLEGRO_SAMPLE_INSTANCE* pistaSonido = al_create_sample_instance(pista);
		al_set_sample_instance_playmode(pistaSonido, ALLEGRO_PLAYMODE_ONCE);
		al_attach_sample_instance_to_mixer(pistaSonido, al_get_default_mixer());

		int x = -1, y = -1;
		//int vida = 100;

		int botones[] = { 0 };
		if (vida != 0) {
			while (game)
			{
				if (ContadorKant >= 6)
					break;

				int resp = K[ContadorKant].correcta;
				al_draw_bitmap((test), 0, 0, 0);


				int ancho = 768;
				int alto = 576;

				ALLEGRO_EVENT Evento;
				al_wait_for_event(Mis_eventos, &Evento);

				al_convert_mask_to_alpha(kant , al_map_rgb(245,245,245));

				al_draw_scaled_bitmap(kant, 1, 7, 84, 150, 490, 220, 60, 100, 0);
				al_draw_scaled_bitmap(link, 0 * 32, 2 * 35, 32, 35, 490, 320, 60 , 80 , 1);

				al_draw_text(Triforce, al_map_rgb(0, 255, 0), 1, 50, NULL, K[ContadorKant].pregunta.c_str());
				al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 70, 250, NULL, K[ContadorKant].respuesta1.c_str());
				al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 70, 300, NULL, K[ContadorKant].respuesta2.c_str());
				al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 70, 350, NULL, K[ContadorKant].respuesta3.c_str());
				al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 70, 400, NULL, K[ContadorKant].respuesta4.c_str());

				al_flip_display();
				//	al_clear_to_color(al_map_rgb(0, 0, 0));

				al_draw_scaled_bitmap(navi,160,0,600,555,
					PosPistas[ContadorKant].x , PosPistas[ContadorKant].y,60,60,0);
				al_flip_display();

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

					if (x >= 70 && x <= 300 && y >= 250 && y <= 299) {
						botones[0] = 0;
						if (Evento.mouse.button & 1) {
							int boton = 1;

							if (boton == resp) {
								al_play_sample_instance(pistaSonido);

								al_draw_text(Triforce1, al_map_rgb(0, 255, 0), 70, 250, NULL,
									K[ContadorKant].respuesta1.c_str());
								ContadorKant++;
								cout << boton << endl;

							}
							else {
								al_play_sample_instance(pistaSonido);

								al_draw_text(Triforce1, al_map_rgb(255, 0, 0), 70, 250, NULL,
									K[ContadorKant].respuesta1.c_str());
								ContadorKant++;
								vida = vida - 10;
								cout << boton << endl;
							}
						}
					}
					else if (x >= 70 && x <= 300 && y >= 299 && y <= 349) {
						botones[0] = 1;
						if (Evento.mouse.button & 1) {
							int boton2 = 2;
							if (boton2 == resp) {
								al_play_sample_instance(pistaSonido);

								al_draw_text(Triforce1, al_map_rgb(0, 255, 0), 70, 300, NULL,
									K[ContadorKant].respuesta1.c_str());
								ContadorKant++;
								cout << boton2 << endl;

							}
							else {
								al_play_sample_instance(pistaSonido);

								al_draw_text(Triforce1, al_map_rgb(255, 0, 0), 70, 300, NULL,
									K[ContadorKant].respuesta1.c_str());
								ContadorKant++;
								vida = vida - 10;
								cout << boton2 << endl;

							}
						}
					}

					else if (x >= 70 && x <= 300 && y >= 350 && y <= 399) {
						botones[0] = 2;
						if (Evento.mouse.button & 1) {
							al_play_sample_instance(instance);
							al_draw_text(Triforce1, al_map_rgb(255, 0, 0), 70, 350, NULL,
								K[ContadorKant].respuesta1.c_str());
							int boton3 = 3;
							if (boton3 == resp) {
								al_play_sample_instance(pistaSonido);

								ContadorKant++;
								cout << boton3 << endl;

							}
							else {
								al_play_sample_instance(pistaSonido);

								al_draw_text(Triforce1, al_map_rgb(255, 0, 0), 70, 350, NULL,
									K[ContadorKant].respuesta1.c_str());
								ContadorKant++;
								vida = vida - 10;
								cout << boton3 << endl;

							}
						}
					}


					else {
						if (x >= 70 && x <= 300 && y >= 400 && y <= 450) {
							botones[0] = 3;
							int boton4 = 4;

							if (Evento.mouse.button & 1)
								if (boton4 == resp) {
									al_play_sample_instance(pistaSonido);

									al_draw_text(Triforce1, al_map_rgb(255, 0, 0), 70, 400, NULL,
										K[ContadorKant].respuesta1.c_str());
									ContadorKant++;
									cout << boton4 << endl;


								}
								else {
									al_play_sample_instance(pistaSonido);

									al_draw_text(Triforce1, al_map_rgb(255, 0, 0), 70, 400, NULL,
										K[ContadorKant].respuesta1.c_str());
									ContadorKant++;
									vida = vida - 10;
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
		al_destroy_sample_instance(instance);

		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_flip_display();
		al_rest(1);
		return 0;

	}
};





#pragma once
