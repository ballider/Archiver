#ifndef AF163633_088C_4169_BF0C_4C4188516CF6
#define AF163633_088C_4169_BF0C_4C4188516CF6

class zipper{
private:
    std::string path_file_;     // путь до файла, который надо архивировать
    std::string path_zip_file_; // путь до заорхивированного файла

    std::string get_file_name(const std::string path_to_file) const;
public:
    zipper();
    zipper(const std::string path_file, const std::string path_zip_file);

    void update_fields(const std::string path_file, const std::string path_zip_file);

    void compress();
    void decompress(const std::string path_zip_file);
};

#endif /* AF163633_088C_4169_BF0C_4C4188516CF6 */
