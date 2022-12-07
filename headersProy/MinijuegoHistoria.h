#pragma 
#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <Windows.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <string>
#include "Transicion.h"
using std::string;
using namespace std;

class MinijuegoHistoria
{
public:

	int ancho = 768;
	int alto = 576;
	MinijuegoHistoria(ALLEGRO_DISPLAY* ventanaMain);
	void texto(string, int, int, int);
	int minjuego();
	void LifeBar(int vida);
	int menu();
	ALLEGRO_DISPLAY* ventana;

};

MinijuegoHistoria::MinijuegoHistoria(ALLEGRO_DISPLAY* ventanaMain) {
	ventana = ventanaMain;
	minjuego();
}

int MinijuegoHistoria::minjuego() {
	int ancho_W = GetSystemMetrics(SM_CXSCREEN);
	int alto_W = GetSystemMetrics(SM_CYSCREEN);

	al_set_window_title(ventana, "Minijuego Historia");
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());

	return menu();
}
void MinijuegoHistoria::LifeBar(int vida) {


	al_draw_filled_rectangle(10, 20, 200, 30, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(10, 20, vida, 30, al_map_rgb(0, 255, 0));
	al_flip_display();

}
int MinijuegoHistoria ::menu() {
	al_register_event_source(event_queue, al_get_display_event_source(ventana));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	int vida = 10;
	int m = 1;
	ALLEGRO_FONT* Triforce = al_load_font("Fonts/Triforce.ttf", 19, 0);
	ALLEGRO_FONT* Triforce1 = al_load_font("Fonts/Triforce.ttf", 23, 0);
	int x = -1, y = -1;
	al_init_ttf_addon();
	al_install_audio();
	al_init_font_addon();
	al_init_acodec_addon();
	al_reserve_samples(2);
	ALLEGRO_SAMPLE* song = al_load_sample("Audios/Correcta.mp3");
	ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
	ALLEGRO_SAMPLE* incorrecta = al_load_sample("Audios/Incorrecta.mp3");
	ALLEGRO_SAMPLE_INSTANCE* instance2 = al_create_sample_instance(incorrecta);
	al_set_sample_instance_playmode(instance2, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(instance2, al_get_default_mixer());


	ALLEGRO_BITMAP* arena = al_load_bitmap("Imagenes/arena.jpeg");
	ALLEGRO_BITMAP* izqmedio = al_load_bitmap("Imagenes/izqmedio.jpeg");
	ALLEGRO_BITMAP* derecha = al_load_bitmap("Imagenes/derecha.jpeg");
	ALLEGRO_BITMAP* izquierda = al_load_bitmap("Imagenes/izquierda.jpeg");
	ALLEGRO_BITMAP* dermedio = al_load_bitmap("Imagenes/dermedio.jpeg");
	ALLEGRO_BITMAP* menu_null = al_load_bitmap("Imagenes/vacios.jpeg");

	Transition transHisto;
	transHisto.drawTransitionReversa(ventana, menu_null, 800, 600,
		dermedio, 0, 0, 0, 0);

	//menu
	int botones[] = { 0 };


	while (true)
	{
		ALLEGRO_EVENT Evento;
		al_wait_for_event(event_queue, &Evento);

		if (botones[0] == 0) {
			al_clear_to_color(al_map_rgb(0, 0, 0));


			al_draw_bitmap(menu_null, 0, 0, 0);
			LifeBar(vida);
			texto("1. Despues del feudalismo medieval acudimos al surgimiento de una nueva clase social", 0, 109, 110);
			texto("conocida como la : ", 0, 109, 135);
			texto("A) La monarquia", 0, 10, 480);
			texto("B) El mercantilismo", 0, 200, 480);
			texto("C) La burguesia", 0, 448, 480);
			texto("D) El proletariado", 0, 636, 480);
			botones[0] = 1;

		}
		if (Evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (m == 1) {
				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_C: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 2;
					al_draw_bitmap(dermedio, 0, 0, 0);
					texto("1. Despues del feudalismo medieval acudimos al surgimiento de una nueva clase social", 0, 109, 110);
					texto("conocida como la : ", 0, 109, 135);
					texto("A) La monarquia", 0, 10, 480);
					texto("B) El mercantilismo", 0, 200, 480);

					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 448, 480, NULL, "C) La burguesia");
					al_play_sample_instance(instance);
					vida += 10;
					LifeBar(vida);
					texto("D) El proletariado", 0, 636, 480);
					break;

				}
				case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 2;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("1. Despues del feudalismo medieval acudimos al surgimiento de una nueva clase social", 0, 109, 110);
					texto("conocida como la : ", 0, 109, 135);
					texto("A) La monarquia", 0, 10, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 480, NULL, "B) El mercantilismo");
					al_play_sample_instance(instance2);
					LifeBar(vida);
					texto("C) La burguesia", 0, 448, 480);

					texto("D) El proletariado", 0, 636, 480);

					break;

				}case ALLEGRO_KEY_A: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 2;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("1. Despues del feudalismo medieval acudimos al surgimiento de una nueva clase social", 0, 109, 110);
					texto("conocida como la : ", 0, 109, 135);
					texto("B) El mercantilismo", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 10, 480, NULL, "A) La monarquia");
					al_play_sample_instance(instance2);
					LifeBar(vida);
					texto("C) La burguesia", 0, 448, 480);

					texto("D) El proletariado", 0, 636, 480);

					break;
				}

				case ALLEGRO_KEY_D: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 2;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("1. Despues del feudalismo medieval acudimos al surgimiento de una nueva clase social", 0, 109, 110);
					texto("conocida como la : ", 0, 109, 135);
					texto("B) El mercantilismo", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 636, 480, NULL, "D) El proletariado");
					al_play_sample_instance(instance2);
					LifeBar(vida);
					texto("C) La burguesia", 0, 448, 480);

					texto("A) La monarquia", 0, 10, 480);

					break;
				}




				}



			}
			else if (m == 2) {
				al_clear_to_color(al_map_rgb(0, 0, 0));


				al_draw_bitmap(menu_null, 0, 0, 0);
				LifeBar(vida);
				texto("2. El renacimiento supone una epoca de absolutismo y nacionalismos, como el ", 0, 109, 110);
				texto("nacimiento de fuertes monarquias europeos centralizadas como:", 0, 109, 135);
				texto("A) Grecia", 0, 10, 480);
				texto("B) Inglaterra", 0, 200, 480);
				texto("C) Yugoslavia", 0, 448, 480);

				texto("D) Egipto", 0, 636, 480);

				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_C: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 3;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("2. El renacimiento supone una epoca de absolutismo y nacionalismos, como el ", 0, 109, 110);
					texto("nacimiento de fuertes monarquias europeos centralizadas como:", 0, 109, 135);
					texto("A) Grecia", 0, 10, 480);
					texto("B) Inglaterra", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 448, 480, NULL, "C) Yugoslavia");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("D) Egipto", 0, 636, 480);
					break;

				}
				case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 3;
					al_draw_bitmap(izqmedio, 0, 0, 0);
					texto("2. El renacimiento supone una epoca de absolutismo y nacionalismos, como el ", 0, 109, 110);
					texto("nacimiento de fuertes monarquias europeos centralizadas como:", 0, 109, 135);
					texto("A) Grecia", 0, 10, 480);
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 200, 480, NULL, "B) Inglaterra");
					LifeBar(vida);
					al_play_sample_instance(instance);
					vida += 10;
					LifeBar(vida);
					texto("C) Yugoslavia", 0, 448, 480);

					texto("D) Egipto", 0, 636, 480);

					break;

				}case ALLEGRO_KEY_A: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 3;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("2. El renacimiento supone una epoca de absolutismo y nacionalismos, como el ", 0, 109, 110);
					texto("nacimiento de fuertes monarquias europeos centralizadas como:", 0, 109, 135);
					texto("B) Inglaterra", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 10, 480, NULL, "A) Grecia");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("C) Yugoslavia", 0, 448, 480);

					texto("D) Egipto", 0, 636, 480);

					break;
				}

				case ALLEGRO_KEY_D: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 3;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("2. El renacimiento supone una epoca de absolutismo y nacionalismos, como el ", 0, 109, 110);
					texto("nacimiento de fuertes monarquias europeos centralizadas como:", 0, 109, 135);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 636, 480, NULL, "D) Egipto");
					al_play_sample_instance(instance2);
					LifeBar(vida);
					texto("C) Yugoslavia", 0, 448, 480);
					texto("A) Grecia", 0, 10, 480);
					texto("B) Inglaterra", 0, 200, 480);

					break;
				}




				}
			}
			else if (m == 3) {
				al_clear_to_color(al_map_rgb(0, 0, 0));


				al_draw_bitmap(menu_null, 0, 0, 0);
				LifeBar(vida);
				texto("3. Antes de la consolidacion del estado moderno, Italia esuvo divida en", 0, 109, 110);
				texto("pequenias ciudades estado normalmente enfrentadas entre si,como es el caso de:", 0, 109, 135);
				texto("C) Reims-Colonia", 0, 448, 480);
				texto("B) Amsterdam-Cracovia", 0, 200, 480);
				texto("A) Florencia-Napoli", 0, 10, 480);
				texto("D) Milan-Lourdes", 0, 636, 480);


				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_A: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 4;
					al_draw_bitmap(izquierda, 0, 0, 0);
					texto("3. Antes de la consolidacion del estado moderno, Italia esuvo divida en", 0, 109, 110);
					texto("pequenias ciudades estado normalmente enfrentadas entre si,como es el caso de:", 0, 109, 135);
					texto("C) Reims-Colonia", 0, 448, 480);
					texto("B) Amsterdam-Cracovia", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 10, 480, NULL, "A) Florencia-Napoli");
					al_play_sample_instance(instance);
					vida += 10;
					LifeBar(vida);
					texto("D) Milan-Lourdes", 0, 636, 480);
					break;

				}case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 4;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("3. Antes de la consolidacion del estado moderno, Italia esuvo divida en", 0, 109, 110);
					texto("pequenias ciudades estado normalmente enfrentadas entre si,como es el caso de:", 0, 109, 135);
					texto("C) Reims-Colonia", 0, 448, 480);
					texto("A) Florencia-Napoli", 0, 10, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 480, NULL, "B) Amsterdam-Cracovia");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("D) Milan-Lourdes", 0, 636, 480);
					break;

				}case ALLEGRO_KEY_C: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 4;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("3. Antes de la consolidacion del estado moderno, Italia esuvo divida en", 0, 109, 110);
					texto("pequenias ciudades estado normalmente enfrentadas entre si,como es el caso de:", 0, 109, 135);
					texto("A) Florencia-Napoli", 0, 10, 480);
					texto("B) Amsterdam-Cracovia", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 448, 480, NULL, "C) Reims-Colonia");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("D) Milan-Lourdes", 0, 636, 480);
					break;

				}

				case ALLEGRO_KEY_D: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 4;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("3. Antes de la consolidacion del estado moderno, Italia esuvo divida en", 0, 109, 110);
					texto("pequenias ciudades estado normalmente enfrentadas entre si,como es el caso de:", 0, 109, 135);
					texto("A) Florencia-Napoli", 0, 10, 480);
					texto("B) Amsterdam-Cracovia", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 636, 480, NULL, "D) Milan-Londres");
					LifeBar(vida);
					al_play_sample_instance(instance2);

					texto("C) Reims-Colonia", 0, 448, 480);
					break;
				}




				}
			}
			else if (m == 4) {
				al_clear_to_color(al_map_rgb(0, 0, 0));


				al_draw_bitmap(menu_null, 0, 0, 0);
				LifeBar(vida);
				texto("4. La toma de Constantinopla supone un bloque comercial entre Europa y", 0, 109, 110);
				texto("Asia (la ruta de la seda) y ocurrio en lo que hoy es actualmente:", 0, 109, 135);
				texto("C) Mesopotamia", 0, 448, 480);
				texto("B) Estambul en Turquia", 0, 200, 480);
				texto("A) Eslovaquia", 0, 10, 480);
				texto("D) Jerusalen", 0, 636, 480);


				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_A: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 5;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("4. La toma de Constantinopla supone un bloque comercial entre Europa y", 0, 109, 110);
					texto("Asia (la ruta de la seda) y ocurrio en lo que hoy es actualmente:", 0, 109, 135);
					texto("C) Mesopotamia", 0, 448, 480);
					texto("B) Estambul en Turquia", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 10, 480, NULL, "A) Eslovaquia");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("D) Jerusalen", 0, 636, 480);
					break;

				}case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 5;
					al_draw_bitmap(izqmedio, 0, 0, 0);
					texto("4. La toma de Constantinopla supone un bloque comercial entre Europa y", 0, 109, 110);
					texto("Asia (la ruta de la seda) y ocurrio en lo que hoy es actualmente:", 0, 109, 135);
					texto("C) Mesopotamia", 0, 448, 480);
					texto("A) Eslovaquia", 0, 10, 480);
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 200, 480, NULL, "B) Estambul en Turquia");
					LifeBar(vida);
					al_play_sample_instance(instance);
					vida += 10;
					LifeBar(vida);
					texto("D) Jerusalen", 0, 636, 480);
					break;

				}case ALLEGRO_KEY_C: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 5;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("4. La toma de Constantinopla supone un bloque comercial entre Europa y", 0, 109, 110);
					texto("Asia (la ruta de la seda) y ocurrio en lo que hoy es actualmente:", 0, 109, 135);;
					texto("A) Eslovaquia", 0, 10, 480);
					texto("B) Estambul en Turquia", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 448, 480, NULL, "C) Mesopotamia");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("D) Jerusalen", 0, 636, 480);
					break;

				}

				case ALLEGRO_KEY_D: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 5;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("4. La toma de Constantinopla supone un bloque comercial entre Europa y", 0, 109, 110);
					texto("Asia (la ruta de la seda) y ocurrio en lo que hoy es actualmente:", 0, 109, 135);
					texto("A) Eslovaquia", 0, 10, 480);
					texto("B) Estambul en Turquia", 0, 200, 480);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 636, 480, NULL, "D) Jerusalen");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("C) Mesopotamia", 0, 448, 480);
					break;
				}




				}
			}
			else if (m == 5) {
				al_clear_to_color(al_map_rgb(0, 0, 0));


				al_draw_bitmap(menu_null, 0, 0, 0);
				LifeBar(vida);
				texto("5. Resurge el interes por Grecia y Roma, junto al declive del sistema feudal", 0, 109, 110);
				texto("el crecimiento del comercio e innovaciones entre las que mencionamos", 0, 109, 135);
				texto("C) Las maquinas", 0, 448, 455);
				texto("de vapor y la  ", 0, 448, 475);
				texto("produccion en masa", 0, 448, 495);
				texto("B) La rueda y", 0, 200, 470);
				texto("escritura", 0, 200, 495);
				texto("A) La imprenta y la", 0, 10, 470);
				texto("brujula", 0, 10, 495);
				texto("D) La polvora y", 0, 636, 470);
				texto("la rueda", 0, 636, 495);


				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_A: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 6;
					al_draw_bitmap(izquierda, 0, 0, 0);
					texto("5. Resurge el interes por Grecia y Roma, junto al declive del sistema feudal", 0, 109, 110);
					texto("el crecimiento del comercio e innovaciones entre las que mencionamos", 0, 109, 135);
					texto("C) Las maquinas", 0, 448, 455);
					texto("de vapor y la  ", 0, 448, 475);
					texto("produccion en masa", 0, 448, 495);
					texto("B) La rueda y", 0, 200, 470);
					texto("escritura", 0, 200, 495);
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 10, 470, NULL, "A) La imprenta y la");
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 10, 495, NULL, "brujula");
					al_play_sample_instance(instance);
					vida += 10;
					LifeBar(vida);
					texto("D) La polvora y", 0, 636, 470);
					texto("la rueda", 0, 636, 495);
					break;

				}case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 6;
					al_draw_bitmap(izqmedio, 0, 0, 0);
					texto("5. Resurge el interes por Grecia y Roma, junto al declive del sistema feudal", 0, 109, 110);
					texto("el crecimiento del comercio e innovaciones entre las que mencionamos", 0, 109, 135);;
					texto("C) Las maquinas", 0, 448, 455);
					texto("de vapor y la  ", 0, 448, 475);
					texto("produccion en masa", 0, 448, 495);
					texto("A) La imprenta y la", 0, 10, 470);
					texto("brujula", 0, 10, 495);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 470, NULL, "B) La rueda y");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 495, NULL, "escritura");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("D) La polvora y", 0, 636, 470);
					texto("la rueda", 0, 636, 495);
					break;

				}case ALLEGRO_KEY_C: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 6;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("5. Resurge el interes por Grecia y Roma, junto al declive del sistema feudal", 0, 109, 110);
					texto("el crecimiento del comercio e innovaciones entre las que mencionamos", 0, 109, 135);
					texto("A) La imprenta y la", 0, 10, 470);
					texto("brujula", 0, 10, 495);
					texto("B) La rueda y", 0, 200, 470);
					texto("escritura", 0, 200, 495);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 448, 455, NULL, "C) Las maquinas");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 448, 475, NULL, "de vapor y la");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 448, 495, NULL, "produccion en masa");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("D) La polvora y", 0, 636, 470);
					texto("la rueda", 0, 636, 495);
					break;

				}

				case ALLEGRO_KEY_D: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 6;
					al_draw_bitmap(menu_null, 0, 0, 0);
					texto("5. Resurge el interes por Grecia y Roma, junto al declive del sistema feudal", 0, 109, 110);
					texto("el crecimiento del comercio e innovaciones entre las que mencionamos", 0, 109, 135);
					texto("A) La imprenta y la", 0, 10, 470);
					texto("brujula", 0, 10, 495);
					texto("B) La rueda y", 0, 200, 470);
					texto("escritura", 0, 200, 495);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 636, 470, NULL, "D) La polvora y");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 636, 495, NULL, "la rueda");
					LifeBar(vida);
					al_play_sample_instance(instance2);
					texto("C) Las maquinas", 0, 448, 455);
					texto("de vapor y la  ", 0, 448, 475);
					texto("produccion en masa", 0, 448, 495);
					break;
				}




				}
			}


		}switch (Evento.keyboard.keycode) {
		case ALLEGRO_KEY_ESCAPE: {
			transHisto.drawTransition(ventana, menu_null, 800, 600,
				dermedio, 0, 0, 0, 0);
			transHisto.destroyTrans();

			al_clear_to_color(al_map_rgb(255, 255, 255));
			al_flip_display();
			al_rest(1);

			return 1;
		}
		}

		al_flip_display();

	}
	al_destroy_sample_instance(instance2);
	al_destroy_sample_instance(instance);

}


void MinijuegoHistoria::texto(string msj, int c, int x, int y) {
	ALLEGRO_FONT* Triforce = al_load_font("Fonts/Triforce.ttf", 19, 0);
	ALLEGRO_FONT* Triforce1 = al_load_font("Fonts/Triforce.ttf", 23, 0);
	al_draw_text(Triforce, al_map_rgb(c, c, c), x, y, 0, msj.c_str());
}






