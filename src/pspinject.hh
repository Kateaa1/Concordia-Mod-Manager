#pragma once 

#include <filesystem>

namespace fs = std::filesystem;

void psp_inject(fs::path& source_dir, fs::path& target_dir, std::string modtype);
