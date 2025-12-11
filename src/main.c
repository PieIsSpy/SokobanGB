#include "header.h"
#include "entity.c"

void main(void) {
    BYTE gameRunning = 1;
    defineSpriteData();

    Entity player = createEntity(PLAYER, 88, 78);
    SHOW_SPRITES;
    DISPLAY_ON;

    while (gameRunning) {
        entityControl(&player);
        performantDelay(5);
    }
}