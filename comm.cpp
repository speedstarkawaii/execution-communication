// Include all of these files
#include <iostream>
#include <chrono>
#include <thread>
#include <filesystem>
#include <fstream>
#include <string>

void readscript(const std::filesystem::path& scriptpath) {
    std::ifstream file(scriptpath);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
            // Execute the script, line would contain the script
        }
        file.close();
    } else { /* Cant open the script, you could add exceptions OR you can just create a file*/ 
        exit(-1);
    }
}

int main() {
    std::filesystem::path scriptname = "executedscript.lua"; // You can either hide this somewhere in a secret folder, or  keep it public but I just keep it public
    auto lastscriptwritetime = std::filesystem::last_write_time(scriptname);

    while (true) { // Loop read the script
        auto currentscriptwritetime = std::filesystem::last_write_time(scriptname); // Each time the script is modified, it will be read
        if (currentscriptwritetime != lastscriptwritetime) {
            lastscriptwritetime = currentscriptwritetime;
            std::cout << "New script in queue!\n";
            readscript(filePath);
        }
        std::this_thread::sleep_for(std::chrono::seconds(1)); // I would add a short cooldown that speeds up the execution process
    }

    return NULL;
}
