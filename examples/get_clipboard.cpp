#include <iostream>
#include <string>

#include <clipboard.hpp>

int main(int argc, char* argv) {
    std::string buffer;
    if (Clipboard::get_clipboard_text(buffer)) {
        std::cout << buffer << std::endl;
    } else {
        std::cout << "Could not get clipboard text" << std::endl;
    }

    return 0;
}