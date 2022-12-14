#pragma once
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
using std::string;
using namespace std;

//ALLEGRO_EVENT_QUEUE* event_queue;

class Descartes
{
public:

	int ancho = 768;
	int alto = 576;
	Descartes(ALLEGRO_DISPLAY* ventanaMain);
	void texto(string, int, int, int);
	int minjuego();
	void LifeBar(int vida);
	int menu();
	ALLEGRO_DISPLAY* ventana;



};

Descartes::Descartes(ALLEGRO_DISPLAY* ventanaMain) {
	ventana = ventanaMain;
	minjuego();
}

int Descartes::minjuego() {
	int ancho_W = GetSystemMetrics(SM_CXSCREEN);
	int alto_W = GetSystemMetrics(SM_CYSCREEN);

	al_set_window_title(ventana, "Minijuego Laboratorio");
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());

	return menu();
}
void Descartes::LifeBar(int vida) {


	al_draw_filled_rectangle(10, 20, 200, 30, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(10, 20, vida, 30, al_map_rgb(0, 255, 0));
	al_flip_display();

}
int Descartes::menu() {
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
	ALLEGRO_SAMPLE* song = al_load_sample("Audios/rCorrecta.mp3");
	ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
	ALLEGRO_SAMPLE* incorrecta = al_load_sample("Audios/Incorrecta.mp3");
	ALLEGRO_SAMPLE_INSTANCE* instance2 = al_create_sample_instance(incorrecta);
	al_set_sample_instance_playmode(instance2, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
	al_attach_sample_instance_to_mixer(instance2, al_get_default_mixer());


	ALLEGRO_BITMAP* arena = al_load_bitmap("Imagenes/arena.jpeg");
	ALLEGRO_BITMAP* izqmedio = al_load_bitmap("Imagenes/izqmedio.jpeg");
	ALLEGRO_BITMAP* globo = al_load_bitmap("Imagenes/Capa2.png");
	ALLEGRO_BITMAP* pocion = al_load_bitmap("Imagenes/Capa7.png");
	ALLEGRO_BITMAP* derecha = al_load_bitmap("Imagenes/derecha.jpeg");
	ALLEGRO_BITMAP* izquierda = al_load_bitmap("Imagenes/izquierda.jpeg");
	ALLEGRO_BITMAP* dermedio = al_load_bitmap("Imagenes/dermedio.jpeg");
	ALLEGRO_BITMAP* menu_null = al_load_bitmap("Imagenes/Mapa Rojo.png");


	//menu
	int botones[] = { 0 };

	while (true)
	{
		ALLEGRO_EVENT Evento;
		al_wait_for_event(event_queue, &Evento);

		if (botones[0] == 0) {
			al_clear_to_color(al_map_rgb(0, 0, 0));
			menu_null = al_load_bitmap("Imagenes/MapaCheck.png");

			al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
			//al_draw_bitmap(globo, 2, 156, NULL);
			//al_draw_bitmap(globo, 200, 156, NULL);
			//al_draw_bitmap(globo, 400, 156, NULL);
			//al_draw_bitmap(globo, 600, 156, NULL);
			texto("1. Son los pasos o razones de la duda metodica ", 0, 5, 20);
			texto("A) Los sentidos nos", 0, 2, 48);
			texto("enganian", 0, 2, 65);
			texto("B) La existencia del", 0, 200, 48);
			texto("genio maligno", 0, 200, 65);
			texto("C) Imposibilidad para", 0, 400, 48);
			texto("diferenciar la", 0, 400, 65);
			texto("vigilia del suenio", 0, 400, 85);
			texto("D) Todas son correctas", 0, 600, 48);
			botones[0] = 1;

		}
		if (Evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (m == 1) {
				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_C: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 2;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(pocion, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);

					texto("1. Son los pasos o razones de la duda metodica ", 0, 5, 20);
					texto("A) Los sentidos nos", 0, 2, 48);
					texto("enganian", 0, 2, 65);
					texto("B) La existencia del", 0, 200, 48);
					texto("genio maligno", 0, 200, 65);
					texto("D) Todas son correctas", 0, 600, 48);


					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 400, 48, NULL, "C) Imposibilidad para");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 400, 65, NULL, "diferenciar la");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 400, 85, NULL, "vigilia del suenio");
					al_play_sample_instance(instance2);


					break;

				}
				case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 2;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(pocion, 200, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);
					texto("1. Son los pasos o razones de la duda metodica ", 0, 5, 20);
					texto("A) Los sentidos nos", 0, 5, 48);
					texto("enganian", 0, 5, 65);

					texto("C) Imposibilidad para", 0, 400, 48);
					texto("diferenciar la", 0, 400, 65);
					texto("vigilia del suenio", 0, 400, 85);
					texto("D) Todas son correctas", 0, 600, 48);


					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 48, NULL, "B) La existencia del");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 65, NULL, "genio maligno");

					al_play_sample_instance(instance2);

					break;

				}case ALLEGRO_KEY_A: {
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					m = 2;
					//al_draw_bitmap(menu_null, 0, 0, 0);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(pocion, 2, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);

					texto("1. Son los pasos o razones de la duda metodica ", 0, 5, 20);

					texto("B) La existencia del", 0, 200, 48);
					texto("genio maligno", 0, 200, 65);
					texto("C) Imposibilidad para", 0, 400, 48);
					texto("diferenciar la", 0, 400, 65);
					texto("vigilia del suenio", 0, 400, 85);
					texto("D) Todas son correctas", 0, 600, 48);


					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 2, 48, NULL, "A) Los sentidos nos");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 2, 65, NULL, "enganian");

					al_play_sample_instance(instance2);


					break;
				}

				case ALLEGRO_KEY_D: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 2;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);

					texto("1. Son los pasos o razones de la duda metodica ", 0, 5, 20);
					texto("A) Los sentidos nos", 0, 2, 48);
					texto("enganian", 0, 2, 65);
					texto("B) La existencia del", 0, 200, 48);
					texto("genio maligno", 0, 200, 65);
					texto("C) Imposibilidad para", 0, 400, 48);
					texto("diferenciar la", 0, 400, 65);
					texto("vigilia del suenio", 0, 400, 85);



					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 600, 48, NULL, "D) Todas son correctas");

					al_play_sample_instance(instance);

					break;
				}




				}



			}
			else if (m == 2) {
				al_clear_to_color(al_map_rgb(0, 0, 0));

				menu_null = al_load_bitmap("Imagenes/Mapa Lupa.png");
				al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
				//al_draw_bitmap(globo, 2, 156, NULL);
				//al_draw_bitmap(globo, 200, 156, NULL);
				//al_draw_bitmap(globo, 400, 156, NULL);
				//al_draw_bitmap(globo, 600, 156, NULL);
				 

				texto("2. Una de las siguientes es considerada de las cuatro reglas del metodo", 0, 5, 15);
				texto("en Descartes ", 0, 5, 35);
				texto("A) Hipotesis", 0, 2, 53);
				texto("B) Deduccion", 0, 200, 53);
				texto("C) Evidencia", 0, 400, 53);
				texto("D) Induccion", 0, 600, 53);

				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_C: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 3;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(menu_null, 0, 0, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);
					texto("2. Una de las siguientes es considerada de las cuatro reglas del metodo", 0, 5, 20);
					texto("en Descartes ", 0, 5, 48);
					texto("A) Hipotesis", 0, 2, 53);
					texto("B) Deduccion", 0, 200, 53);
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 400, 53, NULL, "C) Evidencia");

					al_play_sample_instance(instance);
					texto("D) Induccion", 0, 600, 53);
					break;

				}
				case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 3;
					
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(pocion, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);
					texto("2. Una de las siguientes es considerada de las cuatro reglas del metodo", 0, 5, 20);
					texto("en Descartes ", 0, 5, 35);
					texto("A) Hipotesis", 0, 2, 53);
					texto("C) Evidencia", 0, 400, 53);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 53, NULL, "B) Deduccion");

					al_play_sample_instance(instance2);
					texto("D) Induccion", 0, 600, 53);
					break;

				}case ALLEGRO_KEY_A: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 3;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(pocion, 2, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);
					texto("2. Una de las siguientes es considerada de las cuatro reglas del metodo", 0, 5, 20);
					texto("en Descartes ", 0, 5, 35);
					texto("B) Deduccion", 0, 200, 53);
					texto("C) Evidencia", 0, 400, 53);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 2, 53, NULL, "A) Hipotesis");

					al_play_sample_instance(instance2);
					texto("D) Induccion", 0, 600, 53);
					break;
				}

				case ALLEGRO_KEY_D: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 3;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(pocion, 600, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					texto("2. Una de las siguientes es considerada de las cuatro reglas del metodo", 0, 5, 20);
					texto("en Descartes ", 0, 5, 35);
					texto("A) Hipotesis", 0, 2, 53);
					texto("C) Evidencia", 0, 400, 53);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 600, 53, NULL, "D) Induccion");

					al_play_sample_instance(instance2);
					texto("B) Deduccion", 0, 200, 53);
					break;
				}




				}
			}
			else if (m == 3) {
				al_clear_to_color(al_map_rgb(0, 0, 0));

				menu_null = al_load_bitmap("Imagenes/Mapa Corazon.png");

				al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
				//al_draw_bitmap(globo, 2, 156, NULL);
				//al_draw_bitmap(globo, 200, 156, NULL);
				//al_draw_bitmap(globo, 400, 156, NULL);
				//al_draw_bitmap(globo, 600, 156, NULL);

				texto("3. En ralacion con los datos experimentales que otorgan los sentidos en el  ", 0, 5, 15);
				texto("conocimiento, Descartes define como; ", 0, 5, 33);
				texto("A) Los sentidos son una ", 0, 2, 53);
				texto("fuente confiable", 0, 2, 73);
				texto("para conocer", 0, 2, 88);
				texto("B) Desconfianza de", 0, 200, 53);
				texto("lo que los sentidos  ", 0, 200, 73);
				texto("nos proporcionan", 0, 200, 88);
				texto("C) Los sentidos son ", 0, 400, 53);
				texto("complementarios", 0, 400, 73);

				texto("D) Los sentidos son", 0, 600, 53);
				texto("determinantes", 0, 600, 73);


				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_A: {
					al_clear_to_color(al_map_rgb(0, 0, 0));


					m = 4;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(pocion, 2, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);


					texto("3. En ralacion con los datos experimentales que otorgan los sentidos en el  ", 0, 5, 15);
					texto("conocimiento, Descartes define como; ", 0, 5, 45);
					texto("B) Desconfianza de", 0, 200, 53);
					texto("lo que los sentidos  ", 0, 200, 73);
					texto("nos proporcionan", 0, 200, 88);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 2, 53, NULL, "A)  Los sentidos son una");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 2, 73, NULL, "fuente confiable");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 2, 88, NULL, "para conocer");

					al_play_sample_instance(instance2);
					texto("C) Los sentidos son ", 0, 400, 53);
					texto("complementarios", 0, 400, 73);

					texto("D) Los sentidos son", 0, 600, 53);
					texto("determinantes", 0, 600, 73);
					break;

				}case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));


					m = 4;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);


					texto("3. En ralacion con los datos experimentales que otorgan los sentidos en el  ", 0, 5, 15);
					texto("conocimiento, Descartes define como; ", 0, 5, 45);
					texto("A) Los sentidos son una ", 0, 2, 53);
					texto("fuente confiable", 0, 2, 73);
					texto("para conocer", 0, 2, 88);
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 200, 210, NULL, "B) Desconfianza de");
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 200, 230, NULL, "lo que los sentidos");
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 200, 250, NULL, "nos proporcionan");

					al_play_sample_instance(instance);
					texto("C) Los sentidos son ", 0, 400, 53);
					texto("complementarios", 0, 400, 73);

					texto("D) Los sentidos son", 0, 600, 53);
					texto("determinantes", 0, 600, 73);
					break;

				}case ALLEGRO_KEY_C: {
					al_clear_to_color(al_map_rgb(0, 0, 0));


					m = 4;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(pocion, 400, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);


					texto("3. En ralacion con los datos experimentales que otorgan los sentidos en el  ", 0, 5, 15);
					texto("conocimiento, Descartes define como; ", 0, 5, 35);
					texto("A) Los sentidos son una ", 0, 2, 53);
					texto("fuente confiable", 0, 2, 73);
					texto("para conocer", 0, 2, 88);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 400, 53, NULL, "C) Los sentidos son");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 400, 73, NULL, "complementarios");


					al_play_sample_instance(instance2);
					texto("B) Desconfianza de", 0, 200, 53);
					texto("lo que los sentidos  ", 0, 200, 73);
					texto("nos proporcionan", 0, 200, 88);

					texto("D) Los sentidos son", 0, 600, 53);
					texto("determinantes", 0, 600, 73);
					break;

				}

				case ALLEGRO_KEY_D: {
					al_clear_to_color(al_map_rgb(0, 0, 0));


					m = 4;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(pocion, 600, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 2, 156, NULL);


					texto("3. En ralacion con los datos experimentales que otorgan los sentidos en el  ", 0, 5, 15);
					texto("conocimiento, Descartes define como; ", 0, 5, 35);
					texto("A) Los sentidos son una ", 0, 2, 53);
					texto("fuente confiable", 0, 2, 73);
					texto("para conocer", 0, 2, 88);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 600, 53, NULL, "C) Los sentidos son");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 600, 73, NULL, "determinantes");


					al_play_sample_instance(instance2);
					texto("B) Desconfianza de", 0, 200, 53);
					texto("lo que los sentidos  ", 0, 200, 73);
					texto("nos proporcionan", 0, 200, 88);

					texto("C) Los sentidos son", 0, 400, 53);
					texto("complementarios", 0, 400, 73);
					break;
				}




				}
			}
			else if (m == 4) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				menu_null = al_load_bitmap("Imagenes/MapaDescartes.png");

				al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
				//al_draw_bitmap(globo, 2, 156, NULL);
				//al_draw_bitmap(globo, 200, 156, NULL);
				//al_draw_bitmap(globo, 400, 156, NULL);
				//al_draw_bitmap(globo, 600, 156, NULL);


				texto("4. Solo debemos aceptar como verdadero aquel conocimineto que sea ", 0, 5, 15);
				texto("EVIDENTE, CLARO Y DISTINTO ", 0, 5, 35);
				texto("A) Rene Descartes", 0, 2, 53);
				texto("B) David Hume", 0, 200, 53);
				texto("C) George Berkeley", 0, 400, 53);
				texto("D) Aristoteles", 0, 600, 53);


				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_A: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 5;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);
					texto("4. Solo debemos aceptar como verdadero aquel conocimineto que sea ", 0, 5, 15);
					texto("EVIDENTE, CLARO Y DISTINTO ", 0, 5, 35);
					texto("B) David Hume", 0, 200, 53);
					texto("C) George Berkeley", 0, 400, 53);
					texto("D) Aristoteles", 0, 600, 53);
					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 2, 53, NULL, "A) Rene Descartes");

					al_play_sample_instance(instance);

					break;

				}case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 5;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(pocion, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);
					texto("4. Solo debemos aceptar como verdadero aquel conocimineto que sea ", 0, 5, 15);
					texto("EVIDENTE, CLARO Y DISTINTO ", 0, 5, 35);
					texto("A) Rene Descartes", 0, 2, 53);
					texto("C) George Berkeley", 0, 400, 53);
					texto("D) Aristoteles", 0, 600, 53);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 53, NULL, "B) David Hume");

					al_play_sample_instance(instance2);
					break;

				}case ALLEGRO_KEY_C: {
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					m = 5;
					//al_draw_bitmap(menu_null, 0, 0, 0);
					//al_draw_bitmap(menu_null, 0, 0, 0);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(pocion, 400, 156, NULL);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);
					texto("4. Solo debemos aceptar como verdadero aquel conocimineto que sea ", 0, 5, 15);
					texto("EVIDENTE, CLARO Y DISTINTO ", 0, 5, 35);
					texto("A) Rene Descartes", 0, 2, 53);
					texto("B) David Hume", 0, 200, 53);
					texto("D) Aristoteles", 0, 600, 53);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 400, 53, NULL, "C) George Berkeley");

					al_play_sample_instance(instance2);
					break;

				}

				case ALLEGRO_KEY_D: {
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					m = 5;
					//al_draw_bitmap(menu_null, 0, 0, 0);
					//al_draw_bitmap(menu_null, 0, 0, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(pocion, 600, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					texto("4. Solo debemos aceptar como verdadero aquel conocimineto que sea ", 0, 5, 15);
					texto("EVIDENTE, CLARO Y DISTINTO ", 0, 5, 35);
					texto("A) Rene Descartes", 0, 2, 53);
					texto("B) David Hume", 0, 200, 53);
					texto("C) George Berkeley", 0, 400, 53);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 600, 53, NULL, "D) Aristoteles");

					al_play_sample_instance(instance2);
					break;
				}




				}
			}
			else if (m == 5) {
				al_clear_to_color(al_map_rgb(0, 0, 0));

				menu_null = al_load_bitmap("Imagenes/Mapa Pregunta.png");
				al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
				//al_draw_bitmap(globo, 2, 156, NULL);
				//al_draw_bitmap(globo, 200, 156, NULL);
				//al_draw_bitmap(globo, 400, 156, NULL);
				//al_draw_bitmap(globo, 600, 156, NULL);


				texto("5. En cuanto a la certeza del conocimiento, Rene descartes afirma lo siguiente ", 0, 5, 15);
				texto("A) Es preciso dudar", 0, 2, 35);
				texto("B) Debemos confiar", 0, 200, 35);
				texto("ciegamente", 0, 200, 55);
				texto("C) Nada es importante", 0, 400, 35);
				texto("D) Todo es posible", 0, 600, 35);


				switch (Evento.keyboard.keycode) {
				case ALLEGRO_KEY_A: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 6;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);

					texto("5. En cuanto a la certeza del conocimiento, Rene descartes afirma lo siguiente ", 0, 5, 15);
					texto("B) Debemos confiar", 0, 200, 35);
					texto("ciegamente", 0, 200, 55);
					texto("C) Nada es importante", 0, 400, 35);
					texto("D) Todo es posible", 0, 600, 35);

					al_draw_text(Triforce, al_map_rgb(0, 255, 0), 2, 35, NULL, "A) Es preciso dudar");
					al_play_sample_instance(instance);

					break;

				}case ALLEGRO_KEY_B: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 6;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(pocion, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);
					texto("5. En cuanto a la certeza del conocimiento, Rene descartes afirma lo siguiente ", 0, 5, 15);
					texto("A) Es preciso dudar", 0, 2, 35);
					texto("C) Nada es importante", 0, 400, 35);
					texto("D) Todo es posible", 0, 600, 35);

					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 35, NULL, "B) Debemos confiar");
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 200, 55, NULL, "ciegamente");
					al_play_sample_instance(instance2);
					break;

				}case ALLEGRO_KEY_C: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 6;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(pocion, 400, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 600, 156, NULL);
					texto("5. En cuanto a la certeza del conocimiento, Rene descartes afirma lo siguiente ", 0, 5, 15);
					texto("A) Es preciso dudar", 0, 2, 35);
					texto("B) Debemos confiar", 0, 200, 35);
					texto("ciegamente", 0, 200, 55);
					texto("D) Todo es posible", 0, 600, 35);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 400, 35, NULL, "C) Nada es importante");
					al_play_sample_instance(instance2);
					break;

				}

				case ALLEGRO_KEY_D: {
					al_clear_to_color(al_map_rgb(0, 0, 0));
					m = 6;
					al_draw_scaled_bitmap(menu_null, 0, -29, 242, 161, 0, 0, 801, 600, 0);
					//al_draw_bitmap(globo, 2, 156, NULL);
					//al_draw_bitmap(pocion, 600, 156, NULL);
					//al_draw_bitmap(globo, 200, 156, NULL);
					//al_draw_bitmap(globo, 400, 156, NULL);
					texto("5. En cuanto a la certeza del conocimiento, Rene descartes afirma lo siguiente ", 0, 5, 15);
					texto("A) Es preciso dudar", 0, 2, 35);
					texto("B) Debemos confiar", 0, 200, 35);
					texto("ciegamente", 0, 200, 35);
					texto("C) Nada es importante", 0, 400, 35);
					al_draw_text(Triforce, al_map_rgb(255, 0, 0), 600, 35, NULL, "D) Todo es posible");
					al_play_sample_instance(instance2);
					break;
				}




				}
			}


		}
		switch (Evento.keyboard.keycode) {
		case ALLEGRO_KEY_ESCAPE: {
			return 1;
		}
		}
		al_flip_display();

	}

	al_destroy_sample_instance(instance2);
	al_destroy_sample_instance(instance);

}


void Descartes::texto(string msj, int c, int x, int y) {
	ALLEGRO_FONT* Triforce = al_load_font("Fonts/Triforce.ttf", 19, 0);
	ALLEGRO_FONT* Triforce1 = al_load_font("Fonts/Triforce.ttf", 23, 0);
	al_draw_text(Triforce, al_map_rgb(225, 225, 225), x, y, 0, msj.c_str());
}




