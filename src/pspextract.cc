#include <iostream>
#include <string>
#include <filesystem>
#include <cstdlib>
/* Calls 7z to extract the game ISO, very immature "error handling" 
 * like the rest of this codebase, it is a mess*/
void psp_extract(const std::filesystem::path& iso_path)
{
    auto psp_output_dir = iso_path.stem();
    std::string extract_command = "7z x \"" + iso_path.string() + "\""
    " -o\"" + psp_output_dir.string() + "-extracted\"";
   int result = std::system(extract_command.c_str());
   if (result != 0){
       std::cout << "error\n";
   }
}
