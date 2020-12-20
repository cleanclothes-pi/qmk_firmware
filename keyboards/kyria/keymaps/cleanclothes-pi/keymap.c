/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

typedef union {
    uint32_t raw;
    struct {
        bool osIsWindows;
    };
} user_config_t;

user_config_t user_config;

/* --------- DEFINE CUSTOM KEY CODE --------------------------- */

#define ____ KC_TRNS
#define XXXX KC_NO

#define KC_PAST KC_KP_ASTERISK
#define Key_Y KC_Y
#define OneSFT OSM(MOD_LSFT)

// Define Left Thumb keys L + [TopLeft,TopRight,BottomLeft,BottomRight]
#define ThL_TI TD(LGC)
#define ThL_TO OSL(_EDIT)
#define ThL_BI LT(_NN, KC_SPC)
#define ThL_BO OSL(_SYMB)
// Define Right Thumb keys R + [TopLeft,TopRight,BottomLeft,BottomRight]
#define ThR_TO OSL(_ADJ)
#define ThR_TI TD(RCG)
#define ThR_BO OSL(_SYMB)
#define ThR_BI LT(_NN, KC_ENT)

#define MS_BSPC LT(_MS, KC_BSPC)
#define MS_DEL LT(_MS, KC_DEL)
#define MS_TAB LT(_MS, KC_TAB)

// Homerow modifiers
// Right hand
#define HOME_T LCTL_T(KC_T)
#define HOME_S LSFT_T(KC_S)
#define HOME_R LGUI_T(KC_R)
#define HOME_A LALT_T(KC_A)
// Left hand
#define HOME_N LCTL_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LGUI_T(KC_I)
#define HOME_O LALT_T(KC_O)

#define NN_COMMA LT(_NN,KC_COMMA)
#define SYMB_G LT(_SYMB,KC_G)
#define SYMB_M LT(_SYMB,KC_M)

// THAI LAYER HOME ROW
    // left hand
#define TH_HOME_F LT(_THCOMMON, KC_F)
#define TH_HOME_D LSFT_T(KC_D)
#define TH_HOME_S LT(_THUP, KC_S)
    // right hand
#define TH_HOME_J LT(_THCOMMON, KC_J)
#define TH_HOME_K LSFT_T(KC_K)
#define TH_HOME_L LT(_THUP, KC_L)

// Words
#define PrvWd LCTL(KC_LEFT)
#define NxtWd LCTL(KC_RIGHT)
#define TopPG LCTL(KC_HOME)
#define BtmPG LCTL(KC_END)
#define DelPWord LCTL(KC_BSPC)
#define DelNWord LCTL(KC_DEL)

// WSPC Windows Manager Workspaces switching
#define WSP_1 LGUI(KC_1)
#define WSP_2 LGUI(KC_2)
#define WSP_3 LGUI(KC_3)
#define WSP_4 LGUI(KC_4)
#define WSP_5 LGUI(KC_5)   //changed to custom keycode
#define WSP_6 LGUI(KC_6)   //changed to custom keycode
#define WSP_7 LGUI(KC_7)   //changed to custom keycode

#define WSP_QUIT LGUI(KC_Q)
#define WSP_TAB LGUI(KC_TAB)
#define WSP_LAY LGUI(KC_SPACE)

// Tiling window manager
#define FOCUP G(KC_K)
#define FOCDN G(KC_J)
#define MV_MSTR G(S(KC_ENT))
#define SHRINKM LGUI(KC_H)  // Shrink size of master
#define EXPANDM LGUI(KC_L)  // Expand size of master

// TAP DNACE
#define CAPS_Y TD(TD_CAPS_Y)
#define LT_PRN TD(LT_LPRN)
#define GT_PRN TD(GT_RPRN)
#define LT_GT TD(TD_LT_GT)
    
/* --------- ENUMERATE ---------------------------------------- */
enum layers {
    _CLMK = 0,
    _QWERTY,
    _TH,
    _THUP,
    _THCOMMON,
    _NN,
    _WM,
    _SYMB,
    _ADJ,
    _MS,
    _EDIT
};

