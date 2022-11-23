#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Transicion.h"

using namespace std;

struct coordenadasEntradas {
    int xRect;
    int yRect;
    string minijuego;
};

struct Sprite
{
    double x, y;

    int desplaza;

    int paso;

    int dir;
};

class HubN2 {
public:
    ALLEGRO_DISPLAY* pantalla;
    HubN2(ALLEGRO_DISPLAY* pantallaMain);
    string minijuego;
    void crearNivel2(string minijuegoP);
    coordenadasEntradas entradaAbierta;
    void validarMinijuego(ALLEGRO_BITMAP* obsP, coordenadasEntradas entrada,
        coordenadasEntradas warp, string minijuegoAjugar);
    void crearColisionesEntradas(coordenadasEntradas entrada, string minjuegoP);
    bool crearColisionesWarp(coordenadasEntradas entrada, string minjuegoP);

    double x, y;
    int desplaza;
    int paso;
    int dir;
    coordenadasEntradas coordRectangulos[4];
    coordenadasEntradas entradaArte;
    coordenadasEntradas entradaHist;
    coordenadasEntradas entradaPolit;
    coordenadasEntradas entradaCiencia;
    coordenadasEntradas coordWarp;

private:

};


void HubN2::validarMinijuego(ALLEGRO_BITMAP* obsP, coordenadasEntradas entrada, coordenadasEntradas warp, string minijuegoAjugar) {
    if (minijuegoAjugar == entrada.minijuego)
    {
        coordWarp.xRect = warp.xRect;
        coordWarp.yRect = warp.yRect;
        coordWarp.minijuego = "";

    }
    else
    {
        al_draw_scaled_bitmap(obsP, 0, 0, 31, 31, entrada.xRect, entrada.yRect, 40, 40, 0);
    }
}

void HubN2::crearColisionesEntradas(coordenadasEntradas entrada, string minijuegoP)
{
    if (entrada.minijuego != minijuegoP)
    {
        if (y * desplaza < entrada.yRect + 40 && y * desplaza >(entrada.yRect + 40) - 8
            && (x * desplaza < entrada.xRect + 40) && (x * desplaza + 32.5 > entrada.xRect))
        {
            cout << "COLLISION TRUE!" << endl;
            y = (entrada.yRect + 40) / desplaza;
        }
        if (y * desplaza + 35 > entrada.yRect && (y * desplaza + 35 < entrada.yRect + 8)
            && (x * desplaza < entrada.xRect + 40) && (x * desplaza + 32.5 > entrada.xRect))
        {
            cout << "COLLISION TRUE!" << endl;
            y = (entrada.yRect - (35)) / desplaza;
        }

        if (x * desplaza < entrada.xRect + 40 && x * desplaza >(entrada.xRect + 40) - 8
            && (y * desplaza < entrada.yRect + 40) && (y * desplaza + 35 > entrada.yRect))
        {
            cout << "COLLISION TRUE!" << endl;
            x = (entrada.xRect + 40) / desplaza;
        }
        if (x * desplaza + 32.5 > entrada.xRect && x * desplaza + 32.5 < entrada.xRect + 8
            && (y * desplaza < entrada.yRect + 40) && (y * desplaza + 35 > entrada.yRect))
        {
            cout << "COLLISION TRUE!" << endl;
            x = (entrada.xRect - 32.5) / desplaza;
        }
    }
}

bool HubN2::crearColisionesWarp(coordenadasEntradas warp, string minijuegoP)
{

    if (y * desplaza < warp.yRect + 40 && y * desplaza >(warp.yRect + 40) - 8
        && (x * desplaza < warp.xRect + 40) && (x * desplaza + 32.5 > warp.xRect))
    {
        cout << "COLLISION TRUE!" << endl;
        return true;
    }
    if (y * desplaza + 35 > warp.yRect && (y * desplaza + 35 < warp.yRect + 8)
        && (x * desplaza < warp.xRect + 40) && (x * desplaza + 32.5 > warp.xRect))
    {
        cout << "COLLISION TRUE!" << endl;
        return true;
    }

    if (x * desplaza < warp.xRect + 40 && x * desplaza >(warp.xRect + 40) - 8
        && (y * desplaza < warp.yRect + 40) && (y * desplaza + 35 > warp.yRect))
    {
        cout << "COLLISION TRUE WARP!" << endl;
        return true;
    }
    if (x * desplaza + 32.5 > warp.xRect && x * desplaza + 32.5 < warp.xRect + 8
        && (y * desplaza < warp.yRect + 40) && (y * desplaza + 35 > warp.yRect))
    {
        cout << "COLLISION TRUE!" << endl;
        return true;
    }

    return false;
}


HubN2::HubN2(ALLEGRO_DISPLAY* pantallaMain)
{
    pantalla = pantallaMain;
    minijuego = "";
}
void HubN2::crearNivel2(string minijuegoP)

