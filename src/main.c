#include "header.h"
#include "misc.c"
#include "tileChecker.c"
#include "entity.c"
#include "player.c"
#include "mapHandler.c"

void main(void) {
    defineSpriteData();

    Entity player = createEntity(PLAYER, 88, 72);
    Entity boxes[2];
    boxes[0] = createEntity(BOX, 80, 72);
    boxes[1] = createEntity(BOX, 72, 80);

    set_bkg_tiles(0, 0, 20, 18, twoBoxes);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    while (!isWon(boxes, 2)) {
        playerControl(&player, boxes, 2);
        performantDelay(20);
    }
    printf("======You Win!======");
}