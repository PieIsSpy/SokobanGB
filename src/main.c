#include "header.h"
#include "tileChecker.c"
#include "entity.c"
#include "player.c"

UINT8 isWon(Entity boxes[], UINT8 numBoxes) {
    UINT8 cout = 0;

    for (UINT8 i = 0; i < numBoxes; i++) {
        if (isTileGoal(boxes[i].x, boxes[i].y))
            cout++;
    }

    return cout == numBoxes;
}

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