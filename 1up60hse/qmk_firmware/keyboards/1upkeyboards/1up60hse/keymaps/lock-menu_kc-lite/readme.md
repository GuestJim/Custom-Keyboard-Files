# 1up60hse keymap with KC_LOCK, Lighting Layers, Menu key, OBS hotkeys

KC_LOCK enabled in rules.mk and placed on Layer 3, Right Shift

Lighting Layers enabled with override

	Layer 1, Layer 2, Layer 3, and Caps Lock all have lighting layers
	
Menu (KC_APP) key returned to right-bottom row, moving over MO(1) key on Layer 0 and MO(2) on Layer 1

	Also, MO(1) changed to TT(1), which acts like MO(1) when held, but will toggle layer 1 by tapping the key
	
		TAPPING_TOGGLE changed from default of 5 to 2 for this in config.h
		
	Menu key changed to LT(1, KC_APP) so when tapped is Menu key, but when held acts as MO(1)
	
OBS Studio hotkeys for start/stop recordings (Alt + F9 with RALT(KC_F9)) and saving replay buffer (Alt + F10 with RALT(KC_F10)) placed on Layer 3

	RALT(KC_F9) and RALT(KC_F10) assigned to OBS_REC and OBS_BUF objects for clear labeling