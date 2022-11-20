#pragma once
//VER SI FUNCIONA LA FUNCION PARA DIBUJAR UN SPRITESHEET DE UNA FILA
//CON UN PARAMETRO SIZE PARA INICIAR EL ARRAY
#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <Windows.h>

struct varsFrame
{
		ALLEGRO_BITMAP* bitmap; double Sx; double Sy; double Sw; double Sh;
		double Dx; double Dy; double Dw; double Dh; double alrestTime;	
};

class SpritesheetRow
{
	int size;
	SpritesheetRow(int sizeP, ALLEGRO_DISPLAY* displayP)
	{
		//varsFrame vars[size];
		//for (size_t i = 0; i < size; i++)
		//{

		//}
	}
};
