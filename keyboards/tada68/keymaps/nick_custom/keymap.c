#include "tada68.h"
#include "action_layer.h"

// Custom keymap for Nicholas's TADA68. Currently trying to replicate keymap that has been done by flash application online

//#define LEADER_TIMEOUT 300

#define _WL 0 //Windows Layer
#define _LL 1 //Linux Layer
#define _GL 2 //Gaming Layer
#define _WU 3 //Windows Utility Layer
#define _LU 4 //Unix Utility Layer
#define _NP 5 //NumPad Layer
#define _EL 6 //Emoji_Linux Layer
#define _EW 7 //Emoji_Windows Layer
#define _SW 8 //Switch Layer

#define _TRNS_ KC_TRNS
#define EW_CAPS LT(_EW, KC_CAPS)
#define EL_CAPS LT(_EL, KC_CAPS)
#define NP_C LT(_NP, KC_C)
//#define AL_SPACE LT(_AL, KC_SPC)
//#define NP_GUI LT(_NP, KC_LGUI)
//#define MC_SPACE LT(_MC, KC_SPC)
#define SW_RCTRL LT(_SW, KC_RCTRL)

#define MACRO_UNIX_TERMINAL 0
#define MACRO_LINUX_WB      1
#define MACRO_WIN_CMD       2
#define MACRO_WIN_WB        3
#define MACRO_WORD          4
#define MACRO_BCKWORD       5
#define MACRO_GUI           99

#define M_TERM M(MACRO_UNIX_TERMINAL)
#define M_LXWB M(MACRO_LINUX_WB)
#define M_WCMD M(MACRO_WIN_CMD)
#define M_WNWB M(MACRO_WIN_WB)
#define M_GUI  M(MACRO_GUI)
#define M_WORD M(MACRO_WORD) //copying the 'word' funcitonality in Vim, to move one word forward in any documents
#define M_BWRD M(MACRO_BCKWORD)

LEADER_EXTERNS();

enum emoticons {
	LENNY = SAFE_RANGE,
  LENNY_LNX,
	DWNHRT,
  DWNHRT_LNX,
	SHRUG,
  SHRUG_LNX,
  DWI,
  DWI_LNX
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _WL: Windows Layer (Layer for use in Windows OS, Default Layer when first flashed)
   * ,------------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Insert|
   * |------------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Delete|
   * |------------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|. F|  G|  H|. J|  K|  L|  ;|  '|Return |PrScrn|
   * |------------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|GUI   |
   * |------------------------------------------------------------------|
   * |Ctrl|Win |Alt | 	   Space(_AL) 	    |FN|Alt|Ctrl|Lef  |Dow|Rig 	|
   * `------------------------------------------------------------------'
   */
[_WL] = KEYMAP_ANSI(
  KC_GESC,   KC_1,   	KC_2, 		KC_3,   	KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,   	KC_0,   	KC_MINS,	KC_EQL, 	KC_BSLS,	KC_INS, \
  KC_TAB,  	KC_Q,   	KC_W,   	KC_E,   	KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,   	KC_P,   	KC_LBRC,	KC_RBRC,	KC_BSPC,	KC_DEL, \
  EW_CAPS, 	KC_A,   	KC_S,   	KC_D,   	KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,   	KC_SCLN,	KC_QUOT,		    KC_ENT,				KC_PSCR, \
  KC_LSFT,  KC_Z,   	KC_X,   	NP_C,   	KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,		KC_RSFT , 	  KC_UP,		    M_GUI, \
  KC_LCTL, 	M_GUI,		KC_LALT,                					KC_SPACE,				     		MO(_WU),	KC_RALT, 	SW_RCTRL, 	KC_LEFT, 	    KC_DOWN, 	    KC_RGHT),


/* Keymap _LL: Linux Layer, (Layer for use in Linux environment)
   * ,------------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Insert|
   * |------------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Delete|
   * |------------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|. F|  G|  H|. J|  K|  L|  ;|  '|Return |Home 	|
   * |------------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End 	|
   * |------------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space         |UL|Alt|Ctrl|Lef |Dow|Right	|
   * `------------------------------------------------------------------'
   */
[_LL] = KEYMAP_ANSI(
  KC_GESC,   KC_1,   	KC_2, 		KC_3,   	KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,   	KC_0,   	KC_MINS,	KC_EQL, 	KC_BSLS,	KC_INS, \
  KC_TAB,  	KC_Q,   	KC_W,     KC_E,   	KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,   	KC_P,   	KC_LBRC,	KC_RBRC,	KC_BSPC,	KC_DEL, \
  EL_CAPS, 	KC_A,   	KC_S,   	KC_D,   	KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,   	KC_SCLN,	KC_QUOT,		    KC_ENT,				KC_PSCR, \
  KC_LSFT,  KC_Z,   	KC_X,   	NP_C,   	KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,		KC_RSFT ,     KC_UP,		    M_GUI, \
  KC_LCTL, 	M_GUI,	KC_LALT,                					KC_SPACE,				     			MO(_LU),	KC_RALT, 	SW_RCTRL, 	KC_LEFT, 	    KC_DOWN, 	    KC_RGHT),


