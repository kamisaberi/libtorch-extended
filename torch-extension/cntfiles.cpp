#include <filesystem>
#include <algorithm>
#include <iostream>

std::size_t count_files_recursively(const std::filesystem::path& path) {
    return std::count_if(
        std::filesystem::recursive_directory_iterator(path),
        std::filesystem::recursive_directory_iterator{},
        [](const std::filesystem::directory_entry& entry) {
            return entry.is_regular_file();
        }
    );
}

int main() {
    std::filesystem::path directory_path = "/home/kami/Documents/temp/videos/";
    try {
        std::size_t total_files = count_files_recursively(directory_path);
        std::cout << "Total number of files: " << total_files << std::endl;
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}