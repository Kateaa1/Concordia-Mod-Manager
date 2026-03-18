#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

/* This is needs to actually be written lmao
 * what this should do is copy things from the mods directory to the extracted folder like
 * mods/sysdir -> p1-extracted/PSP_GAME/SYSDIR/ 
 * for example */

void psp_inject(fs::path& source_dir, fs::path& target_dir, std::string modtype)
{ 
    if (modtype == "--init") {
        fs::path output_dir = target_dir / "PSP_GAME" / "SYSDIR" / "EBOOT.BIN";
        source_dir = source_dir / "SYSDIR" / "EBOOT.BIN";
        fs::copy_file(source_dir, output_dir, fs::copy_options::overwrite_existing);
    } else {
        std::cout << "error, kate is dumb\n";
    }
    std::cout << source_dir << "\n";
    std::cout << target_dir << "\n";
}
