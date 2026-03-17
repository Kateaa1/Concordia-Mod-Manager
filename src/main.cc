#include <iostream>
#include <filesystem>
#include "pspextract.hh"
#include "psprepack.hh"
/* Main function, shouldnt need huge docs, read the alpha-1-scope file to see what this is meant to do
 * however we are still in very foundational stage */
int main(int argc, char *argv[])
{
    std::filesystem::path psp_iso_path = argv[1];
    psp_extract(psp_iso_path);
    std::cout << "Extracted file to" << psp_iso_path << "\n";
    std::filesystem::path psp_folder_path = argv[2];
    psp_repack(psp_folder_path);
    std::cout << "Repacked files\n";
    return 0;
}
