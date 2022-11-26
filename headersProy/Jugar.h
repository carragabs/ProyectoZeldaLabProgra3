#pragma once
//ARREGLAR EL BITON X Y ESCAPE PARA SALIR
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
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

using namespace std;

int jugar();
int ancho = 768;
int alto = 576;

ALLEGRO_EVENT_QUEUE* event_queueJ;

class Jugar
{
public:
	ALLEGRO_DISPLAY* ventanaJ;
	Jugar(ALLEGRO_DISPLAY* ventanaMain);
	int jugar();
private:
};

Jugar::Jugar(ALLEGRO_DISPLAY* ventanaMain)
{
	ventanaJ = ventanaMain;
	jugar();
}

int Jugar::jugar() {
	/*
	if (!al_init()) {
		al_show_native_message_box(NULL, "ERROR CRITICO",
			"ERROR: 404", "No se pudo cargar correctamente la libreria alelgro", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	}*/

	cout << "Click en boton jugar";
	ALLEGRO_FONT* Triforce = al_load_font("Fonts/Triforce.ttf", 62, 0);
	ALLEGRO_FONT* Triforce1 = al_load_font("Fonts/Triforce.ttf", 23, 0);
	ALLEGRO_BITMAP* Nivel1 = al_load_bitmap("Imagenes/Mapa2.jpg");

	int ancho_W = GetSystemMetrics(SM_CXSCREEN);
	int alto_W = GetSystemMetrics(SM_CYSCREEN);

	al_set_window_title(ventanaJ, "Nivel 1: Narracion");
	al_set_window_position(ventanaJ, ancho_W / 2 - ancho / 2, alto_W / 2 - alto / 2);

	event_queueJ = al_create_event_queue();

	al_register_event_source(event_queueJ, al_get_mouse_event_source());
	//al_register_event_source(event_queue, al_get_display_event_source(ventanaJ));
	//al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	ALLEGRO_SAMPLE* song = al_load_sample("Audios/Opciones.mpeg");
	ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer()); 

	int botones[] = { 0 };
	
	int x = -1, y = -1;
	while (true)
	{

		ALLEGRO_EVENT Evento;
		al_wait_for_event(event_queueJ, &Evento);

		//ALLEGRO_KEYBOARD_STATE teclado;

		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_scaled_bitmap(Nivel1, 0, 0, 768, 576, 0, 0, 800, 600, 0);

		//al_draw_(200, 200, 100, al_map_rgb(255, 255, 255));
		al_draw_text(Triforce, al_map_rgb(0, 0, 0), 250, 1, NULL, "Historia:");
		al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 63, NULL, "En el reino de Hyrule, la trifuerza un objeto deseado por muchas personas,");
		al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 93, NULL, "algunas intentando dominarse del mundo. Dos bandos,los empiristas y los racionalistas");
		al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 123, NULL, "apoderarse de ese poder para demostrar quien es superior, en una lucha");
		al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 153, NULL, "constante.Link, un mercenario en busca de trabajo, este se topa");
		al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 183, NULL, "con dos personas que estan en peligro, corriendo a su llamado de auxilio,");
		al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 213, NULL, "Link elige ayudar a estas dos personas.");
		al_draw_text(Triforce, al_map_rgb(0, 0, 0), 250, 375, NULL, "Jugar");
		al_flip_display();

		if (botones[0] == 0)
			al_draw_text(Triforce, al_map_rgb(0, 0, 0), 250, 375, NULL, "Jugar");
		else
			al_draw_text(Triforce, al_map_rgb(255, 0, 0), 250, 375, NULL, "Jugar");



		if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{

			x = Evento.mouse.x;
			y = Evento.mouse.y;

				if (x >= 250 && x <= 250+62 && y >= 375 && y <= 375+62) {
					botones[0] = 1;
					al_play_sample_instance(instance);
					if (Evento.mouse.button & 1)
					{
						break;
					}
				}
				else {
					botones[0] = 0;
				}

		}
		al_flip_display();


	}

	al_destroy_sample(song);
	al_destroy_sample_instance(instance);


	al_destroy_event_queue(event_queueJ);

	//al_destroy_display(ventanaJ);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_rest(1);

	return 1;
} 
