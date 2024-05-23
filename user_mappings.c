#include <ApplicationServices/ApplicationServices.h>
#include "./keys_and_modifiers.c"

/** User-defined logic of mapping one key chord to another */
int64_t mapEventKeys(int64_t keyWithModifiers){
	switch(keyWithModifiers){
		case ALT+TAB: return META+TAB; // switch active window
		case CTRL+C: return META+C; // copy
		case CTRL+V: return META+V; // paste
		case CTRL+X: return META+X; // cut
		case CTRL+S: return META+S; // save
		case CTRL+F: return META+F; // find
		case CTRL+A: return META+A; // select all
		case CTRL+Z: return META+Z; // undo
		case CTRL+Y: return META+Y; // redo
		case CTRL+W: return META+W; // close tab
		case FN+F5: return META+R; // refresh
		case HOME: return CTRL+LEFT; // go to line start
		case FN+HOME: return CTRL+LEFT; // go to line start
		case SHIFT+FN+HOME: return CTRL+SHIFT+LEFT; // select to line start
		case END: return CTRL+RIGHT; // go to line end
		case FN+END: return CTRL+RIGHT; // go to line end
		case SHIFT+FN+END: return CTRL+SHIFT+RIGHT; // select to line end
		case CTRL+FN+LEFT: return ALT+LEFT; // go 1 word left
		case CTRL+FN+SHIFT+LEFT: return ALT+SHIFT+LEFT; // select 1 word left
		case CTRL+FN+RIGHT: return ALT+RIGHT; // go 1 word right
		case CTRL+FN+SHIFT+RIGHT: return ALT+SHIFT+RIGHT; // select 1 word right
		case CTRL+BACKSPACE: return ALT+BACKSPACE; // delete 1 word left
		case CTRL+DELETE: return ALT+DELETE; // delete 1 word right
		case CTRL+SHIFT+T: return META+SHIFT+T; // reopen tab
		default: return keyWithModifiers;
	}
}