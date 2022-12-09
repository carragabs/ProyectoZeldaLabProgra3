#pragma once

#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <Windows.h>
#include "SpritesheetRow.h"
#include "Transicion.h"
#include <vector>
#include <string>

using namespace std;

struct coordenadasCofres {
    int xRect; int yRect;
    char respuesta; bool colisionAbajo;
};

struct rondaPreguntas
{
    string pregunta;
    string opciones;
    char respuesta;
};

struct variablesDrawExplosion
{
    ALLEGRO_BITMAP* bitmap; double Sx; double Sy; double Sw; double Sh;
    double Dx; double Dy; double Dw; double Dh; double alrestTime;
};

ALLEGRO_LOCKED_REGION* lock3;
ALLEGRO_BITMAP* choque3;

class MinijuegoCofres {
public:
    ALLEGRO_DISPLAY* pantalla;
    bool salir = false;
    MinijuegoCofres(ALLEGRO_DISPLAY* pantallaMain, int* vida);
    char respuesta;
    void crearMinijuego();

    bool crearColisionesCofres(coordenadasCofres cofre, double cofreW, double cofreH);
    void drawResultadoCofre(ALLEGRO_BITMAP* cofreBit, coordenadasCofres cofre,
        ALLEGRO_BITMAP* bitmapCorrecto, ALLEGRO_BITMAP* bitmapIncorrecto);

    double x, y;
    double protaW, protaH;
    int desplaza;
    int paso;
    int dir;
    int rot;
    int* vidaptr;
    coordenadasCofres  coordCofres[4];
    coordenadasCofres  cofre1;
    coordenadasCofres  cofre2;
    coordenadasCofres  cofre3;
    coordenadasCofres  cofre4;
    ALLEGRO_BITMAP* fondo;
    varsFrame varsExplosion[17];
    vector<rondaPreguntas> rondas;
    ALLEGRO_FONT* textboxFont = al_load_font("Fonts/ReturnofGanon.ttf", 22, 0);
    void setPreguntas();
    void drawPreguntas(int rondaActual);
    int vidasCount;
    void LifeBar(int vida);
private:

};

void bloquea3()
{
    lock3 = al_lock_bitmap(choque3, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);
}

// libera memoria
void desbloquea3()
{
    al_unlock_bitmap(choque3);
}

// comprueba si esta bloqueado
bool esRojo3(int x, int y)
{
    unsigned char r, g, b;
    ALLEGRO_COLOR colorMira;
    colorMira = al_get_pixel(choque3, x, y);
    al_unmap_rgb(colorMira, &r, &g, &b);

    return (r == 255 && g == 0 && b == 0);
}

bool colisiona3(int x, int y)
{
    bloquea3();
    bool valor = false;
    for (int i = 1; i < 32 - 1; i++)
    {
        for (int j = 35 / 2; j < 35; j++)
        {
            int vx = x + i;
            int vy = y + j;
            if (esRojo3(vx, vy))
            {
                valor = true;
            }
        }
    }
    desbloquea3();
    return valor;
}

void MinijuegoCofres::LifeBar(int vida) {

    //al_draw_filled_rectangle(20, 85, 80, 110, al_map_rgba(0, 0, 0, 150));

    al_draw_filled_rectangle(20, 100, 210, 110, al_map_rgb(255, 0, 0));
    al_draw_filled_rectangle(20, 100, 10 + (vida + 1) * 10, 110, al_map_rgb(0, 255, 0));
    al_flip_display();

}

