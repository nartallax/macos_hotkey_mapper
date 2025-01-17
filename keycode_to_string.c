#include <ApplicationServices/ApplicationServices.h>

/** Map a CGKeyCode to string. Reverse to definitions in keys_and_modifiers.
 * Exists for debug purposes. */
const char* keycodeToString(CGKeyCode code){
	switch(code){
		case 0: return "A";
		case 1: return "S";
		case 2: return "D";
		case 3: return "F";
		case 4: return "H";
		case 5: return "G";
		case 6: return "Z";
		case 7: return "X";
		case 8: return "C";
		case 9: return "V";
		case 10: return "PARAGRAPH";
		case 11: return "B";
		case 12: return "Q";
		case 13: return "W";
		case 14: return "E";
		case 15: return "R";
		case 16: return "Y";
		case 17: return "T";
		case 18: return "ONE";
		case 19: return "TWO";
		case 20: return "THREE";
		case 21: return "FOUR";
		case 22: return "FIVE";
		case 23: return "SIX";
		case 24: return "EQUALS";
		case 25: return "NINE";
		case 26: return "SEVEN";
		case 27: return "MINUS";
		case 28: return "EIGHT";
		case 29: return "ZERO";
		case 30: return "CLOSING_SQUARE_BRACKET";
		case 31: return "O";
		case 32: return "U";
		case 33: return "OPENING_SQUARE_BRACKET";
		case 34: return "I";
		case 35: return "P";
		case 36: return "RETURN";
		case 37: return "L";
		case 38: return "J";
		case 39: return "SINGLE_QUOTE";
		case 40: return "K";
		case 41: return "SEMICOLON";
		case 42: return "BACKSLASH";
		case 43: return "COMMA";
		case 44: return "SLASH";
		case 45: return "N";
		case 46: return "M";
		case 47: return "DOT";
		case 48: return "TAB";
		case 49: return "SPACE";
		case 50: return "BACKTICK";
		case 51: return "BACKSPACE";
		case 52: return "ENTER";
		case 53: return "ESCAPE";
		case 65: return "NUMPAD_DOT";
		case 67: return "NUMPAD_ASTERISK";
		case 69: return "NUMPAD_PLUS";
		case 71: return "CLEAR";
		case 75: return "NUMPAD_SLASH";
		case 76: return "NUMPAD_RETURN";
		case 78: return "NUMPAD_MINUS";
		case 81: return "NUMPAD_EQUALS";
		case 82: return "NUMPAD_ZERO";
		case 83: return "NUMPAD_ONE";
		case 84: return "NUMPAD_TWO";
		case 85: return "NUMPAD_THREE";
		case 86: return "NUMPAD_FOUR";
		case 87: return "NUMPAD_FIVE";
		case 88: return "NUMPAD_SIX";
		case 89: return "NUMPAD_SEVEN";
		case 91: return "NUMPAD_EIGHT";
		case 92: return "NUMPAD_NINE";
		case 96: return "F5";
		case 97: return "F6";
		case 98: return "F7";
		case 99: return "F3";
		case 100: return "F8";
		case 101: return "F9";
		case 103: return "F11";
		case 105: return "F13";
		case 107: return "F14";
		case 109: return "F10";
		case 111: return "F12";
		case 113: return "F15";
		case 114: return "HELP";
		case 115: return "HOME";
		case 116: return "PGUP";
		case 117: return "DELETE";
		case 118: return "F4";
		case 119: return "END";
		case 120: return "F2";
		case 121: return "PGDN";
		case 122: return "F1";
		case 123: return "LEFT";
		case 124: return "RIGHT";
		case 125: return "DOWN";
		case 126: return "UP";
		default: return "???";
	}
}