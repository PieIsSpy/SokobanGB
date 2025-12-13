#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <types.h>
#include "../res/sprites/EntitySprites.c"
#include "../res/sprites/TileSprites.c"
#include "../res/maps/twoboxes.c"

#define tileWidth 8
#define tileHeight 8
#define offsetX 8
#define offsetY 16

// define the entity types
typedef enum {
    PLAYER,
    BOX
} entityType;

// define directions
typedef enum {
    LEFT,
    RIGHT,
    UP,
    DOWN
} directions;

// define counter for entity sprites
UINT8 spriteCount = 0;