#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string source = "//home/gaffor/gaffor/saqlash"; // Manba papkasi yo'li
    std::string destination = "//home/gaffor/gaffor/Nabiyev"; // Nusxa olish uchun mo'ljallangan papka yo'li

    try {
        // Agar maqsad papkasi mavjud bo'lmasa, uni yaratish
        if (!fs::exists(destination)) {
            fs::create_directories(destination);
        }
        // Manba papkasidagi barcha fayllar va papkalarni nusxalash
        for (const auto& entry : fs::recursive_directory_iterator(source)) {
            const auto& path = entry.path();
            auto relative_path = fs::relative(path, source);
            fs::copy(path, destination / relative_path, fs::copy_options::overwrite_existing | fs::copy_options::recursive);
        }

        std::cout << "Papkadan rezerv nusxa muvaffaqiyatli olingan." << std::endl;
    } catch (const fs::filesystem_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
