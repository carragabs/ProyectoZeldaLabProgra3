#pragma once

#include<Windows.h>
#include<iostream>
#include <string>
#include "Transicion.h"
using namespace std;

struct preguntas {
    int correcta;
    string pregunta, extra, respuesta1, respuesta2, respuesta3;
}P[6];

ALLEGRO_LOCKED_REGION* lock2;
ALLEGRO_BITMAP* choque2;

class mapa {
public :
	
    void laberinto(ALLEGRO_DISPLAY* pantalla , int* vida);

private:
    void LifeBar(int vida);
    bool validarRespuesta(int, preguntas*, int);
    int numAleatorio();
    int aleatorio = 0, num1 = 7, num2 = 7, num3 = 7, num4 = 7,num5=7, contador = 0;
    int* vidaptr;
    int corazones;
    void Preguntas();
};

void mapa::LifeBar(int vida) {

    al_draw_filled_rectangle(10, 20, 210, 30, al_map_rgb(255, 0, 0));
    al_draw_filled_rectangle(10, 20, vida * 10 + 10, 30, al_map_rgb(0, 255, 0));
    al_flip_display();

}

void mapa::Preguntas() {
    P[0].pregunta = ". Entre los siguientes renacentistas seleccione, uno de los precursoresfilosofo-cientifico ";
    P[0].extra = "del heliocentrismo (teoria que afirma que el sol es el centro del universo):";
    P[0].respuesta1 = "1) Tomas Moro (arriba)";
    P[0].respuesta2 = "2)Galileo (izquierda)";
    P[0].respuesta3 = "3)Platón (derecha)";
    P[0].correcta = 2;

    P[1].pregunta = "El metodo cientifico se introduce por el interes de tres filosofos. Entre los siguientes uno de los";
    P[1].extra = " mencionados no es precursor del metodo cientifico:";
    P[1].respuesta1 = "1)Francis Bacon.(arriba)";
    P[1].respuesta2 = "2)  Galileo Galilei. (izquierda)";
    P[1].respuesta3 = "3)Nicolas Maquiavelo (derecha)";
    P[1].correcta = 3;

    P[2].pregunta = "Es uno de los precursores del pensamiento Moderno:";
    P[2].extra = " ";
    P[2].respuesta1 = "1)Isaac Newton. (arriba)";
    P[2].respuesta2 = "2)Rene Descartes. (izquierda)";
    P[2].respuesta3 = "3)Erasmo de Roterdam (derecha)";
    P[2].correcta = 2;

    P[3].pregunta = "De los siguientes filosofos niega el geocentrismo (teoria que afirma que ";
    P[3].extra = " el centro de nuestro sistema solares es la tierra).";
    P[3].respuesta1 = "1)Aristoteles (arriba)";
    P[3].respuesta2 = "2)Nicolas Copernico (izquierda)";
    P[3].respuesta3 = "3)Tomas de Aquino (derecha)";
    P[3].correcta = 2;

    P[4].pregunta = "Uno de los inventos que suscito un conocimiento ilimitado, fue el de Gutenberg";
    P[4].extra = "";
    P[4].respuesta1 = "1)El astrolabio (arriba)";
    P[4].respuesta2 = "2)La imprenta (izquierda)";
    P[4].respuesta3 = "3)La Nao y la Carabela (derecha)";
    P[4].correcta = 2;

    P[5].pregunta = "";
    P[5].extra = "";
    P[5].respuesta1 = "Todas las preguntas fueron contestadas";
    P[5].respuesta2 = " ";
    P[5].respuesta3 = " ";
    P[5].correcta = 0;
}

//COLISIONES
void bloquea2()
{
    lock2 = al_lock_bitmap(choque2, ALLEGRO_PIXEL_FORMAT_ANY, ALLEGRO_LOCK_READONLY);
}

// libera memoria
void desbloquea2()
{
    al_unlock_bitmap(choque2);
}

// comprueba si esta bloqueado
bool esRojo2(int x, int y)
{
    unsigned char r, g, b;
    ALLEGRO_COLOR colorMira;
    colorMira = al_get_pixel(choque2, x, y);
    al_unmap_rgb(colorMira, &r, &g, &b);

    return (r == 255 && g == 0 && b == 0);
}

bool colisiona2(int x, int y)
{
    bloquea2();
    bool valor = false;
    for (int i = 1; i < 32 - 1; i++)
    {
        for (int j = 35 / 2; j < 35; j++)
        {
            int vx = x + i;
            int vy = y + j;
            if (esRojo2(vx, vy))
            {
                valor = true;
            }
        }
    }
    desbloquea2();
    return valor;
}



