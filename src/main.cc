#include <iostream>
#include <filesystem> 
#include "pspextract.hh"
#include "psprepack.hh"
#include "pspinject.hh"

/* Main function, shouldnt need huge docs, read the alpha-1-scope file to see what this is meant to do
 * however we are still in very foundational stage */
int main(int argc, char *argv[])
{
    std::filesystem::path psp_iso_path = argv[2];
    psp_extract(psp_iso_path);
    std::cout << "Extracted file to" << psp_iso_path << "\n";
    std::string modtype = argv[1];
    fs::path mod_path = argv[4];
    std::filesystem::path psp_folder_path = argv[3];
    psp_inject(mod_path, psp_folder_path, modtype);
    psp_repack(psp_folder_path);
    std::cout << "Repacked files\n";
    
    // example run;
    //  concordia --init /home/katelyn/Development/Concorida/game-files/P1.iso /home/katelyn/Development/Concorida/game-files/P1-Extracted /home/katelyn/Development/Concorida/mods/
    return 0;
}
