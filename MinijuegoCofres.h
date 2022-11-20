#pragma once
//AGREGAR PREGUNTAS Y VER COMO SALDRAN
//LABEL LOS COFRES
// BARRA DE VIDA
//VER SI TRAS LA EXPLOSION DESAPARECE EL COFRE
//VER SI EXPLOTA UNO O VARIOS COFRES
#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <Windows.h>

using namespace std;

struct coordenadasCofres {
    int xRect; int yRect;
    char respuesta; bool colisionAbajo;
};

struct variablesDrawExplosion
{
    ALLEGRO_BITMAP* bitmap; double Sx; double Sy; double Sw; double Sh;
    double Dx; double Dy; double Dw; double Dh; double alrestTime;
};

class MinijuegoCofres {
public:
    //MinijuegoCofres(string respuesta P);
    ALLEGRO_DISPLAY* pantalla;
    bool salir = false;
    MinijuegoCofres(ALLEGRO_DISPLAY* pantallaMain);
    char respuesta;
    void crearMinijuego(char respuestaP);

    bool crearColisionesCofres(coordenadasCofres cofre, char respuestaP);
    void drawResultadoCofre(ALLEGRO_BITMAP* cofreBit, coordenadasCofres cofre,
        ALLEGRO_BITMAP* bitmapCorrecto, ALLEGRO_BITMAP* bitmapIncorrecto);

    double x, y;
    int desplaza;
    int paso;
    int dir;
    coordenadasCofres  coordCofres[4];
    coordenadasCofres  cofre1;
    coordenadasCofres  cofre2;
    coordenadasCofres  cofre3;
    coordenadasCofres  cofre4;
    ALLEGRO_BITMAP* fondo = al_load_bitmap("mapacofres.png");
    variablesDrawExplosion varsExplosion[17];
private:

};


bool MinijuegoCofres::crearColisionesCofres(coordenadasCofres  cofre, char respuestaP)
{
    if (y * desplaza < cofre.yRect + 50 && y * desplaza >(cofre.yRect + 50) - 8
        && (x * desplaza < cofre.xRect + 50) && (x * desplaza + 32.5 > cofre.xRect))
    {
        //cout << "COLLISION TRUE!" << endl;
        y = (cofre.yRect + 50) / desplaza;
        return true;
    }
    if (y * desplaza + 35 > cofre.yRect && (y * desplaza + 35 < cofre.yRect + 8)
        && (x * desplaza < cofre.xRect + 50) && (x * desplaza + 32.5 > cofre.xRect))
    {
        // cout << "COLLISION TRUE!" << endl;
        y = (cofre.yRect - (35)) / desplaza;
    }

    if (x * desplaza < cofre.xRect + 50 && x * desplaza >(cofre.xRect + 50) - 8
        && (y * desplaza < cofre.yRect + 50) && (y * desplaza + 35 > cofre.yRect))
    {
        // cout << "COLLISION TRUE!" << endl;
        x = (cofre.xRect + 50) / desplaza;
    }
    if (x * desplaza + 32.5 > cofre.xRect && x * desplaza + 32.5 < cofre.xRect + 8
        && (y * desplaza < cofre.yRect + 50) && (y * desplaza + 35 > cofre.yRect))
    {
        //z cout << "COLLISION TRUE!" << endl;
        x = (cofre.xRect - 32.5) / desplaza;
    }
    return false;
}

coordenadasCofres validarCofres(coordenadasCofres cofre1, coordenadasCofres cofre2,
    coordenadasCofres cofre3, coordenadasCofres cofre4)
{
    if (cofre1.colisionAbajo)
        return cofre1;
    if (cofre2.colisionAbajo)
        return cofre2;
    if (cofre3.colisionAbajo)
        return cofre3;
    if (cofre4.colisionAbajo)
        return cofre4;
}

MinijuegoCofres::MinijuegoCofres(ALLEGRO_DISPLAY* pantallaMain)
{
    pantalla = pantallaMain;
    cout << "respuesta: " << endl;
    //cin >> respuesta;
    respuesta = 'd';
    crearMinijuego(respuesta);
}

void MinijuegoCofres::drawResultadoCofre(ALLEGRO_BITMAP* cofreBit, coordenadasCofres cofre,
    ALLEGRO_BITMAP* bitmapCorrecto, ALLEGRO_BITMAP* bitmapIncorrecto)
{
    if (cofre.respuesta == respuesta)
    {
        al_draw_scaled_bitmap(bitmapCorrecto, 0, 0, 15, 21, cofre.xRect - 1, cofre.yRect - 20, 50, 50, 0);
        al_flip_display();
        al_rest(3);
        salir = true;
    }
    else
    {
        al_convert_mask_to_alpha(bitmapIncorrecto, al_map_rgb(255, 192, 255));
        for (size_t i = 0; i < 17; i++)
        {
            cout << "rest time " << varsExplosion[i].alrestTime << endl;

            al_draw_scaled_bitmap(varsExplosion[i].bitmap, varsExplosion[i].Sx, varsExplosion[i].Sy,
                varsExplosion[i].Sw, varsExplosion[i].Sh, varsExplosion[i].Dx,
                varsExplosion[i].Dy, varsExplosion[i].Dw, varsExplosion[i].Dh, 0);
            al_flip_display();
            al_rest(varsExplosion[i].alrestTime);
        }

    }

}

