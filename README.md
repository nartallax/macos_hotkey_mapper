# MacOS hotkey mapper

This app is created to help user achieve arbitrary-style hotkeys (i.e. Windows-like) on MacOS.  
Because having two separate sets of hotkeys - one for mac and other for everything else - is a pain for muscle memory.  
Main advantage of this app is that it comes in form of source code, and this source code is very small, which means it is easily reviewable; this may come in handy for various paranoic reasons.  

Also it's "from programmers, to programmers", so you are expected to figure out most of the stuff yourself.  

## Install aka build

This app does not come with any pre-built binaries. You are supposed to build them yourself.  
For that we have a handy [./compile.sh](./compile.sh) script. You only need to have `cc` binary somewhere on your path, which is something that you can get by installing xcode developer tools or whatever its called.  
As result of compilation [./mapper](./mapper) binary is produced. You can run it; while it is running, your keys will be mapped. After it is stopped - they won't be mapped anymore.  
The rest is up to you. This tool is not leaving any files/configuration/handlers/services/etc in some obscure part of the system, it's just the binary and that's it.  

## FAQ

Q: How do I actually customize the behaviour?  
A: There are no config files; all the behaviour is baked-in into the executable. See [user_mappings.c](./user_mappings.c) and [keys_and_modifiers.c](./keys_and_modifiers.c) to get the idea. Don't forget to recompile after changing something.  
Yeah, it's pretty limited, but that's a price to pay for simplicity. Also works like a charm. Most of the time.  

Q: I'm kinda scared to screw things up, is there a failsafe?  
A: Sure is! Pass `--limit` option, like `./mapper --limit 10`. After this amount of events handled (no matter mapped or not), the mapper will exit on its own, so no matter how hard you screwed the config - you will most probably be fine, just press a few keys and wait for it to exit.  

Q: Why my mapping is not working? / I can't find how this key is called!  
A: Just pass `--verbose` option and try to make sense of what you're seeing in STDERR. For example, sometimes macos adds FN to keypresses when you really don't intend it. And maybe there are other modifiers which are not known, see `flags = ` part of the output.  
Extra modifiers are a common reason of mappings not working. For example, press of CTRL+SHIFT+END won't trigger mapping of CTRL+END - you will need to define both of them.  
And also there's only one mapping operation per press, at most. If you map A to B and B to C, you will only have B when A is pressed.  
And also also original key stroke is lost after mapping. If you press CTRL+F and there's mapping to make it META+F - outside world will only see META+F and won't know anything about CTRL+F.  

Q: There is no key, and verbose output shows "???", what do I do now?  
A: There is `keycode = ` part of the verbose output - this is the key. Just `#define MY_UNIQUE_KEY valueFromVerboseOutput` or whatever and here you have it.  

## Attribution

Loosely based on [this snippet](https://github.com/mjolnirapp/mjolnir/issues/9).