{
    minijuego = minijuegoP;

    const int maxFrame = 7;
    int curFrame = 0;
    int frameCount = 0;
    int frameDelay = 2;


    al_set_window_title(pantalla, "HUB Nivel 2");

    ALLEGRO_BITMAP* prota = al_load_bitmap("Alm1.png");
    ALLEGRO_BITMAP* warpOff = al_load_bitmap("warpOff.png");
    ALLEGRO_BITMAP* fondo = al_load_bitmap("PrototipoMapa1.jpeg");
    ALLEGRO_BITMAP* obstaculoEntrada = al_load_bitmap("boulderBig.png");
    ALLEGRO_BITMAP* transition = al_load_bitmap("watertrans.png");
    ALLEGRO_BITMAP* warptile = al_load_bitmap("warpsheetsmall.png");

    ALLEGRO_EVENT_QUEUE* Mis_eventos;
    //ALLEGRO_EVENT evento;
    ALLEGRO_TIMER* timer;
    // creo lista de eventos

    Mis_eventos = al_create_event_queue();
    timer = al_create_timer(1.0 / 15);

    // asigno eventos a la lista de eventos

    al_register_event_source(Mis_eventos, al_get_timer_event_source(timer));

    al_register_event_source(Mis_eventos, al_get_keyboard_event_source());

    al_register_event_source(Mis_eventos, al_get_display_event_source(pantalla));

    ALLEGRO_KEYBOARD_STATE teclado;


    bool salir;

    // inicializar vbles
    
    x = 356 / 4;

    y = 288 / 4;


    desplaza = 4;


    paso = 0;

    dir = 0;


    salir = false;

    entradaArte = { 356,200 , "ARTE" };
    entradaHist = { 355,355 , "HISTORIA" };
    entradaPolit = { 250,280 ,"POLITICA" };
    entradaCiencia = { 455,280,"CIENCIA" };
    coordRectangulos[0] = entradaArte;
    coordRectangulos[1] = entradaHist;
    coordRectangulos[2] = entradaPolit;
    coordRectangulos[3] = entradaCiencia;
    int xWA = 250;
    int yWA = 75;
    int xWH = 460;
    int yWH = 450;
    int xWP = 165;
    int yWP = 350;
    int xWC = 646;
    int yWC = 160;

    coordenadasEntradas warpArte = { xWA,yWA , "" };
    coordenadasEntradas warpHist = { xWH,yWH , "" };
    coordenadasEntradas warpPolit = { xWP,yWP , "" };
    coordenadasEntradas warpCiencia = { xWC,yWC , "" };

    coordenadasEntradas cordWarps[4];
    cordWarps[0] = warpArte;
    cordWarps[1] = warpHist;
    cordWarps[2] = warpPolit;
    cordWarps[3] = warpCiencia;

    Transition transHub;
    transHub.drawTransitionReversa(pantalla, fondo, 1280, 1022, prota, paso, dir, x, y, desplaza);

    al_start_timer(timer);

    while (!salir)

    {
        ALLEGRO_EVENT evento;
        al_wait_for_event(Mis_eventos, &evento);

        al_draw_scaled_bitmap(fondo, 0, 0, 1280, 1022, 0, 0, 800, 600, 0);
        al_draw_scaled_bitmap(warpOff, 1, 9, 15, 15, 356, 288, 30, 30, 0);
        al_draw_bitmap_region(prota, paso * 32.5, dir * 35, 32.5, 35, x * desplaza, y * desplaza, 0);
        al_draw_bitmap_region(warptile, 40 * curFrame, 0, 40, 75, coordWarp.xRect, coordWarp.yRect, 0);

        int i;
        for (i = 0; i < 4; i++)
        {
            validarMinijuego(obstaculoEntrada, coordRectangulos[i], cordWarps[i], minijuego);
        }

        salir = crearColisionesWarp(coordWarp, minijuego);

        al_flip_display();

        al_get_keyboard_state(&teclado);

        if (evento.type == ALLEGRO_EVENT_TIMER)

        {
            if (++curFrame >= maxFrame)
            {
                curFrame = 0;
            }

            al_draw_bitmap_region(warptile, 40 * curFrame, 0, 40, 75, coordWarp.xRect, coordWarp.yRect, 0);
            al_flip_display();
        }


        else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)

        {

            exit(0);

        }


        else

        {
            if (al_key_down(&teclado, ALLEGRO_KEY_UP))

            {

                y--;

                cout << "y: " << y * desplaza << endl;
                cout << "x: " << x * desplaza << endl;

                dir = 4;

                paso++;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_DOWN))

            {

                y++;

                cout << "y: " << y * desplaza << endl;
                cout << "x: " << x * desplaza << endl;

                dir = 3;

                paso++;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_LEFT))

            {

                x--;

                cout << "x: " << x * desplaza << endl;
                cout << "y: " << y * desplaza << endl;

                dir = 1;

                paso++;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT))

            {

                x++;

                cout << "x: " << x * desplaza << endl;
                cout << "y: " << y * desplaza << endl;


                dir = 2;

                paso++;

            }
        }


        // limitadores


        if (x < 0) x = 0;

        if (x * desplaza > 800 - 32.5) x = 191.87;

        if (y < 0) y = 0;

        if (y * desplaza > 600 - 35) y = 141.25;


        if (paso > 3) paso = 0;

        if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE)) {
            exit(0);
        }

        crearColisionesEntradas(entradaArte, minijuego);
        crearColisionesEntradas(entradaCiencia, minijuego);
        crearColisionesEntradas(entradaHist, minijuego);
        crearColisionesEntradas(entradaPolit, minijuego);


    }

    transHub.drawTransition(pantalla, fondo, 1280, 1022,prota, paso, dir, x, y, desplaza);
    transHub.destroyTrans();

    al_destroy_bitmap(prota);
    al_destroy_bitmap(fondo);
    al_destroy_bitmap(obstaculoEntrada);
    al_destroy_bitmap(transition);
    al_destroy_bitmap(warptile);
    al_destroy_event_queue(Mis_eventos);
    al_destroy_timer(timer);

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();
    al_rest(1);

    //return 0;

}
