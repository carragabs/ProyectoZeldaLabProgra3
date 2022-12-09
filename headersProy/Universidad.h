#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Transicion.h"

using namespace std;

struct coordenadas3 {
    int xRect;
    int yRect;
    string minijuego;
};



ALLEGRO_LOCKED_REGION* lock5;
ALLEGRO_BITMAP* choque5;

class Dentro {
public:
    ALLEGRO_DISPLAY* pantalla;
    Dentro(ALLEGRO_DISPLAY* pantallaMain);
    string minijuego;
    bool crearUni();
    void validarPuerta(coordenadas3 warp);
    bool ColisionPuerta(coordenadas3 warp, double entradaW, double entradaH);


    double x, y;
    double protaW, protaH;
    int desplaza;
    int paso;
    int rot;
    int dir;

    coordenadas3 card;

private:

};

void bloquea5()
{
    lock5 = al_lock_bitmap(choque5, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);
}

// libera memoria
void desbloquea5()
{
    al_unlock_bitmap(choque5);
}

// comprueba si esta bloqueado
bool esRojo5(int x, int y)
{
    unsigned char r, g, b;
    ALLEGRO_COLOR colorMira;
    colorMira = al_get_pixel(choque5, x, y);
    al_unmap_rgb(colorMira, &r, &g, &b);

    return (r == 255 && g == 0 && b == 0);
}


void Dentro::validarPuerta(coordenadas3 warp) {

    card.xRect = warp.xRect;
    card.yRect = warp.yRect;
    card.minijuego = "";
}



bool Dentro::ColisionPuerta(coordenadas3 warp, double warpW, double warpH)
{

    if (y < warp.yRect + warpH && y >(warp.yRect + warpH) - 8
        && (x < warp.xRect + warpW) && (x + protaW > warp.xRect))
    {
        cout << "COLLISION TRUE!" << endl;
        return true;
    }
    if (y + protaH > warp.yRect && (y + protaH < warp.yRect + 8)
        && (x < warp.xRect + warpW) && (x + protaW > warp.xRect))
    {
        cout << "COLLISION TRUE!" << endl;
        return true;
    }

    if (x < warp.xRect + warpW && x >(warp.xRect + warpW) - 8
        && (y < warp.yRect + warpH) && (y + protaH > warp.yRect))
    {
        cout << "COLLISION TRUE WARP!" << endl;
        return true;
    }
    if (x + protaW > warp.xRect && x + protaW < warp.xRect + 8
        && (y < warp.yRect + warpH) && (y + protaH > warp.yRect))
    {
        cout << "COLLISION TRUE!" << endl;
        return true;
    }

    return false;
}

bool colisiona5(int x, int y)
{
    bloquea5();
    bool valor = false;
    for (int i = 1; i < 32 - 1; i++)
    {
        for (int j = 35 / 2; j < 35; j++)
        {
            int vx = x + i;
            int vy = y + j;
            if (esRojo5(vx, vy))
            {
                valor = true;
            }
        }
    }
    desbloquea5();
    return valor;
}


Dentro::Dentro(ALLEGRO_DISPLAY* pantallaMain)
{
    pantalla = pantallaMain;
    minijuego = "";
}

bool Dentro::crearUni()

{
    al_set_window_title(pantalla, "Nivel 4 - Uni");

    const int maxFrame = 7;
    int curFrame = 0;
    int frameCount = 0;
    int frameDelay = 2;

    choque5 = al_load_bitmap("Imagenes/MapaRojo_Adentro.png");

    ALLEGRO_BITMAP* prota = al_load_bitmap("Imagenes/SheetZelda2.png");
    ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/MapaAdentro4.png");


    ALLEGRO_EVENT_QUEUE* Mis_eventos;
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

    x = 370;

    y = 530;

    protaW = 32;
    protaH = 35;

    desplaza = 4;
    rot = 0;


    paso = 0;

    dir = 0;

    int ax, ay;





    salir = false;


    double entradaW = 40;
    double entradaH = 40;

    int xWA = 224;
    int yWA = 0;
    int xWW = 544;
    int yWW = 0;

    coordenadas3 warp4 = { xWA,yWA , "" };
    coordenadas3 warp5 = { xWW,yWW, "" };

    coordenadas3 cord[2];
    cord[0] = warp4;
    cord[1] = warp5;

    double warpW = 20;
    double warpH = 20;
    Transition transHub;
    transHub.drawTransitionReversa(pantalla, fondo, 800, 608, prota, paso, dir, x, y);

    al_start_timer(timer);


    while (!salir)

    {
        ax = x;
        ay = y;


        ALLEGRO_EVENT evento;
        al_wait_for_event(Mis_eventos, &evento);

        al_draw_scaled_bitmap(fondo, 0, 0, 800, 608, 0, 0, 800, 600, 0);
        al_draw_bitmap_region(prota, paso * 32, dir * 35, 32, 35, x, y, rot);
        for (int i = 0; i < 2; i++) {
            validarPuerta(cord[i]);
        }


        salir = ColisionPuerta(cord[0], warpW, warpH);
        if (salir == false) {
            salir = ColisionPuerta(cord[1], warpW, warpH);
        }

        al_flip_display();

        al_get_keyboard_state(&teclado);

        if (evento.type == ALLEGRO_EVENT_TIMER)

        {
            if (++curFrame >= maxFrame)
            {
                curFrame = 0;
            }
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

                y -= desplaza;

                cout << "y: " << y << endl;
                cout << "x: " << x << endl;

                dir = 2;
                rot = 0;
                paso++;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_DOWN))

            {

                y += desplaza;

                cout << "y: " << y << endl;
                cout << "x: " << x << endl;

                dir = 0;
                rot = 0;
                paso++;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_LEFT))

            {

                x -= desplaza;

                cout << "x: " << x << endl;
                cout << "y: " << y << endl;

                dir = 1;
                rot = 0;
                paso++;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT))

            {

                x += desplaza;

                cout << "x: " << x << endl;
                cout << "y: " << y << endl;


                dir = 1;
                rot = 1;
                paso++;

            }

            if ((x != ax || y != ay) && colisiona5(x, y))
            {
                cout << "ES ROJO" << endl;
                cout << "X: " << x << endl;
                x = ax;
                y = ay;
            }
        }


        // limitadores


        if (x < 0) x = 0;

        if (x > 800 - 32) x = 800 - 32;

        if (y < 0) y = 0;

        if (y > 600 - 35) y = 600 - 35;


        if (paso > 9) paso = 0;

        if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE)) {
            exit(0);
        }



    }



    transHub.drawTransition(pantalla, fondo, 800, 608, prota, paso, dir, x, y);
    transHub.destroyTrans();

    al_destroy_bitmap(prota);
    al_destroy_bitmap(fondo);
    al_destroy_bitmap(choque5);
    al_destroy_event_queue(Mis_eventos);
    al_destroy_timer(timer);

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();
    al_rest(1);
    if (x > 200 && x < 300 && y < 30) {
        return true;
    }
    else if (x > 530 && y < 30) {
        return false;
    }

    //return 0;

}