BYTE isTileWall(UINT8 targetX, UINT8 targetY);

BYTE isTileWall(UINT8 targetX, UINT8 targetY) {
    UINT16 x_index, y_index, tile_index;

    x_index = ((UINT16)targetX - 8) / 8;
    y_index = ((UINT16)targetY - 16) / 8;
    tile_index = (y_index * 20) + x_index;

    return twoBoxes[tile_index] == 0x02;
}

BYTE isTileGoal(UINT8 targetX, UINT8 targetY) {
    UINT16 x_index, y_index, tile_index;

    x_index = ((UINT16)targetX - 8) / 8;
    y_index = ((UINT16)targetY - 16) / 8;
    tile_index = (y_index * 20) + x_index;

    return twoBoxes[tile_index] == 0x01;
}