//ANTES DE CREAR HACER EL PROCESO DE MOSTRAR LA PREGUNTA

void MinijuegoCofres::crearMinijuego(char respuestaP)

{
    respuesta = respuestaP;

    const int maxFrame = 7;
    int curFrame = 0;
    int frameCount = 0;
    int frameDelay = 2;

    // allegro_init();

   /* al_init();

    al_init_image_addon();


    al_install_keyboard();

    al_init_primitives_addon(); */


    //ALLEGRO_DISPLAY* pantalla = al_create_display(800, 600);


    al_set_window_title(pantalla, "HUB Nivel 2");


    // BITMAP* prota = load_bmp("personaje.bmp", NULL);

    ALLEGRO_BITMAP* prota = al_load_bitmap("Alm1.png");
    fondo = al_load_bitmap("mapacofres.png");
    ALLEGRO_BITMAP* cofre = al_load_bitmap("chest.png");
    ALLEGRO_BITMAP* heart = al_load_bitmap("heart.png");
    ALLEGRO_BITMAP* explosion = al_load_bitmap("alttpExplosion.png");

    // defino lista de eventos

    ALLEGRO_EVENT_QUEUE* Mis_eventos;


    ALLEGRO_EVENT evento;

    ALLEGRO_TIMER* timer;
    // creo lista de eventos

    Mis_eventos = al_create_event_queue();
    timer = al_create_timer(1.0 / 60);


    // asigno eventos a la lista de eventos

    al_register_event_source(Mis_eventos, al_get_timer_event_source(timer));

    al_register_event_source(Mis_eventos, al_get_keyboard_event_source());

    al_register_event_source(Mis_eventos, al_get_display_event_source(pantalla));


    ALLEGRO_KEYBOARD_STATE teclado;




    // inicializar vbles

    x = 350 / 4;

    y = 380 / 4;


    desplaza = 4;


    paso = 0;

    dir = 0;


    salir = false;

    cofre1 = { 440,280 , 'c' , false };
    cofre2 = { 320,280 , 'b' , false };
    cofre3 = { 200,280 ,'a' , false };
    cofre4 = { 550,280,'d' , false };
    coordCofres[0] = cofre1;
    coordCofres[1] = cofre2;
    coordCofres[2] = cofre3;
    coordCofres[3] = cofre4;

    al_start_timer(timer);

    while (!salir)

    {
        int i;

        for (i = 0; i < 4; i++)
        {
            coordCofres[i].colisionAbajo = false;
        }
        // pinta el fondo de un color 

        // clear_to_color(buffer, 0x785a5a);

        al_clear_to_color(al_map_rgb(120, 90, 90));

        // masked_blit(prota, buffer, paso*32, dir*32, x, y, 32,32);
        al_draw_scaled_bitmap(fondo, 0, 0, 254, 254, 0, 0, 800, 600, 0);

        al_draw_bitmap_region(prota, paso * 32.5, dir * 35, 32.5, 35, x * desplaza, y * desplaza, 0);


        //al_draw_filled_rectangle(warpArte.xRect, warpArte.yRect, warpArte.xRect + 40, warpArte.yRect + 40, al_map_rgba_f(.6, 0, .6, .6));



        for (i = 0; i < 4; i++)
        {
            //validarrespuesta(cofre, coordCofres[i], warpArte, respuesta);
            al_draw_scaled_bitmap(cofre, 5, 5, 170, 126, coordCofres[i].xRect, coordCofres[i].yRect, 50, 50, 0);
        }

        // mostramos la pantalla

        al_flip_display();


        al_wait_for_event(Mis_eventos, &evento);


        // se ha cerrado la ventana


       // if (evento.type == ALLEGRO_EVENT_TIMER)
        //{


        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)

        {

            exit(0);

        }


        al_get_keyboard_state(&teclado);



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

        if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE))
            exit(0);

        // limitadores


        if (x < 0) x = 0;

        if (x * desplaza > 800 - 32.5) x = 191.87;

        if (y < 0) y = 0;

        if (y * desplaza > 600 - 35) y = 141.25;


        if (paso > 3) paso = 0;


        //if(x*desplaza > )

        if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE)) {

            salir = true;

        }

        cofre1.colisionAbajo = crearColisionesCofres(cofre1, respuesta);
        cofre2.colisionAbajo = crearColisionesCofres(cofre2, respuesta);
        cofre3.colisionAbajo = crearColisionesCofres(cofre3, respuesta);
        cofre4.colisionAbajo = crearColisionesCofres(cofre4, respuesta);

        if (al_key_down(&teclado, ALLEGRO_KEY_SPACE))
        {
            int posX = x * desplaza;
            int posY = y * desplaza;
            if (cofre1.colisionAbajo || cofre2.colisionAbajo ||
                cofre3.colisionAbajo || cofre4.colisionAbajo)
            {
                //cout << "ABAJO DE COFRE" << endl;
                coordenadasCofres cofreElegido = validarCofres(cofre1, cofre2, cofre3, cofre4);
                al_draw_scaled_bitmap(cofre, 187, 5, 170, 126, cofreElegido.xRect, cofreElegido.yRect, 50, 50, 0);
                al_flip_display();

                varsExplosion[0] = { explosion,5, 36, 13, 13, cofreElegido.xRect + 12.5, //FRAME 1 EXPLO
                     cofreElegido.yRect + 12.5, 22, 22 , 0.1 };
                varsExplosion[1] = { explosion,22, 25, 29, 29, cofreElegido.xRect + 0.0, //FRAME 2 EXPLO
                    cofreElegido.yRect + 0.0, 50, 50 ,0.1 };
                varsExplosion[2] = { cofre, 187, 5, 170, 126, cofreElegido.xRect + 0.0, //COFRE ABIERTO
                    cofreElegido.yRect + 0.0, 50, 50 , 0 };
                varsExplosion[3] = { explosion,55, 25, 29, 29, cofreElegido.xRect + 0.0, //FRAME 3 EXPLO
                    cofreElegido.yRect + 0.0, 50, 50,0.1 };
                varsExplosion[4] = { explosion,22, 25, 29, 29, cofreElegido.xRect + 0.0, //FRAME 2 EXPLO
                    cofreElegido.yRect + 0.0, 50, 50 ,0.1 };
                varsExplosion[5] = { cofre, 187, 5, 170, 126, cofreElegido.xRect + 0.0, //COFRE ABIERTO
                    cofreElegido.yRect + 0.0, 50, 50 , 0 };
                varsExplosion[6] = { explosion,55, 25, 29, 29, cofreElegido.xRect + 0.0, //FRAME 3 EXPLO
                    cofreElegido.yRect + 0.0, 50, 50,0.1 };
                varsExplosion[7] = { cofre, 187, 5, 170, 126, cofreElegido.xRect + 0.0, //COFRE ABIERTO
                    cofreElegido.yRect + 0.0, 50, 50 , 0 };
                varsExplosion[8] = { explosion,88, 16, 43, 45, cofreElegido.xRect - 20 + 0.0, //FRAME 4 EXPLO
                    cofreElegido.yRect - 20 + 0.0, 90, 90,0.1 };
                varsExplosion[9] = { cofre, 187, 5, 170, 126, cofreElegido.xRect + 0.0, //COFRE ABIERTO
                    cofreElegido.yRect + 0.0, 50, 50 , 0 };
                varsExplosion[10] = { explosion,135, 25, 29, 29, cofreElegido.xRect + 0.0, //FRAME 5 EXPLO
                    cofreElegido.yRect + 0.0, 50, 50 ,0.1 };
                varsExplosion[11] = { cofre, 187, 5, 170, 126, cofreElegido.xRect + 0.0, //COFRE ABIERTO
                    cofreElegido.yRect + 0.0, 50, 50 , 0 };
                varsExplosion[12] = { explosion,166, 20, 38, 38, cofreElegido.xRect - 10 + 0.0,//FRAME 6 EXPLO
                    cofreElegido.yRect - 10 + 0.0, 70, 70,0.1 };
                varsExplosion[13] = { cofre, 187, 5, 170, 126, cofreElegido.xRect + 0.0, //COFRE ABIERTO
                    cofreElegido.yRect + 0.0, 50, 50 , 0 };
                varsExplosion[14] = { explosion, 208, 18, 40, 40, cofreElegido.xRect - 10 + 0.0, //FRAME 7 EXPLO
                    cofreElegido.yRect - 10 + 0.0, 70, 70,0.1 };
                varsExplosion[15] = { cofre, 187, 5, 170, 126, cofreElegido.xRect + 0.0,  //COFRE ABIERTO
                    cofreElegido.yRect + 0.0, 50, 50 , 0 };
                varsExplosion[16] = { explosion, 253, 24, 42, 37, cofreElegido.xRect - 10 + 0.0, //FRAME 8 EXPLO
                    cofreElegido.yRect - 10 + 0.0, 70, 70,0.1 };

                al_rest(1);
                drawResultadoCofre(cofre, cofreElegido, heart, explosion);

            }
        }


    }

    al_destroy_bitmap(prota);
    al_destroy_bitmap(cofre);
    al_destroy_bitmap(explosion);
    al_destroy_bitmap(heart);
    al_destroy_bitmap(fondo);
    al_destroy_event_queue(Mis_eventos);
    al_destroy_timer(timer);

    //al_destroy_display(pantalla);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_flip_display();
    al_rest(1);

    //return 0;

}