enum custom_keycodes {
    OSSwitch = SAFE_RANGE,
    Altwind,
    WorkspcLeft5,
    WorkspcRight6,
    AltWkspc,
    Chlang,
    Chinput,
    // Thai words macros
    thKan,
    thKwam,
    thKrub,
    thLAE,
    thKEU,
    thJAK,
    thKONG,
    thCHEN,
    thTAA,
    thTAE,
    thREU,
    thPRAU,
    thDANGNAN,
    thDAI,
    thMAI,
    thYANGRAI,
    thARAI,
    thNNGJAK,
    thPEN,
    thNUNNUN,
    thWAA,
    thPENTON,
    thTONG,
    thLAEW,
    thYRKT,
    thKLAOKEU,
    thKUAN,
    thMYNAME,
    thAJAN,
    thEEA
};


// ============= TAP DANCE =================//
// Tap Dance declaration
enum {
    TD_QUOT_DEL,
    ESCAP,
    TD_CAPS_Y,

    LGC,            // THUMB KEYS
    RCG,

    //Number Layer
    LT_LPRN,
    GT_RPRN,
    TD_LT_GT,
    MNS_PER,
    DOT_COMM,
    // Advance TD keycodes
};

// Tap Dance definition
qk_tap_dance_action_t tap_dance_actions[] = {
    // SIDE COLUMNS
    [ESCAP] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPSLOCK),
    [TD_QUOT_DEL] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DEL),
    [TD_CAPS_Y] = ACTION_TAP_DANCE_DOUBLE(KC_CAPSLOCK, KC_Y),

    // Double tap top row letters for enclosing
    [LGC] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LCTL),
    [RCG] = ACTION_TAP_DANCE_DOUBLE(KC_RCTL, KC_RGUI),

    [LT_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_LPRN),
    [GT_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_GT, KC_RPRN),
    [TD_LT_GT] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
    [MNS_PER] = ACTION_TAP_DANCE_DOUBLE(KC_PMNS, KC_PERC),
    [DOT_COMM] = ACTION_TAP_DANCE_DOUBLE(KC_PDOT, KC_COMM),
};

// ============= COMBO =================//
enum combo_events {
    XD_COPY,
    XC_CUT,
    XV_COPY,
    CV_PASTE,
    CD_PASTE,
    ZX_UNDO,
    CZ_REDO,
    FP_ENT,
    WF_BSPC,
    YU_DEL
};

const uint16_t PROGMEM qcopy_combo[]    = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM qpaste_combo[]   = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM lcopy_combo[]    = {KC_X, KC_D, COMBO_END};
const uint16_t PROGMEM lcut_combo[]     = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM lpaste_combo[]   = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM undo_combo[]     = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM redo_combo[]     = {KC_C, KC_Z, COMBO_END};
const uint16_t PROGMEM lent_combo[]     = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM lbspc_combo[]     = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM rdel_combo[]     = {KC_Y, KC_U, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    // Qwerty layout
    [XV_COPY] = COMBO_ACTION(qcopy_combo),
    [CV_PASTE] = COMBO_ACTION(qpaste_combo),
    // Colemak layout left hand
    [XD_COPY] = COMBO_ACTION(lcopy_combo),
    [XC_CUT] = COMBO_ACTION(lcut_combo),
    [CD_PASTE] = COMBO_ACTION(lpaste_combo),
    // Colemak & Qwerty, left hand
    [ZX_UNDO] = COMBO_ACTION(undo_combo),
    [CZ_REDO] = COMBO_ACTION(redo_combo),
    [FP_ENT] = COMBO_ACTION(lent_combo),
    [WF_BSPC] = COMBO_ACTION(lbspc_combo),
    [YU_DEL] = COMBO_ACTION(rdel_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) {
        case XV_COPY:
            if (pressed) {
                tap_code16(LCTL(KC_C));
            }
            break;
        case CV_PASTE:
            if (pressed) {
                tap_code16(LCTL(KC_V));
            }
            break;
        case XD_COPY:
            if (pressed) {
                tap_code16(LCTL(KC_C));
            }
            break;
        case XC_CUT:
            if (pressed) {
                tap_code16(LCTL(KC_X));
            }
            break;
        case CD_PASTE:
            if (pressed) {
                tap_code16(LCTL(KC_V));
            }
            break;
        case ZX_UNDO:
            if (pressed) {
                tap_code16(LCTL(KC_Z));
            }
            break;
        case CZ_REDO:
            if (pressed) {
                tap_code16(LCTL(KC_Y));
            }
            break;
        case FP_ENT:
            if (pressed) {
                tap_code(KC_ENT);
            }
            break;
        case WF_BSPC:
            if (pressed) {
                tap_code(KC_BSPC);
            }
            break;
        case YU_DEL:
            if (pressed) {
                tap_code(KC_DEL);
            }
            break;
    }
};

