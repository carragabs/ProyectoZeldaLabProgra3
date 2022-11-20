#pragma once

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

//ALLEGRO_DISPLAY* ventana;
ALLEGRO_EVENT_QUEUE* event_queue;

int jugar();
int menu();

class MenuInicial 
{
public:

	int ancho = 768;
	int alto = 576;

	ALLEGRO_SAMPLE* songFondo;
	ALLEGRO_SAMPLE_INSTANCE* instanceFondo;
	MenuInicial(ALLEGRO_DISPLAY* ventanaMain);
	int crearMenuInicial();
	int menu();
	ALLEGRO_DISPLAY* ventana;

private:

};

MenuInicial::MenuInicial(ALLEGRO_DISPLAY* ventanaMain)
{
	ventana = ventanaMain;
}

int MenuInicial::crearMenuInicial()
{

	/*if (!al_init()) {
		al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR: 404", "No se pudo cargar correctamente la libreria alelgro", NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return -1;
	} */

	//ventana = al_create_display(ancho, alto);

	int ancho_W = GetSystemMetrics(SM_CXSCREEN);
	int alto_W = GetSystemMetrics(SM_CYSCREEN);

	al_set_window_title(ventana, "Zelda");
	//al_set_window_position(ventana, ancho_W / 2 - ancho / 2, alto_W / 2 - alto / 2);

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());

	return menu();

}

int MenuInicial::menu() {
	int x = -1, y = -1;
	al_register_event_source(event_queue, al_get_display_event_source(ventana));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	ALLEGRO_KEYBOARD_STATE teclado;

	//al_install_audio();

	//al_init_acodec_addon();
	al_reserve_samples(2);
	al_reserve_samples(2);
	ALLEGRO_SAMPLE* song = al_load_sample("Audios/Opciones.mpeg");
	ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
	
	al_reserve_samples(2);
	songFondo = al_load_sample("Audios/Fondo.mpeg");
	instanceFondo = al_create_sample_instance(songFondo);
	al_set_sample_instance_playmode(instanceFondo, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(instanceFondo, al_get_default_mixer());
	al_play_sample_instance(instanceFondo); 

	ALLEGRO_BITMAP* menu_null = al_load_bitmap("Imagenes/Menu.jpeg");
	ALLEGRO_BITMAP* menu_jugar = al_load_bitmap("Imagenes/Jugar.jpeg");
	ALLEGRO_BITMAP* menu_salir = al_load_bitmap("Imagenes/Salir.jpeg");

	//menu
	int botones[] = { 0 };
	int resultadoBoton;

	while (true)
	{
		ALLEGRO_EVENT Evento;
		al_wait_for_event(event_queue, &Evento);

		ALLEGRO_KEYBOARD_STATE teclado;

		al_clear_to_color(al_map_rgb(0, 0, 0));



		//SI ESTA ENCIMA DEL BOTON, DIBUJA EL BOTON COLOREADO
		if (botones[0] == 0)
			al_draw_scaled_bitmap(menu_null, 0, 0, 768 ,576,0,0,800,600,0);
		else if (botones[0] == 1)
		al_draw_scaled_bitmap(menu_jugar, 0, 0, 768, 576, 0, 0, 800, 600, 0);

		else
			al_draw_scaled_bitmap(menu_salir, 0, 0, 768, 576, 0, 0, 800, 600, 0);

		al_get_keyboard_state(&teclado);

		if (Evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			exit(0);
		if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE))
			exit(0);

		if (Evento.type == ALLEGRO_EVENT_MOUSE_AXES || Evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{

			x = Evento.mouse.x;
			y = Evento.mouse.y;

			//SI ESTA ENCIMA DEL BOTON Y PRESIONA EL MOUSE, SE QUIEBRA EL LOOP PARA RETORNAR EL RESULTADO
			if (x >= 234 && x <= 527 && y >= 354 && y <= 413) {
				botones[0] = 1;
				al_play_sample_instance(instance);
				if (Evento.mouse.button & 1)
				{
					resultadoBoton = 1;
					break;
				}

			}
			else {
				if (x >= 234 && x <= 527 && y >= 451 && y <= 510) {
					botones[0] = 2;
					al_play_sample_instance(instance);
					if (Evento.mouse.button & 1)
					{
						exit(0);
					}
				}
				else {
					botones[0] = 0;
				}

			}


		}

		al_flip_display();
	}

	al_destroy_sample(song);
	al_destroy_sample_instance(instance);

	al_destroy_event_queue(event_queue);

	al_destroy_bitmap(menu_null);
	al_destroy_bitmap(menu_jugar);
	al_destroy_bitmap(menu_salir);

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_rest(1);

	return resultadoBoton;


}