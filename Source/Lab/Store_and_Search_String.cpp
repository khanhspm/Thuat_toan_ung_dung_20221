#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> database;
    std::string key;

    // read in the database
    while (std::getline(std::cin, key)) {
        if (key == "*") break;
        database.insert(key);
    }

    // perform queries
    std::string cmd;
    while (std::cin >> cmd >> key) {
        if (cmd == "find") {
            std::cout << (database.count(key) ? 1 : 0) << std::endl;
        } else if (cmd == "insert") {
            std::cout << (database.insert(key).second ? 1 : 0) << std::endl;
        }
        if (key == "***") break;
    }

    return 0;
}