// ============= TAPPING PER KEY=================//

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // left hand homerow
        case HOME_T:
            return TAPPING_TERM + 15;
        case HOME_S:
            return TAPPING_TERM - 20;
        case HOME_R:
            return TAPPING_TERM + 80;
        case HOME_A:
            return TAPPING_TERM + 80;
        // right hand homerow
        case HOME_N:
            return TAPPING_TERM - 10;
        case HOME_E:
            return TAPPING_TERM - 20;
        case HOME_I:
            return TAPPING_TERM + 70;
        case HOME_O:
            return TAPPING_TERM + 85;

        default:
            return TAPPING_TERM;
    }
};


/* ============================================================ */
/* LAYOUTS */
/* ============================================================ */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


// Base layer [0]: COLMAKDHM
	[_CLMK] = LAYOUT(
    //+--------+--------+--------+--------+--------+--------\                                                /--------+--------+--------+--------+--------+--------+
       CAPS_Y,  KC_Q  ,  KC_W  ,  KC_F  ,  KC_P  ,  KC_B  ,                                                   KC_J  ,  KC_L  ,  KC_U  ,  KC_Y  , KC_SCLN, KC_MINS,
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
       KC_ESC  , HOME_A , HOME_R , HOME_S , HOME_T , SYMB_G ,                                                  SYMB_M , HOME_N ,  HOME_E, HOME_I , HOME_O , KC_QUOT,
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
        OneSFT ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_D  ,  KC_V  , ThL_TI , ThL_TO ,              ThR_TO , ThR_TI ,  KC_K  ,  KC_H  ,NN_COMMA, KC_DOT , KC_SLSH, KC_EXLM ,        
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
                                  XXXX ,OSL(_MS),LT(_WM,KC_TAB),ThL_BI,ThL_BO ,              ThR_BO , ThR_BI , MS_BSPC, MS_DEL , Chlang 
    //                           \--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------/
    ),

/* ---------------------------------------------------------------------------- */
//  Base Layer [1]: THAI 
	[_TH] = LAYOUT(
         ____, 	KC_L,	KC_S,	KC_U,	KC_P,	KC_0,					 		                        KC_B,	KC_COMMA,KC_RBRC,	    KC_X,	KC_W,	    S(KC_W),
        KC_ESC,	KC_QUOT,KC_G,LT(_THUP,KC_D),KC_O,KC_F,				 		                            KC_H,	KC_K,	LT(_THUP,KC_J),	KC_I,	KC_SCLN,	KC_LBRC,
        OneSFT,	KC_C,	KC_T,	KC_Y,	    KC_8,	S(KC_H),ThL_TI,	ThL_TO,			ThR_TO , ThR_TI ,	KC_9,	KC_M,	KC_V,	        KC_N,	KC_MINS,	S(KC_N),
		                XXXX,	OSL(_MS), LT(_WM,KC_TAB),   ThL_BI,	ThL_BO,	        ThR_BO , ThR_BI ,	MS_BSPC,MS_DEL, Chlang	
    ),
    [_THUP] = LAYOUT(
        ____  , S(KC_A),KC_Q,	S(KC_F),  S(KC_K),  S(KC_E),                                        S(KC_LBRC),	KC_5,	    KC_4,	    S(KC_COMMA),S(KC_U),	S(KC_DOT),
        ____  , KC_R,	KC_DOT,	KC_EQUAL, S(KC_6),  S(KC_D),                                        S(KC_N),	KC_6,	    KC_7,	    KC_E,	    S(KC_I),	S(KC_S),
        ____  , KC_A,	S(KC_R),KC_Z,	  S(KC_P),  S(KC_C), ____,	____,	        ____,	____,	KC_SLSH,	S(KC_L),	S(KC_SCLN),	S(KC_T),	S(KC_J),	S(KC_G),
                                XXXX,	  ____,	    ____,	 ____,	____,	        ____,	____,	____,	____,	TO(_CLMK)
    ),
    [_THCOMMON] = LAYOUT(
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
         XXXX  ,  XXXX  ,  XXXX  , thKan  , thTAA  , thAJAN ,                                                   XXXX  , thKrub , thKwam , thCHEN ,  XXXX  ,  XXXX  , 
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
       thMYNAME, thLAEW , thREU  , thLAE  ,  thTAE ,thYANGRAI,                                                 thARAI , thPEN  , thDAI  , thMAI  , thWAA  ,  XXXX  ,
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
        XXXX  , thDANGNAN , thYRKT , thPRAU ,thNNGJAK, XXXX ,  XXXX  ,  XXXX  ,               XXXX  ,  XXXX  ,  XXXX  ,thNUNNUN, thKUAN , thPENTON, XXXX  ,  XXXX  ,
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
                                    XXXX  ,  XXXX  ,  XXXX  ,  XXXX  ,  XXXX  ,               XXXX  ,  XXXX  ,  XXXX  ,  XXXX  , TO(_CLMK)
    //                           \--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+

    ),