bool MinijuegoCofres::crearColisionesCofres(coordenadasCofres cofre, double cofreW, double cofreH)
{
    if (y < cofre.yRect + cofreH && y >(cofre.yRect + cofreH) - 8
        && (x < cofre.xRect + cofreW) && (x + protaW > cofre.xRect))
    {
        //cout << "COLLISION TRUE!" << endl;
        y = (cofre.yRect + cofreH);
        //y += desplaza;
        return true;
    }
    if (y + protaH > cofre.yRect && (y + protaH < cofre.yRect + 8)
        && (x < cofre.xRect + cofreW) && (x + protaW > cofre.xRect))
    {
        // cout << "COLLISION TRUE!" << endl;
        y = (cofre.yRect - (protaH));
        //y -= desplaza;
    }

    if (x < cofre.xRect + cofreW && x >(cofre.xRect + cofreW) - 8
        && (y < cofre.yRect + cofreH) && (y + protaH > cofre.yRect))
    {
        // cout << "COLLISION TRUE!" << endl;
        x = (cofre.xRect + cofreW);
    }
    if (x + protaW > cofre.xRect && x + protaW < cofre.xRect + 8
        && (y < cofre.yRect + cofreH) && (y + protaH > cofre.yRect))
    {
        // cout << "COLLISION TRUE!" << endl;
        x = (cofre.xRect - protaW);
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

MinijuegoCofres::MinijuegoCofres(ALLEGRO_DISPLAY* pantallaMain, int* vida)
{
    pantalla = pantallaMain;
    vidaptr = vida;
    vidasCount = *vidaptr / 10;
    respuesta = ' ';
    setPreguntas();
    crearMinijuego();
}

void MinijuegoCofres::setPreguntas()
{
    string pregunta, opciones;
    char respuesta;
    pregunta = "1. Durante el renacimiento, el modelo de gobierno es uno de los siguientes:";
    opciones = "A) Monarquia absoluta. B) Tirania republicana. ";
    opciones += "C) Democracia participativa. D) Liberalismo politico";
    respuesta = 'A';
    rondas.push_back({ pregunta,opciones,respuesta });

    pregunta = "2. De los siguientes acontecimientos, selecciones el que inicia ";
    pregunta += "el periodo moderno: ";
    opciones = "A) Toma de Constantinopla. B) Tratado de paz de westfalia. ";
    opciones += "C) Toma de la Bastilla. La ruta de la seda.";
    respuesta = 'B';
    rondas.push_back({ pregunta,opciones,respuesta });

    pregunta = "3. Durante el siglo XV, la sociedad se ";
    pregunta += "estratifica en tres estamentos definidos: ";
    opciones = "A) Clase media, baja y alta. B) nobleza, clero y estado llano. ";
    opciones += "C) Artesanos, guardianes y gobernantes";
    respuesta = 'B';
    rondas.push_back({ pregunta,opciones,respuesta });

    pregunta = "4. Aparece el realismo politico, que se basaba en un orden establecido, ";
    pregunta += "explicacion de un sistema y recomendaciones de como gobernar: ";
    opciones = "A) Tomas Moro. B) Jean Bodin. ";
    opciones += "C) Nicolas Maquiavelo. D) Erasmo de Rotterdam.";
    respuesta = 'C';
    rondas.push_back({ pregunta,opciones,respuesta });

    pregunta = "5. Terminada la edad media, en el contexto de la politica resulta que:";
    opciones = "A) La Iglesia resalta su poder. B) La Iglesia pierde el papel rector en la politica ";
    opciones += "C) La Iglesia evangelica se posiciona en la politica. D) La politica desaparece.";
    respuesta = 'B';
    rondas.push_back({ pregunta,opciones,respuesta });
}

void MinijuegoCofres::drawPreguntas(int rondaActual)
{
    switch (rondaActual)
    {
    case(4):
        al_draw_filled_rectangle(15, 3, 780, 85, al_map_rgba(0, 0, 0, 150));

        al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 20, 5, 0,
            rondas[rondaActual].pregunta.c_str());

        al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 20, 35, 0,
            rondas[rondaActual].opciones.substr(0, 84).c_str());

        al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 20, 55, 0,
            rondas[rondaActual].opciones.substr(84, 79).c_str());
        break;
    case(3):
        al_draw_filled_rectangle(15, 3, 780, 85, al_map_rgba(0, 0, 0, 150));

        al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 20, 5, 0,
            rondas[rondaActual].pregunta.substr(0, 71).c_str());
        al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 20, 25, 0,
            rondas[rondaActual].pregunta.substr(72, 62).c_str());

        al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 20, 55, 0,
            rondas[rondaActual].opciones.c_str());
        break;
    default:
        al_draw_filled_rectangle(15, 3, 780, 65, al_map_rgba(0, 0, 0, 150));
        al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 20, 5, 0,
            rondas[rondaActual].pregunta.c_str());
        al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 20, 35, 0,
            rondas[rondaActual].opciones.c_str());
        break;
    }

}

