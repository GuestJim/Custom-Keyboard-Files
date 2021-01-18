#include QMK_KEYBOARD_H

#define OBS_REC RALT(KC_F9)
//	Alt + F9	OBS Studio start and stop recording hotkey
#define OBS_BUF RALT(KC_F10)
//	Alt + F10	OBS Studio replay buffer save
#define OBS_MUT	RSFT(KC_PAUS)

	/* RGB LEDs
	*	,-------------------.
	*	|	0	1	2	3	|
	*	|					|
	*	|	7	6	5	4	|
	*	|					|
	*	|	8	9	10	11	|
	*	|					|
	*	|	15	14	13	12	|
	*	 `------------------'
	*/


const rgblight_segment_t PROGMEM layer_nav_sym[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN},	//	Nav
    {5, 3, HSV_GREEN},	//	Nav
    {14, 1, HSV_GREEN},	//	Nav
    {3, 2, HSV_RED},	//	Sym
    {11, 2, HSV_RED},	//	Sym
    {13, 1, HSV_CYAN}	//	Layer
	// {15, 1, HSV_WHITE}	//	Reset
);

const rgblight_segment_t PROGMEM lock_num[] = RGBLIGHT_LAYER_SEGMENTS(
	{15, 1, HSV_MAGENTA}	//	Num Lock
);

const rgblight_segment_t PROGMEM layer_review[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 2, HSV_ORANGE},	//	Mouse
	{7, 2, HSV_ORANGE},	//	KC_Lock and Space
	{3, 2, HSV_RED},	//	Review
    {10, 3, HSV_RED},	//	Review
    {12, 1, HSV_RED},	//	Review
    {13, 3, HSV_CYAN}	//	Layer
);

const rgblight_segment_t PROGMEM layer_ahk[] = RGBLIGHT_LAYER_SEGMENTS(
	{0, 2, HSV_PINK},		//	Macros
	{7, 1, HSV_PURPLE},		//	Script Kill
	{14, 1, HSV_YELLOW},	//	Shift
	{13, 1, HSV_MAGENTA},	//	Control
	{12, 1, HSV_CYAN},		//	Alt
	{15, 1, HSV_RED},		//	Layer
	{2, 5, HSV_OFF},		//	Off to disable Review Layer lighting
	{8, 4, HSV_OFF}			//	Off to disable Review Layer lighting
);

const rgblight_segment_t PROGMEM layer_rgb[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 2, HSV_WHITE},		//	Brightness
    {2, 1, HSV_BLUE},		//	Hue
    {5, 1, HSV_BLUE},		//	Hue
    {1, 1, HSV_GREEN},		//	Speed
    {6, 1, HSV_GREEN},		//	Speed
    {0, 1, HSV_RED},		//	Effect
    {7, 1, HSV_RED},		//	Effect
    {15, 1, HSV_RED},		//	Effect (Toggle)
    {10, 1, HSV_ORANGE},	//	Saturation
    {13, 1, HSV_ORANGE},	//	Saturation
    {8, 1, HSV_WHITE},		//	Reset
    {14, 1, HSV_CYAN}		//	Layer
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	lock_num,			//	0
	layer_nav_sym,		//	1
	layer_review,		//	2
	layer_rgb,			//	3
	layer_ahk			//	4
);

void keyboard_post_init_user(void) {
//    Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	//	first number is lighting layer (as shown above)
	//	second number is the keymap layer number
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, !led_state.num_lock);
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //	Number Pad
	[0] = LAYOUT_ortho_4x4(
        KC_P7,		KC_P8,		KC_P9,		KC_PSLS,
        KC_P4,		KC_P5,		KC_P6,		KC_PAST,
        KC_P1,		KC_P2,		KC_P3,		KC_PMNS,
        KC_P0,		OSL(1),		KC_PDOT,	KC_PPLS
    ),

	//	Navigation and Symbols
    [1] = LAYOUT_ortho_4x4(
        KC_INS,		KC_HOME,	KC_PGUP,	KC_HASH,
        KC_DEL,		KC_END,		KC_PGDN,	KC_DLR,
        KC_NO,		KC_NO,		KC_NO,		KC_PERC,
        KC_NLCK,	KC_PENT,	TG(2),		KC_AMPR
    ),

	//	Review Macros
    [2] = LAYOUT_ortho_4x4(
        KC_BTN1,	KC_BTN2,	KC_NO,		KC_F12,
        KC_LOCK,	KC_SPC,		KC_NO,		OBS_BUF,
        KC_NO,		KC_NO,		OBS_MUT,	KC_PSCR,
        TT(4),		MO(3),		TG(2),		OBS_REC
    ),

	//	RGB Controls
    [3] = LAYOUT_ortho_4x4(
        RGB_MOD,	RGB_SPI,	RGB_HUI,	RGB_VAI,
        RGB_RMOD,	RGB_SPD,	RGB_HUD,	RGB_VAD,
        RESET,		KC_NO,		RGB_SAI,	KC_NO,
        RGB_TOG,	KC_TRNS,	RGB_SAD,	KC_NO
    ),

	//	AHK Macros through F13-F24 with OSM Modifiers
    [4] = LAYOUT_ortho_4x4(
        KC_F13,		KC_F14,		KC_F15,		KC_F16,
        KC_F17,		KC_F18,		KC_F19,		KC_F20,
        KC_F21,		KC_F22,		KC_F23,		KC_F24,
        KC_TRNS,	OSM(MOD_RSFT),	OSM(MOD_RCTL),	OSM(MOD_RALT)
    ),

    [5] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [6] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [7] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [8] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [9] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [10] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [11] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [12] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [13] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [14] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

    [15] = LAYOUT_ortho_4x4(
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,
        KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
    ),

};