/* ---------------------------------------------------------------------------- */
//  Layer [3]: NUMBER AND NAVIGATION
    [_NN] = LAYOUT(

    //+--------+--------+--------+--------+--------+--------\                                                /--------+--------+--------+--------+--------+-------\*
       KC_PAST , KC_EQL ,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PPLS,                                                  TopPG  ,  PrvWd , KC_PGDN, KC_PGUP, NxtWd  ,  ____  ,  
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
        PrvWd ,TD(DOT_COMM),KC_P4,  KC_P5 ,  KC_P6 , KC_P0  ,                                                  BtmPG  , KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT,  NxtWd ,
    //+--------+--------+--------+--------+--------+--------+-----------+--------+        +--------+---------+--------+--------+--------+--------+--------+--------+
      DelPWord , LT_GT ,  KC_P7 ,  KC_P8 ,  KC_P9 ,TD(MNS_PER), ThL_TI , ThL_TO ,           ThR_TO ,  ThR_TI ,  ____  ,  ____  ,  ____  ,  ____  ,  NxtWd ,  DelNWord, 
    //+--------+--------+--------+--------+--------+--------+-----------+--------+        +--------+---------+--------+--------+--------+--------+--------+--------"
                                    XXXX  ,  ____  ,  ____  ,   ThL_BI , ThL_BO ,           ThR_BO , ThR_BI  , OneSFT ,  ____  , TO(_CLMK) 
    //                           \--------+--------+--------+-----------+--------+        +--------+---------+--------+--------+--------+
    ),                                                                                              

/* ---------------------------------------------------------------------------- */
//  Layer [4]: WINDOW MANAGER
	[_WM] = LAYOUT(   
    //+--------+--------+--------+--------+--------+--------\                                                /--------+--------+--------+--------+--------+-------\*
      AltWkspc ,WSP_QUIT,  WSP_1 ,  WSP_2 ,  WSP_3 ,  ____  ,                                                   ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  , 
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
      Altwind  ,  ____  ,  WSP_4 ,  WSP_5 ,  WSP_6 ,  ____  ,                                                   ____  , SHRINKM,  FOCDN , FOCUP  , EXPANDM,  ____  , 
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
       OneSFT  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,               ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  , 
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------"
                                    XXXX  ,  ____  ,  ____  ,  ____  ,  ____  ,              WSP_LAY, MV_MSTR,  ____  ,  ____  ,TO(_CLMK)
    //                           \--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+
    ),

/* ---------------------------------------------------------------------------- */
//  Layer [5]:SYMBOLS LAYER
    [_SYMB] = LAYOUT(
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+-------\*
        ____   , KC_HASH, KC_EXLM, KC_DLR , KC_TILD, KC_CIRC,                                                 KC_PERC , KC_PIPE,  KC_AT , KC_AMPR, KC_GRV ,  ____  , 
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
        PrvWd  ,  LT_GT , KC_LPRN, KC_LCBR, KC_LBRC, KC_EQL,                                                 KC_BSLS , KC_RBRC, KC_RCBR, KC_RPRN,  KC_GT ,  NxtWd ,
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
      DelPWord , KC_HOME, PrvWd  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,               ____  ,  ____  ,  ____  ,  ____  ,  ____  , NxtWd  , KC_END , DelNWord, 
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
                                    ____  ,  ____  ,  ____  ,  ____  ,  ____  ,               ____  ,  ____  ,G(KC_BSLS), Chinput, TG(_TH)
    //                           \--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+
    ),

