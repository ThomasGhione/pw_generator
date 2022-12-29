#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std::chrono;

char boolCheck(bool boolean) { return boolean ? 'X' : ' '; }

std::string shuffle(std::string pw) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(pw.begin(), pw.end(), e);
    return pw;
}



void menu() {
    int length;
    bool letters = true, numbers = true, capitalized = true, symbols = true;

    std::cout << "Password Generator \n\nCurrently settings: \nLetters [" << boolCheck(letters) << "] \nNumbers [" << boolCheck(numbers) << "] \nCapitalized [" << boolCheck(capitalized) << "] \nSymbols [" << boolCheck(symbols) << "] \n\nInsert password length, minimum length is 8. \nPassword length = ";
    std::cin >> length;

    while (length < 8) {
        std::cout << "\nPassword length is too short, minimum length is 8. \nPassword length = ";
        std::cin >> length;
    }
}

int main() {
    std::string testPW = "abc123";
    std::string lowerCase = "qwertyuiopasdfghjklzxcvbnm";
    std::string upperCase = "QWERTYUIOPASDFGHJKLZXCVBNM";
    std::string numbers = "0123456789";
    std::string symbols = "!£$%&/=?@,.-;:_";

    std::string combinedLowerCase = shuffle(lowerCase);
    std::string combinedUpperCase = shuffle(upperCase);
    std::string combinedNumbers = shuffle(numbers);
    std::string combinedSymbols = shuffle(symbols);

    int lenght = 16;

    //PLACEHOLDER FOR TESTING

    std::string notShuffledPW;
    for (int i=0; i<4; ++i) notShuffledPW += combinedLowerCase[i];
    for (int i=0; i<4; ++i) notShuffledPW += combinedUpperCase[i];
    for (int i=0; i<4; ++i) notShuffledPW += combinedNumbers[i];
    for (int i=0; i<4; ++i) notShuffledPW += combinedSymbols[i];
    // std::cout << notShuffledPW;

    std::string shuffledPW = shuffle(notShuffledPW);
    std::cout << shuffledPW;
    // std::string notShuffledPW = combinedLowerCase + combinedUpperCase + combinedNumbers + combinedSymbols;
    
}