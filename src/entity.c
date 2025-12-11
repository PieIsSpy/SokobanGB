typedef struct {
    UBYTE spriteId;
    entityType type;
    UINT8 x;
    UINT8 y;
} Entity;

Entity createEntity(entityType type, UINT8 x, UINT8 y);
void moveEntity(Entity* entity, UINT8 x, UINT8 y);

Entity createEntity(entityType type, UINT8 x, UINT8 y) {
    Entity temp = {spriteCount, type, x, y};

    if (type == PLAYER) {
        set_sprite_tile(spriteCount, 0);
    }
    else {
        set_sprite_tile(spriteCount, 1);
    }

    moveEntity(&temp, x, y);
    spriteCount++;

    return temp;
}

void moveEntity(Entity* entity, UINT8 x, UINT8 y) {
    move_sprite(entity->spriteId, x, y);
}