//
// creator.cpp
//

#include <iostream>
#include <fstream>
#include <string>
#include "employee.h"

int main(int argc, char* argv[]) {
    // Чтение имени файла и количества записей
    std::string filePath = argv[1];
    int recordNumber = 0;

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
        std::string tempName;
        emp.name = tempName; // Присвоение значения имени

        // Запись данных в файл
        fileStream.write(reinterpret_cast<char*>(&emp), sizeof(emp));

    }

    // Закрытие файла
    fileStream.close();
    return 0;
}