  /* Keymap _GL: Gaming Layer (Layer for use when Gaming)
   * ,------------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Insert|
   * |------------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Delete|
   * |------------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|. F|  G|  H|. J|  K|  L|  ;|  '|Return |PrScrn|
   * |------------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|GUI   |
   * |------------------------------------------------------------------|
   * |Ctrl|    |Alt |      Space(_AL)      |FN|Alt|Ctrl|Lef  |Dow|Rig   |
   * `------------------------------------------------------------------'
   */
[_GL] = KEYMAP_ANSI(
  KC_GESC,   KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_INS, \
  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_DEL, \
  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,        KC_ENT,       KC_PSCR, \
  KC_LSFT,  KC_Z,     KC_X,     NP_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,    KC_RSFT ,     KC_UP,        KC_MPLY, \
  KC_LCTL,  KC_NO,    KC_LALT,                          KC_SPACE,                 MO(_WU),  KC_RALT,  SW_RCTRL,   KC_LEFT,      KC_DOWN,      KC_RGHT),

  /* Keymap _WU: Windows Utility Layer (Utility Functions for use in Windows OS)
   * ,-----------------------------------------------------------------.
   * |~`  |F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Home |
   * |-----------------------------------------------------------------|
   * |     |   |WD |Up |WB |CMD|   |   |Up |   |   |   |   |     |End  |
   * |-----------------------------------------------------------------|
   * |      |   | <-|Dwn|.->|   |   |.<-|Dwn| ->|   |   |        |PgUp |
   * |-----------------------------------------------------------------|
   * |        |   |   |   |   |BWD|   |MUT|VL-|VL+|   |      |BL+|PgDn |
   * |-----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |BL |BL-|BLStp|
   * `-----------------------------------------------------------------'
   */
[_WU] = KEYMAP_ANSI(
  KC_GRV, 	KC_F1, 		KC_F2, 		KC_F3, 		KC_F4, 		KC_F5, 		KC_F6, 		KC_F7, 		KC_F8, 		KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_DEL, 	KC_HOME, \
  _TRNS_,	_TRNS_, 	M_WORD,		KC_UP,		M_WNWB, 	M_WCMD,		_TRNS_,		_TRNS_,		KC_UP,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		KC_END, \
  _TRNS_,	_TRNS_,		KC_LEFT, KC_DOWN,  KC_RIGHT,		_TRNS_,		_TRNS_,		KC_LEFT, KC_DOWN,  KC_RIGHT,		_TRNS_,		_TRNS_,     	_TRNS_,				KC_PGUP, \
  _TRNS_,	_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		M_BWRD, 	_TRNS_,		KC_MUTE,	KC_VOLD,	KC_VOLU,	_TRNS_,			_TRNS_, 			BL_INC, 	KC_PGDN, \
  _TRNS_,	_TRNS_,		_TRNS_,                 					_TRNS_,               					_TRNS_,		_TRNS_,		_TRNS_,		BL_TOGG,	BL_DEC, 	BL_STEP),

  
  /* Keymap _LU: Linux Utility Layer (Layer containing productivity shortcuts for Linux OS)
   * ,-----------------------------------------------------------------.
   * |~`  |F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Home |
   * |-----------------------------------------------------------------|
   * |     |   |WD |Up |WB |Trm|   |   |Up |   |   |   |   |     |End  |
   * |-----------------------------------------------------------------|
   * |      |   | <-|Dwn|.->|   |   |.<-|Dwn| ->|   |   |        |PgUp |
   * |-----------------------------------------------------------------|
   * |        |   |   |   |   |BWD|   |MUT|VL-|VL+|   |      |BL+|PgDn |
   * |-----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |BL |BL-|BLStp|
   * `-----------------------------------------------------------------'
   */
[_LU] = KEYMAP_ANSI(
  KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_HOME, \
  _TRNS_, _TRNS_,   M_WORD,   KC_UP,   M_LXWB,   M_TERM,   _TRNS_,   _TRNS_,   KC_UP,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   KC_END, \
  _TRNS_, _TRNS_,   KC_LEFT,  KC_DOWN,  KC_RIGHT,   _TRNS_,   _TRNS_,  KC_LEFT, KC_DOWN,  KC_RIGHT,   _TRNS_,   _TRNS_,       _TRNS_,       KC_PGUP, \
  _TRNS_, _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   M_BWRD,   _TRNS_,   KC_MUTE,   KC_VOLD,   KC_VOLU,   _TRNS_,     _TRNS_,     BL_INC,   KC_PGDN, \
  _TRNS_, _TRNS_,   _TRNS_,                           _TRNS_,                         _TRNS_,   _TRNS_,   _TRNS_,   BL_TOGG,   BL_DEC,   BL_STEP),


