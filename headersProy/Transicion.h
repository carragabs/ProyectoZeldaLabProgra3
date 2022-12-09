#pragma once
#include <allegro5/allegro.h>
#include <iostream>
#include <allegro5/allegro_image.h>
#include "SpritesheetRow.h"

class Transition
{
public:
    ALLEGRO_BITMAP* transition;
    Transition()
    {
        transition = al_load_bitmap("Imagenes/watertrans.png");
    };

    void drawTransition(ALLEGRO_DISPLAY* pantalla, ALLEGRO_BITMAP* fondo, double fondow, double fondoh,
        ALLEGRO_BITMAP* prota, double paso, double dir, double x, double y);
    void drawTransitionReversa(ALLEGRO_DISPLAY* pantalla, ALLEGRO_BITMAP* fondo, double fondow, double fondoh,
        ALLEGRO_BITMAP* prota, double paso, double dir, double x, double y);
    void destroyTrans()
    {
        al_destroy_bitmap(transition);

    };

private:

};

void Transition::drawTransition(ALLEGRO_DISPLAY* pantalla, ALLEGRO_BITMAP* fondo, double fondow, double fondoh,

    ALLEGRO_BITMAP* prota, double paso, double dir, double x, double y)
{
    al_reserve_samples(2);
    ALLEGRO_SAMPLE* song = al_load_sample("Audios/mirrorwarp.wav");
    ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song);
    al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
    varsFrame varsTransition[48];
    varsTransition[0] = { transition,87,62,181,105,0,0,800,600,0.25 }; //FILA 1 DE FOTO
    varsTransition[1] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[2] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[3] = { transition,87 + 181 * 1 + 8 * 1,62,181,105,0,0,800,600,0.25 };
    varsTransition[4] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[5] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[6] = { transition,87 + 181 * 2 + 8 * 2,62,181,105,0,0,800,600,0.25 };
    varsTransition[7] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[8] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[9] = { transition,87 + 181 * 3 + 8 * 3,62,181,105,0,0,800,600,0.25 };
    varsTransition[10] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[11] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[12] = { transition,87 + 181 * 4 + 8 * 4,62,181,105,0,0,800,600,0.25 };
    varsTransition[13] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[14] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[15] = { transition,87 + 181 * 5 + 8 * 5,62,181,105,0,0,800,600,0.25 };
    varsTransition[16] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[17] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[18] = { transition,87,183.5,181,102,0,0,800,600,0.25 };//FILA 2 DE FOTO
    varsTransition[19] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[20] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[21] = { transition,87 + 181 * 1 + 8 * 1,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[22] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[23] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[24] = { transition,87,183.5,181,102,0,0,800,600,0.25 };//FILA 2 DE FOTO
    varsTransition[25] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[26] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[27] = { transition,87 + 181 * 1 + 8 * 1,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[28] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[29] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[30] = { transition,87,183.5,181,102,0,0,800,600,0.25 };//FILA 2 DE FOTO
    varsTransition[31] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[32] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[33] = { transition,87 + 181 * 1 + 8 * 1,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[34] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[35] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[36] = { transition,87 + 181 * 2 + 8 * 2,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[37] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[38] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[39] = { transition,87 + 181 * 3 + 8 * 3,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[40] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[41] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[42] = { transition,87 + 181 * 4 + 8 * 4,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[43] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[44] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[45] = { transition,87 + 181 * 5 + 8 * 5,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[46] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[47] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    SpritesheetRow Sheettrans;
    al_convert_mask_to_alpha(transition, al_map_rgb(0, 0, 0));
    al_play_sample_instance(instance);
    Sheettrans.drawSpritesheetRow(48, pantalla, varsTransition);
}

void Transition::drawTransitionReversa(ALLEGRO_DISPLAY* pantalla, ALLEGRO_BITMAP* fondo, double fondow, double fondoh,
    ALLEGRO_BITMAP* prota, double paso, double dir, double x, double y)
{
    varsFrame varsTransition[48];
    varsTransition[47] = { transition,87,62,181,105,0,0,800,600,0.25 }; //FILA 1 DE FOTO
    varsTransition[46] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[45] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[44] = { transition,87 + 181 * 1 + 8 * 1,62,181,105,0,0,800,600,0.25 };
    varsTransition[43] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[42] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[41] = { transition,87 + 181 * 2 + 8 * 2,62,181,105,0,0,800,600,0.25 };
    varsTransition[40] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[39] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[38] = { transition,87 + 181 * 3 + 8 * 3,62,181,105,0,0,800,600,0.25 };
    varsTransition[37] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[36] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[35] = { transition,87 + 181 * 4 + 8 * 4,62,181,105,0,0,800,600,0.25 };
    varsTransition[34] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[33] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[32] = { transition,87 + 181 * 5 + 8 * 5,62,181,105,0,0,800,600,0.25 };
    varsTransition[31] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[30] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[29] = { transition,87,183.5,181,102,0,0,800,600,0.25 };//FILA 2 DE FOTO
    varsTransition[28] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[27] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[26] = { transition,87 + 181 * 1 + 8 * 1,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[25] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[24] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[23] = { transition,87,183.5,181,102,0,0,800,600,0.25 };//FILA 2 DE FOTO
    varsTransition[22] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[21] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };
    varsTransition[20] = { transition,87 + 181 * 1 + 8 * 1,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[19] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[18] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[17] = { transition,87,183.5,181,102,0,0,800,600,0.25 };//FILA 2 DE FOTO
    varsTransition[16] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[15] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[14] = { transition,87 + 181 * 1 + 8 * 1,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[13] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[12] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[11] = { transition,87 + 181 * 2 + 8 * 2,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[10] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[9] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[8] = { transition,87 + 181 * 3 + 8 * 3,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[7] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[6] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[5] = { transition,87 + 181 * 4 + 8 * 4,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[4] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[3] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    varsTransition[2] = { transition,87 + 181 * 5 + 8 * 5,183.5,181,102,0,0,800,600,0.25 };
    varsTransition[1] = { fondo, 0, 0, fondow, fondoh, 0, 0, 800, 600, 0 };
    varsTransition[0] = { prota, paso * 32.5, dir * 35.0, 32.5, 35,
        x , y , 32.5, 35, 0 };

    SpritesheetRow Sheettrans;
    al_convert_mask_to_alpha(transition, al_map_rgb(0, 0, 0));

    //AQUISONIDO mirrorwarp.wav
    al_reserve_samples(2);
    ALLEGRO_SAMPLE* song = al_load_sample("Audios/mirrorwarp.wav");
    ALLEGRO_SAMPLE_INSTANCE* instance = al_create_sample_instance(song);
    al_set_sample_instance_playmode(instance, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(instance, al_get_default_mixer());
    al_play_sample_instance(instance);
    Sheettrans.drawSpritesheetRow(48, pantalla, varsTransition);


}