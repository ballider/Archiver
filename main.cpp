#include "head.hpp"
#include "AutoTest.hpp"

int main(){

    //if(!AutoTest()) return 0;
    
    std::cout << "Input 1 to compress.\n";
    std::cout << "Input 2 to decompress.\n";
    std::cout << "Input 0 to exit.\n";

    while(true){
        int key; std::cin >> key;
        if(key == 0) break;
        if(key == 1){
            std::string path_file, zip_path_file;
            std::cout << "Enter path to file: "; std::cin >> path_file;
            std::cout << "Enter path to put zip file: "; std::cin >> zip_path_file;

            zipper z(path_file, zip_path_file);
            z.compress();
        }
        if(key == 2){
            std::string path_archiv_file;
            std::cout << "Enter path to zip file: "; std::cin >> path_archiv_file;
            zipper z;
            z.decompress(path_archiv_file);
        }
    }
    
    return 0;
}