  /* Keymap _NP: NumPad Layer --> custom numpad layer
   * ,-----------------------------------------------------------------.
   * |    |  |   |   |   |   |   |   |*  |-  |-  |   |   |Bcksp  |     |
   * |-----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |7  |8  |9  |+  |   |   |     |     |
   * |-----------------------------------------------------------------|
   * |      |   |   |   |.  |   |   |.4 |5  |6  |.  |   |Enter   |     |
   * |-----------------------------------------------------------------|
   * |        |   |   |   |   |   |Nlk|1  |2  |3  |/  |      |   |     |
   * |-----------------------------------------------------------------|
   * |    |    |    |            0          |   |   |    |   |   |     |
   * `-----------------------------------------------------------------'
   */
[_NP] = KEYMAP_ANSI(
  _TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	KC_PAST, 	KC_PMNS, 	KC_PMNS, 	_TRNS_, 	_TRNS_, 	KC_BSPC, 	_TRNS_, \
  _TRNS_,	_TRNS_, 	_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_,		KC_P7,		KC_P8,		KC_P9,		KC_PPLS,	_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_, \
  _TRNS_,	_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		KC_P4,		KC_P5,		KC_P6,		KC_PDOT, 	_TRNS_,     	KC_PENT,			_TRNS_, \
  _TRNS_,	_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_, 	KC_NLCK,		KC_P1,		KC_P2,		KC_P3,		KC_PSLS,		_TRNS_, 			_TRNS_, 	_TRNS_, \
  _TRNS_,	_TRNS_,		_TRNS_,                 					KC_P0,               					_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_, 	_TRNS_),



  /* Keymap _EL: Emoji Layer
   * ,-----------------------------------------------------------------.
   * |    |  |   |   |   |   |   |   |   |   |   |   |   |       |     |
   * |-----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |     |
   * |-----------------------------------------------------------------|
   * |      |   |   |   |.LNY|DWI|SHG|.DHT|   |   |   |   |      |     |
   * |-----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |     |
   * |-----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |     |
   * `-----------------------------------------------------------------'
   */
[_EL] = KEYMAP_ANSI(
  _TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, \
  _TRNS_,	_TRNS_, 	_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_, \
  _TRNS_,	_TRNS_,		_TRNS_,		_TRNS_,		LENNY_LNX,		DWI_LNX,		SHRUG_LNX,		DWNHRT_LNX,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,     	_TRNS_,				_TRNS_, \
  _TRNS_,	_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_,  _TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,			_TRNS_, 			_TRNS_, 	_TRNS_, \
  _TRNS_,	_TRNS_,		_TRNS_,                 					_TRNS_,               					_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_, 	_TRNS_),
		

