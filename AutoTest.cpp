#include "AutoTest.hpp"

bool AutoTest1(){
    std::fstream file("AutoTest.bmp", std::ios_base::binary | std::ios_base::in);
    file.seekg(0, std::ios::end);
    int64_t SIZE = file.tellg();
    file.close();

    char *path = _getcwd(NULL, 0);
    std::string str = "";
    for(int i = 0; i < strlen(path); i++){
        str.push_back(path[i]);
    }
    zipper z("AutoTest.bmp", str);
    z.compress();

    file.open("AutoTest.bmp.ziplzw", std::ios_base::binary | std::ios_base::in);
    file.seekg(0, std::ios::end);
    int64_t size = file.tellg();

    if(SIZE > size) return 1;
    else return 0;
}

bool AutoTest2(){
    char *path = _getcwd(NULL, 0);
    std::string str = "";
    for(int i = 0; i < strlen(path); i++){
        str.push_back(path[i]);
    }

    std::fstream file("AutoTest.bmp.ziplzw", std::ios_base::binary | std::ios_base::in);
    file.seekg(0, std::ios::end);
    int64_t size = file.tellg();
    file.close();

    zipper z;
    z.decompress(str + "\\" + "AutoTest.bmp.ziplzw");

    file.open(str + "\\" + "decompress_AutoTest.bmp", std::ios_base::binary | std::ios_base::in);
    file.seekg(0, std::ios::end);
    int64_t SIZE = file.tellg();
    file.close();

    if(SIZE > size) return 1;
    else return 0;
}

bool AutoTest(){
    bool ok = 1;
    if(!AutoTest1()){
        std::cout << "AutoTest1 is failed!\n";
        ok = 0;
    }
    if(!AutoTest2()){
        std::cout << "AutoTest2 is failed!\n";
        ok = 0;
    }
    return ok;
}