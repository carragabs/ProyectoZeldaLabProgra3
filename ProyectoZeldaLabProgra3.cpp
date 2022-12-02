#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "headersProy/HubNivel2.h"
#include "headersProy/Ruleta.h"
#include "headersProy/MinijuegoCofres.h"
#include "headersProy/MenuInicial.h"
#include "headersProy/Jugar.h"
#include "headersProy/eleccionDeBando.h"
#include "headersProy/MinijuegoHistoria.h"
#include "headersProy/animN3.h"

void crearSigMinijuego(char minijuegoP, ALLEGRO_DISPLAY* pantallaMain)
{

	if (minijuegoP == 'A')
		cout << "SE CREA MINIJUEGO ARTE" << endl;

	else if (minijuegoP == 'H')
		MinijuegoHistoria miniHistoria(pantallaMain);

	else if (minijuegoP == 'P')
		MinijuegoCofres miMiniCofres(pantallaMain);

	else if (minijuegoP == 'C')
		cout << "SE CREA MINIJUEGO CIENCIA" << endl;

}

int main()

{
	bool salir = true;

	int ancho = 800;
	int alto = 600;

	ALLEGRO_DISPLAY* ventana = NULL;
	if (!al_init())
		return -1;

	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_install_mouse();
	al_init_image_addon();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();

	ventana = al_create_display(ancho, alto);

	if (!ventana)
		return -1;

	int resultadoReturn;

	//NIVEL 1
	MenuInicial miMenuI(ventana);
	miMenuI.crearMenuInicial();

	Jugar miJugar(ventana);

	al_destroy_sample(miMenuI.songFondo);
	al_destroy_sample_instance(miMenuI.instanceFondo);


	//NIVEL 2
	string resultadominijuego;
	char sigMini;

	Ruleta miRuleta(ventana);
	miRuleta.crearRuleta();
	resultadominijuego = miRuleta.getMinijuego(miRuleta.resultadoruleta);
	sigMini = resultadominijuego[0];
	HubN2 miHUbN2(ventana);
	miHUbN2.crearNivel2(resultadominijuego);
	crearSigMinijuego(sigMini, ventana);

	miRuleta.crearRuleta();
	resultadominijuego = miRuleta.getMinijuego(miRuleta.resultadoruleta);
	sigMini = resultadominijuego[0];
	miHUbN2.crearNivel2(resultadominijuego);
	crearSigMinijuego(sigMini, ventana);

	miRuleta.crearRuleta();
	resultadominijuego = miRuleta.getMinijuego(miRuleta.resultadoruleta);
	sigMini = resultadominijuego[0];
	miHUbN2.crearNivel2(resultadominijuego);
	crearSigMinijuego(sigMini, ventana);

	miRuleta.crearRuleta();
	resultadominijuego = miRuleta.getMinijuego(miRuleta.resultadoruleta);
	sigMini = resultadominijuego[0];
	miHUbN2.crearNivel2(resultadominijuego);
	crearSigMinijuego(sigMini, ventana);


	eleccionDeBando miEDB(ventana);
	miEDB.crearEleccionBando();	
	
	animacionN3 mianimN3(ventana);
	mianimN3.crearAnimaciones();	

	return 0;


}

