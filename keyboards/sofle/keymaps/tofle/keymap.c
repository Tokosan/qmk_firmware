// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes { KC_PRVWD = QK_USER, KC_NXTWD, KC_LSTRT, KC_LEND };

enum tap_dance_codes {
    TD_LSFT_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_COLEMAK PDF(_COLEMAK)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |HYPR/E|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|  MUTE |    |  MUTE |------+------+------+------+------+------|
     * |SFT/CP|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  | Ent  |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL | LAlt | LCMD |LOWER | /Space  /       \Enter \  |RAISE | RCMD | RAlt | RCTL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */

    [_QWERTY] = LAYOUT(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, HYPR_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, TD(TD_LSFT_CAPS), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_MUTE, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT, KC_LCTL, KC_LALT, KC_LCMD, TL_LOWR, KC_SPC, KC_ENT, TL_UPPR, KC_RCMD, KC_RALT, KC_RCTL),
    /* LOWER
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |------|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
     * |------+------+------+------+------+------|  MUTE |    |  MUTE |------+------+------+------+------+------|
     * |------|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  |------|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL | LAlt | LCMD |LOWER | /Space  /       \Enter \  |RAISE | RCMD | RAlt | RCTL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_LOWER] = LAYOUT(_______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, _______, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, _______, KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* RAISE
     * ,----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |------| Ins  | Pscr | Menu |      |      |                    | PgUp | PWrd |  Up  | NWrd | DLine| Bspc |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |------| LAt  | LCtl |LShift|      | Caps |-------.    ,-------| PgDn | Left | Down | Right|  Del | Bspc |
     * |------+------+------+------+------+------|  MUTE  |    |  MUTE |------+------+------+------+------+------|
     * |------| Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      |------|
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL | LAlt | LCMD |LOWER | /Space  /       \Enter \  |RAISE | RCMD | RAlt | RCTL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_RAISE] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, KC_PSCR, KC_APP, XXXXXXX, XXXXXXX, KC_PGUP, _______, _______, KC_NXTWD, C(KC_BSPC), KC_BSPC, _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_DEL, KC_BSPC, _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX, _______, _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    /* ADJUST
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | BOOT |      |      |      |CG_TOG|UG_TOG|                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |CG_TOG|      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
     * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            | LCTL | LAlt | LCMD |LOWER | /Space  /       \Enter \  |RAISE | RCMD | RAlt | RCTL |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
    [_ADJUST] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}

#ifdef OLED_ENABLE

// Tabla de seno: 64 pasos para 0-360°, valores escalados ×100 (rango -100..100)
static const int8_t PROGMEM sin64[64] = {0, 10, 20, 29, 38, 47, 56, 63, 71, 77, 83, 88, 92, 96, 98, 100, 100, 100, 98, 96, 92, 88, 83, 77, 71, 63, 56, 47, 38, 29, 20, 10, 0, -10, -20, -29, -38, -47, -56, -63, -71, -77, -83, -88, -92, -96, -98, -100, -100, -100, -98, -96, -92, -88, -83, -77, -71, -63, -56, -47, -38, -29, -20, -10};

static inline int8_t isin(uint8_t a) {
    return (int8_t)pgm_read_byte(&sin64[a & 63]);
}
static inline int8_t icos(uint8_t a) {
    return (int8_t)pgm_read_byte(&sin64[(uint8_t)(a + 16) & 63]);
}

// 8 vértices del cubo en ±1
static const int8_t PROGMEM cube_v[8][3] = {{-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}, {-1, -1, 1}, {1, -1, 1}, {1, 1, 1}, {-1, 1, 1}};

// 12 aristas (pares de índices de vértices)
static const uint8_t PROGMEM cube_e[12][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 0}, {4, 5}, {5, 6}, {6, 7}, {7, 4}, {0, 4}, {1, 5}, {2, 6}, {3, 7}};

static uint8_t cube_angle = 0;

static void cube_draw_line(int8_t x0, int8_t y0, int8_t x1, int8_t y1) {
    int16_t dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int16_t dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int16_t err = dx + dy;
    while (true) {
        if (x0 >= 0 && x0 < 32 && y0 >= 0 && y0 < 128) oled_write_pixel((uint8_t)x0, (uint8_t)y0, true);
        if (x0 == x1 && y0 == y1) break;
        int16_t e2 = 2 * err;
        if (e2 >= dy) {
            err += dy;
            x0 += (int8_t)sx;
        }
        if (e2 <= dx) {
            err += dx;
            y0 += (int8_t)sy;
        }
    }
}

static void render_cube(void) {
    // Escala, inclinación en X (22.5°) y centro en la pantalla 32×128
    const uint8_t TILT = 4;
    const int8_t  S    = 10;
    const int8_t  CX   = 16;
    const int8_t  CY   = 48;

    int8_t px[8], py[8];
    for (uint8_t i = 0; i < 8; i++) {
        int8_t vx = (int8_t)pgm_read_byte(&cube_v[i][0]);
        int8_t vy = (int8_t)pgm_read_byte(&cube_v[i][1]);
        int8_t vz = (int8_t)pgm_read_byte(&cube_v[i][2]);

        // Rotación en Y
        int16_t rx = (int16_t)vx * icos(cube_angle) + (int16_t)vz * isin(cube_angle);
        int16_t rz = -(int16_t)vx * isin(cube_angle) + (int16_t)vz * icos(cube_angle);
        int16_t ry = (int16_t)vy * 100;

        // Inclinación fija en X para efecto 3D
        int16_t ry2 = (ry * icos(TILT) - rz * isin(TILT)) / 100;

        px[i] = (int8_t)(rx * S / 100) + CX;
        py[i] = (int8_t)(ry2 * S / 100) + CY;
    }

    for (uint8_t i = 0; i < 12; i++) {
        uint8_t a = pgm_read_byte(&cube_e[i][0]);
        uint8_t b = pgm_read_byte(&cube_e[i][1]);
        cube_draw_line(px[a], py[a], px[b], py[b]);
    }
}

bool oled_task_user(void) {
    if (!is_keyboard_master()) return true; // el lado esclavo muestra el logo por defecto

    static uint16_t anim_timer = 0;
    uint8_t         layer      = get_highest_layer(layer_state);

    // Actualizar ángulo según la capa (cada 30ms ≈ ~1 vuelta cada 2s)
    if (timer_elapsed(anim_timer) > 30) {
        anim_timer = timer_read();
        if (layer == _LOWER) {
            cube_angle = (cube_angle + 1) & 63;
        } else if (layer == _RAISE) {
            cube_angle = (cube_angle - 1) & 63;
        }
        // _QWERTY / _ADJUST: cubo quieto
    }

    oled_clear();
    render_cube();

    // Indicador de capa en la parte inferior
    oled_set_cursor(0, 11);
    switch (layer) {
        case _QWERTY:
            oled_write_P(PSTR("BASE"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOW <"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RSE>"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJ "), false);
            break;
        default:
            oled_write_P(PSTR("??? "), false);
            break;
    }

    return false;
}

#endif
