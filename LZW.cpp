#include "head.hpp"

void compress_LZW(const std::string path_file, const std::string path_zip_file){
    std::ifstream file(path_file, std::ios_base::binary);          // открываем файл для архивации
    std::ofstream zip_file(path_zip_file, std::ios_base::binary);  // открываем файл куда архивируем

    if(!file){
        std::cout << "Error! Cannot open file " << path_file << "\n";
        return;
    }

    int64_t dictSize = 256;
    std::map<std::string, int64_t> dictionary;
    for (int64_t i = 0; i < dictSize; i++) dictionary[std::string(1, i)] = i;
    
    std::string w = "";
    char c;
    while(file.get(c)){
        std::string wc = w + c;
        if(dictionary.count(wc)) w = wc;
        else {
            zip_file << dictionary[w] << " ";
            dictionary[wc] = dictSize++;
            w = std::string(1, c);
        }
    }
    if(!w.empty()) zip_file << dictionary[w];

    std::cout << "Compress success! \n";

    file.close();
    zip_file.close();
}

void decompress_LZW(const std::string path_zip_file){
    std::ifstream zip_file(path_zip_file, std::ios_base::binary);    // открываем зип файл

    std::string name = path_zip_file.substr(path_zip_file.find_last_of("\\")+1, path_zip_file.size());
    name = name.substr(0, name.find_last_of('.'));
    name = "decompress_" + name;
    std::string path = path_zip_file.substr(0, path_zip_file.find_last_of("\\")) + "\\" + name;
                                              
    std::ofstream file(path, std::ios_base::binary);     // разархивированный файл

    if(!zip_file){
        std::cout << "Error! Cannot open file " << path_zip_file << "\n";
        return;
    }

    int64_t dictSize = 256;
    std::map<int64_t, std::string> dictionary;
    for (int64_t i = 0; i < dictSize; i++) dictionary[i] = std::string(1, i);

    int64_t k; zip_file >> k;
    std::string w(1, k);
    file << w;
    std::string entry;
    while(zip_file >> k){
        if(dictionary.count(k)) entry = dictionary[k];
        else if(k == dictSize) entry = w + w[0];
        else throw "Bad decompress! \n";

        file << entry;
        dictionary[dictSize++] = w + entry[0];
        w = entry;
    }
    
    std::cout << "Decompress success! \n";

    file.close();
    zip_file.close();
}