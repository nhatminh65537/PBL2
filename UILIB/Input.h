#ifndef __INPUT__
#define __INPUT__

enum KeyCode {
    KEY_UP = 328,
    KEY_DOWN = 336,
    KEY_LEFT = 331,
    KEY_RIGHT = 333,
    KEY_HOME = 327,
    KEY_END = 335,
    KEY_PGUP = 329,
    KEY_PGDN = 337,
    KEY_DEL = 339,
    KEY_INS = 338,
    KEY_F1 = 344,
    KEY_F2 = 345,
    KEY_F3 = 346,
    KEY_F4 = 347,
    KEY_F5 = 348,
    KEY_F6 = 349,
    KEY_F7 = 350,
    KEY_F8 = 351,
    KEY_F9 = 352,
    KEY_F10 = 353,
    KEY_BACKSPACE = 8,
    KEY_RETURN = 13,
    KEY_TAB = 9,
    KEY_ESC = 27,
    KEY_CTRL_A = 1,
    KEY_CTRL_B = 2,
    KEY_CTRL_C = 3,
    KEY_CTRL_D = 4,
    KEY_CTRL_E = 5,
    KEY_CTRL_F = 6,
    KEY_CTRL_G = 7,
    KEY_CTRL_H = 8,
    KEY_CTRL_I = 9,
    KEY_CTRL_J = 10,
    KEY_CTRL_K = 11,
    KEY_CTRL_L = 12,
    KEY_CTRL_M = 13,
    KEY_CTRL_N = 14,
    KEY_CTRL_O = 15,
    KEY_CTRL_P = 16,
    KEY_CTRL_Q = 17,
    KEY_CTRL_R = 18,
    KEY_CTRL_S = 19,
    KEY_CTRL_T = 20,
    KEY_CTRL_U = 21,
    KEY_CTRL_V = 22,
    KEY_CTRL_W = 23,
    KEY_CTRL_X = 24,
    KEY_CTRL_Y = 25,
    KEY_CTRL_Z = 26,
};

unsigned getKey();

#endif