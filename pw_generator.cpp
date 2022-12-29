#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>

std::string shuffle(std::string pw) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(pw.begin(), pw.end(), e);
    return pw;
}

int main() {
    std::string lowercase = "qwertyuiopasdfghjklzxcvbnm";
    std::string uppercase = "QWERTYUIOPASDFGHJKLZXCVBNM";
    std::string numbers = "0123456789";
    std::string symbols = "!$%&/=?@,.-;:_()[]{}~#*+|<>'";

    int length = -1;
    std::cout << "Insert the desired length: "; 
    std::cin >> length;
    
    // check if length is too short
    while (length < 12) {
        std::cout << "\nPassword length is too short, minimum length is 12. \nInsert length again: ";
        std::cin >> length;
    }
    // check if length is too long
    while (length > 32) {
        std::cout << "\nPassword length is too long, maximum length is 32. \nInsert length again: ";
        std::cin >> length;        
    }

    // pw must have every type of char to be efficient 
    std::string pw = lowercase + uppercase + numbers + symbols;
    // then we shuffle it
    pw = shuffle(pw);
    // then we resize it to the desired length
    pw.resize(length);
    // finally we print it
    std::cout << pw;
    
    return 0;
}