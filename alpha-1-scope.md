### Alpha 1 scope

Alpha 1 (or really alpha 0 tbh) is very very simple
shouldn't be more than like 3 files and will do very very simple, basically just this

1) Extract the ISO (argv[2]) for the selected game (argv[1]) as a folder
2) Copy the mods in the mod folder (argv[4]) to the directory for in the game folder corrisponding to the selected mod 
type (argv[3]).
3) Remove the temporary extracted folder
4) repack the iso into the specified directory/file name (argv[5])

A sample run would look like this
`concordia --game=Persona1 --iso-path=~/Development/Concordia/P1.iso --mod-type=sound --mod-dir=~/Development/Concordia/Mods/ --modded-path=~/Development/Concordia/Modded-ISO.iso`
(THIS WILL BE CLEANED UP LATER I PROMISE)

We're using 7z to extract the iso (`7z x`) and mkisofs to rebuild the iso (`mkisofs -iso-level 4 -xa -A "PSP GAME" -V "PSP GAME" -sysid "PSP GAME" -volset SSX_PSP -p SSX -o "{modPath}/P1PSP.iso" "{modPath}/Persona 1 (PSP)"`) so those will both be deps

I may look into an `--init=Persona1` arg that will automatically wget the patched EBOOT mod, use some xdelta command line thing to patch it and then rebuild the ISO, the game won't work after being repaked without it so it is a requirement

No mod priority yet, it'll just blindly copy everything, so file conflicts will be resolved as "whatever file was written last" 

As for packages...I may look into an RPM or AppImage so testers don't need to compile from source, and so steamdeck users
don't need to break their sandbox to install it

No handling of PPSSPP cheats or textures yet

Only sound mods so far, this is a proof of concept more than anything.
