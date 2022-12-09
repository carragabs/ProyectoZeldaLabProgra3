#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <iostream>



using namespace std;

struct preguntasL3 {
    int correcta;
    string pregunta, respuesta1, respuesta2, respuesta3, respuesta4;
}Q[5];

struct posicion
{
    double x, y;
};


int escenax = 800;
int escenay = 480;

int pantallax = 800;
int pantallay = 600;

int desplaza = 3;
int mueve = 18;
ALLEGRO_FONT* font;
ALLEGRO_LOCKED_REGION* lock;





class escenario {
    ALLEGRO_BITMAP* choque;

public:
    ALLEGRO_BITMAP* suelo;
    double x, y;
    //bool crearColisionesWarp(coordenadasEntradas entrada);

    void carga()
    {
        suelo = al_load_bitmap("Imagenes/MapaMini.jpeg");
        choque = al_load_bitmap("Imagenes/MapaRojo_Nivel2.png");

    }

    void pinta(bool sup = false)
    {
        // suelo
        if (!sup) al_draw_bitmap(suelo, 0, 0, 0);

    }

    void pinta(int x, int y, bool sup = false)
    {
        if (!sup) al_draw_bitmap(suelo, x, y, 0);
    }

    // para poder utilizar el getpixel mas rápido
    void bloquea()
    {
        lock = al_lock_bitmap(choque, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);
    }

    // libera memoria
    void desbloquea()
    {
        al_unlock_bitmap(choque);
    }

    // comprueba si esta bloqueado
    bool esRojo(int x, int y)
    {
        unsigned char r, g, b;
        ALLEGRO_COLOR colorMira;
        colorMira = al_get_pixel(choque, x, y);
        al_unmap_rgb(colorMira, &r, &g, &b);

        return (r == 255 && g == 0 && b == 0);
    }
} escena;

class player
{

public:
    // posicion del personaje con respecto imagen
    int x, y, rot;
    // posicion del personaje con respecto pantalla
    int px, py;
    // posicion de la camara que sigue al personaje
    int camarax, camaray;
    int dir;
    int paso;
    double tamx;
    double tamy;
    int tiempoPaso;
    int tiempoCont;
    int playerW, playerH;

    ALLEGRO_BITMAP* img;

    int getCamX() { return camarax; }
    int getCamY() { return camaray; }

    void inicia()
    {
        img = al_load_bitmap("Imagenes/SheetZelda2.png");
        tiempoPaso = int(30 / mueve);
        tiempoCont = 0;
        x = 400;
        y = 100;
        px = x;
        py = y;
        camarax = 0;
        camaray = 0;
        dir = 0;
        paso = 0;
        tamx = 32;
        tamy = 35;
    }

    bool colisiona()
    {
        escena.bloquea();
        bool valor = false;
        for (int i = 1; i < tamx - 1; i++)
        {
            for (int j = tamy / 2; j < tamy; j++)
            {
                int vx = x + i;
                int vy = y + j;
                if (escena.esRojo(vx, vy))
                {
                    valor = true;
                }
            }
        }
        escena.desbloquea();
        return valor;
    }


    void actualiza(ALLEGRO_EVENT evento)
    {
        ALLEGRO_KEYBOARD_STATE teclado;

        // estado anterior
        int ax, ay;

        ax = x;
        ay = y;

        al_get_keyboard_state(&teclado);

        if (al_key_down(&teclado, ALLEGRO_KEY_UP))
        {
            y -= desplaza;
            dir = 2;
            tiempoCont++;
            rot = 0;
        }
        if (al_key_down(&teclado, ALLEGRO_KEY_DOWN))
        {
            y += desplaza;
            dir = 0;
            tiempoCont++;
            rot = 0;
        }
        if (al_key_down(&teclado, ALLEGRO_KEY_LEFT))
        {
            x -= desplaza;
            dir = 1;
            tiempoCont++;
            rot = 0;
        }
        if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT))
        {
            x += desplaza;
            dir = 1;
            tiempoCont++;
            rot = 1;
        }

        if ((x != ax || y != ay) && colisiona())
        {
            cout << "ES ROJO" << endl;
            x = ax;
            y = ay;
        }

        cout << "VALOR X:" << x << endl;
        cout << "VALOR Y:" << y << endl;

        // limitadores
        if (x < 0) x = 0;
        if (x > escenax - tamx) x = escenax - tamx;
        if (y < 0) y = 0;
        if (y > escenay - tamy) y = escenay - tamy;
        if (tiempoCont > tiempoPaso)
        {
            paso++;
            tiempoCont = 0;
        }

        if (paso > 9) paso = 0;

        if (x < pantallax / 2) camarax = 0;
        if (y < pantallay / 2) camaray = 0;
        if (x >= pantallax / 2 && x <= escenax - (pantallax / 2)) camarax = -x + (pantallax / 2);
        if (y >= pantallay / 2 && y <= escenay - (pantallay / 2)) camaray = -y + (pantallay / 2);
        if (x > escenax - (pantallax / 2)) camarax = pantallax - escenax;
        if (y > escenay - (pantallay / 2)) camaray = pantallay - escenay;

        px = x + camarax;
        py = y + camaray;
    }

    void pinta()
    {
        al_draw_bitmap_region(img, paso * tamx, dir * tamy, tamx, tamy, px, py, rot);
    }

} jugador;

