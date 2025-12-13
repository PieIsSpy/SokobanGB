BYTE canPlayerMove(directions direction, Entity player, Entity boxes[], UINT8 numBoxes);
BYTE canBoxMove(directions direction, Entity targetBox, Entity boxes[], UINT8 numBoxes);
INT8 findAdjacentBox(UINT8 targetX, UINT8 targetY, Entity boxes[], UINT8 numBoxes);
void playerControl(Entity* player, Entity boxes[], UINT8 numBoxes);

BYTE canPlayerMove(directions direction, Entity player, Entity boxes[], UINT8 numBoxes) {
    UINT8 targetX;
    UINT8 targetY;
    INT8 adjacentBox;
    BYTE boxDecision;

    switch (direction) {
        case LEFT:
            targetX = player.x - tileWidth;
            targetY = player.y;
            break;
        case RIGHT:
            targetX = player.x + tileWidth;
            targetY = player.y;
            break;
        case UP:
            targetX = player.x;
            targetY = player.y - tileHeight;
            break;
        case DOWN:
            targetX = player.x;
            targetY = player.y + tileHeight;
            break;
    }

    if (isTileWall(targetX, targetY))
        return 0;

    adjacentBox = findAdjacentBox(targetX, targetY, boxes, numBoxes);

    if (adjacentBox != -1) {
        boxDecision = canBoxMove(direction, boxes[adjacentBox], boxes, numBoxes);

        if (!boxDecision)
            return 0;
        else {
            switch (direction) {
                case LEFT:
                    boxes[adjacentBox].x -= tileWidth;
                    break;
                case RIGHT:
                    boxes[adjacentBox].x += tileWidth;
                    break;
                case UP:
                    boxes[adjacentBox].y -= tileHeight;
                    break;
                case DOWN:
                    boxes[adjacentBox].y += tileHeight;
                    break;
            }

            moveEntity(&boxes[adjacentBox], boxes[adjacentBox].x, boxes[adjacentBox].y);
        }
    }

    return 1;
}

BYTE canBoxMove(directions direction, Entity targetBox, Entity boxes[], UINT8 numBoxes) {
    UINT8 targetX;
    UINT8 targetY;
    INT8 adjacentBox;
    BYTE boxDecision;

    switch (direction) {
        case LEFT:
            targetX = targetBox.x - tileWidth;
            targetY = targetBox.y;
            break;
        case RIGHT:
            targetX = targetBox.x + tileWidth;
            targetY = targetBox.y;
            break;
        case UP:
            targetX = targetBox.x;
            targetY = targetBox.y - tileHeight;
            break;
        case DOWN:
            targetX = targetBox.x;
            targetY = targetBox.y + tileHeight;
            break;
    }

    if (isTileWall(targetX, targetY))
        return 0;

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
                player->x -= tileWidth;
            break;
        case J_RIGHT:
            if (canPlayerMove(RIGHT, *player, boxes, numBoxes))
                player->x += tileWidth;
            break;
        case J_UP:
            if (canPlayerMove(UP, *player, boxes, numBoxes))
                player->y -= tileHeight;
            break;
        case J_DOWN:
            if (canPlayerMove(DOWN, *player, boxes, numBoxes))
                player->y += tileHeight;
            break;
    }
    moveEntity(player, player->x, player->y);
}