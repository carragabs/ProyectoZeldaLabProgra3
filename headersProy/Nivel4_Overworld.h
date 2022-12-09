#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "Transicion.h"

using namespace std;

struct coordenadas2 {
    int xRect;
    int yRect;
    string minijuego;
};



ALLEGRO_LOCKED_REGION* lock4;
ALLEGRO_BITMAP* choque4;

class Nivel4 {
public:
    ALLEGRO_DISPLAY* pantalla;
    Nivel4(ALLEGRO_DISPLAY* pantallaMain);
    string minijuego;
    void crearOverworld();
    void validarPuerta(coordenadas2 warp);
    bool ColisionPuerta(coordenadas2 warp, double entradaW, double entradaH);


    double x, y;
    double protaW, protaH;
    int desplaza;
    int paso;
    int rot;
    int dir;

    coordenadas2 card;

private:

};

void bloquea4()
{
    lock4 = al_lock_bitmap(choque4, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);
}

// libera memoria
void desbloquea4()
{
    al_unlock_bitmap(choque4);
}

// comprueba si esta bloqueado
bool esRojo4(int x, int y)
{
    unsigned char r, g, b;
    ALLEGRO_COLOR colorMira;
    colorMira = al_get_pixel(choque4, x, y);
    al_unmap_rgb(colorMira, &r, &g, &b);

    return (r == 255 && g == 0 && b == 0);
}


void Nivel4::validarPuerta(coordenadas2 warp) {

    card.xRect = warp.xRect;
    card.yRect = warp.yRect;
    card.minijuego = "";
}



bool Nivel4::ColisionPuerta(coordenadas2 warp, double warpW, double warpH)
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

bool colisiona4(int x, int y)
{
    bloquea4();
    bool valor = false;
    for (int i = 1; i < 32 - 1; i++)
    {
        for (int j = 35 / 2; j < 35; j++)
        {
            int vx = x + i;
            int vy = y + j;
            if (esRojo4(vx, vy))
            {
                valor = true;
            }
        }
    }
    desbloquea4();
    return valor;
}


Nivel4::Nivel4(ALLEGRO_DISPLAY* pantallaMain)
{
    pantalla = pantallaMain;
    minijuego = "";
}

void Nivel4::crearOverworld()

{
    al_set_window_title(pantalla, "Nivel 4 - Overworld");

    const int maxFrame = 7;
    int curFrame = 0;
    int frameCount = 0;
    int frameDelay = 2;

    choque4 = al_load_bitmap("Imagenes/MapaRojoNivel4.png");

    ALLEGRO_BITMAP* prota = al_load_bitmap("Imagenes/SheetZelda2.png");
    ALLEGRO_BITMAP* warpOff = al_load_bitmap("Imagenes/warpOff.png");
    ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/MapaNivel4.png");


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

    x = 290;

    y = 130;

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

    int xWA = 450;
    int yWA = 505;

    coordenadas2 warp4 = { xWA,yWA , "" };

    coordenadas2 cord;
    cord = warp4;

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
        al_draw_scaled_bitmap(warpOff, 1, 9, 15, 15, 290, 130, 30, 30, 0);
        al_draw_bitmap_region(prota, paso * 32, dir * 35, 32, 35, x, y, rot);
        validarPuerta(cord);



        salir = ColisionPuerta(cord, warpW, warpH);

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

            if ((x != ax || y != ay) && colisiona4(x, y))
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
    al_destroy_bitmap(choque4);
    al_destroy_event_queue(Mis_eventos);
    al_destroy_timer(timer);

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();
    al_rest(1);

    //return 0;

}