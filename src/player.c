BYTE canPlayerMove(directions direction, Entity player, Entity boxes[], UINT8 numBoxes);
INT8 findAdjacentBox(UINT8 targetX, UINT8 targetY, Entity boxes[], UINT8 numBoxes);
void playerControl(Entity* player, Entity boxes[], UINT8 numBoxes);

BYTE canPlayerMove(directions direction, Entity player, Entity boxes[], UINT8 numBoxes) {
    UINT8 targetX;
    UINT8 targetY;
    INT8 adjacentBox;
    INT8 anotherAdjacentBox;
    BYTE boxDecision;

    switch (direction) {
        case LEFT:
            targetX = player.x - 8;
            targetY = player.y;
            break;
        case RIGHT:
            targetX = player.x + 8;
            targetY = player.y;
            break;
        case UP:
            targetX = player.x;
            targetY = player.y - 8;
            break;
        case DOWN:
            targetX = player.x;
            targetY = player.y + 8;
            break;
    }

    adjacentBox = findAdjacentBox(targetX, targetY, boxes, numBoxes);

    if (adjacentBox != -1) {
        return 0;
    }

    return 1;
}

INT8 findAdjacentBox(UINT8 targetX, UINT8 targetY, Entity boxes[], UINT8 numBoxes) {
    for (UINT8 i = 0; i < numBoxes; i++) {
        if (boxes[i].x == targetX & boxes[i].y == targetY)
            return i;
    }
    return -1;
}

void playerControl(Entity* player, Entity boxes[], UINT8 numBoxes) {
    switch (joypad()) {
        case J_LEFT:
            if (canPlayerMove(LEFT, *player, boxes, numBoxes))
                player->x -= 8;
            break;
        case J_RIGHT:
            if (canPlayerMove(RIGHT, *player, boxes, numBoxes))
                player->x += 8;
            break;
        case J_UP:
            if (canPlayerMove(UP, *player, boxes, numBoxes))
                player->y -= 8;
            break;
        case J_DOWN:
            if (canPlayerMove(DOWN, *player, boxes, numBoxes))
                player->y += 8;
            break;
    }
    moveEntity(player, player->x, player->y);
}