  /* Keymap _EL: Emoji Layer
   * ,-----------------------------------------------------------------.
   * |    |  |   |   |   |   |   |   |   |   |   |   |   |       |     |
   * |-----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |     |
   * |-----------------------------------------------------------------|
   * |      |   |   |   |.LNW|DWW|SHW|.DHW|   |   |   |   |      |     |
   * |-----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |     |
   * |-----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |     |
   * `-----------------------------------------------------------------'
   */
[_EW] = KEYMAP_ANSI(
  _TRNS_,  _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_, \
  _TRNS_, _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_, \
  _TRNS_, _TRNS_,   _TRNS_,   _TRNS_,   LENNY,    DWI,    SHRUG,    DWNHRT,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,       _TRNS_,       _TRNS_, \
  _TRNS_, _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,     _TRNS_,       _TRNS_,   _TRNS_, \
  _TRNS_, _TRNS_,   _TRNS_,                           _TRNS_,                         _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_,   _TRNS_),
    


  /* Keymap _SW: Switching Layer
   * ,-----------------------------------------------------------------.
   * |    |ML|SL |GL |   |   |   |   |   |   |   |   |   |       |     |
   * |-----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |     |
   * |-----------------------------------------------------------------|
   * |      |   |   |   |.  |   |   |.  |   |   |   |   |        |     |
   * |-----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |     |
   * |-----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |   |   |     |
   * `-----------------------------------------------------------------'
   */
[_SW] = KEYMAP_ANSI(
  _TRNS_, 	TO(_WL), 	TO(_LL), 	TO(_GL), 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, 	_TRNS_, \
  _TRNS_,	_TRNS_, 	_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_, \
  _TRNS_,	_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,     	_TRNS_,				_TRNS_, \
  _TRNS_,	_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_, 	_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_,			_TRNS_, 			_TRNS_, 	_TRNS_, \
  _TRNS_,	_TRNS_,		_TRNS_,                 					_TRNS_,               					_TRNS_,		_TRNS_,		_TRNS_,		_TRNS_, 	_TRNS_, 	_TRNS_),



};

//tap function for simulating a 'tap' or a keystroke of a particular key
void tap(uint16_t keycode){
    register_code(keycode);
    unregister_code(keycode);
};

/* //function for keys that are typed after KC_LEAD. Not sure what to do with these yet though.
void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      tap(KC_S);
    }
    SEQ_TWO_KEYS(KC_A, KC_S) {
    }
    SEQ_THREE_KEYS(KC_A, KC_S, KC_D) {
      register_code(KC_LGUI);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LGUI);
    }
  }
}
*/