/* ---------------------------------------------------------------------------- */
//  Layer [6]:ADJUST
    [_ADJ] = LAYOUT( 
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
     G(S(KC_Q)), KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_APP ,                                                 KC_PSCR , KC_PSCR, KC_BRID, KC_BRIU,  ____  , KC_SLEP,
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
         ____  , KC_F11 , KC_F4  , KC_F5  , KC_F6  ,  ____  ,                                                   ____  , KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_WAKE,
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
         ____  , KC_F12 , KC_F7  , KC_F8  , KC_F9  ,  ____  ,  ____  ,  ____  ,               ____  ,  ____  ,  ____  , KC_MPLY, KC_MSTP, KC_MUTE,  ____  , OSSwitch,
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
                                    ____  ,  ____  ,  ____  ,  ____  ,  ____  ,               ____  ,  ____  ,  ____  ,  ____  , TO(_CLMK)
    //                           \--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+
    ),


/* ---------------------------------------------------------------------------- */
//  Layer [7]:MOUSE
    [_MS] = LAYOUT(
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
         ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,                                                   ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  , 
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
         ____  , KC_BTN1, KC_BTN2, KC_BTN3,  ____  ,  ____  ,                                                   ____  ,KC_MS_L, KC_MS_D , KC_MS_U, KC_MS_R,  ____  ,
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
         ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,               ____  ,  ____  ,  ____  ,KC_WH_L ,KC_WH_D , KC_WH_U, KC_WH_R,  ____  ,
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
                                    ____  ,  ____  , KC_BTN2, KC_BTN1, KC_BTN3,              KC_BTN3, KC_BTN1, KC_BTN2,  ____  , TO(_CLMK)
    //                           \--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+
    ),
/* ---------------------------------------------------------------------------- */
//  Layer [8]:TEXT EDITOR
    [_EDIT] = LAYOUT(
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
         ____  , C(KC_J), C(KC_L), C(KC_E), C(KC_R), KC_APP ,                                                   ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,
    //+--------+--------+--------+--------+--------+--------+                                                +--------+--------+--------+--------+--------+--------+
         ____  , C(KC_S), C(KC_U), C(KC_I), C(KC_B), KC_F2  ,                                                   ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  , 
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
         ____  , C(KC_1), C(KC_2), C(KC_3), C(KC_4),  ____  ,  ____  ,  ____  ,               ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,  ____  ,
    //+--------+--------+--------+--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+--------+--------+--------+
                                    ____  ,  ____  ,  ____  ,  ____  ,  ____  ,               ____  ,  ____  ,  ____  ,  ____  , TO(_CLMK)
    //                           \--------+--------+--------+--------+--------+            +--------+--------+--------+--------+--------+
    ),
};

/* ============================================================ */
/* OTHER FEATURES */
/* ============================================================ */

void keyboard_post_init_user(void) {
    // Call the post init code.

    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
}

/*========================== MACROS (as per OS) ==========================*/

