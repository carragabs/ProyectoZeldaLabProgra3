#include <iostream>
#include <string>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <Windows.h>

using namespace std;


class Header {

public:

	Header();
	~Header();
	

void LifeBar(int);


};

Header::Header() {


}
Header::~Header() {


}

void Header::LifeBar(int vida) {


	al_draw_filled_rectangle(10, 20, 200, 30, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(10, 20, vida, 30, al_map_rgb(0, 255, 0));
	al_flip_display();

}