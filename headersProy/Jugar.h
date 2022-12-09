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
struct text {
	char intro[100];
}T[10];
class Jugar
{
public:
	ALLEGRO_DISPLAY* ventanaJ;
	Jugar(ALLEGRO_DISPLAY* ventanaMain);
	int jugar();
private:
	int contador = 0;
	void Texto();
	void mostrar(ALLEGRO_DISPLAY* pantalla);
	int show = 0;
};

Jugar::Jugar(ALLEGRO_DISPLAY* ventanaMain)
{
	ventanaJ = ventanaMain;
	jugar();
}
void Jugar::Texto() {
	strcpy_s(T[0].intro, "En el reino de Hyrule, la trifuerza un");
	strcpy_s(T[1].intro, "objeto deseado por muchas personas, algunas");
	strcpy_s(T[2].intro, "intentando dominarse del mundo. Dos bandos,");
	strcpy_s(T[3].intro, "los empiristas y los racionalistas quieren ");
	strcpy_s(T[4].intro, "apoderarse de ese poder para demostrar quien ");
	strcpy_s(T[5].intro, "es superior, en una lucha constante. Quien ");
	strcpy_s(T[6].intro, "ganara? Link, un mercenario en busca de trabajo ");
	strcpy_s(T[7].intro, "se topa con dos personas que estan en peligro,");
	strcpy_s(T[8].intro, "corriendo a su llamado de auxilio, Link elige ");
	strcpy_s(T[9].intro, "ayudar a estas dos personas.");

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

		//al_draw_scaled_bitmap(Nivel1, 0, 0, 768, 576, 0, 0, 800, 600, 0);
		if (show < 1) {
			mostrar(ventanaJ);
			show++;
		}
		//al_draw_(200, 200, 100, al_map_rgb(255, 255, 255));
		//al_draw_text(Triforce, al_map_rgb(0, 0, 0), 250, 1, NULL, "Historia:");
		//al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 63, NULL, "En el reino de Hyrule, la trifuerza un objeto deseado por muchas personas,");
		//al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 93, NULL, "algunas intentando dominarse del mundo. Dos bandos,los empiristas y los racionalistas");
		///al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 123, NULL, "apoderarse de ese poder para demostrar quien es superior, en una lucha");
		//al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 153, NULL, "constante.Link, un mercenario en busca de trabajo, este se topa");
		//al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 183, NULL, "con dos personas que estan en peligro, corriendo a su llamado de auxilio,");
		//al_draw_text(Triforce1, al_map_rgb(0, 0, 0), 1, 213, NULL, "Link elige ayudar a estas dos personas.");
		al_draw_text(Triforce, al_map_rgb(225, 225, 225), 250, 375, NULL, "Jugar");
		al_flip_display();
		al_draw_text(Triforce, al_map_rgb(225, 225, 225), 250, 375, NULL, "Jugar");
		al_flip_display();
		if (botones[0] == 0)
			al_draw_text(Triforce, al_map_rgb(225, 225, 225), 250, 375, NULL, "Jugar");
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
void Jugar::mostrar(ALLEGRO_DISPLAY* pantalla) {
	al_init_image_addon();
	Texto();

	al_install_keyboard();

	//Incializa texto
	al_init_font_addon();
	al_init_ttf_addon();




	//ALLEGRO_DISPLAY* pantalla = al_create_display(800, 600);




	//texto
	text h;
	strcpy_s(h.intro, "En el reino de Hyrule, la trifuerza un objeto");

	cout << h.intro << endl;

	char hola[100];
	strcpy_s(hola, h.intro);


	ALLEGRO_FONT* font = al_load_font("Fonts/VPPixel-Simplified.otf", 18, 0);
	ALLEGRO_EVENT evento;


	char a;
	string b;

	ALLEGRO_EVENT_QUEUE* Mis_eventos;




	// creo lista de eventos

	Mis_eventos = al_create_event_queue();


	// asigno eventos a la lista de eventos

	al_register_event_source(Mis_eventos, al_get_keyboard_event_source());

	al_register_event_source(Mis_eventos, al_get_display_event_source(pantalla));

	int respuesta;
	contador++;

	//cout << answer<<endl;
	ALLEGRO_TIMER* segundo = al_create_timer(0.1);

	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

	al_register_event_source(queue, al_get_timer_event_source(segundo));
	al_start_timer(segundo);
	int sec = 0, line = 0;
	ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/introduccion.png");
	al_draw_scaled_bitmap(fondo, 0, 0, 256, 239, 0, 0, 800, 600, 0);
	string lenght;
	while (line < 10) {
		lenght = T[line].intro;

		while (sec <= lenght.size()) {
			al_wait_for_event(queue, &evento);
			if (evento.type == ALLEGRO_EVENT_TIMER) {
				if (evento.timer.source == segundo) {



					a = lenght[sec];
					sec++;
					b = a;
					cout << a;
					//cout << a << endl;
					al_draw_text(font, al_map_rgb(255, 255, 255), 70 + (sec * 14), 100 + (line * 40), NULL, b.c_str());


					al_flip_display();




				}
			}

		}
		sec = 0;
		line++;
	}
	while (sec <= 20) {
		al_wait_for_event(queue, &evento);
		if (evento.type == ALLEGRO_EVENT_TIMER) {
			if (evento.timer.source == segundo) {



				
				sec++;
				b = a;
				




			}
		}

	}
	// al_clear_to_color(al_map_rgb(0, 0, 0));

}