// Initialize variable holding the binary representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch(keycode) {
        case OSSwitch:
            if (record->event.pressed){
                if (user_config.osIsWindows == 1) {
                    user_config.osIsWindows = false;
                    eeconfig_update_user(user_config.raw);
                } else {
                    user_config.osIsWindows = true;
                    eeconfig_update_user(user_config.raw);
                }
            }
        case Altwind:
            if (record->event.pressed) {
                if (user_config.osIsWindows == 1) {
                    tap_code16(LALT(KC_TAB));
                } else if (user_config.osIsWindows == 0) {
                    tap_code16(LGUI(KC_TAB));
                }
            }
            break;
        case AltWkspc:
            if (record->event.pressed) {
                if (user_config.osIsWindows == 1) {
                    tap_code16(LGUI(KC_TAB));
                } else if (user_config.osIsWindows == 0) {
                    tap_code16(LGUI(KC_ESC));
                }
            }
            break;
        case Chlang:
            if (record->event.pressed) {
                if (user_config.osIsWindows == 1) {
                    /* tap_code16(A(KC_LSFT)); */
                    SEND_STRING( SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_UP(X_LSFT) SS_UP(X_LALT) );
                    layer_invert(_TH);
                } else if (user_config.osIsWindows == 0) {
                    tap_code16(G(KC_BSLS));
                    SEND_STRING( SS_DELAY(320) );
                    SEND_STRING( SS_DOWN(X_RCTL) SS_DOWN(X_LCTL) SS_UP(X_RCTL) SS_UP(X_LCTL) );
                    layer_invert(_TH);
                }
            }
            break;
        case Chinput:
            if (record->event.pressed) {
                if (user_config.osIsWindows == 1) {
                    /* tap_code16(A(KC_LSFT)); */
                    SEND_STRING( SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_DELAY(100) SS_UP(X_LSFT) SS_UP(X_LALT) );
                } else if (user_config.osIsWindows == 0) {
                    SEND_STRING( SS_DOWN(X_RCTL) SS_DOWN(X_LCTL) SS_UP(X_RCTL) SS_UP(X_LCTL) );
                }
            }

        // THAI WORDS MACROs
        case thKan:
            if (record->event.pressed) { SEND_STRING("dki"); } else {}      break; //การ
        case thKwam:
            if (record->event.pressed) { SEND_STRING("8;k,"); } else {}     break; //ความ
        case thKrub:
            if (record->event.pressed) { SEND_STRING("8iy["); } else {}     break; //ครับ
        case thLAE:
            if (record->event.pressed) { SEND_STRING("c]t"); } else {}     break; //และ
        case thKEU:
            if (record->event.pressed) { SEND_STRING("8nv"); } else {}     break; //คือ
        case thJAK:
            if (record->event.pressed) { SEND_STRING("0kd"); } else {}     break; //จาก
        case thKONG:
            if (record->event.pressed) { SEND_STRING("-v'"); } else {}     break; //ของ
        case thCHEN:
            if (record->event.pressed) { SEND_STRING("g=jo"); } else {}     break; //เช่น
        case thTAA:
            if (record->event.pressed) { SEND_STRING("5hk"); } else {}     break; //ถ้า
        case thTAE:
            if (record->event.pressed) { SEND_STRING("c9j"); } else {}     break; //แต่
        case thREU:
            if (record->event.pressed) { SEND_STRING("sinv"); } else {}     break; //หรือ
        case thPRAU:
            if (record->event.pressed) { SEND_STRING("grikt"); } else {}     break; //เพราะ
        case thDANGNAN:
            if (record->event.pressed) { SEND_STRING("fy'oyho"); } else {}     break; //ดังนั้น
        case thDAI:
            if (record->event.pressed) { SEND_STRING("wfh"); } else {}     break; //ได้
        case thMAI:
            if (record->event.pressed) { SEND_STRING("w,j"); } else {}     break; //ไม่
        case thYANGRAI:
            if (record->event.pressed) { SEND_STRING("vpjk'wi"); } else {}     break; //อย่างไร
        case thARAI:
            if (record->event.pressed) { SEND_STRING("vtwi"); } else {}     break; //อะไร
        case thNNGJAK:
            if (record->event.pressed) { SEND_STRING("gonjv'0kd"); } else {}     break; //จาก
        case thPEN:
            if (record->event.pressed) { SEND_STRING("gxHo"); } else {}     break; //เป็น
        case thNUNNUN:
            if (record->event.pressed) { SEND_STRING("oyhoq"); } else {}     break; //นั้นๆ
        case thWAA:
            if (record->event.pressed) { SEND_STRING(";jk"); } else {}     break; //ว่า
        case thPENTON:
            if (record->event.pressed) { SEND_STRING("gxHo9ho"); } else {}     break; //เป็นต้น
        case thTONG:
            if (record->event.pressed) { SEND_STRING("9hv'"); } else {}     break; //ต้อง
        case thLAEW:
            if (record->event.pressed) { SEND_STRING("cc]h;"); } else {}     break; //แล้ว
        case thYRKT: 
            if (record->event.pressed) { SEND_STRING("vpjk'widH9k,"); } else {}     break; //อย่างไรก็ตาม
        case thKLAOKEU: 
            if (record->event.pressed) { SEND_STRING("d]jk;8nv"); } else {}     break; //กล่าคือ
        case thKUAN: 
            if (record->event.pressed) { SEND_STRING("8;i"); } else {}     break; //ควร
        case thMYNAME: 
            if (record->event.pressed) { SEND_STRING("4u vk4iINgvujp,"); } else {}     break; // ภี อาภรณ์เอี่ยม
        case thAJAN: 
            if (record->event.pressed) { SEND_STRING("vk0kipN"); } else {}     break; // อาจารย์
        case thEEA: // สระเอีย
            if (record->event.pressed) { SEND_STRING("g"); } else { SEND_STRING("up"); } break;


    /* ========= HOMEROW MODIFIER SETUP ====================*/
        // Source: https://github.com/precondition/qmk_firmware/blob/user-precondition/keyboards/handwired/dactyl_manuform/5x6/keymaps/precondition/keymap.c
        case HOME_I:
            // This piece of code nullifies the effect of Right Shift when
            // tapping the HOME_I key. This helps rolling over HOME_E and HOME_I 
            // to obtain the intended "ei" instead of "I". Consequently, capital I can 
            // only be obtained by tapping HOME_I and holding HOME_S (which is the left shift mod tap).
            if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
                if (mod_state & MOD_BIT(KC_RSHIFT)) {
                    unregister_code(KC_RSHIFT);
                    tap_code(KC_E);
                    tap_code(KC_I);
                    set_mods(mod_state);
                    return false;
                } 
            }
            // else process HOME_I as usual.
            return true;

        case HOME_N:
            /* This piece of code nullifies the effect of Right Shift when */
            /* tapping the HOME_N key. This helps rolling over HOME_E and HOME_N */ 
            /* to obtain the intended "en" instead of "N". Consequently, capital N can */ 
            /* only be obtained by tapping HOME_N and holding HOME_S (which is the left shift mod tap). */
            if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) {
                if (mod_state & MOD_BIT(KC_RSHIFT)) {
                    unregister_code(KC_RSHIFT);
                    tap_code(KC_E);
                    tap_code(KC_N);
                    set_mods(mod_state);
                    return false;
                }
            }
            // else process HOME_N as usual.
            return true;

     /* // my own config, but donsn't work */
    /*     case KC_Y: */
    /*         if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) { */
    /*             if (mod_state & MOD_BIT(KC_RSHIFT)) {  // same effect but for 'ey' in succession, e.g. typing "they" */
    /*                 unregister_code(KC_RSHIFT); */
    /*                 tap_code(KC_E); */
    /*                 tap_code(KC_Y); */
    /*                 set_mods(mod_state); */
    /*                 return false; */
    /*             } */
    /*         } */
    /*         // else process KC_Y as usual. */ 
    /*         return true; */

    /*     case HOME_O: */
    /*         if (record->event.pressed && record->tap.count == 1 && !record->tap.interrupted) { */
    /*             if (mod_state & MOD_BIT(KC_LALT)){  // same effect but for 'io' in succession */
    /*                 unregister_code(KC_LALT); */
    /*                 tap_code(KC_I); */
    /*                 tap_code(KC_O); */
    /*                 set_mods(mod_state); */
    /*                 return false; */
    /*             } */
    /*         } */
    /*         // else process KC_O as usual. */ 
    /*         return true; */

        }
    return true;
};

