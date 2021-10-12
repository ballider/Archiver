#include "head.hpp"

zipper::zipper(){
    path_file_ = "";
    path_zip_file_ = "";
}

std::string zipper::get_file_name(const std::string path_to_file) const{
    return path_to_file.substr(path_to_file.find_last_of("\\")+1, path_to_file.size());
}

zipper::zipper(const std::string path_file, const std::string path_zip_file){
    path_file_ = path_file;
    path_zip_file_ = path_zip_file + "\\" + get_file_name(path_file_) + ".ziplzw";
}

void zipper::compress(){
    compress_LZW(path_file_, path_zip_file_);
}

void zipper::decompress(const std::string path_zip_file){
    decompress_LZW(path_zip_file);
}

void zipper::update_fields(const std::string path_file, const std::string path_zip_file){
    path_file_ = path_file;
    path_zip_file_ = path_zip_file + "\\" + get_file_name(path_file_) + ".ziplzw";
}