typedef struct {
    UBYTE spriteId;
    UINT8 x;
    UINT8 y;
} Entity;

Entity createEntity(entityType type, UINT8 x, UINT8 y);
void moveEntity(Entity* entity, UINT8 x, UINT8 y);
void entityControl(Entity* entity);

Entity createEntity(entityType type, UINT8 x, UINT8 y) {
    Entity temp = {spriteCount, x, y};

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

void entityControl(Entity* entity) {
    switch (joypad()) {
        case J_LEFT:
            entity->x -= 8;
            break;
        case J_RIGHT:
            entity->x += 8;
            break;
        case J_UP:
            entity->y -= 8;
            break;
        case J_DOWN:
            entity->y += 8;
            break;
    }
    moveEntity(entity, entity->x, entity->y);
}