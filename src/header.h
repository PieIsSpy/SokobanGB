#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <types.h>
#include "../res/sprites/EntitySprites.c"
#include "../res/sprites/TileSprites.c"

#define tileWidth 8
#define tileHeight 8

// define the entity types
typedef enum {
    PLAYER,
    BOX
} entityType;

// define counter for entity sprites
UINT8 spriteCount = 0;

void performantDelay(UINT8 numloops) {
    UINT8 i;
    for (i = 0; i < numloops; i++) {
        wait_vbl_done();
    }
}

void defineSpriteData(void) {
    set_sprite_data(0, 2, entitySprites);
    set_bkg_data(0, 3, tileSprites);
}