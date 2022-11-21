#pragma once
//VER COMO OPTIMIZAR LA RUEDA PARA QUE NO SE TRABE AL INICIO
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include<iostream>
#include<cstdlib>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

class Ruleta {
public:
	ALLEGRO_DISPLAY* display;
	int resultadoruleta;
	string resultados[4];
	 Ruleta(ALLEGRO_DISPLAY* displayMain);
	 int crearRuleta();
	 string getMinijuego(int resultado);
	void drawRuletaFinal(int frameActual, ALLEGRO_BITMAP* ruletaP);
private:

};

Ruleta::Ruleta(ALLEGRO_DISPLAY* displayMain)
{
	display = displayMain;
	//crearRuleta();

	for (size_t i = 0; i < 4; i++)
	{
		resultados[i] = "";
	}

}

string Ruleta::getMinijuego(int resultado)
{
	switch (resultado)
	{
	case 9: return "HISTORIA";
		break;
	case 13: return "HISTORIA";
		break;
	case 10: return "POLITICA";
		break;
	case 14: return "POLITICA";
		break;
	case 11: return "CIENCIA";
		break;
	case 15: return "CIENCIA";
		break;
	case 12: return "ARTE";
		break;
	default:
		break;
	}
}

void Ruleta::drawRuletaFinal(int FrameFinal , ALLEGRO_BITMAP* ruletaP)
{
	switch (FrameFinal)
	{
	case 9: al_draw_bitmap_region(ruletaP, 1006,0,503,490,100,100,0);
		break;
	case 13:  al_draw_bitmap_region(ruletaP, 1006, 0, 503, 490, 100, 100, 0);
		break;
	case 10:  al_draw_bitmap_region(ruletaP, 1509, 0, 503, 490, 100, 100, 0);
		break;
	case 14:  al_draw_bitmap_region(ruletaP, 1509, 0, 503, 490, 100, 100, 0);
		break;
	case 11: al_draw_bitmap_region(ruletaP, 503, 0, 503, 490, 100, 100, 0);
		break;
	case 15: al_draw_bitmap_region(ruletaP, 503, 0, 503, 490, 100, 100, 0);
		break;
	case 12: al_draw_bitmap_region(ruletaP, 0, 0, 503, 490, 100, 100, 0);
		break;
	default:
		break;
	}
}

int Ruleta::crearRuleta()
{
	int width = 800;
	int height = 600;
	bool done = false;

	const int maxFrame = 16;
	int curFrame = 0;
	int frameCount = 0;
	int frameDelay = 30;

	bool resultadovalido = false;
	string resultadorandom = "";
	bool resultadoEnarray;

	int i;
	//Loop hasta que el resultado que salga no este en el array(para no repetir minijuego)
	while(!resultadovalido)
	{
		resultadoEnarray = false;
		//Random number generator
		srand((unsigned)time(NULL));
		resultadoruleta = 9 + (rand() % 7);
		resultadorandom = getMinijuego(resultadoruleta); //get minijuego con el numero random desde 9-16

		for (i = 0; i < 4; i++) //si el resultado esta en el array, la variable se hace true
		{
			//VER SI EL RESULTADO SACADO ESTA EN EL ARRAY DE RESULTADOS
			if (resultadorandom == resultados[i])
			{
				resultadoEnarray = true; //Se busca todo el array, si permanece falso resultadoEnarray, no esta en el array
				//cout << "RESULTADO EN ARRAY " << resultadoEnarray << endl;
			}

		}

		if (!resultadoEnarray) //PRUEBA: solo si el resultado no esta en el array se hace false
			resultadovalido = true;
	}

	//Si se sale, ya se tiene un resultado que no esta en el array, entonces se busca donde este vacio para agregarlo
	for (i = 0; i < 4; i++) //si el resultado esta en el array, la variable se hace true
	{
		if (resultados[i] == "")
		{
			resultados[i] = resultadorandom; //en cuanto encuentre un indice vacio, agrega el nuevo resultado
			break; //ya no se necesita correr el for y buscar o agregar a mas indices
		}
	}

	//cout << "RESULTADO: " << resultadorandom << endl;

	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer;

	ALLEGRO_BITMAP* prota = al_load_bitmap("Alm1.png");
	ALLEGRO_BITMAP* fondo = al_load_bitmap("PrototipoMapa1.jpeg");
	ALLEGRO_BITMAP* ruletaSheet = al_load_bitmap("ruletasheet.png");
	ALLEGRO_FONT* Triforce = al_load_font("Fonts/Triforce.ttf", 50, 0);

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / 60);

	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_start_timer(timer);


	//al_init_acodec_addon();
	al_reserve_samples(2);
	al_reserve_samples(2);
	ALLEGRO_SAMPLE* song = al_load_sample("Opciones.mpeg");
	ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
	al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());

	bool salir;

	double x, y;

	int desplaza;

	int paso;

	int dir;


	// inicializar vbles

	x = 350 / 4;

	y = 280 / 4;


	desplaza = 4;


	paso = 0;

	dir = 0;


	salir = false;

	al_draw_scaled_bitmap(fondo, 0, 0, 1280, 1022, 0, 0, 800, 600, 0);

	al_draw_bitmap_region(prota, paso * 32.5, dir * 35, 32.5, 35, x * desplaza, y * desplaza, 0);

	al_flip_display();


	string resultadotemp = "";
	int iSX = 0;
	int sxRuleta[4];

	sxRuleta[0] = 0;
	sxRuleta[1] = 503;
	sxRuleta[2] = 1006;
	sxRuleta[3] = 1509;

	al_rest(2.5);

	while (!done)
	{


		//cout << "IN WHILE RULETA" << endl;
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exit(0);

			
		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)

		{

			exit(0);

		}

		curFrame++;

		if (iSX > 3)
			iSX = 0;


		if (curFrame < resultadoruleta)
		{
			al_play_sample(song, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			al_draw_bitmap_region(ruletaSheet, sxRuleta[iSX], 0, 503, 490, 100, 100, 0);
			al_flip_display();
			al_rest(0.5);
			iSX++;
		}
		else 
		{
			al_rest(0.5);
			al_play_sample(song, 1.0, 0.5, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
			drawRuletaFinal(curFrame, ruletaSheet);
			al_draw_text(Triforce, al_map_rgb(0, 0, 0), 100, 40, NULL, "PRESIONE SPACEBAR");
			al_flip_display();
			break;
		}

	}

	done = false;

	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				exit(0);
			else if (ev.keyboard.keycode == ALLEGRO_KEY_SPACE)
				done = true;

		}
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)

		{

			exit(0);

		}

	}

	//destroys
	al_destroy_sample(song);
	al_destroy_sample_instance(instance);
	al_destroy_timer(timer);

	al_destroy_bitmap(prota);
	al_destroy_bitmap(fondo);
	al_destroy_bitmap(ruletaSheet);
	al_destroy_event_queue(event_queue);

	//al_destroy_display(display);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_flip_display();
	al_rest(1);
	return 0;
}