bool mapa::validarRespuesta(int  answer, preguntas* pregunta,int aleatorio) {
    int respuesta;
    contador++;
    respuesta = pregunta->correcta;
    //cout << answer<<endl;
    ALLEGRO_TIMER* segundo = al_create_timer(1.0);
    ALLEGRO_EVENT evento;
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

    al_register_event_source(queue, al_get_timer_event_source(segundo));
    al_start_timer(segundo);
    int sec = 0; ALLEGRO_FONT* font = al_load_font("Fonts/VPPixel-Simplified.otf", 18, 0);
    if (answer == respuesta) {
        ALLEGRO_SAMPLE* incorrecta2 = al_load_sample("Audios/heartpiece1.wav");
        ALLEGRO_SAMPLE_INSTANCE* heartpiece = al_create_sample_instance(incorrecta2);
        al_set_sample_instance_playmode(heartpiece, ALLEGRO_PLAYMODE_ONCE);
        al_attach_sample_instance_to_mixer(heartpiece, al_get_default_mixer());
        al_play_sample_instance(heartpiece);

        al_clear_to_color(al_map_rgb(0, 0, 0));
        while (sec < 2) {
            al_wait_for_event(queue, &evento);
            if (evento.type == ALLEGRO_EVENT_TIMER) {
                if (evento.timer.source == segundo) {
                    sec++;

                    if (aleatorio != 5) {


                        ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/HeartLink.png");
                        al_draw_scaled_bitmap(fondo, 0, 0, 234, 208, 0, 0, 800, 500, 0);
                        al_draw_text(font, al_map_rgb(255, 255, 255), 8, 550, NULL, "Respuesta Correcta");
                        //corazones++;
                        al_flip_display();
                    }

                    cout << "Respuesta correcta" << endl;

                }
            }

        }
        corazones++;
            al_clear_to_color(al_map_rgb(0, 0, 0));



            return true;
        }
        else {
            al_clear_to_color(al_map_rgb(0, 0, 0));
            cout << "Respuesta incorrecta" << endl;

        }

    if (contador == 5) {
        while (sec < 6) {
            al_wait_for_event(queue, &evento);
            if (evento.type == ALLEGRO_EVENT_TIMER) {
                if (evento.timer.source == segundo) {
                    sec++;

                    ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/Out.png");
                    al_draw_scaled_bitmap(fondo, 0, 0, 874, 602, 0, 0, 800, 500, 0);
                    al_draw_text(font, al_map_rgb(255, 255, 255), 8, 550, NULL, "Has contestado toda las preguntas");
                    al_flip_display();
                    cout << "Respuesta correcta" << endl;

                }
            }

        }
    }

        return false;

    };


    int mapa::numAleatorio() {

        aleatorio = 0 + rand() % 5;
        if (num1 != 7 && num2 != 7 && num3 != 7 && num4 != 7 &&num5!=7) {
            aleatorio = 5;
        }
        while (aleatorio == num1 || aleatorio == num2 || aleatorio == num3 || aleatorio == num4) {
            aleatorio = 0 + rand() % 5;
            cout << aleatorio;

        }

        if (num1 == 7) {
            num1 = aleatorio;
            cout << "num1 :" << num1 << endl;
        }
        else if (num1 != aleatorio && num2 == 7) {
            num2 = aleatorio;
            cout << "num2 :" << num2 << endl;
        }
        else if (num2 != aleatorio && num1 != aleatorio && num3 == 7) {
            num3 = aleatorio;
            cout << "num3 :" << num3 << endl;
        }
        else if (num3 != aleatorio && num1 != aleatorio && num2 != aleatorio && num4 == 7) {
            num4 = aleatorio;
            cout << "num4 :" << num4 << endl;
        }else if (num3 != aleatorio && num1 != aleatorio && num2 != aleatorio && num4 != aleatorio&&num5==7) {
            num5 = aleatorio;
            cout << "num5 :" << num5 << endl;
        }

      
        return aleatorio;
    };

    void mapa::laberinto(ALLEGRO_DISPLAY* pantalla , int* vida) {
        vidaptr = vida;
        corazones = *vidaptr / 10;

        Preguntas();
        int respuesta;
        //int Ancho = GetSystemMetrics(SM_CXSCREEN);
        //int Alto = GetSystemMetrics(SM_CYSCREEN);
        bool borrar = false;

        srand(time(NULL));
        int aleatorio = numAleatorio();

        //cout << aleatorio << endl;
        //cout << P[aleatorio].pregunta << endl;
        //cout << P[aleatorio].respuesta1 << "\n" << P[aleatorio].respuesta2 << "\n" << P[aleatorio].respuesta3 << endl;

    

        //al_init();

        al_init_image_addon();


        al_install_keyboard();

        //Incializa texto
        al_init_font_addon();
        al_init_ttf_addon();




        //ALLEGRO_DISPLAY* pantalla = al_create_display(800, 600);




        //texto

        //ALLEGRO_DISPLAY* ventana = al_create_display(800, 600);
        ALLEGRO_DISPLAY* ventana = pantalla;
        choque2 = al_load_bitmap("Imagenes/MapaRojo_Dungeon.png");
        ALLEGRO_FONT* font = al_load_font("Fonts/VPPixel-Simplified.otf", 18, 0);

        ALLEGRO_BITMAP* prota = al_load_bitmap("Imagenes/SheetZelda2.png");
        ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/dungeon.png");    

        al_reserve_samples(2);
        ALLEGRO_SAMPLE* song = al_load_sample("Audios/ciencia.mp3");
        ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song);
        al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_LOOP);
        al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());


        // defino lista de eventos

        ALLEGRO_EVENT_QUEUE* Mis_eventos;

        ALLEGRO_EVENT evento;


        // creo lista de eventos

        Mis_eventos = al_create_event_queue();


        // asigno eventos a la lista de eventos

        al_register_event_source(Mis_eventos, al_get_keyboard_event_source());

        al_register_event_source(Mis_eventos, al_get_display_event_source(pantalla));


        ALLEGRO_KEYBOARD_STATE teclado;


        bool salir;

        double x, y;

        int desplaza, rot = 0;

        int paso;

        int dir;

        double ax, ay;

        // inicializar variables

        x = 96*4;

        y = 59*4;


        desplaza = 4;


        paso = 0;

        dir = 0;


        salir = false;

        Transition transLaberinto;
        transLaberinto.drawTransitionReversa(ventana, fondo, 960, 704,
            prota, 0, 0, 0, 0);
        al_play_sample_instance(instance);

        al_clear_to_color(al_map_rgb(0,0,0));
        al_flip_display();
        while (!salir)

        {
            //cout << "corazones" << corazones << endl << endl;
            ax = x;
            ay = y;
            borrar = false;

            // pinta el fondo de un color 


            al_draw_scaled_bitmap(fondo, 0, 0, 960, 704, 0, 0, 800, 500, 0);
            LifeBar(corazones);


            al_draw_bitmap_region(prota, paso * 32, dir * 35, 32, 35, x, y, rot);

            // mostramos la pantalla
            al_flip_display();


            al_wait_for_event(Mis_eventos, &evento);





           

                al_draw_text(font, al_map_rgb(255, 255, 255), 8, 500, NULL, (P[aleatorio].pregunta).c_str());
                al_draw_text(font, al_map_rgb(255, 255, 255), 8, 530, NULL, (P[aleatorio].extra).c_str());
                al_draw_text(font, al_map_rgb(255, 255, 255), 8, 565, NULL, (P[aleatorio].respuesta1 + "   " + P[aleatorio].respuesta2 + "   " + P[aleatorio].respuesta3).c_str());
                al_flip_display();

            


            // se ha cerrado la ventana



            al_get_keyboard_state(&teclado);


            if (al_key_down(&teclado, ALLEGRO_KEY_UP))

            {

                y -= desplaza;

                dir = 2;

                paso++;
                rot = 0;
            }

            if (al_key_down(&teclado, ALLEGRO_KEY_DOWN)) {

                y += desplaza;

                dir = 0;

                paso++;

                rot = 0;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_LEFT)) {

                x -= desplaza;

                dir = 1;

                paso++;

                rot = 0;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT)) {

                x += desplaza;

                dir = 1;

                paso++;

                rot = 1;
            }
            if ((x != ax || y != ay) && colisiona2(x, y))
            {
                cout << "ES ROJO" << endl;
                x = ax;
                y = ay;
            }
            //cout << "X: "<<x << endl;
            //cout << "Y: " << y << endl;


            // limitadores

            if (y < 0) y = 0;

            if (x >= 24 && x <= 62) {
                if (y < 55) {
                    y = 55;

                }
                if (y > 63) {
                    y = 63;
                }
            }




            //abajo
            if (x > (96 - 32.5)*4 && y > 102*4) {
                x = 96*4;
                y = 102*4;

            }
            //izquierda
            if (x < 19 * desplaza) {
                x = 19*4;
                y = 59*4;
                respuesta = 2;
                if (validarRespuesta(respuesta, &P[aleatorio], aleatorio) == false) {
                    aleatorio = numAleatorio();
                    x = 96*4;
                    y = 59*4;
                    borrar = true;
                }
                else {
                    aleatorio = numAleatorio();
                    x = 96*4;
                    y = 59*4;
                }
            }
            //arriba
            if (y < 18 * desplaza) {
                x = 96*4;
                y = 18*4;
                respuesta = 1;
                if (validarRespuesta(respuesta, &P[aleatorio], aleatorio) == false) {
                    aleatorio = numAleatorio();
                    x = 96*4;
                    y = 59*4;
                    borrar = true;
                }
                else {
                    aleatorio = numAleatorio();
                    x = 96*4;
                    y = 59*4;
                }

            }
            //derecha
            if (x > 173 * desplaza) {
                x = 173*4;
                y = 59*4;
                respuesta = 3;
                if (validarRespuesta(respuesta, &P[aleatorio], aleatorio) == false) {
                    aleatorio = numAleatorio();
                    x = 96*4;
                    y = 59*4;
                    borrar = true;
                }
                else {
                    aleatorio = numAleatorio();
                    x = 96*4;
                    y = 59*4;
                }
            }
            if (paso > 9) paso = 0;


            if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE)) {

                salir = true;

            }
            if (aleatorio == 5) {
                borrar = true;
                salir = true;
            }

        }
        //cout << "corazones" << corazones << endl << endl;
        *vidaptr = corazones * 10;

        al_destroy_sample_instance(instance);
        al_destroy_bitmap(prota);
        al_destroy_bitmap(choque2);
        //al_destroy_display(pantalla);
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_flip_display();
        al_rest(1);
    }

