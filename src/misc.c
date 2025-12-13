void performantDelay(UINT8 numloops);
void defineSpriteData(void);

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