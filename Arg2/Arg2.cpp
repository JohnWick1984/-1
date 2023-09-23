// Arg2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Использование: " << argv[0] << " '*' C:\\Users\\Евгений\\Documents\\Учеба Академия ТОР\\ООП С++\\ООП С++\\Аргумент1\\Arg2" << std::endl;
        return 1;
    }

    char charToReplace = argv[1][0];
    std::string filePath = argv[2];

    std::ifstream inputFile(filePath);
    if (!inputFile) {
        std::cerr << "Не удалось открыть файл: " << filePath << std::endl;
        return 1;
    }

    std::string fileContents((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    for (char& c : fileContents) {
        if (c == charToReplace) {
            c = '*';
        }
    }

    std::ofstream outputFile(filePath);
    if (!outputFile) {
        std::cerr << "Не удалось открыть файл для записи: " << filePath << std::endl;
        return 1;
    }

    outputFile << fileContents;
    outputFile.close();

    std::cout << "Все вхождения символа '" << charToReplace << "' были заменены на '*'" << std::endl;

    return 0;
}
