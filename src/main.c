#include "header.h"
#include "entity.c"

void performantdelay(UINT8 numloops) {
    UINT8 i;
    for (i = 0; i < numloops; i++) {
        wait_vbl_done();
    }
}

void defineSpriteData(void) {
    set_sprite_data(0, 2, entitySprites);
}

void main(void) {
    BYTE gameRunning = 1;
    defineSpriteData();

    Entity player = createEntity(PLAYER, 88, 78);
    SHOW_SPRITES;
    DISPLAY_ON;

    while (gameRunning) {
        entityControl(&player);
        performantdelay(5);
    }
}