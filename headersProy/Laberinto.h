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

class mapa {
public :
	
    void laberinto(ALLEGRO_DISPLAY* pantalla);

private:
    bool validarRespuesta(int, preguntas*, int);
    int numAleatorio();
    int aleatorio = 0, num1 = 7, num2 = 7, num3 = 7, num4 = 7,num5=7, contador = 0;
    int corazones=0;
    void Preguntas();
};

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
                        corazones++;
                        al_flip_display();
                    }

                    cout << "Respuesta correcta" << endl;

                }
            }

        }
            al_clear_to_color(al_map_rgb(0, 0, 0));


            /* Transition transCofres;
             ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/mapa 2d.png");
             transCofres.drawTransitionReversa(pantalla, fondo, 254, 254, prota, paso, dir, x, y, desplaza);*/


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

    void mapa::laberinto(ALLEGRO_DISPLAY* pantalla) {
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
        ALLEGRO_FONT* font = al_load_font("Fonts/VPPixel-Simplified.otf", 18, 0);

        ALLEGRO_BITMAP* prota = al_load_bitmap("Imagenes/SheetZelda2.png");
        ALLEGRO_BITMAP* fondo = al_load_bitmap("Imagenes/dungeon.png");
        

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


        // inicializar variables

        x = 96;

        y = 59;


        desplaza = 4;


        paso = 0;

        dir = 0;


        salir = false;

        Transition transLaberinto;
        transLaberinto.drawTransitionReversa(ventana, fondo, 960, 704,
            prota, 0, 0, 0, 0);

        al_clear_to_color(al_map_rgb(0,0,0));
        al_flip_display();
        while (!salir)

        {

            borrar = false;

            // pinta el fondo de un color 


            al_draw_scaled_bitmap(fondo, 0, 0, 960, 704, 0, 0, 800, 500, 0);




            al_draw_bitmap_region(prota, paso * 32, dir * 35, 32, 35, x * desplaza, y * desplaza, rot);

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

                y--;

                dir = 2;

                paso++;
                rot = 0;
            }

            if (al_key_down(&teclado, ALLEGRO_KEY_DOWN)) {

                y++;

                dir = 0;

                paso++;

                rot = 0;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_LEFT)) {

                x--;

                dir = 1;

                paso++;

                rot = 0;

            }

            if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT)) {

                x++;

                dir = 1;

                paso++;

                rot = 1;
            }

            //cout << "X: "<<x << endl;
            //cout << "Y: " << y << endl;


            // limitadores


            if (x >= 24 && x <= 62) {
                if (y < 55) {
                    y = 55;

                }
                if (y > 63) {
                    y = 63;
                }
            }

            if (y < 0) y = 0;



            //abajo
            if (x > 96 - 32.5 && y > 102) {
                x = 96;
                y = 102;

            }
            //izquierda
            if (x < 19) {
                x = 19;
                y = 59;
                respuesta = 2;
                if (validarRespuesta(respuesta, &P[aleatorio], aleatorio) == false) {
                    aleatorio = numAleatorio();
                    x = 96;
                    y = 59;
                    borrar = true;
                }
                else {
                    aleatorio = numAleatorio();
                    x = 96;
                    y = 59;
                }
            }
            //arriba
            if (y < 18) {
                x = 96;
                y = 18;
                respuesta = 1;
                if (validarRespuesta(respuesta, &P[aleatorio], aleatorio) == false) {
                    aleatorio = numAleatorio();
                    x = 96;
                    y = 59;
                    borrar = true;
                }
                else {
                    aleatorio = numAleatorio();
                    x = 96;
                    y = 59;
                }

            }
            //derecha
            if (x > 173) {
                x = 173;
                y = 59;
                respuesta = 3;
                if (validarRespuesta(respuesta, &P[aleatorio], aleatorio) == false) {
                    aleatorio = numAleatorio();
                    x = 96;
                    y = 59;
                    borrar = true;
                }
                else {
                    aleatorio = numAleatorio();
                    x = 96;
                    y = 59;
                }
            }
            if (paso > 3) paso = 0;


            if (al_key_down(&teclado, ALLEGRO_KEY_ESCAPE)) {

                salir = true;

            }
            if (aleatorio == 5) {
                borrar = true;
                salir = true;
            }

        }
        al_destroy_bitmap(prota);
        //al_destroy_display(pantalla);
        al_clear_to_color(al_map_rgb(255, 255, 255));
        al_rest(1);
        al_flip_display();
    }

