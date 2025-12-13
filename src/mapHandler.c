UINT8 isWon(Entity boxes[], UINT8 numBoxes);

UINT8 isWon(Entity boxes[], UINT8 numBoxes) {
    UINT8 cout = 0;

    for (UINT8 i = 0; i < numBoxes; i++) {
        if (isTileGoal(boxes[i].x, boxes[i].y))
            cout++;
    }

    return cout == numBoxes;
}