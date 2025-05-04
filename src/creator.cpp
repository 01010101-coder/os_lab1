#include <iostream>
#include <fstream>
#include <string>
#include "../include/employee.h"
#include <cstring> // Для использования strncpy

int main(int argc, char* argv[]) {
    // Чтение имени файла и количества записей
    if (argc != 3) {
        std::cerr << "Usage: Creator <binary_file> <record_count>" << std::endl;
        return 1;
    }

    std::string filePath = argv[1];
    int recordNumber = 0;

    try {
        recordNumber = std::stoi(argv[2]);
    }
    catch (...) {
        std::cerr << "Invalid record count" << std::endl;
        return 1;
    }

    // Открытие бинарного файла для записи
    std::ofstream fileStream(filePath, std::ios::binary);
    if (!fileStream.is_open()) {
        std::cerr << "Error: Cannot open file " << filePath << " for writing" << std::endl;
        return 1;
    }

    // Цикл записи данных о сотрудниках
    for (int i = 0; i < recordNumber; ++i) {
        employee emp = {};
        std::cout << "Input details for employee " << i + 1 << " (ID Name HoursWorked): ";

        // Ввод данных сотрудника
        int tempNum;
        std::string tempName;
        double tempHours;

        std::cin >> tempNum >> tempName >> tempHours;

        emp.num = tempNum;
        emp.hours = tempHours;

        // Ограничиваем длину имени до 9 символов (оставляем место для нулевого символа)
        strncpy(emp.name, tempName.c_str(), sizeof(emp.name) - 1);
        emp.name[sizeof(emp.name) - 1] = '\0'; // Обеспечиваем завершение строки нулевым символом

        // Запись данных в файл
        fileStream.write(reinterpret_cast<char*>(&emp), sizeof(emp));
        if (!fileStream) {
            std::cerr << "Error writing to file" << std::endl;
            return 1;
        }
    }

    // Закрытие файла
    fileStream.close();
    return 0;
}
