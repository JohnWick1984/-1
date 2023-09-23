// Аргумент1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
    setlocale(0, "");
    // Проверяем, что передано правильное количество аргументов
    if (argc != 2)
    {
        cerr << "Использование: " << argv[0] << "C:\\Users\\Евгений\\Documents\\Учеба Академия ТОР\\ООП С++\\ООП С++\\Аргумент1\x64\Debug\1.txt" << endl;
        return 1; // Возвращаем ненулевой код ошибки
    }

    // Получаем путь к файлу из аргумента командной строки
    string filePath = argv[1];

    // Открываем файл для чтения
    ifstream inputFile(filePath);

    // Проверяем, удалось ли открыть файл
    if (!inputFile.is_open()) 
    {
        cerr << "Не удалось открыть файл: " << filePath << endl;
        return 2; // Возвращаем код ошибки
    }

    // Читаем и выводим содержимое файла построчно
    string line;
    while (getline(inputFile, line)) 
    {
        cout << line << endl;
    }

    // Закрываем файл
    inputFile.close();

    return 0; 
}