//testing process_record_user from maartenwut
bool process_record_user(uint16_t keycode, keyrecord_t *record ){
	switch (keycode) {
    case LENNY:
      if (record->event.pressed){

        set_unicode_input_mode(UC_WIN);
        register_code(KC_LSFT);
        tap(KC_9);                    // Head
        unregister_code(KC_LSFT);
        tap(KC_SPC);                  // Space
        process_unicode((0x0361|QK_UNICODE), record); // Eyebrow
        process_unicode((0x00B0|QK_UNICODE), record); // Eye
        tap(KC_SPC);
        process_unicode((0x035C|QK_UNICODE), record); // Mouth
        process_unicode((0x0296|QK_UNICODE), record); // Nose
        tap(KC_SPC);
        process_unicode((0x0361|QK_UNICODE), record); // Eyebrow
        process_unicode((0x00B0|QK_UNICODE), record); // Eye
        register_code(KC_LSFT);
        tap(KC_0);                    // Head
        unregister_code(KC_LSFT);
      }
      return false;
      break;

		case LENNY_LNX:			// ( ͡° ͜ʖ ͡°)
			if(record->event.pressed){
        
				//set_unicode_input_mode(UC_WIN); --> this is for Windows Unicode, not Linux!
				set_unicode_input_mode(UC_LNX);
        register_code(KC_LSFT);
				tap(KC_9);										// Head
				unregister_code(KC_LSFT);
				tap(KC_SPC);									// Space
				process_unicode((0x0361|QK_UNICODE), record);	// Eyebrow
				process_unicode((0x00B0|QK_UNICODE), record);	// Eye
				tap(KC_SPC);
				process_unicode((0x035C|QK_UNICODE), record);	// Mouth
				process_unicode((0x0296|QK_UNICODE), record);	// Nose
				tap(KC_SPC);
				process_unicode((0x0361|QK_UNICODE), record);	// Eyebrow
				process_unicode((0x00B0|QK_UNICODE), record);	// Eye
				register_code(KC_LSFT);
				tap(KC_0);										// Head
				unregister_code(KC_LSFT);

			}
			return false;
			break;

		case DWNHRT:		// (´・ω・`)
			if(record->event.pressed){
        
				set_unicode_input_mode(UC_WIN); 
				register_code(KC_LSFT);
				tap(KC_9);										// Head
				unregister_code(KC_LSFT);
				process_unicode((0x00B4|QK_UNICODE), record);	// Eyebrow
				process_unicode((0x30FB|QK_UNICODE), record);	// Eye
				process_unicode((0x03C9|QK_UNICODE), record);	// Mouth
				process_unicode((0x30FB|QK_UNICODE), record);	// Eye
				process_unicode((0x0060|QK_UNICODE), record);	// Eyebrow
				register_code(KC_LSFT);
				tap(KC_0);										// Head
				unregister_code(KC_LSFT);
        
			}
			return false;
			break;

    case DWNHRT_LNX:
      if(record->event.pressed){
        //set_unicode_input_mode(UC_WIN); --> this is for Windows Unicode, not Linux!
        set_unicode_input_mode(UC_LNX);
        register_code(KC_LSFT);
        tap(KC_9);                    // Head
        unregister_code(KC_LSFT);
        process_unicode((0x00B4|QK_UNICODE), record); // Eyebrow
        process_unicode((0x30FB|QK_UNICODE), record); // Eye
        process_unicode((0x03C9|QK_UNICODE), record); // Mouth
        process_unicode((0x30FB|QK_UNICODE), record); // Eye
        process_unicode((0x0060|QK_UNICODE), record); // Eyebrow
        register_code(KC_LSFT);
        tap(KC_0);                    // Head
        unregister_code(KC_LSFT);
      }
      return false;
      break;

    case SHRUG:
      if(record->event.pressed){
        set_unicode_input_mode(UC_WIN); 
        process_unicode((0x00AF|QK_UNICODE), record); // Hand
        tap(KC_BSLS);                 // Arm
        register_code(KC_LSFT);
        tap(KC_UNDS);                 // Arm
        tap(KC_LPRN);                 // Head
        unregister_code(KC_LSFT);
        process_unicode((0x30C4|QK_UNICODE), record); // Face
        register_code(KC_LSFT);
        tap(KC_RPRN);                 // Head
        tap(KC_UNDS);                 // Arm
        unregister_code(KC_LSFT);
        tap(KC_SLSH);                 // Arm
        process_unicode((0x00AF|QK_UNICODE), record); // Hand
      }
      return false;
      break;

		case SHRUG_LNX:			// ¯\_(ツ)_/¯
			if(record->event.pressed){
				//set_unicode_input_mode(UC_WIN); --> this is for Windows Unicode, not Linux!
        set_unicode_input_mode(UC_LNX);
				process_unicode((0x00AF|QK_UNICODE), record);	// Hand
				tap(KC_BSLS);									// Arm
				register_code(KC_LSFT);
				tap(KC_UNDS);									// Arm
				tap(KC_LPRN);									// Head
				unregister_code(KC_LSFT);
				process_unicode((0x30C4|QK_UNICODE), record);	// Face
				register_code(KC_LSFT);
				tap(KC_RPRN);									// Head
				tap(KC_UNDS);									// Arm
				unregister_code(KC_LSFT);
				tap(KC_SLSH);									// Arm
				process_unicode((0x00AF|QK_UNICODE), record);	// Hand
			}
      return false;
      break;

    case DWI:
      if (record->event.pressed){
        set_unicode_input_mode(UC_WIN);
        register_code(KC_LSFT);
        tap(KC_9);
        unregister_code(KC_LSFT);
        process_unicode((0x2310|QK_UNICODE), record); // upper frame
        process_unicode((0x25A0|QK_UNICODE), record); // first square
        process_unicode((0x2581|QK_UNICODE), record); // lower frame
        process_unicode((0x25A0|QK_UNICODE), record); // second square
        register_code(KC_LSFT);
        tap(KC_0);                    // Head
        unregister_code(KC_LSFT);
      }
      return false;
      break;

    case DWI_LNX:
      if (record->event.pressed){
        //set_unicode_input_mode(UC_WIN); --> this is for Windows Unicode, not Linux!
        set_unicode_input_mode(UC_LNX);
        register_code(KC_LSFT);
        tap(KC_9);
        unregister_code(KC_LSFT);
        process_unicode((0x2310|QK_UNICODE), record); // upper frame
        process_unicode((0x25A0|QK_UNICODE), record); // first square
        process_unicode((0x2581|QK_UNICODE), record); // lower frame
        process_unicode((0x25A0|QK_UNICODE), record); // second square
        register_code(KC_LSFT);
        tap(KC_0);                    // Head
        unregister_code(KC_LSFT);

      }
			return false;
			break;
	}
	return true;
};

