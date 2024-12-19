//Generates a set number of random passwords with a given min/max length

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

const int NUM_PASSWORDS = 10000;
const int MIN_LENGTH = 10;
const int MAX_LENGTH = 30;
const std::string CHARACTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:',.<>?";

std::string generateRandomPassword(int length) {
    std::string password;
    for (int i = 0; i < length; ++i) {
        password += CHARACTERS[rand() % CHARACTERS.size()];
    }
    return password;
}

int main() {
    srand(time(0));
    std::string filename = "passwords.txt";

    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Could not open the file for writing." << std::endl;
        return 1;
    }

    for (int i = 0; i < NUM_PASSWORDS; ++i) {
        int length = MIN_LENGTH + rand() % (MAX_LENGTH - MIN_LENGTH + 1);
        std::string password = generateRandomPassword(length);
        outFile << password << std::endl;
    }

    outFile.close();
    std::cout << "Generated " << NUM_PASSWORDS << " random passwords and stored them in " << filename << std::endl;

    return 0;
}
