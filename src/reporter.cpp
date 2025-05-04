//
// reporter.cpp
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include "../include/employee.h"

// Структура для хранения отчета по сотруднику
struct ReportEntry {
    employee emp;
    double computedSalary;
};

int main(int argc, char* argv[]) {
    // Чтение имени бинарного файла, имени отчетного файла и ставки оплаты
    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    double rate = 0;

    // Открытие бинарного файла для чтения
    std::ifstream inputStream(inputFile, std::ios::binary);

    // Массив для хранения данных по сотрудникам
    std::vector<ReportEntry> entries;
    employee currentEmployee;

    // Чтение данных из бинарного файла
    while (inputStream.read(reinterpret_cast<char*>(&currentEmployee), sizeof(currentEmployee))) {
        ReportEntry entry;
        entry.emp = currentEmployee;
        entry.computedSalary = currentEmployee.hours * rate;
        entries.push_back(entry);
    }
    inputStream.close();

    // Сортировка записей по номеру сотрудника
    std::sort(entries.begin(), entries.end(), [](const ReportEntry& a, const ReportEntry& b) {
        return a.emp.num < b.emp.num;
    });

    // Открытие файла для записи отчета
    std::ofstream outputStream(outputFile);

    // Запись данных в отчет
    outputStream << "Employee Report for \"" << inputFile << "\"\n";
    outputStream << "Employee Number\tName\tHours Worked\tSalary\n";

    for (const auto& entry : entries) {
        outputStream << entry.emp.num << "\t"
                     << entry.emp.name << "\t"
                     << entry.emp.hours << "\t"
                     << std::fixed << std::setprecision(2)
                     << entry.computedSalary << "\n";
    }

    outputStream.close();
    return 0;
}
