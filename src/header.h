#include <gb/gb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <types.h>
#include "../res/EntitySprites.c"

#define tileWidth 8
#define tileHeight 8

// define the entity types
typedef enum {
    PLAYER,
    BOX
} entityType;

// define counter for entity sprites
UINT8 spriteCount = 0;