/*========================== OLED DISPLAY=============================*/

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
    static const char PROGMEM qmk_logo[] = {
      0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
      0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
      0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("CustomThai v1\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _CLMK:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case _TH:
            oled_write_P(PSTR("Thai\n"), false);
            break;
        case _THUP:
            oled_write_P(PSTR("Thai Up\n"), false);
            break;
        case _NN:
            oled_write_P(PSTR("Nav&Numbers\n"), false);
            break;
        case _ADJ:
            oled_write_P(PSTR("Adjust\n"), false);
            break;
        case _SYMB:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _WM:
            oled_write_P(PSTR("Tiling\n"), false);
            break;
        case _MS:
            oled_write_P(PSTR("Mouse\n"), false);
            break;
        case _EDIT:
            oled_write_P(PSTR("Edit\n"), false);
            break;

        default:
            oled_write_P(PSTR("Undefined\n"), false);
            break;
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

/*========================== ROTARY ENCODER ==========================*/

// Doc for further detail: 
// https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder-

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_CLMK)) {       // Scroll Up-Down
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    else if (IS_LAYER_ON(_QWERTY)) {    // Scroll Up-Down
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
    else if (IS_LAYER_ON(_SYMB)) {    // History scrubbing
        if (clockwise) {
            tap_code16(C(KC_Y));
        } else {
            tap_code16(C(KC_Z));
        }
    }
    else if (IS_LAYER_ON(_NN)) {  // Jump one word at a time
        if (clockwise) {
            tap_code16(C(KC_RIGHT));
        } else {
            tap_code16(C(KC_LEFT));
        }
    }
    else if (IS_LAYER_ON(_ADJ)) {  // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}
#endif