//testing Macro, currently testing the Unix Terminal Macro first
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt){
	
	switch(id) {
    case MACRO_GUI:{
      if (record->event.pressed){
        //when key is PRESSED
        return MACRO(D(LGUI), END);
      }
      else {
        return MACRO(U(LGUI), END);
      }

      break;
    }

		case MACRO_UNIX_TERMINAL:{
			if (record->event.pressed){
				//when key is PRESSED
				return MACRO( D(LCTL), D(LALT), END);
			}

			else {
				//when key is RELEASED
				return MACRO( T(T), U(LCTL), U(LALT), END);
			}

			break;
		}

    case MACRO_LINUX_WB:{ //opening MOZILLA FIREFOX with a Macro key
      if (record->event.pressed){
        //when key is PRESSED
        return MACRO( D(LGUI), END);
      }
      else{
        //when key is RELEASED
        return MACRO( U(LGUI), T(M), T(O), T(Z), T(I), T(L), T(L), T(A), T(SPACE), T(F), T(I), T(R), T(E), T(F), T(O), T(X), T(ENTER), END);
      }

      break;
    }

    case MACRO_WIN_CMD:{ //opening MOZILLA FIREFOX with a Macro key
      if (record->event.pressed){
        //when key is PRESSED
        return MACRO( D(LGUI), END);
      }
      else{
        //when key is RELEASED
        return MACRO( U(LGUI), T(C), T(M), T(D), T(ENTER), END);
      }

      break;
    }
    
    case MACRO_WIN_WB:{
      if (record->event.pressed){
        //when key is PRESSED
        return MACRO( D(LGUI), END);
      }
      else{
        //when key is RELEASED
        return MACRO( U(LGUI), T(C), T(H), T(R), T(O), T(M), T(E), T(ENTER), END);
      }

      break;
    }

    case MACRO_WORD: { //macro replicating the 'word' functionality in Vim for all types of documents (tested working in Subl and WA)
      if (record->event.pressed) {
        //when key is PRESSED
        return MACRO( D(LCTL), END);
      }
      else{
      //when key is RELEASED
        return MACRO( T(RIGHT), U(LCTL), END);
      }

      break;
    }

    case MACRO_BCKWORD: {
      if (record->event.pressed) {
        //when key is PRESSED
        return MACRO( D(LCTL), END);
      }
      else{
        //when key is RELEASED
        return MACRO( T(LEFT), U(LCTL), END);
      }

      break;
    }

    

	}

	return MACRO_NONE;
};
