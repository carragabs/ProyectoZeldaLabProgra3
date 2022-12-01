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

struct varsFrameFlag
{
	ALLEGRO_BITMAP* bitmap; double Sx; double Sy; double Sw; double Sh;
	double Dx; double Dy; double Dw; double Dh; double alrestTime; int flag;
};

class SpritesheetRow
{
public:

	void drawSpritesheetRow(int sizeP, ALLEGRO_DISPLAY* displayP, varsFrame vars[])
	{
		for (size_t i = 0; i < sizeP; i++)
		{
			al_draw_scaled_bitmap(vars[i].bitmap, vars[i].Sx, vars[i].Sy,
				vars[i].Sw, vars[i].Sh, vars[i].Dx,
				vars[i].Dy, vars[i].Dw, vars[i].Dh, 0);
			al_flip_display();
			al_rest(vars[i].alrestTime);

		}
	}
	void drawSpritesheetRowFlag(int sizeP, ALLEGRO_DISPLAY* displayP,
		varsFrameFlag vars[])
	{
		for (size_t i = 0; i < sizeP; i++)
		{
			al_draw_scaled_bitmap(vars[i].bitmap, vars[i].Sx, vars[i].Sy,
				vars[i].Sw, vars[i].Sh, vars[i].Dx,
				vars[i].Dy, vars[i].Dw, vars[i].Dh, vars[i].flag);
			al_flip_display();
			al_rest(vars[i].alrestTime);

		}
	}
	private:

};
