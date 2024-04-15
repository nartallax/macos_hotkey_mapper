#include <ApplicationServices/ApplicationServices.h>
#include "./keys_and_modifiers.c"
#include "./keycode_to_string.c"
#include "./user_mappings.c"

/** Mapper's entrypoint */

int64_t count = -1;
int verbose = 0;

void printEvent(int isMapped, CGEventType type, int64_t keycode, int64_t flags){
	if(verbose){
		fprintf(stderr, 
			"\t%s\t%s%s%s%s%s%s%s\t(keycode =\t%lli,\tflags = %lli)\n", 
			isMapped? "sending: ": "received:",
			type == kCGEventKeyDown? "down: ": type == kCGEventKeyUp? "up:   ": "???:  ",
			flags & CTRL? "CTRL+": "",
			flags & ALT? "ALT+": "",
			flags & SHIFT? "SHIFT+": "",
			flags & META? "META+": "",
			flags & FN? "FN+": "",
			keycodeToString(keycode),
			keycode, flags
		);
	}
}

CGEventRef updateKeyEvent(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon){
	// just in case our event mask wasn't enough - let's check again
    if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp)){
        return event;
	}

    int64_t srcKeycode = (int64_t)CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);
	int64_t srcFlags = (int64_t)CGEventGetFlags(event);

	printEvent(0, type, srcKeycode, srcFlags);

	if(count-- == 0){
		exit(1);
	}

	int64_t unmapped = (srcFlags & MOD_KEYS) | srcKeycode;
	int64_t mapped = mapEventKeys(unmapped);
	int64_t mappedFlags = (mapped & MOD_KEYS) | (srcFlags & (~MOD_KEYS));
	int64_t mappedKeycode = (mapped & (~MOD_KEYS));

	if(mapped != unmapped){
		printEvent(1, type, mappedKeycode, mappedFlags);
	}

	if(mappedKeycode != srcKeycode){
	    CGEventSetIntegerValueField(event, kCGKeyboardEventKeycode, mappedKeycode);
	}
	if(mappedFlags != srcFlags){
		CGEventSetFlags(event, (CGEventFlags)mappedFlags);
	}

    return event;
}

void parseOptions(int argc, char** argv) {
	for(int i = 1; i < argc; i++){
		if(!strcmp(argv[i], "--verbose")){
			verbose = 1;
			continue;
		}
		if(!strcmp(argv[i], "--limit") && i < argc - 1){
			count = strtol(argv[++i], NULL, 10);
			continue;
		}
		fprintf(stderr, "Unrecognized option %s\n", argv[i]);
		exit(1);
	}
}

int main(int argc, char** argv){
	parseOptions(argc, argv);
	
	CGEventMask eventMask = ((1 << kCGEventKeyDown) | (1 << kCGEventKeyUp));
    CFMachPortRef eventTap = CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap, 0, eventMask, updateKeyEvent, NULL);
    if (!eventTap) {
        fprintf(stderr, "Failed to create event tap. Fatality T_T\n");
        exit(1);
    }

    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);
    CGEventTapEnable(eventTap, true);
    CFRunLoopRun();

    exit(0);
}