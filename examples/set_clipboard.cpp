#include <iostream>
#include <string>

#include <clipboard.hpp>

int main(int argc, char* argv) {
    std::string buffer = "Hello, world!";
    if (Clipboard::set_clipboard_text(buffer)) {
        std::cout << "Successfully set clipboard text to: " << buffer << std::endl;
    } else {
        std::cout << "Could not set clipboard text" << std::endl;
    }

    return 0;
}