#ifndef A680961E_429C_429F_8386_7E6062442773
#define A680961E_429C_429F_8386_7E6062442773

#include <iostream>
#include <fstream>
#include <io.h>
#include <string>
#include <cstring>

#include <map>
#include "zipper.hpp"

void compress_LZW(const std::string path_file, const std::string path_zip_file);
void decompress_LZW(const std::string path_zip_file);

#endif /* A680961E_429C_429F_8386_7E6062442773 */
