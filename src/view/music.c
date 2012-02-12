#include "music.h"

void gest_music (MIDI * music)
{
    static int pause=0;

    //PAUSE
    if (pause==0 && mouse_y<40 && mouse_x>760 && mouse_b&1)
    {
        midi_pause();
        pause==1;
    }
    //RESUME
    else if (pause==1 && mouse_y<40 && mouse_x>760 && mouse_b&1)
    {
        midi_resume();
        pause==0;
    }

}
