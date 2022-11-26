#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

struct coordenadasCuadro { int xRect; int yRect; };

class ColisionesCuadro
{
public:
    ALLEGRO_DISPLAY* display;
    bool colArriba;
    bool colAbajo;
    bool colIzquierda;
    bool colDerecha;
    
    ColisionesCuadro(ALLEGRO_DISPLAY* displayMain);
    void crearColisionesCuadro(coordenadasCuadro cuadro, double& x, double& y, double desplaza);

private:

};

ColisionesCuadro::ColisionesCuadro(ALLEGRO_DISPLAY* displayMain)
{
        display = displayMain;   
        colArriba = false; colArriba = false; colIzquierda = false; colDerecha = false;
}

void ColisionesCuadro::crearColisionesCuadro(coordenadasCuadro cuadro, double &x, double &y, double desplaza)
{
    //DESDE LA PERPECTIVA DEL CUADRO

    if (y * desplaza < cuadro.yRect + 50 && y * desplaza >(cuadro.yRect + 50) - 8
        && (x * desplaza < cuadro.xRect + 50) && (x * desplaza + 32.5 > cuadro.xRect))
    {
        //cout << "COLLISION TRUE!" << endl;
        y = (cuadro.yRect + 50) / desplaza;
        colAbajo = true;
    }
    if (y * desplaza + 35 > cuadro.yRect && (y * desplaza + 35 < cuadro.yRect + 8)
        && (x * desplaza < cuadro.xRect + 50) && (x * desplaza + 32.5 > cuadro.xRect))
    {
        // cout << "COLLISION TRUE!" << endl;
        y = (cuadro.yRect - (35)) / desplaza;
        colArriba = true;
    }

    if (x * desplaza < cuadro.xRect + 50 && x * desplaza >(cuadro.xRect + 50) - 8
        && (y * desplaza < cuadro.yRect + 50) && (y * desplaza + 35 > cuadro.yRect))
    {
        // cout << "COLLISION TRUE!" << endl;
        x = (cuadro.xRect + 50) / desplaza;
        colDerecha = true;
    }
    if (x * desplaza + 32.5 > cuadro.xRect && x * desplaza + 32.5 < cuadro.xRect + 8
        && (y * desplaza < cuadro.yRect + 50) && (y * desplaza + 35 > cuadro.yRect))
    {
        // cout << "COLLISION TRUE!" << endl;
        x = (cuadro.xRect - 32.5) / desplaza;
        colIzquierda = true;
    }

}
