#include <iostream>
#include <filesystem>
#include <string>
#include <cstdlib>

// Takes the folder created by the psp_extract function is src/pspextract.cc and repacks it back into an ISO 

void psp_repack(const std::filesystem::path& folder_path)
{
    auto output_iso = folder_path.stem();
    std::string repack_command =
       "mkisofs -iso-level 4 -xa"
       " -A \"PSP GAME\""
       " -V \"PSP GAME\""
       " -sysid \"PSP GAME\""
       " -volset SSX_PSP"
       " -p SSX"
       " -o \"" + folder_path.parent_path().string() + "/" + output_iso.string() + "-repacked.iso\""
       " \"" + folder_path.string() + "\"";
    std::cout << repack_command << "\n";
    int result = std::system(repack_command.c_str());
    if (result != 0){
        std::cout << "Error\n";
    }
}