void MinijuegoCofres::drawResultadoCofre(ALLEGRO_BITMAP* cofreBit, coordenadasCofres cofre,
    ALLEGRO_BITMAP* bitmapCorrecto, ALLEGRO_BITMAP* bitmapIncorrecto)
{
    ALLEGRO_SAMPLE* incorrecta = al_load_sample("Audios/bombexplode.wav");
    ALLEGRO_SAMPLE_INSTANCE* aexplosion = al_create_sample_instance(incorrecta);
    al_set_sample_instance_playmode(aexplosion, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(aexplosion, al_get_default_mixer());

    ALLEGRO_SAMPLE* song2 = al_load_sample("Audios/itemget1.wav");
    ALLEGRO_SAMPLE_INSTANCE* item = al_create_sample_instance(song2);
    al_set_sample_instance_playmode(item, ALLEGRO_PLAYMODE_ONCE);
    ALLEGRO_SAMPLE* incorrecta2 = al_load_sample("Audios/heartpiece1.wav");
    ALLEGRO_SAMPLE_INSTANCE* heartpiece = al_create_sample_instance(incorrecta2);
    al_set_sample_instance_playmode(heartpiece, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(item, al_get_default_mixer());
    al_attach_sample_instance_to_mixer(heartpiece, al_get_default_mixer());

    if (cofre.respuesta == respuesta)
    {
        vidasCount++;
        al_draw_scaled_bitmap(bitmapCorrecto, 0, 0, 15, 21, cofre.xRect - 1, cofre.yRect - 20, 50, 50, 0);
        //AQUISONIDO itemget1.wav
        al_play_sample_instance(item);
        //AQUISONIDO heartpiece1.wav
        al_play_sample_instance(heartpiece);
        al_flip_display();
        al_rest(3);
    }
    else
    {
        al_convert_mask_to_alpha(bitmapIncorrecto, al_map_rgb(255, 192, 255));
        SpritesheetRow explosionesSheet;
        //AQUISONIDO bombexplode.wav
        al_play_sample_instance(aexplosion);
        explosionesSheet.drawSpritesheetRow(17, pantalla, varsExplosion);

    }

}


void MinijuegoCofres::crearMinijuego()

{
    al_set_window_title(pantalla, "Nivel 2 - POLITICA:Minijuego Cofres");

    ALLEGRO_BITMAP* prota = al_load_bitmap("Imagenes/SheetZelda2.png");
    fondo = al_load_bitmap("Imagenes/mapacofres.png");
    choque3 = al_load_bitmap("Imagenes/MapaRojo_Cofres.png");
    ALLEGRO_BITMAP* cofre = al_load_bitmap("Imagenes/chest.png");
    ALLEGRO_BITMAP* heart = al_load_bitmap("Imagenes/heart.png");
    ALLEGRO_BITMAP* explosion = al_load_bitmap("Imagenes/alttpExplosion.png");
    ALLEGRO_FONT* triforceFont = al_load_font("Fonts/Triforce.ttf", 40, 0);

    al_reserve_samples(2);
    ALLEGRO_SAMPLE* song5 = al_load_sample("Audios/Minicofres.mpeg");
    ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song5);
    al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_LOOP);
    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());

    ALLEGRO_SAMPLE* song = al_load_sample("Audios/chestopen.wav");
    ALLEGRO_SAMPLE_INSTANCE* abrircofre = al_create_sample_instance(song);
    al_set_sample_instance_playmode(abrircofre, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(abrircofre, al_get_default_mixer());


    ALLEGRO_EVENT_QUEUE* Mis_eventos;


    ALLEGRO_EVENT evento;

    ALLEGRO_TIMER* timer;


    Mis_eventos = al_create_event_queue();
    timer = al_create_timer(1.0 / 30);


    // asigno eventos a la lista de eventos

    al_register_event_source(Mis_eventos, al_get_timer_event_source(timer));

    al_register_event_source(Mis_eventos, al_get_keyboard_event_source());

    al_register_event_source(Mis_eventos, al_get_display_event_source(pantalla));


    ALLEGRO_KEYBOARD_STATE teclado;

    x = 350;

    y = 380;

    protaW = 32;
    protaH = 35;

    desplaza = 4;

    rot = 0;
    paso = 0;

    dir = 0;
    double ax, ay;


    salir = false;

    cofre1 = { 440,280 , 'C' , false };
    cofre2 = { 320,280 , 'B' , false };
    cofre3 = { 200,280 ,'A' , false };
    cofre4 = { 550,280,'D' , false };

    coordCofres[0] = cofre1;
    coordCofres[1] = cofre2;
    coordCofres[2] = cofre3;
    coordCofres[3] = cofre4;

    double cofreW = 50;
    double cofreH = 50;

    Transition transCofres;
    transCofres.drawTransitionReversa(pantalla, fondo, 254, 254, prota, paso, dir, x, y);
    al_play_sample_instance(instance);


    int rondaCount = 0;
    respuesta = rondas[rondaCount].respuesta;
    //string vidas;
    al_start_timer(timer);

    int xfinLifeBar = 0;
    while (!salir)

    {
        ax = x;
        ay = y;
        int i;

        for (i = 0; i < 4; i++)
        {
            coordCofres[i].colisionAbajo = false;
        }

        //vidas = "VIDAS: " + to_string(vidasCount);

        al_clear_to_color(al_map_rgb(120, 90, 90));

        al_draw_scaled_bitmap(fondo, 0, 0, 254, 254, 0, 0, 800, 600, 0);

        al_draw_bitmap_region(prota, paso * 32, dir * 35, 32, 35, x,
            y, rot);

        for (i = 0; i < 4; i++)
        {
            al_draw_scaled_bitmap(cofre, 5, 5, 170, 126, coordCofres[i].xRect, coordCofres[i].yRect, 50, 50, 0);
        }

        al_draw_text(triforceFont, al_map_rgb(255, 255, 255), 210, 240, 0, "A");
        al_draw_text(triforceFont, al_map_rgb(255, 255, 255), 330, 240, 0, "B");
        al_draw_text(triforceFont, al_map_rgb(255, 255, 255), 450, 240, 0, "C");
        al_draw_text(triforceFont, al_map_rgb(255, 255, 255), 560, 240, 0, "D");

        //al_draw_filled_rectangle(20, 85, 80, 110, al_map_rgba(0, 0, 0, 150));
        //al_draw_text(textboxFont, al_map_rgb(255, 255, 255), 20, 85, 0, vidas.c_str());
        //LifeBar(vidasCount);
        xfinLifeBar = 10 + (vidasCount + 1) * 10;
        al_draw_filled_rectangle(20, 100, 220, 110, al_map_rgb(255, 0, 0));
        al_draw_filled_rectangle(20, 100, xfinLifeBar, 110, al_map_rgb(0, 255, 0));
        al_flip_display();

        if (rondaCount > 4)
        {
            al_flip_display();
            al_rest(2);
            break;
        }

        respuesta = rondas[rondaCount].respuesta;
        drawPreguntas(rondaCount);


        al_flip_display();


        al_wait_for_event(Mis_eventos, &evento);


        if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)

        {

            exit(0);

        }


        al_get_keyboard_state(&teclado);



        if (al_key_down(&teclado, ALLEGRO_KEY_UP))

        {

            y -= desplaza;

            cout << "y: " << y << endl;
            cout << "x: " << x << endl << endl;

            dir = 2;
            rot = 0;
            paso++;

        }

        if (al_key_down(&teclado, ALLEGRO_KEY_DOWN))

        {

            y += desplaza;

            cout << "y: " << y << endl;
            cout << "x: " << x << endl << endl;

            dir = 0;
            rot = 0;
            paso++;

        }

        if (al_key_down(&teclado, ALLEGRO_KEY_LEFT))

        {

            x -= desplaza;

            cout << "x: " << x << endl;
            cout << "y: " << y << endl << endl;

            dir = 1;
            rot = 0;
            paso++;

        }

        if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT))

        {

            x += desplaza;

            cout << "x: " << x << endl;
            cout << "y: " << y << endl << endl;


            dir = 1;
            rot = 1;
            paso++;

        }
        if ((x != ax || y != ay) && colisiona3(x, y))
        {
            cout << "ES ROJO" << endl;
            x = ax;
            y = ay;
        }

        if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE))
            exit(0);

        // limitadores

        if (x < 0) x = 0;

        if (x > 800 - 32) x = 800 - 32;

        if (y < 0) y = 0;

        if (y > 600 - 35) y = 600 - 35;


        if (paso > 9) paso = 0;


        if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE)) {

            salir = true;

        }

        cofre1.colisionAbajo = crearColisionesCofres(cofre1, cofreW, cofreH);
        cofre2.colisionAbajo = crearColisionesCofres(cofre2, cofreW, cofreH);
        cofre3.colisionAbajo = crearColisionesCofres(cofre3, cofreW, cofreH);
        cofre4.colisionAbajo = crearColisionesCofres(cofre4, cofreW, cofreH);

        if (al_key_down(&teclado, ALLEGRO_KEY_SPACE))
        {

            if (cofre1.colisionAbajo || cofre2.colisionAbajo ||
                cofre3.colisionAbajo || cofre4.colisionAbajo)
            {
                coordenadasCofres cofreElegido = validarCofres(cofre1, cofre2, cofre3, cofre4);

                //AQUISONIDO chestopen.wav
                al_set_sample_instance_playing(instance, false);

                al_play_sample_instance(abrircofre);
                al_draw_scaled_bitmap(cofre, 187, 5, 170, 126, cofreElegido.xRect, cofreElegido.yRect, 50, 50, 0);
                al_flip_display();
                al_rest(2.5);

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

                drawResultadoCofre(cofre, cofreElegido, heart, explosion);
                rondaCount++;
                al_set_sample_instance_playing(instance, true);
            }
        }

    }
    *vidaptr = vidasCount * 10;
    al_destroy_sample_instance(instance);

    transCofres.drawTransition(pantalla, fondo, 254, 254, prota, paso, dir, x, y);
    transCofres.destroyTrans();

    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();

    al_destroy_bitmap(prota);
    al_destroy_bitmap(cofre);
    al_destroy_bitmap(choque3);
    al_destroy_bitmap(explosion);
    al_destroy_bitmap(heart);
    al_destroy_bitmap(fondo);
    al_destroy_event_queue(Mis_eventos);
    al_destroy_timer(timer);

    al_rest(1);

    //return 0;

}
