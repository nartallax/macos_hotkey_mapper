/** A list of constants about macos key codes */

#define ALT kCGEventFlagMaskAlternate // aka OPTION
#define META kCGEventFlagMaskCommand // aka COMMAND
#define FN kCGEventFlagMaskSecondaryFn
#define CTRL kCGEventFlagMaskControl
#define SHIFT kCGEventFlagMaskShift

#define MOD_KEYS (SHIFT | ALT | CTRL | META | FN)

#define A 0
#define S 1
#define D 2
#define F 3
#define H 4
#define G 5
#define Z 6
#define X 7
#define C 8
#define V 9
#define PARAGRAPH 10 // ?????? what, why
#define B 11
#define Q 12
#define W 13
#define E 14
#define R 15
#define Y 16
#define T 17
#define ONE 18 // non-numlock number keys
#define TWO 19
#define THREE 20
#define FOUR 21
#define FIVE 22
#define SIX 23
#define EQUALS 24
#define NINE 25
#define SEVEN 26
#define MINUS 27
#define EIGHT 28
#define ZERO 29
#define CLOSING_SQUARE_BRACKET 30
#define O 31
#define U 32
#define OPENING_SQUARE_BRACKET 33
#define I 34
#define P 35
#define RETURN 36 // non-numpad enter key
#define L 37
#define J 38
#define SINGLE_QUOTE 39
#define K 40
#define SEMICOLON 41
#define BACKSLASH 42
#define COMMA 43
#define SLASH 44 // non-numpad slash
#define N 45
#define M 46
#define DOT 47 // non-numpad dot
#define TAB 48
#define SPACE 49
#define BACKTICK 50
#define BACKSPACE 51
#define ENTER 52 // not sure how it is different from RETURN. couldn't find it on my keyboard. oh well.
#define ESCAPE 53
#define NUMPAD_DOT 65
#define NUMPAD_ASTERISK 67
#define NUMPAD_PLUS 69
#define CLEAR 71 // numpad I would assume...?
#define NUMPAD_SLASH 75
#define NUMPAD_RETURN 76
#define NUMPAD_MINUS 78
#define NUMPAD_EQUALS 81
#define NUMPAD_ZERO 82
#define NUMPAD_ONE 83
#define NUMPAD_TWO 84
#define NUMPAD_THREE 85
#define NUMPAD_FOUR 86
#define NUMPAD_FIVE 87
#define NUMPAD_SIX 88
#define NUMPAD_SEVEN 89
#define NUMPAD_EIGHT 91
#define NUMPAD_NINE 92
#define F5 96
#define F6 97
#define F7 98
#define F3 99
#define F8 100
#define F9 101
#define F11 103
#define F13 105
#define F14 107
#define F10 109
#define F12 111
#define F15 113
#define HELP 114
#define HOME 115
#define PGUP 116
#define DELETE 117
#define F4 118
#define END 119
#define F2 120
#define PGDN 121
#define F1 122
#define LEFT 123
#define RIGHT 124
#define DOWN 125
#define UP 126